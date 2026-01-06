/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns
`default_nettype none

module AUDIO_controller_16(
	input wire i_reset,
	input wire i_clock,

	// CPU interface.
	input wire i_request,
	input wire i_rw,
	input wire [7:0] i_address,
	input wire [31:0] i_wdata,
	output bit [31:0] o_rdata,
	output bit o_ready,

	// DMA bus master
	output bit o_dma_request,
	output bit [31:0] o_dma_address,
	input wire i_dma_ready,
	input wire [31:0] i_dma_rdata,

	// Audio output
	input wire i_output_sample_clock,
	output bit [31:0] o_output_sample_rate,
	output bit [15:0] o_output_sample_left,
	output bit [15:0] o_output_sample_right,

	// Audio interrupt
	output bit o_interrupt
);

	initial begin
		o_ready = 1'b0;
		o_dma_request = 1'b0;
		o_output_sample_rate = 100_000_000 / (256 * 22050);
		o_output_sample_left = 16'd0;
		o_output_sample_right = 16'd0;
		o_interrupt = 1'b0;
	end

	// Channel 0
	bit ch0_dma_setup_request = 1'b0;
	bit ch0_dma_setup_append_or_replace = 1'b0;
	bit ch0_dma_setup_mono_or_stereo = 1'b0;
	bit [23:0] ch0_dma_setup_count;
	bit [31:0] ch0_dma_setup_address;

	wire ch0_dma_request;
	wire [31:0] ch0_dma_address;
	bit ch0_dma_ready;

	wire ch0_busy;

	bit [3:0] ch0_volume = 4'hf;
	bit [15:0] ch0_sample_left;
	bit [15:0] ch0_sample_right;

	AUDIO_channel ch0(
		.i_reset(i_reset),
		.i_clock(i_clock),

		.i_dma_setup_request(ch0_dma_setup_request),
		.i_dma_setup_append_or_replace(ch0_dma_setup_append_or_replace),
		.i_dma_setup_mono_or_stereo(ch0_dma_setup_mono_or_stereo),
		.i_dma_setup_count(ch0_dma_setup_count),
		.i_dma_setup_address(ch0_dma_setup_address),

		.o_dma_request(ch0_dma_request),
		.o_dma_address(ch0_dma_address),
		.i_dma_ready(ch0_dma_ready),
		.i_dma_rdata(i_dma_rdata),

		.o_busy(ch0_busy),

		.i_volume(ch0_volume),

		.i_output_sample_clock(i_output_sample_clock),
		.o_output_sample_left(ch0_sample_left),
		.o_output_sample_right(ch0_sample_right)
	);

	// Channel 1
	bit ch1_dma_setup_request = 1'b0;
	bit ch1_dma_setup_append_or_replace = 1'b0;
	bit ch1_dma_setup_mono_or_stereo = 1'b0;
	bit [23:0] ch1_dma_setup_count;
	bit [31:0] ch1_dma_setup_address;

	wire ch1_dma_request;
	wire [31:0] ch1_dma_address;
	bit ch1_dma_ready;

	wire ch1_busy;

	bit [3:0] ch1_volume = 4'hf;
	bit [15:0] ch1_sample_left;
	bit [15:0] ch1_sample_right;

	AUDIO_channel ch1(
		.i_reset(i_reset),
		.i_clock(i_clock),

		.i_dma_setup_request(ch1_dma_setup_request),
		.i_dma_setup_append_or_replace(ch1_dma_setup_append_or_replace),
		.i_dma_setup_mono_or_stereo(ch1_dma_setup_mono_or_stereo),
		.i_dma_setup_count(ch1_dma_setup_count),
		.i_dma_setup_address(ch1_dma_setup_address),

		.o_dma_request(ch1_dma_request),
		.o_dma_address(ch1_dma_address),
		.i_dma_ready(ch1_dma_ready),
		.i_dma_rdata(i_dma_rdata),

		.o_busy(ch1_busy),

		.i_volume(ch1_volume),

		.i_output_sample_clock(i_output_sample_clock),
		.o_output_sample_left(ch1_sample_left),
		.o_output_sample_right(ch1_sample_right)
	);

	// Channel 2
	bit ch2_dma_setup_request = 1'b0;
	bit ch2_dma_setup_append_or_replace = 1'b0;
	bit ch2_dma_setup_mono_or_stereo = 1'b0;
	bit [23:0] ch2_dma_setup_count;
	bit [31:0] ch2_dma_setup_address;

	wire ch2_dma_request;
	wire [31:0] ch2_dma_address;
	bit ch2_dma_ready;

	wire ch2_busy;

	bit [3:0] ch2_volume = 4'hf;
	bit [15:0] ch2_sample_left;
	bit [15:0] ch2_sample_right;

	AUDIO_channel ch2(
		.i_reset(i_reset),
		.i_clock(i_clock),

		.i_dma_setup_request(ch2_dma_setup_request),
		.i_dma_setup_append_or_replace(ch2_dma_setup_append_or_replace),
		.i_dma_setup_mono_or_stereo(ch2_dma_setup_mono_or_stereo),
		.i_dma_setup_count(ch2_dma_setup_count),
		.i_dma_setup_address(ch2_dma_setup_address),

		.o_dma_request(ch2_dma_request),
		.o_dma_address(ch2_dma_address),
		.i_dma_ready(ch2_dma_ready),
		.i_dma_rdata(i_dma_rdata),

		.o_busy(ch2_busy),

		.i_volume(ch2_volume),

		.i_output_sample_clock(i_output_sample_clock),
		.o_output_sample_left(ch2_sample_left),
		.o_output_sample_right(ch2_sample_right)
	);

	// Channel 3
	bit ch3_dma_setup_request = 1'b0;
	bit ch3_dma_setup_append_or_replace = 1'b0;
	bit ch3_dma_setup_mono_or_stereo = 1'b0;
	bit [23:0] ch3_dma_setup_count;
	bit [31:0] ch3_dma_setup_address;

	wire ch3_dma_request;
	wire [31:0] ch3_dma_address;
	bit ch3_dma_ready;

	wire ch3_busy;

	bit [3:0] ch3_volume = 4'hf;
	bit [15:0] ch3_sample_left;
	bit [15:0] ch3_sample_right;

	AUDIO_channel ch3(
		.i_reset(i_reset),
		.i_clock(i_clock),

		.i_dma_setup_request(ch3_dma_setup_request),
		.i_dma_setup_append_or_replace(ch3_dma_setup_append_or_replace),
		.i_dma_setup_mono_or_stereo(ch3_dma_setup_mono_or_stereo),
		.i_dma_setup_count(ch3_dma_setup_count),
		.i_dma_setup_address(ch3_dma_setup_address),

		.o_dma_request(ch3_dma_request),
		.o_dma_address(ch3_dma_address),
		.i_dma_ready(ch3_dma_ready),
		.i_dma_rdata(i_dma_rdata),

		.o_busy(ch3_busy),

		.i_volume(ch3_volume),

		.i_output_sample_clock(i_output_sample_clock),
		.o_output_sample_left(ch3_sample_left),
		.o_output_sample_right(ch3_sample_right)
	);

	// Channel 4
	bit ch4_dma_setup_request = 1'b0;
	bit ch4_dma_setup_append_or_replace = 1'b0;
	bit ch4_dma_setup_mono_or_stereo = 1'b0;
	bit [23:0] ch4_dma_setup_count;
	bit [31:0] ch4_dma_setup_address;

	wire ch4_dma_request;
	wire [31:0] ch4_dma_address;
	bit ch4_dma_ready;

	wire ch4_busy;

	bit [3:0] ch4_volume = 4'hf;
	bit [15:0] ch4_sample_left;
	bit [15:0] ch4_sample_right;

	AUDIO_channel ch4(
		.i_reset(i_reset),
		.i_clock(i_clock),

		.i_dma_setup_request(ch4_dma_setup_request),
		.i_dma_setup_append_or_replace(ch4_dma_setup_append_or_replace),
		.i_dma_setup_mono_or_stereo(ch4_dma_setup_mono_or_stereo),
		.i_dma_setup_count(ch4_dma_setup_count),
		.i_dma_setup_address(ch4_dma_setup_address),

		.o_dma_request(ch4_dma_request),
		.o_dma_address(ch4_dma_address),
		.i_dma_ready(ch4_dma_ready),
		.i_dma_rdata(i_dma_rdata),

		.o_busy(ch4_busy),

		.i_volume(ch4_volume),

		.i_output_sample_clock(i_output_sample_clock),
		.o_output_sample_left(ch4_sample_left),
		.o_output_sample_right(ch4_sample_right)
	);

	// Channel 5
	bit ch5_dma_setup_request = 1'b0;
	bit ch5_dma_setup_append_or_replace = 1'b0;
	bit ch5_dma_setup_mono_or_stereo = 1'b0;
	bit [23:0] ch5_dma_setup_count;
	bit [31:0] ch5_dma_setup_address;

	wire ch5_dma_request;
	wire [31:0] ch5_dma_address;
	bit ch5_dma_ready;

	wire ch5_busy;

	bit [3:0] ch5_volume = 4'hf;
	bit [15:0] ch5_sample_left;
	bit [15:0] ch5_sample_right;

	AUDIO_channel ch5(
		.i_reset(i_reset),
		.i_clock(i_clock),

		.i_dma_setup_request(ch5_dma_setup_request),
		.i_dma_setup_append_or_replace(ch5_dma_setup_append_or_replace),
		.i_dma_setup_mono_or_stereo(ch5_dma_setup_mono_or_stereo),
		.i_dma_setup_count(ch5_dma_setup_count),
		.i_dma_setup_address(ch5_dma_setup_address),

		.o_dma_request(ch5_dma_request),
		.o_dma_address(ch5_dma_address),
		.i_dma_ready(ch5_dma_ready),
		.i_dma_rdata(i_dma_rdata),

		.o_busy(ch5_busy),

		.i_volume(ch5_volume),

		.i_output_sample_clock(i_output_sample_clock),
		.o_output_sample_left(ch5_sample_left),
		.o_output_sample_right(ch5_sample_right)
	);

	// Channel 6
	bit ch6_dma_setup_request = 1'b0;
	bit ch6_dma_setup_append_or_replace = 1'b0;
	bit ch6_dma_setup_mono_or_stereo = 1'b0;
	bit [23:0] ch6_dma_setup_count;
	bit [31:0] ch6_dma_setup_address;

	wire ch6_dma_request;
	wire [31:0] ch6_dma_address;
	bit ch6_dma_ready;

	wire ch6_busy;

	bit [3:0] ch6_volume = 4'hf;
	bit [15:0] ch6_sample_left;
	bit [15:0] ch6_sample_right;

	AUDIO_channel ch6(
		.i_reset(i_reset),
		.i_clock(i_clock),

		.i_dma_setup_request(ch6_dma_setup_request),
		.i_dma_setup_append_or_replace(ch6_dma_setup_append_or_replace),
		.i_dma_setup_mono_or_stereo(ch6_dma_setup_mono_or_stereo),
		.i_dma_setup_count(ch6_dma_setup_count),
		.i_dma_setup_address(ch6_dma_setup_address),

		.o_dma_request(ch6_dma_request),
		.o_dma_address(ch6_dma_address),
		.i_dma_ready(ch6_dma_ready),
		.i_dma_rdata(i_dma_rdata),

		.o_busy(ch6_busy),

		.i_volume(ch6_volume),

		.i_output_sample_clock(i_output_sample_clock),
		.o_output_sample_left(ch6_sample_left),
		.o_output_sample_right(ch6_sample_right)
	);

	// Channel 7
	bit ch7_dma_setup_request = 1'b0;
	bit ch7_dma_setup_append_or_replace = 1'b0;
	bit ch7_dma_setup_mono_or_stereo = 1'b0;
	bit [23:0] ch7_dma_setup_count;
	bit [31:0] ch7_dma_setup_address;

	wire ch7_dma_request;
	wire [31:0] ch7_dma_address;
	bit ch7_dma_ready;

	wire ch7_busy;

	bit [3:0] ch7_volume = 4'hf;
	bit [15:0] ch7_sample_left;
	bit [15:0] ch7_sample_right;

	AUDIO_channel ch7(
		.i_reset(i_reset),
		.i_clock(i_clock),

		.i_dma_setup_request(ch7_dma_setup_request),
		.i_dma_setup_append_or_replace(ch7_dma_setup_append_or_replace),
		.i_dma_setup_mono_or_stereo(ch7_dma_setup_mono_or_stereo),
		.i_dma_setup_count(ch7_dma_setup_count),
		.i_dma_setup_address(ch7_dma_setup_address),

		.o_dma_request(ch7_dma_request),
		.o_dma_address(ch7_dma_address),
		.i_dma_ready(ch7_dma_ready),
		.i_dma_rdata(i_dma_rdata),

		.o_busy(ch7_busy),

		.i_volume(ch7_volume),

		.i_output_sample_clock(i_output_sample_clock),
		.o_output_sample_left(ch7_sample_left),
		.o_output_sample_right(ch7_sample_right)
	);

	// Channel 8
	bit ch8_dma_setup_request = 1'b0;
	bit ch8_dma_setup_append_or_replace = 1'b0;
	bit ch8_dma_setup_mono_or_stereo = 1'b0;
	bit [23:0] ch8_dma_setup_count;
	bit [31:0] ch8_dma_setup_address;

	wire ch8_dma_request;
	wire [31:0] ch8_dma_address;
	bit ch8_dma_ready;

	wire ch8_busy;

	bit [3:0] ch8_volume = 4'hf;
	bit [15:0] ch8_sample_left;
	bit [15:0] ch8_sample_right;

	AUDIO_channel ch8(
		.i_reset(i_reset),
		.i_clock(i_clock),

		.i_dma_setup_request(ch8_dma_setup_request),
		.i_dma_setup_append_or_replace(ch8_dma_setup_append_or_replace),
		.i_dma_setup_mono_or_stereo(ch8_dma_setup_mono_or_stereo),
		.i_dma_setup_count(ch8_dma_setup_count),
		.i_dma_setup_address(ch8_dma_setup_address),

		.o_dma_request(ch8_dma_request),
		.o_dma_address(ch8_dma_address),
		.i_dma_ready(ch8_dma_ready),
		.i_dma_rdata(i_dma_rdata),

		.o_busy(ch8_busy),

		.i_volume(ch8_volume),

		.i_output_sample_clock(i_output_sample_clock),
		.o_output_sample_left(ch8_sample_left),
		.o_output_sample_right(ch8_sample_right)
	);

	// Channel 9
	bit ch9_dma_setup_request = 1'b0;
	bit ch9_dma_setup_append_or_replace = 1'b0;
	bit ch9_dma_setup_mono_or_stereo = 1'b0;
	bit [23:0] ch9_dma_setup_count;
	bit [31:0] ch9_dma_setup_address;

	wire ch9_dma_request;
	wire [31:0] ch9_dma_address;
	bit ch9_dma_ready;

	wire ch9_busy;

	bit [3:0] ch9_volume = 4'hf;
	bit [15:0] ch9_sample_left;
	bit [15:0] ch9_sample_right;

	AUDIO_channel ch9(
		.i_reset(i_reset),
		.i_clock(i_clock),

		.i_dma_setup_request(ch9_dma_setup_request),
		.i_dma_setup_append_or_replace(ch9_dma_setup_append_or_replace),
		.i_dma_setup_mono_or_stereo(ch9_dma_setup_mono_or_stereo),
		.i_dma_setup_count(ch9_dma_setup_count),
		.i_dma_setup_address(ch9_dma_setup_address),

		.o_dma_request(ch9_dma_request),
		.o_dma_address(ch9_dma_address),
		.i_dma_ready(ch9_dma_ready),
		.i_dma_rdata(i_dma_rdata),

		.o_busy(ch9_busy),

		.i_volume(ch9_volume),

		.i_output_sample_clock(i_output_sample_clock),
		.o_output_sample_left(ch9_sample_left),
		.o_output_sample_right(ch9_sample_right)
	);

	// Channel 10
	bit ch10_dma_setup_request = 1'b0;
	bit ch10_dma_setup_append_or_replace = 1'b0;
	bit ch10_dma_setup_mono_or_stereo = 1'b0;
	bit [23:0] ch10_dma_setup_count;
	bit [31:0] ch10_dma_setup_address;

	wire ch10_dma_request;
	wire [31:0] ch10_dma_address;
	bit ch10_dma_ready;

	wire ch10_busy;

	bit [3:0] ch10_volume = 4'hf;
	bit [15:0] ch10_sample_left;
	bit [15:0] ch10_sample_right;

	AUDIO_channel ch10(
		.i_reset(i_reset),
		.i_clock(i_clock),

		.i_dma_setup_request(ch10_dma_setup_request),
		.i_dma_setup_append_or_replace(ch10_dma_setup_append_or_replace),
		.i_dma_setup_mono_or_stereo(ch10_dma_setup_mono_or_stereo),
		.i_dma_setup_count(ch10_dma_setup_count),
		.i_dma_setup_address(ch10_dma_setup_address),

		.o_dma_request(ch10_dma_request),
		.o_dma_address(ch10_dma_address),
		.i_dma_ready(ch10_dma_ready),
		.i_dma_rdata(i_dma_rdata),

		.o_busy(ch10_busy),

		.i_volume(ch10_volume),

		.i_output_sample_clock(i_output_sample_clock),
		.o_output_sample_left(ch10_sample_left),
		.o_output_sample_right(ch10_sample_right)
	);

	// Channel 11
	bit ch11_dma_setup_request = 1'b0;
	bit ch11_dma_setup_append_or_replace = 1'b0;
	bit ch11_dma_setup_mono_or_stereo = 1'b0;
	bit [23:0] ch11_dma_setup_count;
	bit [31:0] ch11_dma_setup_address;

	wire ch11_dma_request;
	wire [31:0] ch11_dma_address;
	bit ch11_dma_ready;

	wire ch11_busy;

	bit [3:0] ch11_volume = 4'hf;
	bit [15:0] ch11_sample_left;
	bit [15:0] ch11_sample_right;

	AUDIO_channel ch11(
		.i_reset(i_reset),
		.i_clock(i_clock),

		.i_dma_setup_request(ch11_dma_setup_request),
		.i_dma_setup_append_or_replace(ch11_dma_setup_append_or_replace),
		.i_dma_setup_mono_or_stereo(ch11_dma_setup_mono_or_stereo),
		.i_dma_setup_count(ch11_dma_setup_count),
		.i_dma_setup_address(ch11_dma_setup_address),

		.o_dma_request(ch11_dma_request),
		.o_dma_address(ch11_dma_address),
		.i_dma_ready(ch11_dma_ready),
		.i_dma_rdata(i_dma_rdata),

		.o_busy(ch11_busy),

		.i_volume(ch11_volume),

		.i_output_sample_clock(i_output_sample_clock),
		.o_output_sample_left(ch11_sample_left),
		.o_output_sample_right(ch11_sample_right)
	);

	// Channel 12
	bit ch12_dma_setup_request = 1'b0;
	bit ch12_dma_setup_append_or_replace = 1'b0;
	bit ch12_dma_setup_mono_or_stereo = 1'b0;
	bit [23:0] ch12_dma_setup_count;
	bit [31:0] ch12_dma_setup_address;

	wire ch12_dma_request;
	wire [31:0] ch12_dma_address;
	bit ch12_dma_ready;

	wire ch12_busy;

	bit [3:0] ch12_volume = 4'hf;
	bit [15:0] ch12_sample_left;
	bit [15:0] ch12_sample_right;

	AUDIO_channel ch12(
		.i_reset(i_reset),
		.i_clock(i_clock),

		.i_dma_setup_request(ch12_dma_setup_request),
		.i_dma_setup_append_or_replace(ch12_dma_setup_append_or_replace),
		.i_dma_setup_mono_or_stereo(ch12_dma_setup_mono_or_stereo),
		.i_dma_setup_count(ch12_dma_setup_count),
		.i_dma_setup_address(ch12_dma_setup_address),

		.o_dma_request(ch12_dma_request),
		.o_dma_address(ch12_dma_address),
		.i_dma_ready(ch12_dma_ready),
		.i_dma_rdata(i_dma_rdata),

		.o_busy(ch12_busy),

		.i_volume(ch12_volume),

		.i_output_sample_clock(i_output_sample_clock),
		.o_output_sample_left(ch12_sample_left),
		.o_output_sample_right(ch12_sample_right)
	);

	// Channel 13
	bit ch13_dma_setup_request = 1'b0;
	bit ch13_dma_setup_append_or_replace = 1'b0;
	bit ch13_dma_setup_mono_or_stereo = 1'b0;
	bit [23:0] ch13_dma_setup_count;
	bit [31:0] ch13_dma_setup_address;

	wire ch13_dma_request;
	wire [31:0] ch13_dma_address;
	bit ch13_dma_ready;

	wire ch13_busy;

	bit [3:0] ch13_volume = 4'hf;
	bit [15:0] ch13_sample_left;
	bit [15:0] ch13_sample_right;

	AUDIO_channel ch13(
		.i_reset(i_reset),
		.i_clock(i_clock),

		.i_dma_setup_request(ch13_dma_setup_request),
		.i_dma_setup_append_or_replace(ch13_dma_setup_append_or_replace),
		.i_dma_setup_mono_or_stereo(ch13_dma_setup_mono_or_stereo),
		.i_dma_setup_count(ch13_dma_setup_count),
		.i_dma_setup_address(ch13_dma_setup_address),

		.o_dma_request(ch13_dma_request),
		.o_dma_address(ch13_dma_address),
		.i_dma_ready(ch13_dma_ready),
		.i_dma_rdata(i_dma_rdata),

		.o_busy(ch13_busy),

		.i_volume(ch13_volume),

		.i_output_sample_clock(i_output_sample_clock),
		.o_output_sample_left(ch13_sample_left),
		.o_output_sample_right(ch13_sample_right)
	);

	// Channel 14
	bit ch14_dma_setup_request = 1'b0;
	bit ch14_dma_setup_append_or_replace = 1'b0;
	bit ch14_dma_setup_mono_or_stereo = 1'b0;
	bit [23:0] ch14_dma_setup_count;
	bit [31:0] ch14_dma_setup_address;

	wire ch14_dma_request;
	wire [31:0] ch14_dma_address;
	bit ch14_dma_ready;

	wire ch14_busy;

	bit [3:0] ch14_volume = 4'hf;
	bit [15:0] ch14_sample_left;
	bit [15:0] ch14_sample_right;

	AUDIO_channel ch14(
		.i_reset(i_reset),
		.i_clock(i_clock),

		.i_dma_setup_request(ch14_dma_setup_request),
		.i_dma_setup_append_or_replace(ch14_dma_setup_append_or_replace),
		.i_dma_setup_mono_or_stereo(ch14_dma_setup_mono_or_stereo),
		.i_dma_setup_count(ch14_dma_setup_count),
		.i_dma_setup_address(ch14_dma_setup_address),

		.o_dma_request(ch14_dma_request),
		.o_dma_address(ch14_dma_address),
		.i_dma_ready(ch14_dma_ready),
		.i_dma_rdata(i_dma_rdata),

		.o_busy(ch14_busy),

		.i_volume(ch14_volume),

		.i_output_sample_clock(i_output_sample_clock),
		.o_output_sample_left(ch14_sample_left),
		.o_output_sample_right(ch14_sample_right)
	);

	// Channel 15
	bit ch15_dma_setup_request = 1'b0;
	bit ch15_dma_setup_append_or_replace = 1'b0;
	bit ch15_dma_setup_mono_or_stereo = 1'b0;
	bit [23:0] ch15_dma_setup_count;
	bit [31:0] ch15_dma_setup_address;

	wire ch15_dma_request;
	wire [31:0] ch15_dma_address;
	bit ch15_dma_ready;

	wire ch15_busy;

	bit [3:0] ch15_volume = 4'hf;
	bit [15:0] ch15_sample_left;
	bit [15:0] ch15_sample_right;

	AUDIO_channel ch15(
		.i_reset(i_reset),
		.i_clock(i_clock),

		.i_dma_setup_request(ch15_dma_setup_request),
		.i_dma_setup_append_or_replace(ch15_dma_setup_append_or_replace),
		.i_dma_setup_mono_or_stereo(ch15_dma_setup_mono_or_stereo),
		.i_dma_setup_count(ch15_dma_setup_count),
		.i_dma_setup_address(ch15_dma_setup_address),

		.o_dma_request(ch15_dma_request),
		.o_dma_address(ch15_dma_address),
		.i_dma_ready(ch15_dma_ready),
		.i_dma_rdata(i_dma_rdata),

		.o_busy(ch15_busy),

		.i_volume(ch15_volume),

		.i_output_sample_clock(i_output_sample_clock),
		.o_output_sample_left(ch15_sample_left),
		.o_output_sample_right(ch15_sample_right)
	);

	// Busy register.
	wire [31:0] channels_busy =
	{
		16'h0,
		ch15_busy,
		ch14_busy,
		ch13_busy,
		ch12_busy,
		ch11_busy,
		ch10_busy,
		ch9_busy,
		ch8_busy,
		ch7_busy,
		ch6_busy,
		ch5_busy,
		ch4_busy,
		ch3_busy,
		ch2_busy,
		ch1_busy,
		ch0_busy
	};

	// Issue interrupt whenever a busy bit becomes zero.
	bit [31:0] channels_busy_r = 32'h0;
	always_ff @(posedge i_clock) begin
		channels_busy_r <= channels_busy;
		o_interrupt <= (channels_busy_r & ~channels_busy);
	end

	// CPU register access.
	always_ff @(posedge i_clock) begin

		ch0_dma_setup_request <= 1'b0;
		ch1_dma_setup_request <= 1'b0;
		ch2_dma_setup_request <= 1'b0;
		ch3_dma_setup_request <= 1'b0;
		ch4_dma_setup_request <= 1'b0;
		ch5_dma_setup_request <= 1'b0;
		ch6_dma_setup_request <= 1'b0;
		ch7_dma_setup_request <= 1'b0;
		ch8_dma_setup_request <= 1'b0;
		ch9_dma_setup_request <= 1'b0;
		ch10_dma_setup_request <= 1'b0;
		ch11_dma_setup_request <= 1'b0;
		ch12_dma_setup_request <= 1'b0;
		ch13_dma_setup_request <= 1'b0;
		ch14_dma_setup_request <= 1'b0;
		ch15_dma_setup_request <= 1'b0;

		if (i_request && !o_ready) begin
			if (!i_rw) begin
				case (i_address)
					8'h00: begin
						o_rdata <= o_output_sample_rate;
						o_ready <= 1'b1;
					end
					8'h01: begin
						o_rdata <= channels_busy;
						o_ready <= 1'b1;
					end
					default:
						o_ready <= 1'b1;
				endcase
			end
			else begin
				case (i_address)
					8'h00: begin
						ch0_dma_setup_address <= i_wdata;
						o_ready <= 1'b1;
					end
					8'h01: begin
						ch0_dma_setup_count <= i_wdata[23:0];
						ch0_dma_setup_append_or_replace <= i_wdata[28];
						ch0_dma_setup_mono_or_stereo <= i_wdata[29];
						ch0_dma_setup_request <= 1'b1;
						o_ready <= 1'b1;
					end
					8'h02: begin
						ch0_volume <= i_wdata[3:0];
						o_ready <= 1'b1;
					end
					8'h04: begin
						ch1_dma_setup_address <= i_wdata;
						o_ready <= 1'b1;
					end
					8'h05: begin
						ch1_dma_setup_count <= i_wdata[23:0];
						ch1_dma_setup_append_or_replace <= i_wdata[28];
						ch1_dma_setup_mono_or_stereo <= i_wdata[29];
						ch1_dma_setup_request <= 1'b1;
						o_ready <= 1'b1;
					end
					8'h06: begin
						ch1_volume <= i_wdata[3:0];
						o_ready <= 1'b1;
					end
					8'h08: begin
						ch2_dma_setup_address <= i_wdata;
						o_ready <= 1'b1;
					end
					8'h09: begin
						ch2_dma_setup_count <= i_wdata[23:0];
						ch2_dma_setup_append_or_replace <= i_wdata[28];
						ch2_dma_setup_mono_or_stereo <= i_wdata[29];
						ch2_dma_setup_request <= 1'b1;
						o_ready <= 1'b1;
					end
					8'h0a: begin
						ch2_volume <= i_wdata[3:0];
						o_ready <= 1'b1;
					end
					8'h0c: begin
						ch3_dma_setup_address <= i_wdata;
						o_ready <= 1'b1;
					end
					8'h0d: begin
						ch3_dma_setup_count <= i_wdata[23:0];
						ch3_dma_setup_append_or_replace <= i_wdata[28];
						ch3_dma_setup_mono_or_stereo <= i_wdata[29];
						ch3_dma_setup_request <= 1'b1;
						o_ready <= 1'b1;
					end
					8'h0e: begin
						ch3_volume <= i_wdata[3:0];
						o_ready <= 1'b1;
					end
					8'h10: begin
						ch4_dma_setup_address <= i_wdata;
						o_ready <= 1'b1;
					end
					8'h11: begin
						ch4_dma_setup_count <= i_wdata[23:0];
						ch4_dma_setup_append_or_replace <= i_wdata[28];
						ch4_dma_setup_mono_or_stereo <= i_wdata[29];
						ch4_dma_setup_request <= 1'b1;
						o_ready <= 1'b1;
					end
					8'h12: begin
						ch4_volume <= i_wdata[3:0];
						o_ready <= 1'b1;
					end
					8'h14: begin
						ch5_dma_setup_address <= i_wdata;
						o_ready <= 1'b1;
					end
					8'h15: begin
						ch5_dma_setup_count <= i_wdata[23:0];
						ch5_dma_setup_append_or_replace <= i_wdata[28];
						ch5_dma_setup_mono_or_stereo <= i_wdata[29];
						ch5_dma_setup_request <= 1'b1;
						o_ready <= 1'b1;
					end
					8'h16: begin
						ch5_volume <= i_wdata[3:0];
						o_ready <= 1'b1;
					end
					8'h18: begin
						ch6_dma_setup_address <= i_wdata;
						o_ready <= 1'b1;
					end
					8'h19: begin
						ch6_dma_setup_count <= i_wdata[23:0];
						ch6_dma_setup_append_or_replace <= i_wdata[28];
						ch6_dma_setup_mono_or_stereo <= i_wdata[29];
						ch6_dma_setup_request <= 1'b1;
						o_ready <= 1'b1;
					end
					8'h1a: begin
						ch6_volume <= i_wdata[3:0];
						o_ready <= 1'b1;
					end
					8'h1c: begin
						ch7_dma_setup_address <= i_wdata;
						o_ready <= 1'b1;
					end
					8'h1d: begin
						ch7_dma_setup_count <= i_wdata[23:0];
						ch7_dma_setup_append_or_replace <= i_wdata[28];
						ch7_dma_setup_mono_or_stereo <= i_wdata[29];
						ch7_dma_setup_request <= 1'b1;
						o_ready <= 1'b1;
					end
					8'h1e: begin
						ch7_volume <= i_wdata[3:0];
						o_ready <= 1'b1;
					end
					8'h20: begin
						ch8_dma_setup_address <= i_wdata;
						o_ready <= 1'b1;
					end
					8'h21: begin
						ch8_dma_setup_count <= i_wdata[23:0];
						ch8_dma_setup_append_or_replace <= i_wdata[28];
						ch8_dma_setup_mono_or_stereo <= i_wdata[29];
						ch8_dma_setup_request <= 1'b1;
						o_ready <= 1'b1;
					end
					8'h22: begin
						ch8_volume <= i_wdata[3:0];
						o_ready <= 1'b1;
					end
					8'h24: begin
						ch9_dma_setup_address <= i_wdata;
						o_ready <= 1'b1;
					end
					8'h25: begin
						ch9_dma_setup_count <= i_wdata[23:0];
						ch9_dma_setup_append_or_replace <= i_wdata[28];
						ch9_dma_setup_mono_or_stereo <= i_wdata[29];
						ch9_dma_setup_request <= 1'b1;
						o_ready <= 1'b1;
					end
					8'h26: begin
						ch9_volume <= i_wdata[3:0];
						o_ready <= 1'b1;
					end
					8'h28: begin
						ch10_dma_setup_address <= i_wdata;
						o_ready <= 1'b1;
					end
					8'h29: begin
						ch10_dma_setup_count <= i_wdata[23:0];
						ch10_dma_setup_append_or_replace <= i_wdata[28];
						ch10_dma_setup_mono_or_stereo <= i_wdata[29];
						ch10_dma_setup_request <= 1'b1;
						o_ready <= 1'b1;
					end
					8'h2a: begin
						ch10_volume <= i_wdata[3:0];
						o_ready <= 1'b1;
					end
					8'h2c: begin
						ch11_dma_setup_address <= i_wdata;
						o_ready <= 1'b1;
					end
					8'h2d: begin
						ch11_dma_setup_count <= i_wdata[23:0];
						ch11_dma_setup_append_or_replace <= i_wdata[28];
						ch11_dma_setup_mono_or_stereo <= i_wdata[29];
						ch11_dma_setup_request <= 1'b1;
						o_ready <= 1'b1;
					end
					8'h2e: begin
						ch11_volume <= i_wdata[3:0];
						o_ready <= 1'b1;
					end
					8'h30: begin
						ch12_dma_setup_address <= i_wdata;
						o_ready <= 1'b1;
					end
					8'h31: begin
						ch12_dma_setup_count <= i_wdata[23:0];
						ch12_dma_setup_append_or_replace <= i_wdata[28];
						ch12_dma_setup_mono_or_stereo <= i_wdata[29];
						ch12_dma_setup_request <= 1'b1;
						o_ready <= 1'b1;
					end
					8'h32: begin
						ch12_volume <= i_wdata[3:0];
						o_ready <= 1'b1;
					end
					8'h34: begin
						ch13_dma_setup_address <= i_wdata;
						o_ready <= 1'b1;
					end
					8'h35: begin
						ch13_dma_setup_count <= i_wdata[23:0];
						ch13_dma_setup_append_or_replace <= i_wdata[28];
						ch13_dma_setup_mono_or_stereo <= i_wdata[29];
						ch13_dma_setup_request <= 1'b1;
						o_ready <= 1'b1;
					end
					8'h36: begin
						ch13_volume <= i_wdata[3:0];
						o_ready <= 1'b1;
					end
					8'h38: begin
						ch14_dma_setup_address <= i_wdata;
						o_ready <= 1'b1;
					end
					8'h39: begin
						ch14_dma_setup_count <= i_wdata[23:0];
						ch14_dma_setup_append_or_replace <= i_wdata[28];
						ch14_dma_setup_mono_or_stereo <= i_wdata[29];
						ch14_dma_setup_request <= 1'b1;
						o_ready <= 1'b1;
					end
					8'h3a: begin
						ch14_volume <= i_wdata[3:0];
						o_ready <= 1'b1;
					end
					8'h3c: begin
						ch15_dma_setup_address <= i_wdata;
						o_ready <= 1'b1;
					end
					8'h3d: begin
						ch15_dma_setup_count <= i_wdata[23:0];
						ch15_dma_setup_append_or_replace <= i_wdata[28];
						ch15_dma_setup_mono_or_stereo <= i_wdata[29];
						ch15_dma_setup_request <= 1'b1;
						o_ready <= 1'b1;
					end
					8'h3e: begin
						ch15_volume <= i_wdata[3:0];
						o_ready <= 1'b1;
					end

					8'hf0: begin
						o_output_sample_rate <= i_wdata;
						o_ready <= 1'b1;
					end
					default:
						o_ready <= 1'b1;
				endcase
			end
		end
		else if (!i_request) begin
			o_ready <= 1'b0;
		end
	end

	// DMA round robin scheduler
	bit [3:0] sched_channel = 0;

	always_comb begin
		ch0_dma_ready = ch0_dma_request & i_dma_ready;
		ch1_dma_ready = ch1_dma_request & i_dma_ready;
		ch2_dma_ready = ch2_dma_request & i_dma_ready;
		ch3_dma_ready = ch3_dma_request & i_dma_ready;
		ch4_dma_ready = ch4_dma_request & i_dma_ready;
		ch5_dma_ready = ch5_dma_request & i_dma_ready;
		ch6_dma_ready = ch6_dma_request & i_dma_ready;
		ch7_dma_ready = ch7_dma_request & i_dma_ready;
		ch8_dma_ready = ch8_dma_request & i_dma_ready;
		ch9_dma_ready = ch9_dma_request & i_dma_ready;
		ch10_dma_ready = ch10_dma_request & i_dma_ready;
		ch11_dma_ready = ch11_dma_request & i_dma_ready;
		ch12_dma_ready = ch12_dma_request & i_dma_ready;
		ch13_dma_ready = ch13_dma_request & i_dma_ready;
		ch14_dma_ready = ch14_dma_request & i_dma_ready;
		ch15_dma_ready = ch15_dma_request & i_dma_ready;
	end

	always_ff @(posedge i_clock) begin
		o_dma_request <= 1'b0;

		if (sched_channel == 0) begin
			if (ch0_dma_request) begin
				o_dma_request <= 1'b1;
				o_dma_address <= ch0_dma_address;
			end
			else
				sched_channel <= (sched_channel + 1) & 15;
		end
		else if (sched_channel == 1) begin
			if (ch1_dma_request) begin
				o_dma_request <= 1'b1;
				o_dma_address <= ch1_dma_address;
			end
			else
				sched_channel <= (sched_channel + 1) & 15;
		end
		else if (sched_channel == 2) begin
			if (ch2_dma_request) begin
				o_dma_request <= 1'b1;
				o_dma_address <= ch2_dma_address;
			end
			else
				sched_channel <= (sched_channel + 1) & 15;
		end
		else if (sched_channel == 3) begin
			if (ch3_dma_request) begin
				o_dma_request <= 1'b1;
				o_dma_address <= ch3_dma_address;
			end
			else
				sched_channel <= (sched_channel + 1) & 15;
		end
		else if (sched_channel == 4) begin
			if (ch4_dma_request) begin
				o_dma_request <= 1'b1;
				o_dma_address <= ch4_dma_address;
			end
			else
				sched_channel <= (sched_channel + 1) & 15;
		end
		else if (sched_channel == 5) begin
			if (ch5_dma_request) begin
				o_dma_request <= 1'b1;
				o_dma_address <= ch5_dma_address;
			end
			else
				sched_channel <= (sched_channel + 1) & 15;
		end
		else if (sched_channel == 6) begin
			if (ch6_dma_request) begin
				o_dma_request <= 1'b1;
				o_dma_address <= ch6_dma_address;
			end
			else
				sched_channel <= (sched_channel + 1) & 15;
		end
		else if (sched_channel == 7) begin
			if (ch7_dma_request) begin
				o_dma_request <= 1'b1;
				o_dma_address <= ch7_dma_address;
			end
			else
				sched_channel <= (sched_channel + 1) & 15;
		end
		else if (sched_channel == 8) begin
			if (ch8_dma_request) begin
				o_dma_request <= 1'b1;
				o_dma_address <= ch8_dma_address;
			end
			else
				sched_channel <= (sched_channel + 1) & 15;
		end
		else if (sched_channel == 9) begin
			if (ch9_dma_request) begin
				o_dma_request <= 1'b1;
				o_dma_address <= ch9_dma_address;
			end
			else
				sched_channel <= (sched_channel + 1) & 15;
		end
		else if (sched_channel == 10) begin
			if (ch10_dma_request) begin
				o_dma_request <= 1'b1;
				o_dma_address <= ch10_dma_address;
			end
			else
				sched_channel <= (sched_channel + 1) & 15;
		end
		else if (sched_channel == 11) begin
			if (ch11_dma_request) begin
				o_dma_request <= 1'b1;
				o_dma_address <= ch11_dma_address;
			end
			else
				sched_channel <= (sched_channel + 1) & 15;
		end
		else if (sched_channel == 12) begin
			if (ch12_dma_request) begin
				o_dma_request <= 1'b1;
				o_dma_address <= ch12_dma_address;
			end
			else
				sched_channel <= (sched_channel + 1) & 15;
		end
		else if (sched_channel == 13) begin
			if (ch13_dma_request) begin
				o_dma_request <= 1'b1;
				o_dma_address <= ch13_dma_address;
			end
			else
				sched_channel <= (sched_channel + 1) & 15;
		end
		else if (sched_channel == 14) begin
			if (ch14_dma_request) begin
				o_dma_request <= 1'b1;
				o_dma_address <= ch14_dma_address;
			end
			else
				sched_channel <= (sched_channel + 1) & 15;
		end
		else if (sched_channel == 15) begin
			if (ch15_dma_request) begin
				o_dma_request <= 1'b1;
				o_dma_address <= ch15_dma_address;
			end
			else
				sched_channel <= (sched_channel + 1) & 15;
		end
	end

	// Mixer
	always_ff @(posedge i_clock) begin
		o_output_sample_left <= $signed(ch0_sample_left) + $signed(ch1_sample_left) + $signed(ch2_sample_left) + $signed(ch3_sample_left) + $signed(ch4_sample_left) + $signed(ch5_sample_left) + $signed(ch6_sample_left) + $signed(ch7_sample_left) + $signed(ch8_sample_left) + $signed(ch9_sample_left) + $signed(ch10_sample_left) + $signed(ch11_sample_left) + $signed(ch12_sample_left) + $signed(ch13_sample_left) + $signed(ch14_sample_left) + $signed(ch15_sample_left);
		o_output_sample_right <= $signed(ch0_sample_right) + $signed(ch1_sample_right) + $signed(ch2_sample_right) + $signed(ch3_sample_right) + $signed(ch4_sample_right) + $signed(ch5_sample_right) + $signed(ch6_sample_right) + $signed(ch7_sample_right) + $signed(ch8_sample_right) + $signed(ch9_sample_right) + $signed(ch10_sample_right) + $signed(ch11_sample_right) + $signed(ch12_sample_right) + $signed(ch13_sample_right) + $signed(ch14_sample_right) + $signed(ch15_sample_right);
	end

endmodule

