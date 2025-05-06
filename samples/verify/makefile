
ARCH=rv32imf
ABI=ilp32

C=riscv32-unknown-elf-gcc
C_FLAGS=-march=$(ARCH) -mabi=$(ABI) -mbranch-cost=8 -mstrict-align -fno-rtti -fno-exceptions -fpermissive -Wcast-align -Wno-multichar -Wno-shift-overflow -ffast-math -fdata-sections -ffunction-sections -Wl,--gc-sections -O3
LINK_FLAGS=-march=$(ARCH) -mabi=$(ABI) -Wl,-gc-sections

build/firmware/firmware.vmem : build/firmware/firmware.hex
	./Hex2Verilog -word=32 build/firmware/firmware.hex -vmem=firmware.vmem -vmem-range=firmware.vmem-range

build/firmware/firmware.hex : build/firmware/firmware
	riscv32-unknown-elf-objcopy -O ihex build/firmware/firmware $@

build/firmware/firmware : build/firmware/startup.o code/verify.ld
	$(C) $(LINK_FLAGS) -nostdlib build/firmware/startup.o -o $@ -Tcode/verify.ld
	riscv32-unknown-elf-objdump -D build/firmware/firmware > build/firmware/firmware.dump

build/firmware/startup.o : code/startup.s
	@mkdir -p build/firmware
	$(C) -c $(C_FLAGS) -nostdlib code/startup.s -o $@
