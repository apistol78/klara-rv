/*
 Klara-RV
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

// Since we're using DSP to implement multiplication
// we need to pipeline result so we can meet timing.

`timescale 1ns/1ns

/////////////////////////////////////////////////////////////////////////////////////
//
//Copyright 2019  Li Xinbing
//
//Licensed under the Apache License, Version 2.0 (the "License");
//you may not use this file except in compliance with the License.
//You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
//Unless required by applicable law or agreed to in writing, software
//distributed under the License is distributed on an "AS IS" BASIS,
//WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//See the License for the specific language governing permissions and
//limitations under the License.
//
/////////////////////////////////////////////////////////////////////////////////////

`define N(n) [(n)-1:0]
`define FFx(signal,bits) always @ ( posedge clk or posedge  rst ) if (rst) signal <= bits; else

module divfunc
#(
    parameter XLEN = 32,
    parameter `N(XLEN) STAGE_LIST = 0
)
(
    input              clk,
    input              rst,
    input  `N(XLEN)    a,
    input  `N(XLEN)    b,
    input              vld,
    output `N(XLEN)    quo,
    output `N(XLEN)    rem,
    output             ack
);
    reg               ready    `N(XLEN+1);
    reg `N(XLEN)      dividend `N(XLEN+1);  
    reg `N(XLEN)      divisor  `N(XLEN+1);
    reg `N(XLEN)      quotient `N(XLEN+1);     

    always@* begin
        ready[0]    = vld;    
        dividend[0] = a;
        divisor[0]  = b;
        quotient[0] = 0;
    end   

    generate
    	genvar i;
    	for (i = 0; i < XLEN; i = i + 1) begin : gen_div

            wire [i:0]      m = dividend[i] >> (XLEN - i - 1);
            wire [i:0]      n = divisor[i];
    	    wire            q = (|(divisor[i] >> (i + 1))) ? 1'b0 : (m >= n);
    	    wire [i:0]      t = q ? (m - n) : m;
			wire [XLEN-1:0] u = dividend[i] << (i + 1);
    	    wire [XLEN+i:0] d = {t, u} >> (i + 1);

            if (STAGE_LIST[XLEN-i-1]) begin : gen_ff
                `FFx(ready[i+1], 0)
                ready[i+1] <= ready[i];

                `FFx(dividend[i + 1], 0)
                dividend[i+1] <= d;

                `FFx(divisor[i + 1], 0)
                divisor[i+1] <= divisor[i];

                `FFx(quotient[i + 1], 0)
                quotient[i+1] <= quotient[i] | (q << (XLEN-i-1));
               
            end else begin:gen_comb
                always @* begin
                	ready[i+1]    = ready[i];
                	dividend[i+1] = d;
                    divisor[i+1]  = divisor[i];
                	quotient[i+1] = quotient[i] | (q << (XLEN-i-1));                	
                end
            end
        end
    endgenerate

    assign quo = quotient[XLEN];
    assign rem = dividend[XLEN];
    assign ack = ready[XLEN];

endmodule

module CPU_Divide(
	input i_clock,
	input i_latch,
	input i_signed,
	input [31:0] i_numerator,
	input [31:0] i_denominator,
	output bit o_ready,
	output bit [31:0] o_result,
	output bit [31:0] o_remainder
);

	wire snumerator = i_numerator[31];
	wire sdenominator = i_denominator[31];

	bit [31:0] unumerator;
	bit [31:0] udenominator;

	bit [31:0] result;
	bit [31:0] remainder;
	bit ack = 1'b0;

	bit [1:0] s;
	bit llth = 0;

	wire valid = llth && i_latch;

	divfunc #(
		.XLEN(32),
		.STAGE_LIST(32'b10100010001000100010001000100101)
	) df(
		.clk(i_clock),
		.rst(~i_latch),
		.a(unumerator),
		.b(udenominator),
		.vld(valid),
		.quo(result),
		.rem(remainder),
		.ack(ack)
	);

	always_ff @(posedge i_clock) begin
		llth <= i_latch;
		if (i_latch) begin
			unumerator <= (i_signed && snumerator) ? -$signed(i_numerator) : i_numerator;
			udenominator <= (i_signed && sdenominator) ? -$signed(i_denominator) : i_denominator;		
			s <= { snumerator, sdenominator };
		end
	end

	always_comb begin
		o_ready = i_latch && ack;
		o_result = (i_signed && s[0] != s[1]) ? -$signed(result) : result;
		o_remainder = (i_signed && s[1]) ? -$signed(remainder) : remainder;
	end

endmodule
