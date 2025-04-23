@echo off

call %~dp0..\traktor\scripts\config.bat

:: Generate instructions.
%TRAKTOR_HOME%/bin/win64/releasestatic/Traktor.Run.App rtl/Instructions.run verilog_alu > rtl/private/generated/Instructions_alu.sv
%TRAKTOR_HOME%/bin/win64/releasestatic/Traktor.Run.App rtl/Instructions.run verilog_memory > rtl/private/generated/Instructions_memory.sv
%TRAKTOR_HOME%/bin/win64/releasestatic/Traktor.Run.App rtl/Instructions.run verilog_ops > rtl/private/generated/Instructions_ops.sv
%TRAKTOR_HOME%/bin/win64/releasestatic/Traktor.Run.App rtl/Instructions.run verilog_decode > rtl/private/generated/Instructions_decode.sv
%TRAKTOR_HOME%/bin/win64/releasestatic/Traktor.Run.App rtl/Instructions.run verilog_decode_ops > rtl/private/generated/Instructions_decode_ops.sv
%TRAKTOR_HOME%/bin/win64/releasestatic/Traktor.Run.App rtl/Instructions.run verilog_execute_ops I J R U B S CSR > rtl/private/generated/Instructions_execute_ops.sv
%TRAKTOR_HOME%/bin/win64/releasestatic/Traktor.Run.App rtl/Instructions.run verilog_fpu > rtl/private/generated/Instructions_fpu.sv
