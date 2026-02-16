# Configuration file

#ARCH=rv32imf_zicsr
#ARCH=rv32im_zfinx_zicsr_zba_zbb
ARCH=rv32im_zfinx_zicsr_zba
#ARCH=rv32i_zicsr

ABI=ilp32

C=riscv32-unknown-elf-gcc
C_FLAGS_COMMON=-march=$(ARCH) -mabi=$(ABI) -mbranch-cost=8 -Wcast-align -ffast-math -fdata-sections -ffunction-sections -std=gnu18 -fno-pic
C_FLAGS_DEBUG_SHARED=$(C_FLAGS_COMMON) -g -O0
C_FLAGS_DEBUG_STATIC=$(C_FLAGS_COMMON) -g -O0
C_FLAGS_DEBUG_EXECUTABLE=$(C_FLAGS_COMMON) -g -O0
C_FLAGS_RELEASE_SHARED=$(C_FLAGS_COMMON) -O3
C_FLAGS_RELEASE_STATIC=$(C_FLAGS_COMMON) -O3
C_FLAGS_RELEASE_EXECUTABLE=$(C_FLAGS_COMMON) -O3
C_FLAG_OUTPUT=-o 

CC=riscv32-unknown-elf-g++
CC_FLAGS_COMMON=-march=$(ARCH) -mabi=$(ABI) -mbranch-cost=8 -fno-use-cxa-atexit -fno-rtti -fno-exceptions -fpermissive -Wcast-align -Wno-multichar -Wno-shift-overflow -ffast-math -fdata-sections -ffunction-sections -fno-pic
CC_FLAGS_DEBUG_SHARED=$(CC_FLAGS_COMMON) -g -O0
CC_FLAGS_DEBUG_STATIC=$(CC_FLAGS_COMMON) -g -O0
CC_FLAGS_DEBUG_EXECUTABLE=$(CC_FLAGS_COMMON) -g -O0
CC_FLAGS_RELEASE_SHARED=$(CC_FLAGS_COMMON) -O3
CC_FLAGS_RELEASE_STATIC=$(CC_FLAGS_COMMON) -O3
CC_FLAGS_RELEASE_EXECUTABLE=$(CC_FLAGS_COMMON) -O3
CC_FLAG_OUTPUT=-o 

AR=riscv32-unknown-elf-ar
AR_FLAGS_COMMON=-r -s
AR_FLAGS_DEBUG_STATIC=$(AR_FLAGS_COMMON)
AR_FLAGS_RELEASE_STATIC=$(AR_FLAGS_COMMON)
AR_FLAG_OUTPUT=

LINK=riscv32-unknown-elf-g++
LINK_FLAGS_COMMON=-march=$(ARCH) -mabi=$(ABI) -fno-use-cxa-atexit -fno-pic
LINK_FLAGS_DEBUG_SHARED=$(LINK_FLAGS_COMMON) -g -shared
LINK_FLAGS_DEBUG_STATIC=$(LINK_FLAGS_COMMON) -g
LINK_FLAGS_DEBUG_EXECUTABLE=$(LINK_FLAGS_COMMON) -g
LINK_FLAGS_RELEASE_SHARED=$(LINK_FLAGS_COMMON) -shared -Wl,-gc-sections
LINK_FLAGS_RELEASE_STATIC=$(LINK_FLAGS_COMMON) -Wl,-gc-sections
LINK_FLAGS_RELEASE_EXECUTABLE=$(LINK_FLAGS_COMMON) -Wl,-gc-sections
LINK_FLAG_OUTPUT=-o 
LINK_LIBS=

BINARY_INCLUDE=$(TRAKTOR_HOME)/bin/linux/releasestatic/Traktor.Run.App $(TRAKTOR_HOME)/scripts/binaryinclude/BinaryInclude.run
