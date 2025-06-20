/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns

module UART_RX #(
    parameter PRESCALE = 50000000 / (9600 * 8),
	parameter FIFO_DEPTH = 256
)(
	input i_reset,
	input i_clock,

	input i_request,
	input [1:0] i_address,
	output bit [31:0] o_rdata,
    output o_ready,

	output bit o_interrupt,
	output bit o_soft_reset,
	
    input UART_RX
);
	localparam MAX_PRESCALE_VALUE = (PRESCALE << 3);

	bit [$clog2(MAX_PRESCALE_VALUE)-1:0] prescale = 0;
	bit [7:0] data = 0;
	bit [3:0] bidx = 0;
	bit [3:0] rds = 0;
	bit rx = 0;
	
	// FIFO
	wire rx_fifo_empty;
	bit rx_fifo_write = 0;
	bit rx_fifo_read = 0;
	wire [7:0] rx_fifo_rdata;
	FIFO #(
		.DEPTH(FIFO_DEPTH),
		.WIDTH(8)
	) rx_fifo(
		.i_reset(i_reset),
		.i_clock(i_clock),
		.o_empty(rx_fifo_empty),
		.o_full(),
		.i_write(rx_fifo_write),
		.i_wdata(data),
		.i_read(rx_fifo_read),
		.o_rdata(rx_fifo_rdata),
		.o_queued()
	);
	
	initial begin
		o_rdata = 32'h0;
		o_interrupt = 1'b0;
		o_soft_reset = 1'b0;
	end
	
	assign o_ready = (rds == 5) && i_request;
	
	// Read from FIFO.
	always_ff @(posedge i_clock) begin
		if (i_reset) begin
			rds <= 0;
			o_rdata <= 32'h0;
		end
		else begin
			rx_fifo_read <= 0;
			if (i_request) begin
				if (i_address == 2'h0) begin	// Read byte from fifo.
					case (rds)
						0: begin
							if (!rx_fifo_empty) begin
								rx_fifo_read <= 1;
								rds <= 1;
							end
						end
						1, 2, 3: begin
							// Need to wait a couple of cycles to ensure valid data out from fifo
							// because empty is signaled before values has been latched into queue.
							o_rdata <= { 24'b0, rx_fifo_rdata };
							rds <= rds + 1;
						end
						4: begin
							rds <= 5;
						end
					endcase
				end
				else if (i_address == 2'h1) begin	// Read status.
					o_rdata <= { 30'b0, rx_fifo_empty, 1'b0 };
					rds <= 5;
				end
			end
			else begin
				rds <= 0;
			end
		end
	end	
	
	// Receive and put into FIFO.
	always_ff @(posedge i_clock) begin
		if (i_reset) begin
			o_interrupt <= 1'b0;
			o_soft_reset <= 1'b0;
			prescale <= 0;
			bidx <= 0;
		end
		else begin
			rx_fifo_write <= 0;
			rx <= UART_RX;

			o_interrupt <= 1'b0;
			o_soft_reset <= 1'b0;
		
			if (prescale > 0) begin
				prescale <= prescale - 1;
			end
			else if (bidx > 0) begin
				if (bidx > 8 + 1) begin
					if (!rx) begin
						// Assume mid point of start bit,
						// continue with data bits.
						bidx <= bidx - 1;
						prescale <= (PRESCALE << 3) - 1;
					end
					else begin
						// Unexpected end of start bit.
						bidx <= 0;
						prescale <= 0;
					end
				end
				else if (bidx > 1) begin
					// Shift in data bits.
					bidx <= bidx - 1;
					prescale <= (PRESCALE << 3) - 1;
					data <= { rx, data[8 - 1:1] };
				end
				else if (bidx == 1) begin
					bidx <= bidx - 1;
					if (rx) begin
						// Stop bit found, save data into fifo.
						rx_fifo_write <= 1;

						// Issue interrupt.
						o_interrupt <= 1'b1;

						// Check for soft reset character.
						o_soft_reset <= (data == 8'hff);
					end
					// Else stop bit expected.
				end
			end
			else begin
				// Wait for start bit.
				if (!rx) begin
					prescale <= (PRESCALE << 2) - 2;
					bidx <= 8 + 2;
					data <= 0;
				end
			end
		end
	end

endmodule
