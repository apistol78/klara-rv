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
	parameter DELAY_SLOW,
	parameter DELAY_FAST
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

	typedef enum bit
	{
		I2C_CMD_READ	= 1'd0,
		I2C_CMD_WRITE	= 1'd1
	}
	i2c_command_type_t;

	typedef enum bit
	{
		I2C_CMD_SLOW	= 1'd0,
		I2C_CMD_FAST	= 1'd1
	}
	i2c_command_speed_t;

	typedef struct packed
	{
		i2c_command_type_t cmd;
		i2c_command_speed_t speed;
		bit [7:0] device_address;
		bit [7:0] control_address;
		bit [7:0] nbytes_or_data;
	}
	i2c_command_t;

	typedef enum bit [5:0]
	{
		IDLE,				// 0
		__READ_CMD_0__,
		READ_CMD,
		__READ_CMD_RETIRED__,
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

	// Command
	i2c_command_t cmd;
	bit cmd_tx = 1'b0;
	bit cmd_rx = 1'b0;

	// Receive data queue.
	wire rx_queue_empty;
	wire rx_queue_full;
	bit rx_queue_write = 0;
	bit rx_queue_read = 0;
	bit [7:0] rx_queue_wdata;
	wire [7:0] rx_queue_rdata;
	FIFO #(
		.DEPTH(32),
		.WIDTH(8)
	) rx_queue(
		.i_reset(i_reset),
		.i_clock(i_clock),
		.o_empty(rx_queue_empty),
		.o_almost_full(rx_queue_full),
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
	bit [23:0] dly_speed = DELAY_SLOW;

	state_t state = IDLE;
	bit [2:0] read_state = 0;

	// CPU interface
	// Receive commands and insert into queue.
	always_ff @(posedge i_clock) begin
		if (i_reset) begin
			o_ready <= 1'b0;
			read_state <= 0;		
			cmd_tx <= 1'b0;
			rx_queue_read <= 1'b0;
		end
		else begin
			rx_queue_read <= 1'b0;

			if (i_request && !o_ready) begin
				if (!i_rw) begin
					if (i_address == 2'd0) begin
						o_rdata <=
						{
							27'b0,
							state != IDLE,
							1'b0,
							1'b0,
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
					else
						o_ready <= 1'b1;
				end
				else begin
					if (i_address == 2'd0) begin
						if (state == IDLE) begin

							cmd.cmd <= i_wdata[0];
							cmd.speed <= i_wdata[1];
							cmd.device_address <= i_wdata[15:8];
							cmd.control_address <= i_wdata[23:16];
							cmd.nbytes_or_data <= i_wdata[31:24];

							cmd_tx <= ~cmd_rx;

							o_ready <= 1'b1;
						end
					end
					else
						o_ready <= 1'b1;
				end
			end
			else if (!i_request) begin
				o_ready <= 1'b0;
				read_state <= 0;
			end
		end
	end


	// I2C state machine
	always_ff @(posedge i_clock) begin
		if (i_reset) begin
			scl <= 1'b1;
			sda_rw <= 1'b0;
			sda_w <= 1'b1;

			state <= IDLE;

			cmd_rx <= 1'b0;
			rx_queue_write <= 0;

			dly_speed <= DELAY_SLOW;
		end
		else begin
			unique case (state)

				IDLE: begin
					if (cmd_rx != cmd_tx) begin
						cmd_rx <= cmd_tx;
						state <= READ_CMD;
					end
				end

				READ_CMD: begin
					dly_speed <= cmd.speed ? DELAY_FAST : DELAY_SLOW;
					if (cmd.cmd == I2C_CMD_READ) begin
						i2c_read_device_address <= cmd.device_address;
						i2c_read_control_address <= cmd.control_address;
						i2c_read_nbytes <= cmd.nbytes_or_data;
						`I2C_READ(IDLE);
					end
					else if (cmd.cmd == I2C_CMD_WRITE) begin
						i2c_write_device_address <= cmd.device_address;
						i2c_write_control_address <= cmd.control_address;
						i2c_write_data <= cmd.nbytes_or_data;
						`I2C_WRITE(IDLE);
					end
					else
						state <= IDLE;
				end


				// I2C_READ

				S_I2C_READ_0: begin
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
					dly_count <= dly_speed;
					state <= WAIT_DELAY_I;
				end

				WAIT_DELAY_I: begin
					dly_count <= dly_count - 1;
					if (dly_count == 0)
						state <= dly_next_state;
				end
			endcase
		end
	end

endmodule
