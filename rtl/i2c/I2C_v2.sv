/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

`timescale 1ns/1ns
`default_nettype none

`define DLY_NEXT(ns) begin; dly_next_state <= ns; state <= WAIT_DELAY; end
`define I2C_START(rs) begin; i2c_start_rs <= rs; state <= S_I2C_START_0; end
`define I2C_STOP(rs) begin; i2c_stop_rs <= rs; state <= S_I2C_STOP_0; end
`define I2C_RX(rs) begin; i2c_rx_rs <= rs; state <= S_I2C_RX_0; end
`define I2C_TX_ADDR(rs) begin; i2c_tx_addr_rs <= rs; state <= S_I2C_TX_ADDR_0; end
`define I2C_WRITE(rs) begin; i2c_write_rs <= rs; state <= S_I2C_WRITE_0; end
`define I2C_READ(rs) begin; i2c_read_rs <= rs; state <= S_I2C_READ_0; end

module I2C_v2 #(
	parameter DELAY = 128
)(
	input i_reset,
	input i_clock,
	input i_request,
	input i_rw,
	input [1:0] i_address,
	input [31:0] i_wdata,
	output bit [31:0] o_rdata,
	output bit o_ready,

	output I2C_SCL,
	output I2C_SDA_direction,
	input I2C_SDA_r,
	output I2C_SDA_w
);
	bit scl = 1'b1;
	bit sda_rw = 1'b0;
	bit sda_w = 1'b1;
	wire sda_r = I2C_SDA_r;

	assign I2C_SCL = scl;
	assign I2C_SDA_direction = sda_rw;
	assign I2C_SDA_w = sda_w;

	typedef enum bit [1:0]
	{
		I2C_CMD_READ	= 2'd1,
		I2C_CMD_WRITE	= 2'd2
	}
	i2c_command_type_t;

	typedef struct packed
	{
		i2c_command_type_t cmd;
		bit [7:0] device_address;
		bit [7:0] control_address;
		bit [7:0] nbytes_or_data;
		bit [31:0] tag;
	}
	i2c_command_t;

	typedef enum bit [5:0]
	{
		IDLE,				// 0
		READ_CMD_0,
		READ_CMD,
		READ_CMD_RETIRED,
		S_I2C_READ_0,
		S_I2C_READ_1,
		S_I2C_READ_2,
		S_I2C_READ_3,
		S_I2C_READ_4,
		S_I2C_READ_5,
		S_I2C_READ_6,
		S_I2C_READ_7,		// 10
		S_I2C_WRITE_0,
		S_I2C_WRITE_1,
		S_I2C_WRITE_2,
		S_I2C_WRITE_3,
		S_I2C_WRITE_4,
		S_I2C_START_0,		// 16
		S_I2C_START_1,
		S_I2C_START_2,
		S_I2C_START_3,
		S_I2C_STOP_0,		// 20
		S_I2C_STOP_1,
		S_I2C_STOP_2,
		S_I2C_RX_0,
		S_I2C_RX_0_1,
		S_I2C_RX_1,
		S_I2C_RX_2,
		S_I2C_RX_3,
		S_I2C_RX_4,
		S_I2C_RX_5,
		S_I2C_RX_5_1,
		S_I2C_RX_6,
		S_I2C_TX_ADDR_0,	// 30
		S_I2C_TX_ADDR_1,
		S_I2C_TX_ADDR_2,
		S_I2C_TX_ADDR_3,
		S_I2C_TX_ADDR_4,
		S_I2C_TX_ADDR_5,
		S_I2C_TX_ADDR_6,
		WAIT_DELAY,			// 47
		WAIT_DELAY_I
	}
	state_t;

	// Command queue.
	wire queue_empty;
	wire queue_full;
	bit queue_write = 0;
	bit queue_read = 0;
	i2c_command_t queue_wdata;
	i2c_command_t queue_rdata;
	FIFO #(
		.DEPTH(16),
		.WIDTH($bits(i2c_command_t))
	) queue(
		.i_reset(i_reset),
		.i_clock(i_clock),
		.o_empty(queue_empty),
		.o_full(queue_full),
		.i_write(queue_write),
		.i_wdata(queue_wdata),
		.i_read(queue_read),
		.o_rdata(queue_rdata),
		.o_queued()
	);

	// Receive data queue.
	wire rx_queue_empty;
	wire rx_queue_full;
	bit rx_queue_write = 0;
	bit rx_queue_read = 0;
	bit [7:0] rx_queue_wdata;
	wire [7:0] rx_queue_rdata;
	FIFO #(
		.DEPTH(16),
		.WIDTH(8)
	) rx_queue(
		.i_reset(i_reset),
		.i_clock(i_clock),
		.o_empty(rx_queue_empty),
		.o_full(rx_queue_full),
		.i_write(rx_queue_write),
		.i_wdata(rx_queue_wdata),
		.i_read(rx_queue_read),
		.o_rdata(rx_queue_rdata),
		.o_queued()
	);

	// State registers

	state_t i2c_read_rs;
	bit [6:0] i2c_read_device_address;		//!< Input
	bit [7:0] i2c_read_control_address;		//!< Input
	bit [3:0] i2c_read_nbytes;				//!< Input

	state_t i2c_write_rs;
	bit [6:0] i2c_write_device_address;		//!< Input
	bit [7:0] i2c_write_control_address;	//!< Input
	bit [7:0] i2c_write_data;				//!< Input
	
	state_t i2c_start_rs;

	state_t i2c_stop_rs;

	state_t i2c_rx_rs;
	bit i2c_rx_ack;							//!< Input
	bit [7:0] i2c_rx_data;					//!< Output
	bit [4:0] i2c_rx_counter;

	state_t i2c_tx_addr_rs;
	bit [7:0] i2c_tx_addr_device_address;	//!< Input
	bit i2c_tx_addr_ack;					//!< Output
	bit [4:0] i2c_tx_addr_counter;

	state_t dly_next_state;
	bit [23:0] dly_count;

	state_t state = IDLE;
	bit [2:0] read_state = 0;

	bit [31:0] queued_counter = 32'h0;
	bit [31:0] retired_counter = 32'h0;

	// CPU interface
	// Receive commands and insert into queue.
	always_ff @(posedge i_clock) begin

		queue_write <= 1'b0;
		rx_queue_read <= 1'b0;

		if (i_request && !o_ready) begin
			if (!i_rw) begin
				if (i_address == 2'd0) begin
					o_rdata <=
					{
						27'b0,
						state != IDLE,
						queue_empty,
						queue_full,
						rx_queue_empty,
						rx_queue_full
					};
					o_ready <= 1'b1;
				end
				else if (i_address == 2'd1) begin
					case (read_state)
						0: begin
							if (!rx_queue_empty) begin
								rx_queue_read <= 1'b1;
								read_state <= 1;
							end
						end
						1: begin
							rx_queue_read <= 1'b0;
							read_state <= 2;
						end
						2: begin
							o_rdata <= rx_queue_rdata;
							o_ready <= 1'b1;
						end
					endcase
				end
				else if (i_address == 2'd2) begin
					o_rdata <= queued_counter;
					o_ready <= 1'b1;
				end
				else if (i_address == 2'd3) begin
					o_rdata <= retired_counter;
					o_ready <= 1'b1;
				end
			end
			else begin
				if (i_address == 2'd0) begin
					queue_wdata.cmd <= i_wdata[1:0];
					queue_wdata.device_address <= i_wdata[15:8];
					queue_wdata.control_address <= i_wdata[23:16];
					queue_wdata.nbytes_or_data <= i_wdata[31:24];
					queue_wdata.tag <= queued_counter + 1;
					if (!queue_full) begin
						queue_write <= 1'b1;
						queued_counter <= queued_counter + 1;
						o_ready <= 1'b1;
					end
				end
			end
		end
		else if (!i_request) begin
			o_ready <= 1'b0;
			read_state <= 0;
		end
	end


	// I2C state machine
	bit [31:0] busy_counter = 0;
	always_ff @(posedge i_clock) begin
		
		unique case (state)

			// Read command from queue.

			IDLE: begin
				if (!queue_empty) begin
					queue_read <= 1'b1;
					state <= READ_CMD_0;
				end
			end

			READ_CMD_0: begin
				queue_read <= 1'b0;
				state <= READ_CMD;
			end

			READ_CMD: begin
				if (queue_rdata.cmd == I2C_CMD_READ) begin
					i2c_read_device_address <= queue_rdata.device_address;
					i2c_read_control_address <= queue_rdata.control_address;
					i2c_read_nbytes <= queue_rdata.nbytes_or_data;
					busy_counter <= queue_rdata.tag;
					`I2C_READ(READ_CMD_RETIRED);
				end
				else if (queue_rdata.cmd == I2C_CMD_WRITE) begin
					i2c_write_device_address <= queue_rdata.device_address;
					i2c_write_control_address <= queue_rdata.control_address;
					i2c_write_data <= queue_rdata.nbytes_or_data;
					busy_counter <= queue_rdata.tag;
					`I2C_WRITE(READ_CMD_RETIRED);
				end
				else
					state <= READ_CMD_RETIRED;
			end

			READ_CMD_RETIRED: begin
				retired_counter <= busy_counter;
				state <= IDLE;
			end


			// I2C_READ

			S_I2C_READ_0: begin
				$display("S_I2C_READ_0 device address %02x, control %02x, nbytes %d", i2c_read_device_address, i2c_read_control_address, i2c_read_nbytes);
				`I2C_START(S_I2C_READ_1);
			end
			S_I2C_READ_1: begin
				i2c_tx_addr_device_address <= { i2c_read_device_address, 1'b0 };
				`I2C_TX_ADDR(S_I2C_READ_2);
			end
			S_I2C_READ_2: begin
				i2c_tx_addr_device_address <= i2c_read_control_address;
				`I2C_TX_ADDR(S_I2C_READ_3);
			end
			S_I2C_READ_3: begin
				`I2C_START(S_I2C_READ_4);
			end
			S_I2C_READ_4: begin
				i2c_tx_addr_device_address <= { i2c_read_device_address, 1'b1 };
				`I2C_TX_ADDR(S_I2C_READ_5);
			end
			S_I2C_READ_5: begin
				i2c_rx_ack <= (i2c_read_nbytes > 1) ? 1'b1 : 1'b0;
				`I2C_RX(S_I2C_READ_6);
			end
			S_I2C_READ_6: begin
				rx_queue_write <= 1'b1;
				rx_queue_wdata <= i2c_rx_data;
				state <= S_I2C_READ_7;
			end
			S_I2C_READ_7: begin
				rx_queue_write <= 1'b0;
				i2c_read_nbytes <= i2c_read_nbytes - 1;
				if (i2c_read_nbytes > 1)
					`DLY_NEXT(S_I2C_READ_5)
				else
					`I2C_STOP(i2c_read_rs);
			end

			// I2C_WRITE

			S_I2C_WRITE_0: begin
				$display("S_I2C_WRITE_0 device address %02x, control %02x, data %02x", i2c_write_device_address, i2c_write_control_address, i2c_write_data);
				`I2C_START(S_I2C_WRITE_1);
			end
			S_I2C_WRITE_1: begin
				i2c_tx_addr_device_address <= { i2c_write_device_address, 1'b0 };
				`I2C_TX_ADDR(S_I2C_WRITE_2);
			end
			S_I2C_WRITE_2: begin
				i2c_tx_addr_device_address <= i2c_write_control_address;
				`I2C_TX_ADDR(S_I2C_WRITE_3);
			end
			S_I2C_WRITE_3: begin
				i2c_tx_addr_device_address <= i2c_write_data;
				`I2C_TX_ADDR(S_I2C_WRITE_4);
			end
			S_I2C_WRITE_4: begin
				`I2C_STOP(i2c_write_rs);
			end

			// I2C_START

			S_I2C_START_0: begin
				$display("S_I2C_START_0");
				sda_rw <= 1'b1;
				sda_w <= 1'b1;
				`DLY_NEXT(S_I2C_START_1);
			end
			S_I2C_START_1: begin
				scl <= 1'b1;
				`DLY_NEXT(S_I2C_START_2);
			end
			S_I2C_START_2: begin
				sda_rw <= 1'b1;
				sda_w <= 1'b0;
				`DLY_NEXT(S_I2C_START_3);
			end
			S_I2C_START_3: begin
				scl <= 1'b0;
				`DLY_NEXT(i2c_start_rs);
			end

			// I2C_STOP

			S_I2C_STOP_0: begin
				$display("S_I2C_STOP_0");
				sda_rw <= 1'b1;
				sda_w <= 1'b0;
				`DLY_NEXT(S_I2C_STOP_1);
			end
			S_I2C_STOP_1: begin
				scl <= 1'b1;
				`DLY_NEXT(S_I2C_STOP_2);
			end
			S_I2C_STOP_2: begin
				sda_rw <= 1'b1;
				sda_w <= 1'b1;
				`DLY_NEXT(i2c_stop_rs);
			end

			// I2C_RX

			S_I2C_RX_0: begin
				$display("S_I2C_RX_0, ack %d", i2c_rx_ack);
				scl <= 1'b0;
				sda_w <= 1'b1;
				sda_rw <= 1'b1;
				i2c_rx_data <= 8'h0;
				i2c_rx_counter <= 5'h0;
				`DLY_NEXT(S_I2C_RX_0_1);
			end
			S_I2C_RX_0_1: begin
				sda_rw <= 1'b0;
				`DLY_NEXT(S_I2C_RX_1);
			end
			S_I2C_RX_1: begin
				scl <= 1'b1;
				`DLY_NEXT(S_I2C_RX_2);
			end
			S_I2C_RX_2: begin
				// if (scl == 0)
				// 	state <= S_I2C_RX_1;
				// else begin
				//	i2c_rx_counter <= i2c_rx_counter + 1;
				// 	`DLY_NEXT(S_I2C_RX_3);
				// end
				i2c_rx_data <= { i2c_rx_data[6:0], sda_r };
				i2c_rx_counter <= i2c_rx_counter + 5'h1;
				`DLY_NEXT(S_I2C_RX_3);
			end
			S_I2C_RX_3: begin
				scl <= 1'b0;
				if (i2c_rx_counter < 5'd8)
					`DLY_NEXT(S_I2C_RX_1)
				else begin
					`DLY_NEXT(S_I2C_RX_4)
				end
			end
			S_I2C_RX_4: begin
				sda_rw <= 1'b1;
				sda_w <= ~i2c_rx_ack;
				`DLY_NEXT(S_I2C_RX_5);
			end
			S_I2C_RX_5: begin
				scl <= 1'b1;
				`DLY_NEXT(S_I2C_RX_5_1);
			end
			S_I2C_RX_5_1: begin
				`DLY_NEXT(S_I2C_RX_6);
			end
			S_I2C_RX_6: begin
				scl <= 1'b0;

				sda_rw <= 1'b0;
				sda_w <= 1'b1;

				`DLY_NEXT(i2c_rx_rs);
			end

			// I2C_TX_ADDR

			// Write data.
			S_I2C_TX_ADDR_0: begin
				$display("S_I2C_TX_ADDR_0 device address %02x, read %d", i2c_tx_addr_device_address[6:0], i2c_tx_addr_device_address[7]);
				i2c_tx_addr_counter <= 5'h0;
				state <= S_I2C_TX_ADDR_1;
			end
			S_I2C_TX_ADDR_1: begin
				sda_rw <= 1'b1;
				sda_w <= i2c_tx_addr_device_address[7];
				i2c_tx_addr_device_address <= i2c_tx_addr_device_address << 1;
				i2c_tx_addr_counter <= i2c_tx_addr_counter + 5'h1;
				`DLY_NEXT(S_I2C_TX_ADDR_2);
			end
			S_I2C_TX_ADDR_2: begin
				scl <= 1'b1;
				`DLY_NEXT(S_I2C_TX_ADDR_3);
			end
			S_I2C_TX_ADDR_3: begin
				scl <= 1'b0;
				if (i2c_tx_addr_counter < 5'h8)
					`DLY_NEXT(S_I2C_TX_ADDR_1)
				else begin
					sda_rw <= 1'b0;
					`DLY_NEXT(S_I2C_TX_ADDR_4)
				end
			end
			// Read ACK from slave.
			S_I2C_TX_ADDR_4: begin
				`DLY_NEXT(S_I2C_TX_ADDR_5);
			end
			S_I2C_TX_ADDR_5: begin
				scl <= 1'b1;
				`DLY_NEXT(S_I2C_TX_ADDR_6);
			end
			S_I2C_TX_ADDR_6: begin
				i2c_tx_addr_ack <= sda_r;
				scl <= 1'b0;
				sda_rw <= 1'b1;
				`DLY_NEXT(i2c_tx_addr_rs);
			end

			// Delay states.

			WAIT_DELAY: begin
				dly_count <= 0;
				state <= WAIT_DELAY_I;
			end

			WAIT_DELAY_I: begin
				dly_count <= dly_count + 1;
				if (dly_count >= DELAY)
					state <= dly_next_state;
			end
		endcase
	end

endmodule
