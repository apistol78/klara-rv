/*
 Klara-RV
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns

module SoC_BROM(
	input i_clock,
	input i_request,
	input [31:0] i_address,
	output logic [31:0] o_rdata,
	output bit o_ready
);

	logic [31:0] data [
	`include "firmware.vmem-range"		
	];

	initial o_ready = 0;
	initial $readmemh("firmware.vmem", data);

	always_ff @(posedge i_clock)
		if (i_request) begin
			o_rdata <= data[i_address >> 2];
		end
		else begin
			o_rdata <= 32'hx;
		end

	always_ff @(posedge i_clock)
		o_ready <= i_request;

endmodule