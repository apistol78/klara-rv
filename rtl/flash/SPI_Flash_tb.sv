

`timescale 1ns/1ns

module SPI_Flash_tb();

	bit clk;

	bit spif_request = 1'b0;
	wire [31:0] spif_rdata;
	wire spif_ready;

	SPI_Flash #(
		.FREQUENCY(100000000)
	) spif(
		.i_reset(1'b0),
		.i_clock(clk),
		.i_request(spif_request),
		.i_address(32'hdeadbeef),
		.o_rdata(spif_rdata),
		.o_ready(spif_ready)
	);

	initial begin
		clk = 0;
		#1;
		forever clk = #5 ~clk;        
	end

    initial begin
        $dumpfile("build/test/SPI_Flash_tb.vcd");
        $dumpvars(0, SPI_Flash_tb);

		repeat (10) @ (posedge clk);

		spif_request <= 1'b1;
		while (!spif_ready) begin
			@(posedge clk);
		end
		spif_request <= 1'b0;

		repeat (100) @ (posedge clk);

		$finish;
	end

endmodule