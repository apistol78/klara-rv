

`timescale 1ns/1ns

module CPU_Multiply_tb();

	bit clk;

	bit m_latch = 1'b0;
	bit [31:0] m_op1;
	bit [31:0] m_op2;
	wire m_ready;
	wire [31:0] m_result;

	CPU_Multiply m(
		.i_clock(clk),
		.i_latch(m_latch),
		.i_signed(1'b0),
		.i_op1(m_op1),
		.i_op2(m_op2),
		.o_ready(m_ready),
		.o_result(m_result)
	);

	initial begin
		clk = 0;
		#1;
		forever clk = #5 ~clk;        
	end

	initial begin
		$dumpfile("CPU_Multiply_tb.vcd");
		$dumpvars(0, CPU_Multiply_tb);

		repeat (10) @ (posedge clk);

		m_latch = 1'b1;
		m_op1 = 32'd111;
		m_op2 = 32'd222;

		@(posedge clk);

		m_op1 = 32'd333;
		m_op2 = 32'd444;

		while (!m_ready) begin
			@(posedge clk);
		end

		m_latch = 1'b0;

		assert(m_result == 32'd111 * 32'd222);

		@(posedge clk);

		assert(!m_ready);

		// ---

		m_latch = 1'b1;
		m_op1 = 32'd555;
		m_op2 = 32'd666;

		@(posedge clk);

		m_op1 = 32'd777;
		m_op2 = 32'd888;

		while (!m_ready) begin
			@(posedge clk);
		end

		m_latch = 1'b0;

		assert(m_result == 32'd555 * 32'd666);

		@(posedge clk);

		assert(!m_ready);

		repeat (10) @ (posedge clk);

		$finish;
	end

endmodule