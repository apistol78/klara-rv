/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns
`default_nettype none

`ifdef __VERILATOR__
	`define INSTANT_CLEAR
`endif

module BRAM_clear #(
	parameter WIDTH = 32,
	parameter SIZE = 32'h400,
	parameter ADDR_LSH = 2,
	parameter CLEAR_VALUE = 32'h0
)(
	input i_reset,
	input i_clock,
	output o_initialized,
	input i_request,
	input i_rw,
	input [31:0] i_address,
	input [WIDTH - 1:0] i_wdata,
	output bit [WIDTH - 1:0] o_rdata,
	output bit o_ready
);
    bit [31:0] clear = 0;
    
    assign o_initialized = clear >= SIZE;
    assign o_ready = o_initialized ? ready : 1'b0;

	always_ff @(posedge i_clock) begin
		if (i_reset) begin
			clear <= 0;
		end
		else if (clear < SIZE) begin
			clear <= clear + 1;
		end
	end
	
	logic ready;
	
    BRAM #(
        .WIDTH(WIDTH),
        .SIZE(SIZE),
        .ADDR_LSH(ADDR_LSH)
    ) bram(
        .i_clock(i_clock),
        .i_request(o_initialized ? i_request : 1'b1),
        .i_rw(o_initialized ? i_rw : 1'b1),
        .i_address(o_initialized ? i_address : clear),
        .i_wdata(o_initialized ? i_wdata : CLEAR_VALUE),
        .o_rdata(o_rdata),
        .o_ready(ready)
    );
    
endmodule