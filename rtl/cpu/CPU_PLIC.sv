/*
 Klara-RV
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns
`default_nettype none

module CPU_PLIC(
	input wire i_reset,
	input wire i_clock,

	// Input
	input wire i_interrupt_0,
	input wire i_interrupt_1,
	input wire i_interrupt_2,
	input wire i_interrupt_3,

	// Output
	input wire i_interrupt_enable,
	output bit o_interrupt,

	// CPU interface
	input wire i_request,
	input wire i_rw,
	input wire [23:0] i_address,
	input wire [31:0] i_wdata,
	output bit [31:0] o_rdata,
	output bit o_ready
);

	bit [3:0] enable = 0;
	bit [3:0] pending = 0;
	bit issued = 1'b0;

	initial begin
		o_interrupt = 1'b0;
		o_rdata = 1'b0;
		o_ready = 1'b0;
	end

	always_ff @(posedge i_clock) begin
		if (i_reset) begin
			enable <= 0;
			pending <= 0;
			issued <= 1'b0;
		end
		else begin
			if (i_interrupt_enable) begin
				if (enable[0] && i_interrupt_0) begin
					pending[0] <= 1;
				end
				if (enable[1] && i_interrupt_1) begin
					pending[1] <= 1;
				end
				if (enable[2] && i_interrupt_2) begin
					pending[2] <= 1;
				end
				if (enable[3] && i_interrupt_3) begin
					pending[3] <= 1;
				end
			end

			o_interrupt <= 1'b0;

			if (i_interrupt_enable && |pending && !issued) begin
				o_interrupt <= 1'b1;
				issued <= 1'b1;
			end

			o_rdata <= 0;
			o_ready <= 0;

			if (i_request && !i_rw) begin
				if (i_address == 24'h200004) begin	// claim context 0
					if (pending[0]) begin
						o_rdata <= 1;
						pending[0] <= 0;
					end
					else if (pending[1]) begin
						o_rdata <= 2;
						pending[1] <= 0;
					end
					else if (pending[2]) begin
						o_rdata <= 3;
						pending[2] <= 0;
					end
					else if (pending[3]) begin
						o_rdata <= 4;
						pending[3] <= 0;
					end
				end
			end

			if (i_request && i_rw) begin
				if (i_address == 24'h002000) begin	// enable
					enable <= i_wdata[4:1];
				end
				else if (i_address == 24'h200004) begin	// complete context 0
					issued <= 0;
				end
			end

			if (i_request) begin
				o_ready <= 1;
			end
		end
	end

endmodule
