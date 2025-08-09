/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns
`default_nettype none

module Debounce (
	input i_clock,
	input i_data,
	output bit o_stable
);
	initial o_stable = 1'b0;

	bit [15:0] counter = 0;

	always_ff @(posedge i_clock) begin
        o_stable <= 1'b0;
        if (i_data) begin
            if (counter < 10000)
                counter <= counter + 1;
            else
                o_stable <= 1'b1;
        end
        else
            counter <= 0;
	end

endmodule
