/*
 Klara-RV
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns

module CPU_BusMux #(
	parameter REGISTERED
)(
	input i_reset,
	input i_clock,

	// Bus
	output bit o_bus_rw,				// Data read/write
	output bit o_bus_request,			// IO request.
	input i_bus_ready,					// IO request ready.
	output bit [31:0] o_bus_address,	// Address
	input [31:0] i_bus_rdata,			// Read data
	output bit [31:0] o_bus_wdata,		// Write data,

	// Port A (Read only)
	input i_pa_request,
	output o_pa_ready,
	input [31:0] i_pa_address,
	output [31:0] o_pa_rdata,

	// Port B
	input i_pb_rw,
	input i_pb_request,
	output o_pb_ready,
	input [31:0] i_pb_address,
	output [31:0] o_pb_rdata,
	input [31:0] i_pb_wdata
);

	bit [1:0] state = 0;
	bit [1:0] next_state;

	generate if (!REGISTERED) begin

		assign o_pa_ready = i_pa_request && (state == 2'd1) ? i_bus_ready : 1'b0;
		assign o_pb_ready = i_pb_request && (state == 2'd2) ? i_bus_ready : 1'b0;

		assign o_pa_rdata = i_bus_rdata;
		assign o_pb_rdata = i_bus_rdata;

		always_ff @(posedge i_clock) begin
			state <= next_state;
		end

		always_comb begin

			next_state = state;

			o_bus_request = 0;
			o_bus_rw = 0;
			o_bus_address = 0;
			o_bus_wdata = 0;
			
			case (state)

				// Wait for any request.
				2'd0: begin
					if (i_pb_request) begin
						o_bus_rw = i_pb_rw;
						o_bus_address = i_pb_address;
						o_bus_wdata = i_pb_wdata;
						next_state = 2'd2;
					end
					else if (i_pa_request) begin
						o_bus_rw = 1'b0;
						o_bus_address = i_pa_address;
						next_state = 2'd1;		
					end
				end

				// Wait until request has been processed.
				2'd1: begin
					o_bus_request = i_pa_request;
					o_bus_address = i_pa_address;
					if (i_bus_ready) begin
						next_state = 2'd0;
					end
				end
				2'd2: begin
					o_bus_request = i_pb_request;
					o_bus_rw = i_pb_rw;
					o_bus_address = i_pb_address;
					o_bus_wdata = i_pb_wdata;
					if (i_bus_ready) begin
						next_state = 2'd0;
					end
				end

				default:
					next_state = 2'd0;

			endcase
		end
	end endgenerate

	generate if (REGISTERED) begin

		initial begin
			o_bus_rw = 1'b0;
			o_bus_request = 1'b0;
			o_bus_address = 0;
			o_bus_wdata = 0;
		end

		assign o_pa_ready = i_pa_request && (state == 2'd1) ? i_bus_ready : 1'b0;
		assign o_pb_ready = i_pb_request && (state == 2'd2) ? i_bus_ready : 1'b0;

		assign o_pa_rdata = i_bus_rdata;
		assign o_pb_rdata = i_bus_rdata;

		always_ff @(posedge i_clock) begin
			if (i_reset) begin
				state <= 2'd0;

				o_bus_rw <= 1'b0;
				o_bus_request <= 1'b0;
				o_bus_address <= 0;
				o_bus_wdata <= 0;
			end
			else begin

				case (state)

					// Wait for any request.
					2'd0: begin
						o_bus_request <= 1'b0;

						if (i_pb_request) begin
							o_bus_rw <= i_pb_rw;
							o_bus_request <= 1'b1;
							o_bus_address <= i_pb_address;
							o_bus_wdata <= i_pb_wdata;
							state <= 2'd2;
						end
						else if (i_pa_request) begin
							o_bus_rw <= 1'b0;
							o_bus_request <= 1'b1;
							o_bus_address <= i_pa_address;
							state <= 2'd1;		
						end
					end

					// Wait until request has been processed.
					2'd1, 2'd2: begin
						if (i_bus_ready) begin
							o_bus_request <= 1'b0;
							state <= 2'd0;
						end
					end

					default:
						state <= 2'd0;

				endcase
			end
		end

	end endgenerate

endmodule
