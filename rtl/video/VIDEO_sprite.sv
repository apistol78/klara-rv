/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns
`default_nettype none

module VIDEO_sprite(
	input wire i_clock,
	
	input wire i_video_hblank,
	input wire i_video_vblank,
	input wire [10:0] i_overlay_x,
	input wire [10:0] i_overlay_y,
	output bit [31:0] o_overlay_data,
	output bit o_overlay_mask
);
	typedef enum bit [4:0]
	{
		IDLE,
		WAIT_X,
		OUT_LINE
	}
	state_t;

	initial begin
		o_overlay_data = 8'h00;
		o_overlay_mask = 1'b0;
	end

	bit r_video_hblank = 1'b0;
	always_ff @(posedge i_clock) begin
		r_video_hblank <= i_video_hblank;
	end

	bit line_start;
	always_comb begin
		line_start =
			!i_video_vblank &&
			({ r_video_hblank, i_video_hblank } == 2'b10);
	end

	state_t state = IDLE;
	state_t next_state;

	bit signed [10:0] pos_x = 1;
	bit signed [10:0] pos_y = 0;
	bit [7:0] width = 16;
	bit [7:0] height = 16;

	always_ff @(posedge i_clock) begin
		state <= next_state;
	end

	always_comb begin

		next_state = state;

		o_overlay_data = 32'h0;
		o_overlay_mask = 1'b0;

		if (line_start) begin
			if (
				$signed(i_overlay_y) >= pos_y &&
				$signed(i_overlay_y) < pos_y + height
			) begin
				next_state = WAIT_X;
			end
		end
		else begin
			case (state)
			WAIT_X: begin
				if ($signed(i_overlay_x) >= pos_x - 1) begin
					next_state = OUT_LINE;
				end
			end
			
			OUT_LINE: begin
				if ($signed(i_overlay_x) < pos_x + width) begin
					o_overlay_data = 32'hff00ff00;
					o_overlay_mask = 1'b1;
				end
				else begin
					next_state = IDLE;
				end
			end

			default:
				next_state = IDLE;
			endcase
		end
	end

endmodule;
