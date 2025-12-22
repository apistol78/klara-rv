/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns
`default_nettype none

module AUDIO_channel_tb();

	bit clk;
	bit sample_clock;

	bit ac_dma_setup_request = 1'b0;

	wire [15:0] ac_output_sample_left;
	wire [15:0] ac_output_sample_right;

	wire ac_dma_request;
	bit ac_dma_ready = 1'b0;
	wire [31:0] ac_dma_address;

	AUDIO_channel #(
		.BUFFER_SIZE(4)
	) ac(
		.i_reset(1'b0),
		.i_clock(clk),

		.i_dma_setup_request(ac_dma_setup_request),
		.i_dma_setup_count(16),
		.i_dma_setup_address(32'h10002000),

		.o_dma_request(ac_dma_request),
		.o_dma_address(ac_dma_address),
		.i_dma_ready(ac_dma_ready),
		.i_dma_rdata(ac_dma_address),

		.i_output_sample_clock(sample_clock),
		.o_output_sample_left(ac_output_sample_left),
		.o_output_sample_right(ac_output_sample_right)
	);

	always_ff @(posedge clk) ac_dma_ready <= ac_dma_request;

	initial begin
		clk = 0;
		#1;
		forever clk = #5 ~clk;        
	end

	initial begin
		sample_clock = 0;
		#1;
		forever sample_clock = #100 ~sample_clock;     
	end

	initial begin
		$dumpfile("build/test/AUDIO_channel_tb.vcd");
		$dumpvars(0, AUDIO_channel_tb);

		repeat (100) @ (posedge clk);

		ac_dma_setup_request <= 1;
		@(posedge clk);
		ac_dma_setup_request <= 0;



		repeat (100000) @ (posedge clk);

		$finish;
	end

endmodule