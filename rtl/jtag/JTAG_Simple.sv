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
	output wire [3:0] o_state,

	input wire TDI,
	output bit TDO,
	input wire TCK,
	input wire TMS
);
	typedef enum bit [3:0]
	{
		TEST_LOGIC_RESET,	// 0
		RUN_TEST_IDLE,
		SELECT_DR_SCAN,
		CAPTURE_DR,
		SHIFT_DR,			// 4
		EXIT_1_DR,
		PAUSE_DR,			// 6
		EXIT_2_DR,
		UPDATE_DR,
		SELECT_IR_SCAN,
		CAPTURE_IR,			// 10
		SHIFT_IR,
		EXIT_1_IR,
		PAUSE_IR,
		EXIT_2_IR,
		UPDATE_IR			// 15
	} state_t;
	
	wire [31:0] idcode = { IDCODE_VERSION, IDCODE_PART, IDCODE_MANUFACTURER, 1'b1 };
	state_t state = TEST_LOGIC_RESET;
	bit [3:0] ir = 4'h0;    // IR size 4 bits

	initial begin
		TDO = 1'b0;
	end

	assign o_state = state;

	bit [31:0] dr_active;
	bit [31:0] dr = 0;
	bit bypass = 1'b0;

	always_comb begin
		case (ir)
			4'h1, 4'h2, 4'h5, 4'h6, 4'hb: begin
				dr_active = idcode;
			end
			4'hc, 4'he: begin
				dr_active = i_usercode;
			end
			default: begin
				dr_active = 32'hffff_ffff;
			end
		endcase
	end

	bit [2:0] tck_r = 3'b000;
	wire [2:0] tck_p = { tck_r[1:0], TCK & ~i_reset };
	wire PE = (tck_p[1:0] == 2'b01);
	wire BE = (tck_p == 3'b011);

	bit [31:0] tick_count = 0;

	always_ff @(posedge i_clock) begin
		if (i_reset) begin
			state <= TEST_LOGIC_RESET;
			ir <= 4'h0;
			dr <= 0;
			bypass <= 1'b0;
			tck_r <= 2'b00;
			TDO <= 1'b0;
		end
		else begin
			tck_r <= tck_p;
			if (tck_p[1:0] == 2'b01) begin

				tick_count <= tick_count + 1;

				// Update FSM
				case (state)
					TEST_LOGIC_RESET: begin
						dr <= idcode;
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
						if (TMS == 1'b1)
							state <= EXIT_1_DR;
						else
							dr <= { TDI, dr[31:1] };
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
						if (TMS == 1'b1)
							state <= EXIT_1_IR;
						else
							ir <= { TDI, ir[3:1] };
					end

					EXIT_1_IR: begin
						if (TMS == 1'b0)
							state <= PAUSE_IR;
						else
							state <= UPDATE_IR;
					end

					PAUSE_IR: begin
						if (TMS == 1'b1)
							state <= EXIT_2_IR;
					end

					EXIT_2_IR: begin
						if (TMS == 1'b0)
							state <= SHIFT_IR;
						else
							state <= UPDATE_IR;
					end

					UPDATE_IR: begin
						// Activate DR from IR code.
						// if (ir == 4'b1111)
						// 	bypass <= 1'b1;
						// else begin
						// 	bypass <= 1'b0;
						dr <= dr_active;
						// end

						if (TMS == 1'b1)
							state <= SELECT_DR_SCAN;
						else
							state <= RUN_TEST_IDLE;
					end

				endcase
			end
			
			// Shift out one clock delay instead on negative TCK;
			// this to ensure TDO is stable before negative TCK.
			//if (tck_p == 3'b011) begin
				// if (state == CAPTURE_IR || state == SHIFT_IR)
				// 	TDO <= ir[0];
				// else if (state == CAPTURE_DR || state == SHIFT_DR)
				// 	TDO <= dr[0];
				// else
				// 	TDO <= 1'b0;
			//end
		end
	end

	always_comb begin
		if (state == CAPTURE_IR || state == SHIFT_IR)
			TDO = ir[0];
		else if (state == CAPTURE_DR || state == SHIFT_DR)
			TDO = dr[0];
		else
			TDO = 1'b0;
	end		

endmodule
