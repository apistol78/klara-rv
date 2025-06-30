// https://projectf.io/posts/ecp5-fpga-clock/

module PLL_ECP5 #(
	parameter CLKI_DIV  = 1,     // input clock divider
	parameter CLKFB_DIV = 1,     // feedback divider
	parameter CLKOP_DIV = 1,     // primary output clock divider
	parameter CLKOP_CPHASE = 0,  // primary output clock phase
	parameter CLKOS_DIV = 1,     // secondary output clock divider
	parameter CLKOS_CPHASE = 0,  // secondary output clock phase
	parameter CLKOS2_DIV = 1,    // tertiary output clock divider
	parameter CLKOS2_CPHASE = 0  // tertiary output clock phase
)(
	input  wire i_clk,      	// input clock
	output wire o_clk1,  		// output clock
	output wire o_clk2,    		// output clock
	output wire o_clk3,			// output clock
	output reg  o_clk_locked   	// clock locked?
 );

	wire locked;  // unsynced lock signal

	// HDL attributes (values are from Project Trellis)
	(* ICP_CURRENT="12" *)
	(* LPF_RESISTOR="8" *)
	(* MFG_ENABLE_FILTEROPAMP="1" *)
	(* MFG_GMCREF_SEL="2" *)

	EHXPLLL #(
		.PLLRST_ENA("DISABLED"),
		.INTFB_WAKE("DISABLED"),
		.STDBY_ENABLE("DISABLED"),
		.DPHASE_SOURCE("DISABLED"),
		.OUTDIVIDER_MUXA("DIVA"),
		.OUTDIVIDER_MUXB("DIVB"),
		.OUTDIVIDER_MUXC("DIVC"),
		.OUTDIVIDER_MUXD("DIVD"),
		.CLKI_DIV(CLKI_DIV),

		.CLKOP_ENABLE("ENABLED"),
		.CLKOP_DIV(CLKOP_DIV),
		.CLKOP_CPHASE(CLKOP_CPHASE),
		.CLKOP_FPHASE(0),

		.CLKOS_ENABLE("ENABLED"),
		.CLKOS_DIV(CLKOS_DIV),
		.CLKOS_CPHASE(CLKOS_CPHASE),
		.CLKOS_FPHASE(0),

		.CLKOS2_ENABLE("ENABLED"),
		.CLKOS2_DIV(CLKOS2_DIV),
		.CLKOS2_CPHASE(CLKOS2_CPHASE),
		.CLKOS2_FPHASE(0),

		.FEEDBK_PATH("CLKOP"),
		.CLKFB_DIV(CLKFB_DIV)
	) pll_i (
		.RST(1'b0),
		.STDBY(1'b0),
		.CLKI(i_clk),
		.CLKOP(o_clk1),
		.CLKOS(o_clk2),
		.CLKOS2(o_clk3),
		.CLKFB(o_clk1),
		.CLKINTFB(),
		.PHASESEL0(1'b0),
		.PHASESEL1(1'b0),
		.PHASEDIR(1'b1),
		.PHASESTEP(1'b1),
		.PHASELOADREG(1'b1),
		.PLLWAKESYNC(1'b0),
		.ENCLKOP(1'b0),
		.LOCK(locked)
	);

	// ensure clock lock is synced with output clock
	reg locked_sync;
	always @(posedge o_clk2) begin
		locked_sync <= locked;
		o_clk_locked <= locked_sync;
	end
endmodule
