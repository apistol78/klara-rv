
module AUDIO_mul_16x4
(
	input logic clk,
	input logic signed [15:0] a,
	input logic [3:0] b,
	output logic signed [15:0] y
);
	// ------------------------------------------------------------
	// Stage 0: register inputs
	// ------------------------------------------------------------
	logic signed [15:0] a_s0;
	logic        [3:0]  b_s0;

	always_ff @(posedge clk) begin
		a_s0 <= a;
		b_s0 <= b;
	end


	// ------------------------------------------------------------
	// Stage 1: partial for b[0]
	// ------------------------------------------------------------
	logic signed [19:0] p1_s1;
	logic signed [15:0] a_s1;
	logic        [3:0]  b_s1;

	always_ff @(posedge clk) begin
		a_s1 <= a_s0;
		b_s1 <= b_s0;

		p1_s1 <= b_s0[0] ? {{4{a_s0[15]}}, a_s0} : 20'sd0;
	end


	// ------------------------------------------------------------
	// Stage 2: partial for b[1] << 1
	// ------------------------------------------------------------
	logic signed [19:0] p2_s2;
	logic signed [15:0] a_s2;
	logic        [3:0]  b_s2;

	always_ff @(posedge clk) begin
		a_s2 <= a_s1;
		b_s2 <= b_s1;

		p2_s2 <= p1_s1 +
				 (b_s1[1] ? {{3{a_s1[15]}}, a_s1, 1'b0} : 20'sd0);
	end


	// ------------------------------------------------------------
	// Stage 3: partial for b[2] << 2
	// ------------------------------------------------------------
	logic signed [19:0] p3_s3;
	logic signed [15:0] a_s3;
	logic        [3:0]  b_s3;

	always_ff @(posedge clk) begin
		a_s3 <= a_s2;
		b_s3 <= b_s2;

		p3_s3 <= p2_s2 +
				 (b_s2[2] ? {{2{a_s2[15]}}, a_s2, 2'b00} : 20'sd0);
	end


	// ------------------------------------------------------------
	// Stage 4: partial for b[3] << 3 → full product (20-bit)
	// ------------------------------------------------------------
	logic signed [19:0] full_prod_s4;

	always_ff @(posedge clk) begin
		full_prod_s4 <= p3_s3 +
			(b_s3[3] ? {{1{a_s3[15]}}, a_s3, 3'b000} : 20'sd0);
	end


	// ------------------------------------------------------------
	// Stage 5: divide by 15 using shifts → fractional scaling
	// ------------------------------------------------------------
	logic signed [19:0] scaled_s5;

	always_ff @(posedge clk) begin
		// approximate exact integer divide  (error < 0.03%)
		scaled_s5 <= (full_prod_s4 >>> 4) +
					 (full_prod_s4 >>> 8) +
					 (full_prod_s4 >>> 12);
	end


	// ------------------------------------------------------------
	// Stage 6: Saturate to signed 16-bit
	// ------------------------------------------------------------
	logic signed [15:0] sat_s6;

	always_ff @(posedge clk) begin
		if (scaled_s5 > 20'sd32767)
			sat_s6 <= 16'sh7FFF;
		else if (scaled_s5 < -20'sd32768)
			sat_s6 <= 16'sh8000;
		else
			sat_s6 <= scaled_s5[15:0];
	end

	assign y = sat_s6;
	
endmodule
