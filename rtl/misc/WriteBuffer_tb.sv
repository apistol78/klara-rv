

`timescale 1ns/1ns
`default_nettype none

module WriteBuffer_tb();

    bit reset;
	bit clk;

    wire wb_bus_request;
    bit wb_bus_ready = 1'b0;

    bit wb_rw = 1'b0;
    bit wb_request = 1'b0;
    wire wb_ready;
    bit [31:0] wb_address = 32'h0;
    wire [31:0] wb_rdata;
    bit [31:0] wb_wdata = 32'h0;
    bit [3:0] wb_wmask = 4'h0;

	WriteBuffer #(
        .DEPTH(32),
        .ADDRESS_WIDTH(32),
        .STALL_READ(1)
    ) wb(
		.i_reset(reset),
		.i_clock(clk),

        .o_empty(),
        .o_full(),

		.o_bus_rw(),
        .o_bus_request(wb_bus_request),
        .i_bus_ready(wb_bus_ready & wb_bus_request),
        .o_bus_address(),
        .i_bus_rdata(32'hdead_beef),
        .o_bus_wdata(),
        .o_bus_wmask(),

        .i_rw(wb_rw),
        .i_request(wb_request),
        .o_ready(wb_ready),
        .i_address(wb_address),
        .o_rdata(wb_rdata),
        .i_wdata(wb_wdata),
        .i_wmask(wb_wmask)
	);

    always_ff @(posedge clk) begin
        wb_bus_ready <= wb_bus_request;
    end

    task wb_write(
        input logic [31:0] address,
        input logic [31:0] wdata,
        input logic [3:0] wmask
    );
        begin
            wb_request <= 1'b1;
            wb_rw <= 1'b1;
            wb_address <= address;
            wb_wdata <= wdata;
            wb_wmask <= wmask;
            @(posedge wb_ready);
            @(posedge clk);
            wb_request <= 1'b0;
            wb_address <= 32'h0;
            wb_wdata <= 32'h0;
            wb_wmask <= 4'h0;
            @(posedge clk);
            //@(posedge clk);
            if (wb_ready) begin
                $error("wb_ready kept high");
            end
        end
    endtask

    task wb_read(
        input logic [31:0] address
    );
        begin
            wb_request <= 1'b1;
            wb_rw <= 1'b0;
            wb_address <= address;
            @(posedge wb_ready);
            @(posedge clk);
            $display("wb_read %h", wb_rdata);
            wb_request <= 1'b0;
            wb_address <= 32'h0;
            @(posedge clk);
        end
    endtask

	initial begin
		clk = 0;
		#1;
		forever clk = #5 ~clk;        
	end

    initial begin
        $dumpfile("build/test/WriteBuffer_tb.fst");
        $dumpvars(0, WriteBuffer_tb);

        reset = 1;
        repeat (2) @ (posedge clk);
        reset = 0;

		repeat (4) @ (posedge clk);

        wb_write(32'hcafe_0001, 32'hb00b_1111, 4'b1111);
        wb_write(32'hcafe_0002, 32'hb00b_2222, 4'b1111);
        wb_write(32'hcafe_0003, 32'hb00b_3333, 4'b1111);
        
        //wb_read(32'hcafe_0002);

        wb_write(32'hcafe_0004, 32'hb00b_4444, 4'b1111);

        // wb_read(32'hcafe_0003);
        // wb_read(32'hcafe_0004);

        wb_write(32'hcafe_0005, 32'hb00b_5555, 4'b1111);
        wb_write(32'hcafe_0006, 32'hb00b_6666, 4'b1111);
        wb_write(32'hcafe_0007, 32'hb00b_7777, 4'b1111);
        wb_write(32'hcafe_0008, 32'hb00b_8888, 4'b1111);

        wb_read(32'hcafe_0005);

		repeat (100) @ (posedge clk);

		$finish;
	end

endmodule