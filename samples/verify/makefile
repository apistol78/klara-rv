
include config.inc

build/firmware/firmware.vmem : build/firmware/firmware.hex
	./Hex2Verilog -word=32 build/firmware/firmware.hex -vmem=firmware.vmem -vmem-range=firmware.vmem-range

build/firmware/firmware.hex : build/firmware/firmware
	riscv32-unknown-elf-objcopy -O ihex build/firmware/firmware build/firmware/firmware.hex

build/firmware/firmware : build/firmware/startup.o
	$(C) $(LINK_FLAGS_RELEASE_EXECUTABLE) -nostdlib build/firmware/startup.o $(LINK_FLAG_OUTPUT) build/firmware/firmware -Tcode/verify.ld
	riscv32-unknown-elf-objdump -D build/firmware/firmware > firmware.dump

build/firmware/startup.o : code/startup.s
	@mkdir -p build/firmware
	$(C) -c $(CC_FLAGS_RELEASE_EXECUTABLE) -nostdlib code/startup.s $(CC_FLAG_OUTPUT) $@
