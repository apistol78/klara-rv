
C=c++

C_FLAGS=-I$(VERILATOR_ROOT)/include
LINK_FLAGS=

verify : build/main.o
	$(C) $(LINK_FLAGS) build/main.o code/verilator/libVVerify.a code/verilator/libverilated.a -lz -o $@

build/main.o : code/main.cpp
	@mkdir -p build
	$(C) -c $(C_FLAGS) code/main.cpp -o $@

clean :
	@rm -Rf build