/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns
`default_nettype none

module I2C (
	input wire i_clock,
	input wire i_request,
	input wire i_rw,
	input wire [31:0] i_wdata,
	output bit [31:0] o_rdata,
	output bit o_ready,

	output wire I2C_SCL,
	output wire I2C_SDA_direction,
	input wire I2C_SDA_r,
	output wire I2C_SDA_w
);
	bit scl = 1;
	bit sda = 1;
	
	wire [3:0] mask = i_wdata[7:4];
	wire [3:0] value = i_wdata[3:0];

	assign I2C_SCL = scl;
	
	assign I2C_SDA_direction = (i_request && !i_rw) ? 1'b0 : 1'b1;
	assign I2C_SDA_w = sda;

	always_ff @(posedge i_clock) begin
		if (i_request) begin
			if (!i_rw) begin
				o_rdata <= { 30'b0, scl, I2C_SDA_r };
			end
			else begin
				sda <= (sda & ~mask[0]) | value[0];
				scl <= (scl & ~mask[1]) | value[1];
			end
		end
	end
	
	always_ff @(posedge i_clock)
		o_ready <= i_request;

endmodule
