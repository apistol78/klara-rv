/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns

module ClockDivider #(
    parameter CLOCK_RATE = 50000000,
    parameter BAUD_RATE = 9600
)(
	input i_reset,
	input i_clock,
	output bit o_clock
);

	localparam MAX_RATE = CLOCK_RATE / (2 * BAUD_RATE);
	localparam CNT_WIDTH = $clog2(MAX_RATE);

	bit [CNT_WIDTH:0] counter = 0;

	initial o_clock = 0;

	always_ff @(posedge i_clock) begin
		if (i_reset) begin
			counter <= 0;
			o_clock <= 0;
		end
		else begin
			if (counter >= MAX_RATE) begin
				counter <= 0;
				o_clock <= ~o_clock;
			end else begin
				counter <= counter + 1'b1;
			end
		end
	end

endmodule
