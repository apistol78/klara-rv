/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns
`default_nettype none

module VIDEO_controller #(
	parameter MAX_PITCH = 640,
	parameter WRITEBACK_SIZE = 0
)(
	input wire i_clock,

	// CPU
	input wire i_cpu_request,
	input wire i_cpu_rw,
	input wire [31:0] i_cpu_address,
	output bit [31:0] o_cpu_rdata,
	input wire [31:0] i_cpu_wdata,
	input wire [3:0] i_cpu_wmask,
	output bit o_cpu_ready,

	// Video
	input wire i_video_hblank,
	input wire i_video_vblank,
	input wire [10:0] i_video_pos_x,
	input wire [10:0] i_video_pos_y,
	output bit [31:0] o_video_rdata,

	// Memory read/write port for CPU.
	output wire o_vram_pa_request,
	output wire o_vram_pa_rw,
	output wire [31:0] o_vram_pa_address,
	output wire [31:0] o_vram_pa_wdata,
	output wire [3:0] o_vram_pa_wmask,
	input wire [31:0] i_vram_pa_rdata,
	input wire i_vram_pa_ready,

	// Memory read port for video.
	output bit o_vram_pb_request,
	output bit [31:0] o_vram_pb_address,
	input wire [31:0] i_vram_pb_rdata,
	input wire i_vram_pb_ready,

	// Overlay
	output bit [10:0] o_overlay_x,
	output bit [10:0] o_overlay_y,
	input wire [7:0] i_overlay_data,
	input wire i_overlay_mask
);

	bit [31:0] vram_read_offset = 0;
	bit [31:0] vram_pitch = MAX_PITCH;
	bit [1:0] vram_skip = 0;
	bit [10:0] vram_skip_x = 0;
	bit [10:0] vram_skip_y = 0;
	bit vram_use_palette = 1'b1;
	bit [31:0] frame_counter = 0;

	//===============================

	initial begin
		o_cpu_ready = 1'b0;
		o_video_rdata = 1'b0;

		o_vram_pb_request = 1'b0;
		o_vram_pb_address = 0;
	end

	//===============================
	// Palette

	bit palette_cpu_request = 0;
	bit [7:0] palette_cpu_address = 0;
	bit [23:0] palette_cpu_wdata = 0;
	bit [7:0] palette_video_address = 0;
	wire [23:0] palette_video_rdata;

	BRAM_1r1w #(
		.WIDTH(24),
		.SIZE(256),
		.ADDR_LSH(0)
	) palette(
		.i_clock(i_clock),

		// Video read port.
		.i_pa_request(1'b1),
		.i_pa_address({ 24'h0, palette_video_address }),
		.o_pa_rdata(palette_video_rdata),
		.o_pa_ready(),

		// CPU write port.
		.i_pb_request(palette_cpu_request),
		.i_pb_address({ 24'h0, palette_cpu_address }),
		.i_pb_wdata(palette_cpu_wdata),
		.o_pb_ready()
	);	

	//===============================
	// VRAM write buffer

	bit wb_rw;
	bit wb_request;
	wire wb_ready;
	bit [24:0] wb_address;
	wire [31:0] wb_rdata;
	bit [31:0] wb_wdata;
	bit [3:0] wb_wmask;

	generate if (WRITEBACK_SIZE > 0) begin : video_wb_enabled

		wire [24:0] vram_pa_address;
		assign o_vram_pa_address = { 8'h0, vram_pa_address };

		WriteBuffer #(
			.DEPTH(32),
			.ADDRESS_WIDTH(24),
			.STALL_READ(0)
		) wb(
			.i_reset(1'b0),
			.i_clock(i_clock),

			.o_empty(),
			.o_full(),

			.o_bus_rw(o_vram_pa_rw),
			.o_bus_request(o_vram_pa_request),
			.i_bus_ready(i_vram_pa_ready),
			.o_bus_address(vram_pa_address),
			.i_bus_rdata(i_vram_pa_rdata),
			.o_bus_wdata(o_vram_pa_wdata),
			.o_bus_wmask(o_vram_pa_wmask),

			.i_rw(wb_rw),
			.i_request(wb_request),
			.o_ready(wb_ready),
			.i_address(wb_address),
			.o_rdata(wb_rdata),
			.i_wdata(wb_wdata),
			.i_wmask(wb_wmask)
		);

		initial begin
			wb_rw = 1'b0;
			wb_request = 1'b0;
			wb_address = 24'h0;
			wb_wdata = 32'h0;
			wb_wmask = 4'h0;
		end

	end endgenerate

	generate if (WRITEBACK_SIZE == 0) begin : video_wb_disabled

		assign o_vram_pa_rw = wb_rw;
		assign o_vram_pa_request = wb_request;
		assign wb_ready = i_vram_pa_ready;
		assign o_vram_pa_address = { 8'h0, wb_address };
		assign wb_rdata = i_vram_pa_rdata;
		assign o_vram_pa_wdata = wb_wdata;
		assign o_vram_pa_wmask = wb_wmask;

	end endgenerate

	//===============================
	// CPU

	typedef enum bit [3:0]
	{
		IDLE,
		END_PALETTE_WRITE,
		END_VRAM_WRITE,
		ACCESS_CONTROL,
		WAIT_REQUEST_END
	}
	state_t;

	state_t state = IDLE;

	always_ff @(posedge i_clock) begin

		o_cpu_ready <= 1'b0;

		unique case (state)
		IDLE: begin
			if (i_cpu_request) begin
				if (i_cpu_address[23:20] == 4'he) begin
					palette_cpu_request <= 1'b1;
					palette_cpu_address <= i_cpu_address[9:2];
					palette_cpu_wdata <= i_cpu_wdata;
					state <= END_PALETTE_WRITE;	// access palette
				end
				else if (i_cpu_address[23:20] == 4'hf) begin
					state <= ACCESS_CONTROL;
				end
				else begin
					wb_address <= i_cpu_address[23:0];
					wb_rw <= i_cpu_rw;
					wb_wdata <= i_cpu_wdata;
					wb_wmask <= i_cpu_wmask;
					wb_request <= 1'b1;
					state <= END_VRAM_WRITE;
				end
			end
		end

		// access palette.
		END_PALETTE_WRITE: begin
			palette_cpu_request <= 1'b0;
			o_cpu_ready <= 1'b1;
			state <= WAIT_REQUEST_END;
		end

		// wait on vram.
		END_VRAM_WRITE: begin
			if (wb_ready) begin
				o_cpu_ready <= 1'b1;
				o_cpu_rdata <= wb_rdata;
				wb_request <= 1'b0;
				state <= WAIT_REQUEST_END;
			end
		end

		// access control registers.
		ACCESS_CONTROL: begin
			if (i_cpu_rw) begin
				if (i_cpu_address[4:2] == 3'd0) begin
					vram_read_offset <= i_cpu_wdata;
				end
				else if (i_cpu_address[4:2] == 3'd1) begin
					vram_pitch <= i_cpu_wdata;
				end
				else if (i_cpu_address[4:2] == 3'd2) begin
					vram_skip <= i_cpu_wdata[1:0];
				end
				else if (i_cpu_address[4:2] == 3'd3) begin
					vram_skip_x <= i_cpu_wdata;
				end
				else if (i_cpu_address[4:2] == 3'd4) begin
					vram_skip_y <= i_cpu_wdata;
				end
				else if (i_cpu_address[4:2] == 3'd5) begin
					vram_use_palette <= |i_cpu_wdata;
				end
			end
			else begin
				if (i_cpu_address[4:2] == 3'd6) begin
					o_cpu_rdata <= frame_counter;
				end
			end
			o_cpu_ready <= 1'b1;
			state <= WAIT_REQUEST_END;
		end

		// wait until request finishes.
		WAIT_REQUEST_END: begin
			o_cpu_ready <= i_cpu_request;
			if (!i_cpu_request) begin
				state <= IDLE;
			end
		end

		endcase
	end

	//===============================
	// Video

	bit [31:0] line_r_address;
	wire [31:0] line_r_rdata;

	bit line_w_request = 0;
	bit [31:0] line_w_address;
	bit [31:0] line_w_wdata;

	BRAM_1r1w #(
		.WIDTH(32),
		.SIZE(MAX_PITCH / 4),
		.ADDR_LSH(0)
	) line(
		.i_clock(i_clock),
		.i_pa_request(1'b1),
		.i_pa_address(line_r_address),
		.o_pa_rdata(line_r_rdata),
		.o_pa_ready(),
		.i_pb_request(line_w_request),
		.i_pb_address(line_w_address),
		.i_pb_wdata(line_w_wdata),
		.o_pb_ready()
	);

	bit [10:0] column;
	bit [31:0] row_num;
	bit [31:0] row_offset;
	bit [1:0] hs = 2'b00;
	bit [1:0] vs = 2'b00;

	always_ff @(posedge i_clock) begin

		hs <= { hs[0], i_video_hblank };
		vs <= { vs[0], i_video_vblank };

		// Check if we have entered vblank. 
		if ({ vs[0], i_video_vblank } == 2'b01) begin
			column <= 0;
			row_num <= 0;
			row_offset <= 0;
			frame_counter <= frame_counter + 1;
		end

		// At hblank we start read next line.
		if (hs == 2'b01 && /*vs == 2'b00*/ i_video_vblank == 1'b0) begin
			if (
				(row_num >= vram_skip_y && row_num < 720 - vram_skip_y) &&
				(vram_skip[1] == 1'b0 || ~row_num[0])
			) begin
				column <= 0;
				row_offset <= row_offset + vram_pitch;
				o_vram_pb_address <= vram_read_offset + row_offset;
				o_vram_pb_request <= 1'b1;
			end
			row_num <= row_num + 1;
		end

		// Fill line buffer.
		line_w_request <= 1'b0;
		if (o_vram_pb_request) begin
			if (i_vram_pb_ready) begin
				
				line_w_request <= 1'b1;
				line_w_address <= column;
				line_w_wdata <= i_vram_pb_rdata;

				column <= column + 1;

				if (column < vram_pitch / 4) begin
					o_vram_pb_address <= o_vram_pb_address + 4;
					o_vram_pb_request <= 1'b1;
				end
				else begin
					o_vram_pb_request <= 1'b0;
				end
			end
		end
	end

	// Stream out to video "DAC".

	bit valid;
	bit [9:0] pixel_word_offset;	// 0 - 1023
	bit [1:0] pixel_word_switch;

	always_comb begin
		valid =
			(i_video_pos_x >= vram_skip_x) &&
			(i_video_pos_x < 720 - vram_skip_x) &&
			(i_video_pos_y >= vram_skip_y) &&
			(i_video_pos_y < 720 - vram_skip_y);
	end

	always_comb begin
		if (!vram_use_palette) begin
			if (vram_skip[0] == 1'b0) begin
				pixel_word_offset = i_video_pos_x[9:0] - vram_skip_x[9:0];
				pixel_word_switch = 4;
			end
			else begin
				pixel_word_offset = { 1'b0, i_video_pos_x[9:1] - vram_skip_x[9:1] };
				pixel_word_switch = 4;
			end
		end
		else begin
			if (vram_skip[0] == 1'b0) begin
				pixel_word_offset = { 1'b0, i_video_pos_x[10:2] - vram_skip_x[10:2] };
				pixel_word_switch = i_video_pos_x[1:0];
			end
			else begin
				pixel_word_offset = { 2'b00, i_video_pos_x[10:3] - vram_skip_x[10:3] };
				pixel_word_switch = i_video_pos_x[2:1];
			end
		end
	end

	always_comb begin
		line_r_address = pixel_word_offset;
	end

	always_comb begin
		if (!i_overlay_mask) begin
			unique case (pixel_word_switch)
				0: palette_video_address = line_r_rdata[7:0];
				1: palette_video_address = line_r_rdata[15:8];
				2: palette_video_address = line_r_rdata[23:16];
				3: palette_video_address = line_r_rdata[31:24];
				4: palette_video_address = 0;
			endcase
		end
		else begin
			palette_video_address = i_overlay_data;
		end
	end

	always_comb begin
		// Calculate overlay X position.
		if (vram_skip[0] == 1'b0) begin
			o_overlay_x = (i_video_pos_x - vram_skip_x);
		end
		else begin
			o_overlay_x = (i_video_pos_x - vram_skip_x) >> 1;
		end

		// Calculate overlay Y position.
		if (vram_skip[1] == 1'b0) begin
			o_overlay_y = (i_video_pos_y - vram_skip_y);
		end
		else begin
			o_overlay_y = (i_video_pos_y - vram_skip_y) >> 1;
		end
	end

	always_ff @(posedge i_clock) begin
		if (!vram_use_palette) begin
			o_video_rdata <=
				valid ?
				line_r_rdata :
				32'h0;
		end
		else begin
			o_video_rdata <=
				valid ?
				{ 8'h00, palette_video_rdata } :
				32'h0;
		end
	end

endmodule
