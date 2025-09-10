/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns
`default_nettype none

module ClockDividerV (
	input wire i_reset,
	input wire i_clock,
    input wire [31:0] i_rate,
	output bit o_clock
);
	bit [31:0] rate = ~0;
	bit [31:0] counter = 0;

	initial o_clock = 0;

	always_ff @(posedge i_clock) begin
		if (i_reset) begin
			rate <= ~0;
			counter <= 0;
			o_clock <= 0;
		end
		else begin
			rate <= i_rate;
			if (counter >= rate) begin
				counter <= 0;
				o_clock <= ~o_clock;
			end else begin
				counter <= counter + 1'b1;
			end
		end
	end

endmodule
