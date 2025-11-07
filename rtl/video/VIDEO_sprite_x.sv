/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns
`default_nettype none

module VIDEO_sprite_x #(
	parameter WIDTH,
	parameter HEIGHT
) (
	input wire i_clock,

	input wire [10:0] i_pos_x,
	input wire [10:0] i_pos_y,
	
	input wire i_video_hblank,
	input wire i_video_vblank,
	input wire [10:0] i_overlay_x,
	input wire [10:0] i_overlay_y,
	output bit [7:0] o_overlay_data,
	output bit o_overlay_mask,

	input wire i_wd_request,
	input wire [12:0] i_wd_address,
	input wire [7:0] i_wd_wdata
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

	// Signal when overlay X becomes zero.
	bit [1:0] r_overlay_zero = 2'b00;
	always_ff @(posedge i_clock) begin
		r_overlay_zero <= { r_overlay_zero[0], i_overlay_x == 0 };
	end

	// Signal when line starts.
	bit line_start;
	always_comb begin
		line_start =
			!i_video_vblank &&
			(r_overlay_zero == 2'b01);
	end

	// Cast position to be signed.
	bit signed [10:0] pos_x;
	bit signed [10:0] pos_y;

	always_comb begin
		pos_x = $signed(i_pos_x);
		pos_y = $signed(i_pos_y);
	end

	// Sprite pixel data.
	bit data_request;
	bit [12:0] data_address;
	bit [7:0] data_rdata;

	BRAM_1r1w #(
		.WIDTH(8),
		.SIZE(WIDTH * HEIGHT),
		.ADDR_LSH(0)
	) data (
		.i_clock(i_clock),
		.i_pa_request(data_request),
		.i_pa_address({ 19'b0, data_address }),
		.o_pa_rdata(data_rdata),
		.o_pa_ready(),
		.i_pb_request(i_wd_request),
		.i_pb_address({ 19'b0, i_wd_address }),
		.i_pb_wdata(i_wd_wdata),
		.o_pb_ready()
	);

	// Calculate sprite pixel address.
	always_comb begin
		data_address = ($signed(i_overlay_x) - pos_x) + ($signed(i_overlay_y) - pos_y) * WIDTH;
	end

	// State machine.
	state_t state = IDLE;
	state_t next_state;

	always_ff @(posedge i_clock) begin
		state <= next_state;
	end

	always_comb begin

		next_state = state;
		data_request = (next_state == OUT_LINE);

		o_overlay_data = data_rdata;
		o_overlay_mask = 1'b0;

		if (line_start) begin
			if (
				$signed(i_overlay_y) >= pos_y &&
				$signed(i_overlay_y) < pos_y + HEIGHT
			) begin
				next_state = WAIT_X;
			end
			else begin
				next_state = IDLE;
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
				if ($signed(i_overlay_x) < pos_x + WIDTH) begin
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
