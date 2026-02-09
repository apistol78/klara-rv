/*
 Klara-RTL
 Copyright (c) 2026 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns
`default_nettype none

module JTAG_Simple #(
	parameter IDCODE_VERSION = 1,
	parameter IDCODE_PART = 16'hbabe,
	parameter IDCODE_MANUFACTURER = 11'h001
)(
	input wire i_reset,
	input wire i_clock,

	input wire [31:0] i_usercode,

	input wire TDI,
	output bit TDO,
	input wire TCK,
	input wire TMS
);
	typedef enum bit [3:0]
	{
		TEST_LOGIC_RESET,
		RUN_TEST_IDLE,
		SELECT_DR_SCAN,
		CAPTURE_DR,
		SHIFT_DR,
		EXIT_1_DR,
		PAUSE_DR,
		EXIT_2_DR,
		UPDATE_DR,
		SELECT_IR_SCAN,
		CAPTURE_IR,
		SHIFT_IR,
		EXIT_1_IR,
		PAUSE_IR,
		EXIT_2_IR,
		UPDATE_IR
	} state_t;
	
	wire [31:0] idcode = { IDCODE_VERSION, IDCODE_PART, IDCODE_MANUFACTURER, 1'b1 };
	state_t state = TEST_LOGIC_RESET;
	bit [3:0] ir = 4'h0;    // IR size 4 bits
	bit [1:0] tck = 2'b00;

	initial begin
		TDO = 1'b0;
	end

	bit [31:0] dr;
	bit [31:0] dr_out = 0;
	bit bypass = 1'b0;

	always_comb begin
		case (ir)
			4'h5, 4'h6: begin
				dr = idcode;
			end
			4'hc, 4'he: begin
				dr = i_usercode;
			end
			default: begin
				dr = 32'hffff_ffff;
			end
		endcase
	end

	always_ff @(posedge i_clock) begin
		if (i_reset) begin
			state <= TEST_LOGIC_RESET;
			ir <= 4'h0;
			tck <= 2'b00;
			TDO <= 1'b0;
		end
		else begin
			tck <= { tck[0], TCK };
			if (tck == 2'b01) begin

				// Update FSM
				case (state)
					TEST_LOGIC_RESET: begin
						dr_out <= idcode;
						if (TMS == 1'b0)
							state <= RUN_TEST_IDLE;
					end

					RUN_TEST_IDLE: begin
						if (TMS == 1'b1)
							state <= SELECT_DR_SCAN;
					end

					SELECT_DR_SCAN: begin
						if (TMS == 1'b1)
							state <= SELECT_IR_SCAN;
						else
							state <= CAPTURE_DR;
					end

					// DR

					CAPTURE_DR: begin
						if (TMS == 1'b1)
							state <= EXIT_1_DR;
						else
							state <= SHIFT_DR;
					end

					SHIFT_DR: begin
						if (TMS == 1'b0) begin
							dr_out <= { 1'b0, dr_out[31:1] };
						end
						else
							state <= EXIT_1_DR;
					end

					EXIT_1_DR: begin
						if (TMS == 1'b0)
							state <= PAUSE_DR;
						else
							state <= UPDATE_DR;
					end

					PAUSE_DR: begin
						if (TMS == 1'b1)
							state <= EXIT_2_DR;
					end

					EXIT_2_DR: begin
						if (TMS == 1'b0)
							state <= SHIFT_DR;
						else
							state <= UPDATE_DR;
					end

					UPDATE_DR: begin
						if (TMS == 1'b1)
							state <= SELECT_DR_SCAN;
						else
							state <= RUN_TEST_IDLE;
					end

					// IR

					SELECT_IR_SCAN: begin
						if (TMS == 1'b1)
							state <= TEST_LOGIC_RESET;
						else
							state <= CAPTURE_IR;
					end

					CAPTURE_IR: begin
						if (TMS == 1'b1)
							state <= EXIT_1_IR;
						else
							state <= SHIFT_IR;
					end

					SHIFT_IR: begin
						if (TMS == 1'b0) begin
							ir <= { ir[2:0], TDI };
						end
						else
							state <= EXIT_1_IR;
					end

					EXIT_1_IR: begin
						if (TMS == 1'b0)
							state <= PAUSE_IR;
						else
							state <= UPDATE_IR;
					end

					PAUSE_IR: begin
						if (TMS == 1'b1)
							state <= EXIT_2_DR;
					end

					EXIT_2_IR: begin
						if (TMS == 1'b0)
							state <= SHIFT_IR;
						else
							state <= UPDATE_IR;
					end

					UPDATE_IR: begin
						// Activate DR from IR code.
						if (ir == 4'b1111)
							bypass <= 1'b1;
						else begin
							bypass <= 1'b0;
							dr_out <= dr;
						end

						if (TMS == 1'b1)
							state <= SELECT_DR_SCAN;
						else
							state <= RUN_TEST_IDLE;
					end

				endcase
			end
			else if (tck == 2'b10) begin
				if (!bypass)
					TDO <= dr_out[0];
				else
					TDO <= TDI;
			end
		end
	end

endmodule
