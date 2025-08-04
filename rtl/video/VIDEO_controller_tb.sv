/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ps

module VIDEO_controller_tb();

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

	wire video_ram_request;
	wire video_ram_rw;
	wire [31:0] video_ram_address;
	wire [31:0] video_ram_wdata;
	wire [31:0] video_ram_rdata;
	wire video_ram_ready;

	BRAM #(
		.WIDTH(32),
		.SIZE(720 * 720)
	) video_ram (
		.i_clock(clk),
		.i_request(video_ram_request),
		.i_rw(video_ram_rw),
		.i_address(video_ram_address),
		.i_wdata(video_ram_wdata),
		.o_rdata(video_ram_rdata),
		.o_ready(video_ram_ready),
		.o_valid()
	);

	wire vram_pa_request;
	wire vram_pa_rw;
	wire [31:0] vram_pa_address;
	wire [31:0] vram_pa_wdata;
	wire [31:0] vram_pa_rdata;
	wire vram_pa_ready;

	wire vram_pb_request;
	wire vram_pb_rw;
	wire [31:0] vram_pb_address;
	wire [31:0] vram_pb_wdata;
	wire [31:0] vram_pb_rdata;
	wire vram_pb_ready;

	DualPort vram_bus(
		.i_reset(reset),
		.i_clock(clk),

		.o_bus_rw(video_ram_rw),
		.o_bus_request(video_ram_request),
		.i_bus_ready(video_ram_ready),
		.o_bus_address(video_ram_address),
		.i_bus_rdata(video_ram_rdata),
		.o_bus_wdata(video_ram_wdata),

		// Video output access.
		.i_pb_rw(vram_pb_rw),
		.i_pb_request(vram_pb_request),
		.o_pb_ready(vram_pb_ready),
		.i_pb_address(vram_pb_address),
		.o_pb_rdata(vram_pb_rdata),
		.i_pb_wdata(vram_pb_wdata),

		// Video CPU access.
		.i_pc_rw(vram_pa_rw),
		.i_pc_request(vram_pa_request),
		.o_pc_ready(vram_pa_ready),
		.i_pc_address(vram_pa_address),
		.o_pc_rdata(vram_pa_rdata),
		.i_pc_wdata(vram_pa_wdata)
	);

	VIDEO_controller #(
		.MAX_PITCH(720)
	) vc(
		.i_clock(clk),

		.i_cpu_request(1'b0),
		.i_cpu_rw(1'b0),
		.i_cpu_address(0),
		.i_cpu_wdata(0),
		.o_cpu_rdata(),
		.o_cpu_ready(),

		.i_video_hblank(vga_hblank),
		.i_video_vblank(vga_vblank),
		.i_video_pos_x(vga_pos_x),
		.i_video_pos_y(vga_pos_y),
		.o_video_rdata(),

		.o_vram_pa_request(vram_pa_request),
		.o_vram_pa_rw(vram_pa_rw),
		.o_vram_pa_address(vram_pa_address),
		.o_vram_pa_wdata(vram_pa_wdata),
		.i_vram_pa_rdata(vram_pa_rdata),
		.i_vram_pa_ready(vram_pa_ready),

		.o_vram_pb_request(vram_pb_request),
		.o_vram_pb_rw(vram_pb_rw),
		.o_vram_pb_address(vram_pb_address),
		.o_vram_pb_wdata(vram_pb_wdata),
		.i_vram_pb_rdata(vram_pb_rdata),
		.i_vram_pb_ready(vram_pb_ready)
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
		$dumpfile("build/test/VIDEO_controller_tb.vcd");
		$dumpvars(0, VIDEO_controller_tb);

		repeat (1000000) @ (posedge clk);

		$finish;
	end

endmodule