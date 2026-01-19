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
	output bit o_interrupt,
	output bit o_claimed,

	// CPU interface
	input wire i_request,
	input wire i_rw,
	input wire [23:0] i_address,
	input wire [31:0] i_wdata,
	output bit [31:0] o_rdata,
	output bit o_ready
);

	bit [1:0] interrupt_0 = 2'b00;
	bit [1:0] interrupt_1 = 2'b00;
	bit [1:0] interrupt_2 = 2'b00;
	bit [1:0] interrupt_3 = 2'b00;
	bit [3:0] enable = 0;
	bit [3:0] pending = 0;
	bit [2:0] claimed = 0;

	initial begin
		o_rdata = 1'b0;
		o_ready = 1'b0;
	end

	always_comb begin
		o_interrupt = |pending;
		o_claimed = |claimed;
	end

	always_ff @(posedge i_clock) begin
		if (i_reset) begin
			interrupt_0 <= 2'b00;
			interrupt_1 <= 2'b00;
			interrupt_2 <= 2'b00;
			interrupt_3 <= 2'b00;
			enable <= 0;
			pending <= 0;
			claimed <= 1'b0;
		end
		else begin

			// Positive edge detect on interrupt pins.
			interrupt_0 <= { interrupt_0[0], i_interrupt_0 };
			interrupt_1 <= { interrupt_1[0], i_interrupt_1 };
			interrupt_2 <= { interrupt_2[0], i_interrupt_2 };
			interrupt_3 <= { interrupt_3[0], i_interrupt_3 };

			// Latch pending flags.
			if (enable[0] && interrupt_0 == 2'b01) begin
				pending[0] <= 1;
			end
			if (enable[1] && interrupt_1 == 2'b01) begin
				pending[1] <= 1;
			end
			if (enable[2] && interrupt_2 == 2'b01) begin
				pending[2] <= 1;
			end
			if (enable[3] && interrupt_3 == 2'b01) begin
				pending[3] <= 1;
			end

			// Handle claim and completion.
			o_ready <= 0;

			if (i_request && !i_rw && !o_ready) begin
				if (i_address == 24'h200004) begin	// claim context 0
					if (pending[0]) begin
						o_rdata <= 1;
						claimed <= 1;
						pending[0] <= 0;
					end
					else if (pending[1]) begin
						o_rdata <= 2;
						claimed <= 2;
						pending[1] <= 0;
					end
					else if (pending[2]) begin
						o_rdata <= 3;
						claimed <= 3;
						pending[2] <= 0;
					end
					else if (pending[3]) begin
						o_rdata <= 4;
						claimed <= 4;
						pending[3] <= 0;
					end
				end
			end

			if (i_request && i_rw && !o_ready) begin
				if (i_address == 24'h002000) begin	// enable
					enable <= i_wdata[4:1];
				end
				else if (i_address == 24'h200004) begin	// complete context 0
					claimed <= 0;
				end
			end

			if (i_request) begin
				o_ready <= 1;
			end
		end
	end

endmodule
