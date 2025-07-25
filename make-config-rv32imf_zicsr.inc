# Configuration file

OPTIMIZE=-O2
#OPTIMIZE=-Os
#OPTIMIZE=-O0
#ARCH=rv32imf_zicsr
ARCH=rv32im_zicsr
#ARCH=rv32i_zicsr

C=riscv32-unknown-elf-gcc
#C_FLAGS_COMMON=-march=$(ARCH) -mabi=ilp32 -mbranch-cost=8 -Wcast-align -fno-use-cxa-atexit -ffast-math -fdata-sections -ffunction-sections -Wl,--gc-sections
C_FLAGS_COMMON=-march=$(ARCH) -mabi=ilp32 -mbranch-cost=8 -Wcast-align -fno-use-cxa-atexit -fdata-sections -ffunction-sections -Wl,--gc-sections
C_FLAGS_DEBUG_SHARED=$(C_FLAGS_COMMON)
C_FLAGS_RELEASE_SHARED=$(C_FLAGS_COMMON) $(OPTIMIZE)
C_FLAGS_DEBUG_STATIC=$(C_FLAGS_COMMON)
C_FLAGS_RELEASE_STATIC=$(C_FLAGS_COMMON) $(OPTIMIZE)
C_FLAGS_DEBUG_EXECUTABLE=$(C_FLAGS_COMMON)
C_FLAGS_RELEASE_EXECUTABLE=$(C_FLAGS_COMMON) $(OPTIMIZE)
C_FLAG_OUTPUT=-o 

CC=riscv32-unknown-elf-g++
CC_FLAGS_COMMON=-march=$(ARCH) -mabi=ilp32 -mbranch-cost=8 -fno-use-cxa-atexit -fno-rtti -fno-exceptions -fpermissive -Wcast-align -Wno-multichar -Wno-shift-overflow -ffast-math -fdata-sections -ffunction-sections -Wl,--gc-sections
CC_FLAGS_DEBUG_SHARED=$(CC_FLAGS_COMMON)
CC_FLAGS_RELEASE_SHARED=$(CC_FLAGS_COMMON) $(OPTIMIZE)
CC_FLAGS_DEBUG_STATIC=$(CC_FLAGS_COMMON)
CC_FLAGS_RELEASE_STATIC=$(CC_FLAGS_COMMON) $(OPTIMIZE)
CC_FLAGS_DEBUG_EXECUTABLE=$(CC_FLAGS_COMMON)
CC_FLAGS_RELEASE_EXECUTABLE=$(CC_FLAGS_COMMON) $(OPTIMIZE)
CC_FLAG_OUTPUT=-o 

AR=riscv32-unknown-elf-ar
AR_FLAGS_COMMON=-r -s
AR_FLAGS_DEBUG_STATIC=$(AR_FLAGS_COMMON)
AR_FLAGS_RELEASE_STATIC=$(AR_FLAGS_COMMON)
AR_FLAG_OUTPUT=

LINK=riscv32-unknown-elf-g++
LINK_FLAGS_COMMON=-march=$(ARCH) -mabi=ilp32 -fno-use-cxa-atexit -Wl,-gc-sections
LINK_FLAGS_DEBUG_SHARED=$(LINK_FLAGS_COMMON) -g -shared -fsanitize=address
LINK_FLAGS_RELEASE_SHARED=$(LINK_FLAGS_COMMON) -shared 
LINK_FLAGS_DEBUG_STATIC=$(LINK_FLAGS_COMMON) -g -fsanitize=address
LINK_FLAGS_RELEASE_STATIC=$(LINK_FLAGS_COMMON)
LINK_FLAGS_DEBUG_EXECUTABLE=$(LINK_FLAGS_COMMON) -g -fsanitize=address
LINK_FLAGS_RELEASE_EXECUTABLE=$(LINK_FLAGS_COMMON)
LINK_FLAG_OUTPUT=-o 
LINK_LIBS=

BINARY_INCLUDE=$(TRAKTOR_HOME)/bin/linux/releasestatic/Traktor.Run.App $(TRAKTOR_HOME)/scripts/binaryinclude/BinaryInclude.run
