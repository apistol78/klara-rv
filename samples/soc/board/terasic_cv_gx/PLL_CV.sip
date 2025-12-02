set_global_assignment -entity "PLL_CV" -library "lib_PLL_CV" -name IP_TOOL_NAME "altera_pll"
set_global_assignment -entity "PLL_CV" -library "lib_PLL_CV" -name IP_TOOL_VERSION "25.1"
set_global_assignment -entity "PLL_CV" -library "lib_PLL_CV" -name IP_TOOL_ENV "mwpim"
set_global_assignment -library "lib_PLL_CV" -name SPD_FILE [file join $::quartus(sip_path) "PLL_CV.spd"]

set_global_assignment -library "lib_PLL_CV" -name MISC_FILE [file join $::quartus(sip_path) "PLL_CV_sim/PLL_CV.vo"]
