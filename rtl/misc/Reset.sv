/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns

module Reset (
	input i_clock,
	input i_reset,
	output bit o_reset
);
	initial o_reset = 1'b0;

	bit [2:0] counter = 0;

	assign o_reset = !counter[2];

	always_ff @(posedge i_clock) begin
		if (i_reset) begin
			counter <= 0;
		end
		else if (counter != 3'b100) begin
			counter <= counter + 1;
		end
	end

endmodule
