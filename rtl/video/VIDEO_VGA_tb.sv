/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ps

module VIDEO_VGA_tb();

	bit clk;

	wire vga_clock;
	wire vga_hsync;
	wire vga_vsync;
	wire vga_hblank;
	wire vga_vblank;
	wire vga_data_enable;
	wire [10:0] vga_pos_x;
	wire [10:0] vga_pos_y;

	VIDEO_VGA #(
		// 720 0 20 20 40 720 0 15 15 15 0 0 0 60 0 36720000 4
		.USE_CLOCK_OUT(0),
		.HLINE(720),	// horizontal pixels
		.HBACK(40),		// back porch
		.HFRONT(20),	// front porch
		.HPULSE(20),	// sync pulse
		.VLINE(720),	// vertical lines
		.VBACK(15),		// back porch
		.VFRONT(15),	// front porch
		.VPULSE(15),	// sync pulse
		.VSPOL(0),
		.HSPOL(0)
	) vga(
		.i_clock(clk),
		.i_clock_out(clk),
		.o_clock(vga_clock),
		.o_hsync(vga_hsync),
		.o_vsync(vga_vsync),
		.o_hblank(vga_hblank),
		.o_vblank(vga_vblank),
		.o_data_enable(vga_data_enable),
		.o_pos_x(vga_pos_x),
		.o_pos_y(vga_pos_y)
	);

/*
	initial begin
		clk = 0;
		#1;
		forever clk = #5 ~clk;        
	end
*/
	always #13.615 clk = ~clk;

	initial begin
		$dumpfile("VIDEO_VGA_tb.vcd");
		$dumpvars(0, VIDEO_VGA_tb);

		repeat (1000000) @ (posedge clk);

		$finish;
	end

endmodule