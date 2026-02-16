/*
 Klara-RV
 Copyright (c) 2026 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
`timescale 1ns/1ns
`default_nettype none

module CPU_BranchPrediction_tb();

	bit clk;

	bit [31:0] bp_pc = 0;
    bit bp_is_jal = 1'b0;
    bit bp_is_jump_conditional = 1'b0;
    bit [31:0] bp_inst_B_imm = 0;
    bit [31:0] bp_inst_J_imm = 0;
    bit [31:0] bp_pc_launch = 0;
    wire [31:0] bp_pc_hint;
    bit bp_jump = 1'b0;
    bit [31:0] bp_jump_pc = 0;

	CPU_BranchPrediction bp(
		.i_clock(clk),
        .i_pc(bp_pc),
        .i_is_jal(bp_is_jal),
        .i_is_jump_conditional(bp_is_jump_conditional),
        .i_inst_B_imm(bp_inst_B_imm),
        .i_inst_J_imm(bp_inst_J_imm),
        .i_pc_launch(bp_pc_launch),
        .o_pc_hint(bp_pc_hint),
        .i_jump(bp_jump),
        .i_jump_pc(bp_jump_pc)
	);

	initial begin
		clk = 0;
		#1;
		forever clk = #5 ~clk;        
	end

    initial begin
        $dumpfile("build/test/CPU_BranchPrediction_tb.fst");
        $dumpvars(0, CPU_BranchPrediction_tb);

		repeat (10) @ (posedge clk);


        // Launch a jump at given PC
        bp_pc <= 32'hb00b_b00b;
        bp_pc_launch <= 32'hb00b_b00b;

        // Wait N cycles until EX process jump.
        repeat (5) @ (posedge clk);

        // EX report back to BP where jumped.
        bp_jump <= 1'b1;
        bp_jump_pc <= 32'hcafe_babe;
        @(posedge clk);
        bp_pc <= 32'hcafe_babe;
        bp_jump <= 1'b0;
        bp_jump_pc <= 32'h0000_0000;
        @(posedge clk);


	
        // Launch a jump at given PC
        bp_pc <= 32'h1337_1337;
        bp_pc_launch <= 32'h1337_1337;

        // Wait N cycles until EX process jump.
        repeat (5) @ (posedge clk);

        // EX report back to BP where jumped.
        bp_jump <= 1'b1;
        bp_jump_pc <= 32'h1234_5678;
        @(posedge clk);
        bp_pc <= 32'h1234_5678;
        bp_jump <= 1'b0;
        bp_jump_pc <= 32'h0000_0000;
        @(posedge clk);



        // Launch a jump at given PC
        bp_pc <= 32'hb00b_b00b;
        bp_pc_launch <= 32'hb00b_b00b;
        @(posedge clk);
        if (bp_pc_hint != 32'hcafe_babe)
            $error("Incorrect hint %h", bp_pc_hint);


		//===================================
		repeat (100) @ (posedge clk);
		//===================================
		

		$finish;
	end

endmodule