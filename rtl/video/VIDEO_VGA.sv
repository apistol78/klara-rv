/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns

module VIDEO_VGA #(
	parameter USE_CLOCK_OUT,
	parameter HLINE,
	parameter HBACK,
	parameter HFRONT,
	parameter HPULSE,
	parameter VLINE,
	parameter VBACK,
	parameter VFRONT,
	parameter VPULSE,
	parameter VSPOL,			// Polarity (0 = negative, 1 = positive)
	parameter HSPOL
)(
	input i_clock,				//!< VGA timing clock.
	input i_clock_out,			//!< Signal output clock domain.

	output bit o_clock,
	
	output bit o_hsync,			//!< 1 when sync.
	output bit o_vsync,			//!< 1 when sync.

	output bit o_data_enable,

	output bit [10:0] o_pos_x,
	output bit [10:0] o_pos_y
);
	bit [10:0] vga_h = 0;
	bit [10:0] vga_v = 0;

	localparam HTOTAL = HPULSE + HBACK + HLINE + HFRONT;
	localparam VTOTAL = VPULSE + VBACK + VLINE + VFRONT;

	always_ff @(posedge i_clock) begin
		if (vga_h == HTOTAL - 1) begin
			vga_h <= 0;
			if (vga_v == VTOTAL - 1)
				vga_v <= 0;
			else
				vga_v <= vga_v + 1;
		end
		else
			vga_h <= vga_h + 1;
	end

	generate if (!USE_CLOCK_OUT) begin
		assign o_clock = ~i_clock;

		always_comb begin
			o_hsync = (vga_h >= HPULSE) ? HSPOL : (1 - HSPOL);
			o_vsync = (vga_v >= VPULSE) ? VSPOL : (1 - VSPOL);
		end

		always_ff @(posedge i_clock) begin
			o_pos_x <= vga_h - HBACK;
			o_pos_y <= vga_v - VBACK;
		end

		always_comb begin
			o_data_enable =
				(
					(vga_h >= HPULSE + HBACK && vga_h < (HPULSE + HBACK + HLINE)) &&
					(vga_v >= VPULSE + VBACK && vga_v < (VPULSE + VBACK + VLINE))
				);
		end
	end endgenerate

	generate if (USE_CLOCK_OUT) begin

		initial begin
			o_hsync = 0;
			o_vsync = 0;
			o_pos_x = 0;
			o_pos_y = 0;
		end

		bit pl_clock_a = 0;
		bit pl_clock_b = 0;

		always_ff @(posedge i_clock_out) begin
			pl_clock_a <= ~i_clock;
			pl_clock_b <= pl_clock_a;
			o_clock <= pl_clock_b;
		end
		
		bit pl_hsync_a = 0;
		bit pl_hsync_b = 0;
		bit pl_vsync_a = 0;
		bit pl_vsync_b = 0;

		always_ff @(posedge i_clock_out) begin
			pl_hsync_a <= (vga_h >= HPULSE) ? HSPOL : (1 - HSPOL);
			pl_vsync_a <= (vga_v >= VPULSE) ? VSPOL : (1 - VSPOL);
			pl_hsync_b <= pl_hsync_a;
			pl_vsync_b <= pl_vsync_a;
			o_hsync <= pl_hsync_b;
			o_vsync <= pl_vsync_b;
		end

		bit [10:0] pl_pos_x_a = 0;
		bit [10:0] pl_pos_x_b = 0;
		bit [10:0] pl_pos_y_a = 0;
		bit [10:0] pl_pos_y_b = 0;

		always_ff @(posedge i_clock_out) begin
			pl_pos_x_a <= vga_h - HBACK;
			pl_pos_y_a <= vga_v - VBACK;
			pl_pos_x_b <= pl_pos_x_a;
			pl_pos_y_b <= pl_pos_y_a;
			o_pos_x <= pl_pos_x_b;
			o_pos_y <= pl_pos_y_b;
		end

		bit pl_data_enable_a = 0;
		bit pl_data_enable_b = 0;

		always_ff @(posedge i_clock_out) begin
			pl_data_enable_a <=
				(
					(vga_h >= HPULSE + HBACK && vga_h < (HPULSE + HBACK + HLINE)) &&
					(vga_v >= VPULSE + VBACK && vga_v < (VPULSE + VBACK + VLINE))
				);			
			pl_data_enable_b <= pl_data_enable_a;
			o_data_enable <= pl_data_enable_b;
		end

	end endgenerate

endmodule
