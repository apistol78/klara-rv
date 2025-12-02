/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns
`default_nettype none

module VIDEO_sprite #(
	parameter WIDTH,
	parameter HEIGHT
) (
	input wire i_clock,

	input wire i_request,
	input wire [31:0] i_address,
	input wire [31:0] i_wdata,
	output bit o_ready,

	input wire i_video_hblank,
	input wire i_video_vblank,
	input wire [10:0] i_overlay_x,
	input wire [10:0] i_overlay_y,
	output bit [7:0] o_overlay_data,
	output bit o_overlay_mask
);

	bit sprite_0_visible = 1'b0;
	// bit sprite_1_visible = 1'b0;

	bit [10:0] sprite_0_pos_x = 11'h0;
	bit [10:0] sprite_0_pos_y = 11'h0;
	wire [7:0] sprite_0_overlay_data;
	wire sprite_0_overlay_mask;
	bit sprite_0_wd_request = 1'b0;
	bit [12:0] sprite_0_wd_address;
	bit [7:0] sprite_0_wd_wdata;

	VIDEO_sprite_x #(
		.WIDTH(WIDTH),
		.HEIGHT(HEIGHT)
	) sprite_0 (
		.i_clock(i_clock),
		.i_pos_x(sprite_0_pos_x),
		.i_pos_y(sprite_0_pos_y),
		.i_video_hblank(i_video_hblank),
		.i_video_vblank(i_video_vblank),
		.i_overlay_x(i_overlay_x),
		.i_overlay_y(i_overlay_y),
		.o_overlay_data(sprite_0_overlay_data),
		.o_overlay_mask(sprite_0_overlay_mask),
		.i_wd_request(sprite_0_wd_request),
		.i_wd_address(sprite_0_wd_address),
		.i_wd_wdata(sprite_0_wd_wdata)
	);

	// bit [10:0] sprite_1_pos_x = 11'h0;
	// bit [10:0] sprite_1_pos_y = 11'h0;
	// wire [7:0] sprite_1_overlay_data;
	// wire sprite_1_overlay_mask;
	// bit sprite_1_wd_request = 1'b0;
	// bit [12:0] sprite_1_wd_address;
	// bit [7:0] sprite_1_wd_wdata;

	// VIDEO_sprite_x #(
	// 	.WIDTH(WIDTH),
	// 	.HEIGHT(HEIGHT)
	// ) sprite_1 (
	// 	.i_clock(i_clock),
	// 	.i_pos_x(sprite_1_pos_x),
	// 	.i_pos_y(sprite_1_pos_y),
	// 	.i_video_hblank(i_video_hblank),
	// 	.i_video_vblank(i_video_vblank),
	// 	.i_overlay_x(i_overlay_x),
	// 	.i_overlay_y(i_overlay_y),
	// 	.o_overlay_data(sprite_1_overlay_data),
	// 	.o_overlay_mask(sprite_1_overlay_mask),
	// 	.i_wd_request(sprite_1_wd_request),
	// 	.i_wd_address(sprite_1_wd_address),
	// 	.i_wd_wdata(sprite_1_wd_wdata)
	// );

	bit sprite_0_mask;
	// bit sprite_1_mask;
	always_comb begin
		sprite_0_mask = (sprite_0_overlay_data != 8'hff);
		// sprite_1_mask = (sprite_1_overlay_data != 8'hff);
	end

	always_comb begin
		o_overlay_data = 8'h00;
		o_overlay_mask = 1'b0;

		if (sprite_0_overlay_mask) begin
			o_overlay_data = sprite_0_overlay_data;
			o_overlay_mask = sprite_0_mask & sprite_0_visible;
		end
		// else if (sprite_1_overlay_mask) begin
		// 	o_overlay_data = sprite_1_overlay_data;
		// 	o_overlay_mask = sprite_1_mask & sprite_1_visible;
		// end
	end

	always_ff @(posedge i_clock) begin

		o_ready <= 1'b0;

		sprite_0_wd_request <= 1'b0;
		// sprite_1_wd_request <= 1'b0;

		if (i_request) begin

			// pp ppxx xxxx xxxx xx00

			if (i_address[17:14] == 4'h0) begin	// Registers
				case (i_address[4:0])
					5'h00: sprite_0_pos_x <= i_wdata[10:0];
					5'h04: sprite_0_pos_y <= i_wdata[10:0];
					5'h08: sprite_0_visible <= |i_wdata;
					// 5'h0c:

					// 5'h10: sprite_1_pos_x <= i_wdata[10:0];
					// 5'h14: sprite_1_pos_y <= i_wdata[10:0];
					// 5'h18: sprite_1_visible <= |i_wdata;
					// 5'h1c:
				endcase
			end
			else if (i_address[17:14] == 4'h1) begin	// Sprite 0 data
				sprite_0_wd_request <= 1'b1;
				sprite_0_wd_address <= i_address[13:2];
				sprite_0_wd_wdata <= i_wdata[7:0];
			end
			// else if (i_address[17:14] == 4'h2) begin	// Sprite 1 data
			// 	sprite_1_wd_request <= 1'b1;
			// 	sprite_1_wd_address <= i_address[13:2];
			// 	sprite_1_wd_wdata <= i_wdata[7:0];
			// end

			o_ready <= 1'b1;
		end
	end

endmodule;
