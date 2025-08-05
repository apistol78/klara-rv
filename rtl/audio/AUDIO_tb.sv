/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns

module AUDIO_tb();

	bit clk;

    bit ac_request = 1'b0;
    bit ac_rw = 1'b0;
    bit [3:0] ac_address;
    bit [31:0] ac_wdata;
    wire [31:0] ac_rdata;
    wire ac_ready;
    wire ac_interrupt;

    wire ac_output_busy;
    wire [15:0] ac_output_sample_left;
    wire [15:0] ac_output_sample_right;
    wire [31:0] ac_output_reload;

    AUDIO_i2s_output #(
        .FREQUENCY(100_000_000)
    ) ao(
        .i_clock(clk),
        .o_busy(ac_output_busy),
        .i_sample_left(ac_output_sample_left),
        .i_sample_right(ac_output_sample_right)
    );

    AUDIO_controller #(
        .BUFFER_SIZE(64)
    ) ac(
        .i_reset(1'b0),
        .i_clock(clk),

        .i_request(ac_request),
        .i_rw(ac_rw),
        .i_address(ac_address),
        .i_wdata(ac_wdata),
        .o_rdata(ac_rdata),
        .o_ready(ac_ready),
        .o_interrupt(ac_interrupt),

        .i_output_busy(ac_output_busy),
        .o_output_sample_left(ac_output_sample_left),
        .o_output_sample_right(ac_output_sample_right),
        .o_output_reload(ac_output_reload)
    );

	initial begin
		clk = 0;
		#1;
		forever clk = #5 ~clk;        
	end

    initial begin
        $dumpfile("build/test/AUDIO_tb.vcd");
        $dumpvars(0, AUDIO_tb);

		repeat (100) @ (posedge clk);

        ac_wdata <= { 16'h01, 16'h81 };
        repeat (100) begin
            @(posedge clk);
            ac_request <= 1'b1;
            ac_rw <= 1'b1;
            ac_address <= 0;
            while (!ac_ready) @(posedge clk);
            ac_request <= 1'b0;
            ac_wdata <= ac_wdata + { 16'h01, 16'h01 };
            @(posedge clk);
        end

		repeat (100000) @ (posedge clk);

		$finish;
	end

endmodule