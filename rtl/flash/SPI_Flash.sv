/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns

module SPI_Flash #(
	parameter FREQUENCY = 100_000_000
)(
	input i_reset,
	input i_clock,
	input i_request,
	input [31:0] i_address,
	output [31:0] o_rdata,
	output bit o_ready,

    output bit SPI_nCS,
    output SPI_CLK,
    output SPI_MOSI,
    input SPI_MISO,
);
	typedef enum bit [7:0]
	{
		IDLE,
        SEND_CMD,
        RECV_DAT,
        WAIT_EOT
    } state_t;

    initial begin
        o_ready = 1'b0;
        SPI_nCS = 1'b1;
    end

    state_t state = IDLE;
    bit [31:0] caddr;
    bit [31:0] rdata;
    bit [7:0] count;

    assign o_rdata = { rdata[7:0], rdata[15:8], rdata[23:16], rdata[31:24] };
    assign SPI_CLK = !SPI_nCS && !i_clock;
    assign SPI_MOSI = caddr[31];

    always_ff @(posedge i_clock) begin

        o_ready <= 1'b0;

        case (state)
            IDLE: begin
                if (i_request) begin
                    SPI_nCS <= 1'b0;
                    caddr <= { 8'h03, i_address[23:0] };
                    count <= 32;
                    state <= SEND_CMD;
                end
            end

            SEND_CMD: begin
                if (count > 0) begin
                    caddr <= { caddr[30:0], 1'b0 };
                    count <= count - 1;
                end
                else begin
                    rdata <= 0;
                    count <= 32;
                    state <= RECV_DATA;
                end
            end

            RECV_DAT: begin
                if (count > 0) begin
                    rdata <= { rdata[30:0], SPI_MISO };
                    count <= count - 1;
                end
                else begin
                    SPI_nCS <= 1'b1;
                    o_ready <= i_request;
                    state <= WAIT_EOT;
                end
            end

            WAIT_EOT: begin
                o_ready <= i_request;
                if (!i_request) begin
                    state <= IDLE;
                end
            end            

        endcase
    end

endmodule
