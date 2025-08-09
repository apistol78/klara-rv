/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns
`default_nettype none


module bus_cdc_bridge (
    // Master side
    input  wire        m_clk,
    input  wire        m_resetn,
    input  wire        m_request,
    input  wire        m_rw,
    input  wire [31:0] m_address,
    input  wire [31:0] m_wdata,
    output reg  [31:0] m_rdata,
    output reg         m_ready,

    // Slave side
    input  wire        s_clk,
    input  wire        s_resetn,
    output reg         s_request,
    output reg         s_rw,
    output reg  [31:0] s_address,
    output reg  [31:0] s_wdata,
    input  wire [31:0] s_rdata,
    input  wire        s_ready
);
    reg [31:0] s_rdata_sync; // Registered read data in slave domain

    // -------------------------
    // Request handshake signals
    // -------------------------
    reg req_toggle_m;          // Master toggles to indicate new request
    reg req_toggle_s_sync1, req_toggle_s_sync2;  // Slave-domain sync
    reg ack_toggle_s;          // Slave toggles to acknowledge
    reg ack_toggle_m_sync1, ack_toggle_m_sync2;  // Master-domain sync

    // -------------------------
    // Response handshake signals
    // -------------------------
    reg resp_toggle_s;
    reg resp_toggle_m_sync1, resp_toggle_m_sync2;
    reg resp_ack_toggle_m;
    reg resp_ack_toggle_s_sync1, resp_ack_toggle_s_sync2;

    // -------------------------
    // Master domain logic
    // -------------------------
    reg [31:0] req_addr_reg;
    reg [31:0] req_wdata_reg;
    reg        req_rw_reg;

    always @(posedge m_clk or negedge m_resetn) begin
        if (!m_resetn) begin
            req_toggle_m <= 0;
            req_addr_reg <= 0;
            req_wdata_reg <= 0;
            req_rw_reg <= 0;
        end else begin
            if (m_request && (ack_toggle_m_sync2 == req_toggle_m)) begin
                // Latch request data and toggle
                req_addr_reg <= m_address;
                req_wdata_reg <= m_wdata;
                req_rw_reg <= m_rw;
                req_toggle_m <= ~req_toggle_m;
            end
        end
    end

    // Sync ack back into master domain
    always @(posedge m_clk) begin
        ack_toggle_m_sync1 <= ack_toggle_s;
        ack_toggle_m_sync2 <= ack_toggle_m_sync1;
    end

    // -------------------------
    // Master receive response
    // -------------------------
    always @(posedge m_clk or negedge m_resetn) begin
        if (!m_resetn) begin
            m_rdata <= 0;
            m_ready <= 0;
            resp_ack_toggle_m <= 0;
        end else begin
            m_ready <= 0;
            if (resp_toggle_m_sync2 != resp_ack_toggle_m) begin
                // Got new response
                m_rdata <= s_rdata_sync;
                m_ready <= 1;
                resp_ack_toggle_m <= resp_toggle_m_sync2;
            end
        end
    end

    // Sync response toggle from slave
    always @(posedge m_clk) begin
        resp_toggle_m_sync1 <= resp_toggle_s;
        resp_toggle_m_sync2 <= resp_toggle_m_sync1;
    end

    // -------------------------
    // Slave domain logic
    // -------------------------
    // Sync request toggle from master
    always @(posedge s_clk) begin
        req_toggle_s_sync1 <= req_toggle_m;
        req_toggle_s_sync2 <= req_toggle_s_sync1;
    end

    always @(posedge s_clk or negedge s_resetn) begin
        if (!s_resetn) begin
            s_request <= 0;
            s_rw <= 0;
            s_address <= 0;
            s_wdata <= 0;
            ack_toggle_s <= 0;
        end else begin
            if (req_toggle_s_sync2 != ack_toggle_s) begin
                // New request available, capture it
                s_address <= req_addr_reg;
                s_wdata   <= req_wdata_reg;
                s_rw      <= req_rw_reg;
                s_request <= 1;
                ack_toggle_s <= req_toggle_s_sync2; // Acknowledge receipt
            end else begin
                s_request <= 0;
            end
        end
    end

    // -------------------------
    // Slave send response
    // -------------------------

    always @(posedge s_clk or negedge s_resetn) begin
        if (!s_resetn) begin
            resp_toggle_s <= 0;
            s_rdata_sync <= 0;
        end else begin
            if (s_ready) begin
                s_rdata_sync <= s_rdata;
                resp_toggle_s <= ~resp_toggle_s;
            end
        end
    end

    // Sync response ack back into slave domain
    always @(posedge s_clk) begin
        resp_ack_toggle_s_sync1 <= resp_ack_toggle_m;
        resp_ack_toggle_s_sync2 <= resp_ack_toggle_s_sync1;
    end

endmodule


module BusX (
	input i_reset,
	input i_clock,
	input i_clock_far,

	// Near
	input i_request,
	input i_rw,
	input [31:0] i_address,
	input [31:0] i_wdata,
	output bit [31:0] o_rdata,
	output bit o_ready,

	// Far
	output bit o_far_request,
	output o_far_rw,
	output [31:0] o_far_address,
	output [31:0] o_far_wdata,
	input [31:0] i_far_rdata,
	input i_far_ready
);

	bit r_request = 1'b0;
	always_ff @(posedge i_clock) begin
		r_request <= i_request;
	end
	wire request_pulse = ( { r_request, i_request } == 2'b01 );

	initial o_far_request = 1'b0;

	wire r_far_request;
	always_ff @(posedge i_clock_far) begin
		if (r_far_request)
			o_far_request <= 1'b1;
		if (o_far_request && i_far_ready)
			o_far_request <= 1'b0;
	end

	bus_cdc_bridge cdc(
		.m_clk(i_clock),
		.m_resetn(~i_reset),
		.m_request(request_pulse),
		.m_rw(i_rw),
		.m_address(i_address),
		.m_wdata(i_wdata),
		.m_rdata(o_rdata),
		.m_ready(o_ready),
		.s_clk(i_clock_far),
		.s_resetn(~i_reset),
		.s_request(r_far_request),
		.s_rw(o_far_rw),
		.s_address(o_far_address),
		.s_wdata(o_far_wdata),
		.s_rdata(i_far_rdata),
		.s_ready(i_far_ready)
	);

endmodule
