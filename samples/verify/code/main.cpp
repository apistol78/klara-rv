#include <random>
#include <stdio.h>
#include "verilated.h"
#include "verilated_fst_c.h"
#include "verilator/VVerify.h"
#include "verilator/VVerify___024root.h"

#define CHECK_FPU
#define ITERATIONS 10000

#define S0 8
#define S1 9
#define S2 18
#define S3 19
#define S4 20
#define S5 21
#define A0 10
#define A1 11
#define A2 12
#define A3 13
#define A4 14
#define A5 15
#define RA 1

VVerify* create_soc()
{
	VVerify* tb = new VVerify();
	tb->CLOCK_p = 0;
	tb->eval();

	// Fill rom with NOP since prefetch might read more instructions
	// than we evaluate.
	for (int32_t i = 0; i < 256; ++i)
		tb->rootp->Verify__DOT__rom__DOT__data[i] = 0x00000013;

	return tb;
}

void evaluate(VVerify* verify, const char* trace, int32_t steps)
{
	VerilatedFstC* tfp = nullptr;
	if (trace)
	{
		Verilated::traceEverOn(true);
		tfp = new VerilatedFstC;
		verify->trace(tfp, 99);  // Trace 99 levels of hierarchy
		tfp->open(trace);
	}

	auto tb = verify->rootp;
	assert(tb != nullptr); 

	int32_t time = 0;
	bool stuck = false;

	for (int32_t i = 0; !stuck && i < steps; ++i)
	{
		const uint32_t from = tb->Verify__DOT__cpu__DOT__writeback__DOT__retired;
		while (!stuck && tb->Verify__DOT__cpu__DOT__writeback__DOT__retired == from)
		{
			++time;
			
			verify->CLOCK_p = 1;
			verify->eval();

			if (tfp)
				tfp->dump(time);

			++time;
			verify->CLOCK_p = 0;
			verify->eval();

			if (tfp)
				tfp->dump(time);

			if (time > 10000)
			{
				printf("Unable to execute, seems stuck!\n");
				stuck = true;
			}
		}
	}

	verify->final();

	if (tfp)
	{
		tfp->close();
		delete tfp;
	}
}

std::random_device* s_randomDevice = new std::random_device();

// Randomize 32-bit signed integer.
int32_t rnd32()
{
	const uint32_t v = (*s_randomDevice)();
	return *(const int32_t*)&v;
}

// Randomize 32-bit unsigned integer.
uint32_t urnd32()
{
	return (*s_randomDevice)();
}

// Randomize float.
float rndf()
{
	for (;;)
	{
		const uint32_t v = urnd32();
		const float f = *(float*)&v;
		if (std::abs(f) > 1e+3f)
			continue;
		if (!std::isnan(f))
			return f;
	}
}

// Randomize normalized float (0-1).
float rndnf()
{
	const double f = (double)(*s_randomDevice)();
	const double nf = f / (*s_randomDevice).max();
	return (float)nf;
}

// Randomize 12-bit signed integer.
int32_t rnd12()
{
	const int32_t r = rnd32();
	int32_t v = (r & 0x7ff);

	if (rndnf() > 0.5f)
		v = -v;
		
	return v;
}

uint32_t patchImmediateI(uint32_t instruction, int32_t value)
{
	return (value << 20) | (instruction & 0xfffff);
}

//================================================

bool verify_ADD(const char* trace)
{
	int32_t s1 = rnd32();
	int32_t s2 = rnd32();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = s1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S2] = s2;
	tb->Verify__DOT__rom__DOT__data[0] = 0x01248433; // add	s0,s1,s2

	evaluate(verify, trace, 1);

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != (s1 + s2))
		return false;

	delete verify;
	return true;
}

bool verify_ADDI(const char* trace)
{
	int32_t s1 = rnd32();
	int32_t i1 = rnd12();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = s1;
	tb->Verify__DOT__rom__DOT__data[0] = patchImmediateI(0x00348413, i1); // addi	s0,s1,<imm>

	evaluate(verify, trace, 1);

	// printf("%d + %d = %d\n", s1, i1, s1 + i1);
	// printf("-- %d\n", tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0]);

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != (s1 + i1))
		return false;

	delete verify;
	return true;
}

bool verify_AND(const char* trace)
{
	int32_t s1 = rnd32();
	int32_t s2 = rnd32();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = s1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S2] = s2;
	tb->Verify__DOT__rom__DOT__data[0] = 0x0124f433; // and	s0,s1,s2

	evaluate(verify, trace, 1);

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != (s1 & s2))
		return false;

	delete verify;
	return true;
}

bool verify_ANDI(const char* trace)
{
	int32_t s1 = rnd32();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = s1;
	tb->Verify__DOT__rom__DOT__data[0] = 0x03f4f413; // andi	s0,s1,63

	evaluate(verify, trace, 1);

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != (s1 & 63))
		return false;

	delete verify;
	return true;
}

bool verify_AUIPC(const char* trace)
{
	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	tb->Verify__DOT__rom__DOT__data[0] = 0x0003f417; // auipc	s0,0x3f

	evaluate(verify, trace, 1);

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != (0x3f << 12))
		return false;

	delete verify;
	return true;
}

bool verify_BEQ(const char* trace)
{
	uint32_t a = urnd32() & 3;
	uint32_t b = urnd32() & 3;

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = a;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = b;
	tb->Verify__DOT__rom__DOT__data[0] = 0x00940663; // beq	s0,s1,c <jt>	0
	tb->Verify__DOT__rom__DOT__data[1] = 0x00100413; // li	s0,1			4
	tb->Verify__DOT__rom__DOT__data[2] = 0x0000006f; // jal zero, 0			8
	tb->Verify__DOT__rom__DOT__data[3] = 0x00200413; // li	s0,2			c
	tb->Verify__DOT__rom__DOT__data[4] = 0x0000006f; // jal zero, 0			10

	evaluate(verify, trace, 10);

	if (a == b)
	{
		if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != 2)
			return false;
	}
	else
	{
		if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != 1)
			return false;
	}

	delete verify;
	return true;
}

bool verify_BGE(const char* trace)
{
	int32_t a = (int32_t)(urnd32() & 15) - 7;
	int32_t b = (int32_t)(urnd32() & 15) - 7;

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = a;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = b;
	tb->Verify__DOT__rom__DOT__data[0] = 0x00945663; // bge	s0,s1,c <jt>	0
	tb->Verify__DOT__rom__DOT__data[1] = 0x00100413; // li	s0,1			4
	tb->Verify__DOT__rom__DOT__data[2] = 0x00000013; // nop					8
	tb->Verify__DOT__rom__DOT__data[3] = 0x00200413; // li	s0,2			c
	tb->Verify__DOT__rom__DOT__data[4] = 0x00000013; // nop					10

	evaluate(verify, trace, 3);

	// printf("%08x != %08x -> %d\n", a, b, tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0]);

	if (a >= b)
	{
		// if (tb->Verify__DOT__cpu__DOT__fetch_pc != 0x10)
		// 	return false;
		if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != 2)
			return false;
	}
	else
	{
		// if (tb->Verify__DOT__cpu__DOT__fetch_pc != 0x08)
		// 	return false;
		if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != 1)
			return false;
	}

	delete verify;
	return true;
}

bool verify_BGEU(const char* trace)
{
	uint32_t a = urnd32() & 15;
	uint32_t b = urnd32() & 15;

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = a;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = b;
	tb->Verify__DOT__rom__DOT__data[0] = 0x00947663; // bgeu	s0,s1,c <jt>	0
	tb->Verify__DOT__rom__DOT__data[1] = 0x00100413; // li	s0,1			4
	tb->Verify__DOT__rom__DOT__data[2] = 0x00000013; // nop					8
	tb->Verify__DOT__rom__DOT__data[3] = 0x00200413; // li	s0,2			c
	tb->Verify__DOT__rom__DOT__data[4] = 0x00000013; // nop					10

	evaluate(verify, trace, 3);

	// printf("%08x != %08x -> %d\n", a, b, tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0]);

	if (a >= b)
	{
		// if (tb->Verify__DOT__cpu__DOT__fetch_pc != 0x10)
		// 	return false;
		if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != 2)
			return false;
	}
	else
	{
		// if (tb->Verify__DOT__cpu__DOT__fetch_pc != 0x08)
		// 	return false;
		if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != 1)
			return false;
	}

	delete verify;
	return true;
}

bool verify_BLT(const char* trace)
{
	int32_t a = (int32_t)(urnd32() & 15) - 7;
	int32_t b = (int32_t)(urnd32() & 15) - 7;

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = a;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = b;
	tb->Verify__DOT__rom__DOT__data[0] = 0x00944663; // blt	s0,s1,c <jt>	0
	tb->Verify__DOT__rom__DOT__data[1] = 0x00100413; // li	s0,1			4
	tb->Verify__DOT__rom__DOT__data[2] = 0x00000013; // nop					8
	tb->Verify__DOT__rom__DOT__data[3] = 0x00200413; // li	s0,2			c
	tb->Verify__DOT__rom__DOT__data[4] = 0x00000013; // nop					10

	evaluate(verify, trace, 3);

	// printf("%08x != %08x -> %d\n", a, b, tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0]);

	if (a < b)
	{
		// if (tb->Verify__DOT__cpu__DOT__fetch_pc != 0x10)
		// 	return false;
		if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != 2)
			return false;
	}
	else
	{
		// if (tb->Verify__DOT__cpu__DOT__fetch_pc != 0x08)
		// 	return false;
		if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != 1)
			return false;
	}

	delete verify;
	return true;
}

bool verify_BLTU(const char* trace)
{
	uint32_t a = urnd32() & 15;
	uint32_t b = urnd32() & 15;

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = a;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = b;
	tb->Verify__DOT__rom__DOT__data[0] = 0x00946663; // bltu	s0,s1,c <jt>	0
	tb->Verify__DOT__rom__DOT__data[1] = 0x00100413; // li	s0,1			4
	tb->Verify__DOT__rom__DOT__data[2] = 0x00000013; // nop					8
	tb->Verify__DOT__rom__DOT__data[3] = 0x00200413; // li	s0,2			c
	tb->Verify__DOT__rom__DOT__data[4] = 0x00000013; // nop					10

	evaluate(verify, trace, 3);

	// printf("%08x != %08x -> %d\n", a, b, tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0]);

	if (a < b)
	{
		// if (tb->Verify__DOT__cpu__DOT__fetch_pc != 0x10)
		// 	return false;
		if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != 2)
			return false;
	}
	else
	{
		// if (tb->Verify__DOT__cpu__DOT__fetch_pc != 0x08)
		// 	return false;
		if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != 1)
			return false;
	}

	delete verify;
	return true;
}

bool verify_BNE(const char* trace)
{
	uint32_t a = urnd32() & 15;
	uint32_t b = urnd32() & 15;

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = a;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = b;
	tb->Verify__DOT__rom__DOT__data[0] = 0x00941663; // bne	s0,s1,c <jt>	0
	tb->Verify__DOT__rom__DOT__data[1] = 0x00100413; // li	s0,1			4
	tb->Verify__DOT__rom__DOT__data[2] = 0x00000013; // nop					8
	tb->Verify__DOT__rom__DOT__data[3] = 0x00200413; // li	s0,2			c
	tb->Verify__DOT__rom__DOT__data[4] = 0x00000013; // nop					10

	evaluate(verify, trace, 3);

	// printf("%08x != %08x -> %d\n", a, b, tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0]);

	if (a != b)
	{
		// if (tb->Verify__DOT__cpu__DOT__fetch_pc != 0x10)
		// 	return false;
		if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != 2)
			return false;
	}
	else
	{
		// if (tb->Verify__DOT__cpu__DOT__fetch_pc != 0x08)
		// 	return false;
		if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != 1)
			return false;
	}

	delete verify;
	return true;
}

bool verify_DIV(const char* trace)
{
	int32_t s1 = rnd32();
	int32_t s2 = rnd32();
	while (s2 == 0) s2 = rnd32();

	int32_t s4 = rnd32();
	int32_t s5 = rnd32();
	while (s5 == 0) s5 = rnd32();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = s1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S2] = s2;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S3] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S4] = s4;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S5] = s5;

	tb->Verify__DOT__rom__DOT__data[0] = 0x0324c433; // div	s0,s1,s2
	tb->Verify__DOT__rom__DOT__data[1] = 0x035a49b3; // div	s3,s4,s5

	evaluate(verify, trace, 10);

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != (s1 / s2))
		return false;
	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S3] != (s4 / s5))
		return false;

	delete verify;
	return true;
}

bool verify_UDIV(const char* trace)
{
	uint32_t s1 = urnd32();
	uint32_t s2 = urnd32();
	while (s2 == 0) s2 = rnd32();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = s1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S2] = s2;
	tb->Verify__DOT__rom__DOT__data[0] = 0x0324d433; // divu	s0,s1,s2

	evaluate(verify, trace, 1);

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != (s1 / s2))
		return false;

	delete verify;
	return true;
}

bool verify_JAL(const char* trace)
{
	return true;
}

bool verify_JALR(const char* trace)
{
	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	tb->Verify__DOT__rom__DOT__data[0] = 0x00c00413;	// li	s0,12	0
	tb->Verify__DOT__rom__DOT__data[1] = 0x000400e7;	// jalr	s0		4
	tb->Verify__DOT__rom__DOT__data[2] = 0x00100493;	// li	s1,1	8
	tb->Verify__DOT__rom__DOT__data[3] = 0x00200493;	// li	s1,2	12

	evaluate(verify, trace, 10);

	// printf("RA %08x\n", tb->Verify__DOT__cpu__DOT__registers__DOT__r[RA]);
	// printf("S1 %08x\n", tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1]);
	// printf("PC %08x\n", tb->Verify__DOT__cpu__DOT__fetch__DOT__pc);

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[RA] != 0x00000008)
		return false;	

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] != 2)
		return false;	

	// if (tb->Verify__DOT__cpu__DOT__fetch__DOT__pc != 0x00000010)
	// 	return false;	

	delete verify;
	return true;
}

bool verify_LB(const char* trace)
{
	for (int i = 0; i < 4; ++i)
	{
		uint8_t v = urnd32() & 255;
		int32_t r = (int32_t)((int8_t)v);

		auto verify = create_soc();
		auto tb = verify->rootp;

		tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
		tb->Verify__DOT__rom__DOT__data[0] = 0x00400403 + (i << 20); // lb	s0,4(zero) # 4
		tb->Verify__DOT__rom__DOT__data[1] = ((uint32_t)v) << (i * 8);

		evaluate(verify, trace, 1);

		// printf("%d. %d\n", i, tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0]);

		if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != r)
			return false;

		delete verify;
	}

	return true;	
}

bool verify_LBU(const char* trace)
{
	for (int i = 0; i < 4; ++i)
	{
		uint8_t v = urnd32() & 255;
		uint32_t r = (uint32_t)v;

		auto verify = create_soc();
		auto tb = verify->rootp;

		tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
		tb->Verify__DOT__rom__DOT__data[0] = 0x00404403 + (i << 20); // lbu	s0,4(zero) # 4
		tb->Verify__DOT__rom__DOT__data[1] = ((uint32_t)v) << (i * 8);

		evaluate(verify, trace, 1);

		if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != r)
			return false;

		delete verify;
	}

	return true;
}

bool verify_LH(const char* trace)
{
	for (int i = 0; i < 2; ++i)
	{
		uint16_t v = (uint16_t)urnd32();
		int32_t r = (int32_t)((int16_t)v);

		auto verify = create_soc();
		auto tb = verify->rootp;

		tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
		tb->Verify__DOT__rom__DOT__data[0] = 0x00401403 + ((i * 2) << 20); // lh	s0,4(zero) # 4
		tb->Verify__DOT__rom__DOT__data[1] = ((uint32_t)v) << (i * 16);

		evaluate(verify, trace, 1);

		if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != r)
			return false;

		delete verify;
	}

	return true;
}

bool verify_LHU(const char* trace)
{
	for (int i = 0; i < 2; ++i)
	{
		uint16_t v = (uint16_t)urnd32();
		uint32_t r = (uint32_t)v;

		auto verify = create_soc();
		auto tb = verify->rootp;

		tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
		tb->Verify__DOT__rom__DOT__data[0] = 0x00405403 + ((i * 2) << 20); // lhu	s0,4(zero) # 4
		tb->Verify__DOT__rom__DOT__data[1] = ((uint32_t)v) << (i * 16);

		evaluate(verify, trace, 1);

		if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != r)
			return false;

		delete verify;
	}

	return true;
}

bool verify_LUI(const char* trace)
{
	int32_t s1 = rnd32();
	int32_t s2 = rnd32();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	tb->Verify__DOT__rom__DOT__data[0] = 0x008ff437; // lui	s0,0x8ff

	evaluate(verify, trace, 1);

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != 0x08ff000)
		return false;

	delete verify;
	return true;
}

bool verify_LW(const char* trace)
{
	return true;
}

bool verify_MUL(const char* trace)
{
	const int32_t s1 = rnd32();
	const int32_t s2 = rnd32();
	const int32_t s4 = rnd32();
	const int32_t s5 = rnd32();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = s1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S2] = s2;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S3] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S4] = s4;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S5] = s5;

	tb->Verify__DOT__rom__DOT__data[0] = 0x03248433; // mul	s0,s1,s2
	tb->Verify__DOT__rom__DOT__data[1] = 0x035a09b3; // mul	s3,s4,s5

	evaluate(verify, trace, 10);

	// printf("MUL, %d * %d = %d (%d)\n",
	// 	s1,
	// 	s2,
	// 	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0],
	// 	(int32_t)(s1 * s2)
	// );

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != (s1 * s2))
		return false;
	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S3] != (s4 * s5))
		return false;

	delete verify;
	return true;
}

bool verify_MULH(const char* trace)
{
	int32_t s1 = rnd32();
	int32_t s2 = rnd32();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = s1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S2] = s2;
	tb->Verify__DOT__rom__DOT__data[0] = 0x03249433; // mul	s0,s1,s2

	evaluate(verify, trace, 1);

	int32_t r = (int32_t)(((int64_t)s1 * (int64_t)s2) >> 32);

	// printf("MULH, %d * %d = %d (%d)\n",
	// 	s1,
	// 	s2,
	// 	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0],
	// 	r
	// );

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != r)
		return false;

	delete verify;
	return true;
}

bool verify_MULHU(const char* trace)
{
	uint32_t s1 = urnd32();
	uint32_t s2 = urnd32();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = s1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S2] = s2;
	tb->Verify__DOT__rom__DOT__data[0] = 0x0324b433; // mulhu	s0,s1,s2

	evaluate(verify, trace, 1);

	uint32_t r = (uint32_t)(((uint64_t)s1 * (uint64_t)s2) >> 32);

	// printf("MULHU, %d * %d = %d (%d)\n",
	// 	s1,
	// 	s2,
	// 	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0],
	// 	r
	// );

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != r)
		return false;

	delete verify;
	return true;
}

bool verify_OR(const char* trace)
{
	int32_t s1 = rnd32();
	int32_t s2 = rnd32();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = s1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S2] = s2;
	tb->Verify__DOT__rom__DOT__data[0] = 0x0124e433; // or	s0,s1,s2

	evaluate(verify, trace, 1);

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != (s1 | s2))
		return false;

	delete verify;
	return true;
}

bool verify_ORI(const char* trace)
{
	int32_t s1 = rnd32();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = s1;
	tb->Verify__DOT__rom__DOT__data[0] = 0x03f4e413; // ori	s0,s1,63

	evaluate(verify, trace, 1);

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != (s1 | 63))
		return false;

	delete verify;
	return true;
}

bool verify_REM(const char* trace)
{
	int32_t s1 = rnd32();
	int32_t s2 = rnd32();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = s1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S2] = s2;
	tb->Verify__DOT__rom__DOT__data[0] = 0x0324e433; // rem	s0,s1,s2

	evaluate(verify, trace, 1);

	// printf("REM, %d %% %d = %d (%d)\n",
	// 	s1,
	// 	s2,
	// 	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0],
	// 	s1 % s2
	// );

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != (s1 % s2))
		return false;

	delete verify;
	return true;
}

bool verify_REMU(const char* trace)
{
	uint32_t s1 = urnd32();
	uint32_t s2 = urnd32();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = s1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S2] = s2;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[A0] = s2;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[A5] = s1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[A4] = s1;

	tb->Verify__DOT__rom__DOT__data[0] = 0x0324f433; // remu	s0,s1,s2
	tb->Verify__DOT__rom__DOT__data[1] = 0x02a7f7b3; // remu	a5,a5,a0
	tb->Verify__DOT__rom__DOT__data[2] = 0x02a7f733; // remu	a4,a5,a0

	evaluate(verify, trace, 10);

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != (s1 % s2))
		return false;
	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[A5] != (s1 % s2))
		return false;
	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[A4] != (s1 % s2))
		return false;

	delete verify;
	return true;
}

bool verify_REMU2(const char* trace)
{
	uint32_t a0 = urnd32() & 127;
	while (a0 == 0) a0 = urnd32() & 127;

	uint32_t a3 = urnd32();
	uint32_t a5 = urnd32();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[A0] = a0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[A3] = a3;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[A5] = a5;

	tb->Verify__DOT__rom__DOT__data[0] = 0x00d7c7b3; // xor		a5,a5,a3
	tb->Verify__DOT__rom__DOT__data[1] = 0x02a7f7b3; // remu	a5,a5,a0
	tb->Verify__DOT__rom__DOT__data[2] = 0x00279793; // slli	a5,a5,0x2

	evaluate(verify, trace, 10);

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[A5] != (((a5 ^ a3) % a0) << 2))
		return false;

	delete verify;
	return true;
}

bool verify_SB(const char* trace)
{
	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__ram__DOT__data[0] = 0x00000000;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = 0x12;
	tb->Verify__DOT__rom__DOT__data[0] = 0x10000437; // lui	s0,0x10000
	tb->Verify__DOT__rom__DOT__data[1] = 0x00240413; // addi	s0,s0,2 # 10000002 
	tb->Verify__DOT__rom__DOT__data[2] = 0xfe940fa3; // sb		s1,-1(s0)
	tb->Verify__DOT__rom__DOT__data[3] = 0x0ff0000f; // fence

	evaluate(verify, trace, 4);

	//printf("%08x\n", tb->Verify__DOT__ram__DOT__data[0]);

	if (tb->Verify__DOT__ram__DOT__data[0] != 0x00001200)
		return false;

	delete verify;
	return true;
}

bool verify_SH(const char* trace)
{
	return true;
}

bool verify_SLL(const char* trace)
{
	uint32_t s1 = rnd32();
	uint32_t s2 = rnd32();
	uint32_t r = s1 << (s2 & 0x1f);

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = s1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S2] = s2;
	tb->Verify__DOT__rom__DOT__data[0] = 0x01249433; // sll	s0,s1,s2

	evaluate(verify, trace, 1);

	// printf("%08x << (%08x, %u) = %08x\n", s1, s2, (s2 & 0x1f), r);
	// printf("CPU %08x\n", tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0]);

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != r)
		return false;

	delete verify;
	return true;
}

bool verify_SLLI(const char* trace)
{
	int32_t s1 = rnd32();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = s1;
	tb->Verify__DOT__rom__DOT__data[0] = 0x00549413; // slli	s0,s1,0x5

	evaluate(verify, trace, 1);

	// printf("%d -- %d\n", s1 << 5,
	// tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0]);

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != (s1 << 5))
		return false;

	delete verify;
	return true;
}

bool verify_SLT(const char* trace)
{
	int32_t s1 = rnd32();
	int32_t s2 = rnd32();
	int32_t r = (s1 < s2) ? 1 : 0;

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = s1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S2] = s2;
	tb->Verify__DOT__rom__DOT__data[0] = 0x0124a433; // slt	s0,s1,s2

	evaluate(verify, trace, 1);

	// printf("%d < %d = %d\n", s1, s2, r);
	// printf("%d\n", tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0]);

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != r)
		return false;

	delete verify;
	return true;
}

bool verify_SLTI(const char* trace)
{
	int32_t s1 = rnd32();
	int32_t r = (s1 < 5) ? 1 : 0;

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = s1;
	tb->Verify__DOT__rom__DOT__data[0] = 0x0054a413; // slti	s0,s1,5

	evaluate(verify, trace, 1);

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != r)
		return false;

	delete verify;
	return true;
}

bool verify_SLTIU(const char* trace)
{
	uint32_t s1 = urnd32();
	uint32_t r = (s1 < 5) ? 1 : 0;

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = s1;
	tb->Verify__DOT__rom__DOT__data[0] = 0x0054b413; // sltiu	s0,s1,5

	evaluate(verify, trace, 1);

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != r)
		return false;

	delete verify;
	return true;
}

bool verify_SLTU(const char* trace)
{
	uint32_t s1 = rnd32();
	uint32_t s2 = rnd32();
	uint32_t r = (s1 < s2) ? 1 : 0;

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = s1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S2] = s2;
	tb->Verify__DOT__rom__DOT__data[0] = 0x0124b433; // sltu	s0,s1,s2

	evaluate(verify, trace, 1);

	// printf("%d < %d = %d\n", s1, s2, r);
	// printf("%d\n", tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0]);

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != r)
		return false;

	delete verify;
	return true;
}

bool verify_SRA(const char* trace)
{
	int32_t s1 = rnd32();
	int32_t s2 = rnd32();
	int32_t r = s1 >> (s2 & 0x1f);

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = s1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S2] = s2;
	tb->Verify__DOT__rom__DOT__data[0] = 0x4124d433; // sra	s0,s1,s2

	evaluate(verify, trace, 1);

	// printf("%d >> (%d, %u) = %d\n", s1, s2, (s2 & 0x1f), r);
	// printf("CPU %d\n", tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0]);

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != r)
		return false;

	delete verify;
	return true;
}

bool verify_SRAI(const char* trace)
{
	int32_t s1 = rnd32();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = s1;
	tb->Verify__DOT__rom__DOT__data[0] = 0x4054d413; // srai	s0,s1,0x5

	evaluate(verify, trace, 1);

	// printf("%d -- %d\n", s1 << 5,
	// tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0]);

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != (s1 >> 5))
		return false;

	delete verify;
	return true;
}

bool verify_SRL(const char* trace)
{
	uint32_t s1 = rnd32();
	uint32_t s2 = rnd32();
	uint32_t r = s1 >> (s2 & 0x1f);

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = s1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S2] = s2;
	tb->Verify__DOT__rom__DOT__data[0] = 0x0124d433; // srl	s0,s1,s2

	evaluate(verify, trace, 1);

	// printf("%d >> (%d, %u) = %d\n", s1, s2, (s2 & 0x1f), r);
	// printf("CPU %d\n", tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0]);

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != r)
		return false;

	delete verify;
	return true;
}

bool verify_SRLI(const char* trace)
{
	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[A2] = 0x99999998;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[A2] = 0x99999998;
	tb->Verify__DOT__rom__DOT__data[0] = 0x00165613; // srli	a2,a2,0x1

	evaluate(verify, trace, 1);

	// printf("%08x\n", tb->Verify__DOT__cpu__DOT__registers__DOT__r[A2]);

	// printf("%d -- %d\n", s1 << 5,
	// tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0]);

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[A2] != (0x99999998 >> 1))
		return false;

	delete verify;

/*
	uint32_t s1 = rnd32();

	auto tb = create_soc();
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = s1;
	tb->Verify__DOT__rom__DOT__data[0] = 0x0054d413; // srli	s0,s1,0x5

	evaluate(verify, trace, 1);

	// printf("%d -- %d\n", s1 << 5,
	// tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0]);

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != (s1 >> 5))
		return false;

	delete verify;
*/
	return true;
}

bool verify_SUB(const char* trace)
{
	int32_t s1 = rnd32();
	int32_t s2 = rnd32();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = s1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S2] = s2;
	tb->Verify__DOT__rom__DOT__data[0] = 0x41248433; // sub	s0,s1,s2

	evaluate(verify, trace, 1);

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != (s1 - s2))
		return false;

	delete verify;
	return true;
}

bool verify_SW(const char* trace)
{
	return true;
}

bool verify_XOR(const char* trace)
{
	uint32_t s1 = urnd32();
	uint32_t s2 = urnd32();

	auto verify = create_soc();
	auto tb = verify->rootp;

	// tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	// tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = s1;
	// tb->Verify__DOT__cpu__DOT__registers__DOT__r[S2] = s2;
	// tb->Verify__DOT__rom__DOT__data[0] = 0x0124c433; // xor	s0,s1,s2

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[A3] = s2;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[A5] = s1;
	tb->Verify__DOT__rom__DOT__data[0] = 0x00d7c7b3; // xor	a5,a5,a3

	evaluate(verify, trace, 1);

	// if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != (s1 ^ s2))
	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[A5] != (s1 ^ s2))
		return false;

	delete verify;
	return true;
}

bool verify_XORI(const char* trace)
{
	uint32_t s1 = urnd32();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = s1;
	tb->Verify__DOT__rom__DOT__data[0] = 0x03f4c413; // xori	s0,s1,63

	evaluate(verify, trace, 1);

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != (s1 ^ 63))
		return false;

	delete verify;
	return true;
}

bool verify_ENDIAN(const char* trace)
{
	{
		auto verify = create_soc();
		auto tb = verify->rootp;

		tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
		tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = 0;
		tb->Verify__DOT__cpu__DOT__registers__DOT__r[S2] = 0;
		tb->Verify__DOT__cpu__DOT__registers__DOT__r[S3] = 0;

		tb->Verify__DOT__rom__DOT__data[0] = 0x100002b7; // lui	t0,0x10000
		tb->Verify__DOT__rom__DOT__data[1] = 0x11223437; // lui	s0,0x11223
		tb->Verify__DOT__rom__DOT__data[2] = 0x34440413;	// addi	s0,s0,836 # 11223344
		tb->Verify__DOT__rom__DOT__data[3] = 0x0082a023;	// sw	s0,0(t0) # 0
		tb->Verify__DOT__rom__DOT__data[4] = 0x00028403;	// lb	s0,0(t0) # 0
		tb->Verify__DOT__rom__DOT__data[5] = 0x00128483;	// lb	s1,1(t0) # 0
		tb->Verify__DOT__rom__DOT__data[6] = 0x00228903;	// lb	s2,2(t0) # 0
		tb->Verify__DOT__rom__DOT__data[7] = 0x00328983;	// lb	s3,3(t0) # 0

		evaluate(verify, trace, 8);

		// printf("S0 %08x\n", tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0]);
		// printf("S1 %08x\n", tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1]);
		// printf("S2 %08x\n", tb->Verify__DOT__cpu__DOT__registers__DOT__r[S2]);
		// printf("S3 %08x\n", tb->Verify__DOT__cpu__DOT__registers__DOT__r[S3]);

		if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != 0x44)
			return false;
		if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] != 0x33)
			return false;
		if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S2] != 0x22)
			return false;
		if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S3] != 0x11)
			return false;

		delete verify;
	}

	return true;
}

bool verify_MEM_LOAD_HAZARD(const char* trace)
{
	{
		auto verify = create_soc();
		auto tb = verify->rootp;

		tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
		tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = 0;
		tb->Verify__DOT__cpu__DOT__registers__DOT__r[S2] = 0;
		tb->Verify__DOT__cpu__DOT__registers__DOT__r[S3] = 0;

		tb->Verify__DOT__rom__DOT__data[0] = 0x100007b7; // lui	a5,0x10000
		tb->Verify__DOT__rom__DOT__data[1] = 0x0007a783; // lw		a5,0(a5) # 10000000 <_edata+0x1fff0000>
		tb->Verify__DOT__rom__DOT__data[2] = 0x00078413; // mv		s0,a5
		tb->Verify__DOT__rom__DOT__data[3] = 0x00008067; // j		0

		tb->Verify__DOT__ram__DOT__data[0] = 0xcafebabe;

		evaluate(verify, trace, 7);

		// printf("S0 %08x\n", tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0]);

		if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != 0xcafebabe)
			return false;

		delete verify;
	}

	return true;
}

bool verify_PIPELINE(const char* trace)
{
	{
		auto verify = create_soc();
		auto tb = verify->rootp;

		tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;

		tb->Verify__DOT__rom__DOT__data[0] = 0x00100413; // li		s0,1
		tb->Verify__DOT__rom__DOT__data[1] = 0x00840433; // add	s0,s0,s0	2=1+1
		tb->Verify__DOT__rom__DOT__data[2] = 0x00840433; // add	s0,s0,s0	4=2+2
		tb->Verify__DOT__rom__DOT__data[3] = 0x00840433; // add	s0,s0,s0	8=4+4
		tb->Verify__DOT__rom__DOT__data[4] = 0x00840433; // add	s0,s0,s0	16=8+8
		tb->Verify__DOT__rom__DOT__data[5] = 0x00840433; // add	s0,s0,s0	32=16+16
		tb->Verify__DOT__rom__DOT__data[6] = 0x00008067; // j		0

		evaluate(verify, trace, 7 + 6 + 6 + 6);

		//printf("S0 %08x\n", tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0]);

		// if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != 0x11111111)
		// 	return false;

		delete verify;
	}

	return true;
}

bool verify_PIPELINE_MEMORY(const char* trace)
{
	{
		auto verify = create_soc();
		auto tb = verify->rootp;

		tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
		tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = 0;
		tb->Verify__DOT__cpu__DOT__registers__DOT__r[S2] = 0;
		tb->Verify__DOT__cpu__DOT__registers__DOT__r[S3] = 0;

		tb->Verify__DOT__rom__DOT__data[0] = 0x100007b7; // lui	a5,0x10000
		tb->Verify__DOT__rom__DOT__data[1] = 0x0007a403; // lw		s0,0(a5) # 10000000 <_edata+0x1fff0000>
		tb->Verify__DOT__rom__DOT__data[2] = 0x0087a223; // sw		s0,4(a5)
		tb->Verify__DOT__rom__DOT__data[3] = 0x0047a403; // lw		s0,4(a5)
		tb->Verify__DOT__rom__DOT__data[4] = 0x0087a423; // sw		s0,8(a5)
		tb->Verify__DOT__rom__DOT__data[5] = 0x0087a403; // lw		s0,8(a5)
		tb->Verify__DOT__rom__DOT__data[6] = 0x0087a623; // sw		s0,12(a5)
		tb->Verify__DOT__rom__DOT__data[7] = 0x00c7a403; // lw		s0,12(a5)
		tb->Verify__DOT__rom__DOT__data[8] = 0xfe1ff06f; // j		0

		tb->Verify__DOT__ram__DOT__data[0] = 0x11111111;
		tb->Verify__DOT__ram__DOT__data[1] = 0x22222222;
		tb->Verify__DOT__ram__DOT__data[2] = 0x33333333;
		tb->Verify__DOT__ram__DOT__data[3] = 0x44444444;

		evaluate(verify, trace, 8);

		//printf("S0 %08x\n", tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0]);

		if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != 0x11111111)
			return false;

		delete verify;
	}

	return true;
}

bool verify_PIPELINE_MEMORY_B(const char* trace)
{
	{
		auto verify = create_soc();
		auto tb = verify->rootp;

		tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
		tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = 0;
		tb->Verify__DOT__cpu__DOT__registers__DOT__r[S2] = 0;
		tb->Verify__DOT__cpu__DOT__registers__DOT__r[S3] = 0;

		tb->Verify__DOT__rom__DOT__data[0] = 0x100007b7; // lui	a5,0x10000
		tb->Verify__DOT__rom__DOT__data[1] = 0x00078403; // lb		s0,0(a5) # 10000000 <_edata+0x1fff0000>
		tb->Verify__DOT__rom__DOT__data[2] = 0x008780a3; // sb		s0,1(a5)
		tb->Verify__DOT__rom__DOT__data[3] = 0x00178403; // lb		s0,1(a5)
		tb->Verify__DOT__rom__DOT__data[4] = 0x00878123; // sb		s0,2(a5)
		tb->Verify__DOT__rom__DOT__data[5] = 0x00278403; // lb		s0,2(a5)
		tb->Verify__DOT__rom__DOT__data[6] = 0x008781a3; // sb		s0,3(a5)
		tb->Verify__DOT__rom__DOT__data[7] = 0x00378403; // lb		s0,3(a5)
		tb->Verify__DOT__rom__DOT__data[8] = 0xfe1ff06f; // j		0

		tb->Verify__DOT__ram__DOT__data[0] = 0x00000011;
		tb->Verify__DOT__ram__DOT__data[1] = 0x22222222;
		tb->Verify__DOT__ram__DOT__data[2] = 0x33333333;
		tb->Verify__DOT__ram__DOT__data[3] = 0x44444444;

		evaluate(verify, trace, 8);

		//printf("S0 %08x\n", tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0]);
		//printf("D[0] %08x\n", tb->Verify__DOT__ram__DOT__data[0]);

		if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != 0x00000011)
			return false;
		// if (tb->Verify__DOT__ram__DOT__data[0] != 0x11111111)
		// 	return false;

		delete verify;
	}

	return true;
}

#if defined(CHECK_FPU)

//#define FPR(n) (n + 32)
#define FPR(n) (n)	// zfinx

bool verify_FADD(const char* trace)
{
	const float v1 = rndf();
	const float v2 = rndf();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S0)] = *(uint32_t*)&v1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S1)] = *(uint32_t*)&v2;
	tb->Verify__DOT__rom__DOT__data[0] = 0x0084f953; // fadd.s	f18,f9,f8

	evaluate(verify, trace, 1);

	uint32_t r = tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S2)];
	if (*(float*)&r != (v1 + v2))
		return false;

	delete verify;
	return true;
}

bool verify_FSUB(const char* trace)
{
	const float v1 = rndf();
	const float v2 = rndf();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S0)] = *(uint32_t*)&v1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S1)] = *(uint32_t*)&v2;
	tb->Verify__DOT__rom__DOT__data[0] = 0x0884f953; // fsub.s	f18,f9,f8

	evaluate(verify, trace, 1);

	const uint32_t r = tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S2)];
	
	printf("v1 = %f (%08x)\n", v1, *((uint32_t*)&v1));
	printf("v2 = %f (%08x)\n", v2, *((uint32_t*)&v2));
	printf("dot %f, ref %f\n", *(float*)&r, v2 - v1);

	if (*(float*)&r != (v2 - v1))
		return false;

	delete verify;
	return true;
}

bool verify_FMUL(const char* trace)
{
	const float v1 = rndf();
	const float v2 = rndf();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S0)] = *(uint32_t*)&v1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S1)] = *(uint32_t*)&v2;
	tb->Verify__DOT__rom__DOT__data[0] = 0x1084f953; // fmul.s	f18,f9,f8

	evaluate(verify, trace, 1);

	const uint32_t r = tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S2)];
	
	// printf("%f * %f = %f\n", v1, v2, *(float*)&r);

	if (*(float*)&r != (v2 * v1))
		return false;

	delete verify;
	return true;
}

bool verify_FDIV(const char* trace)
{
	const float v1 = rndf();
	const float v2 = rndf();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S0)] = *(uint32_t*)&v1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S1)] = *(uint32_t*)&v2;
	tb->Verify__DOT__rom__DOT__data[0] = 0x1884f953; // fdiv.s	f18,f9,f8

	evaluate(verify, trace, 1);

	const uint32_t r = tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S2)];
	
	printf("%f\n", *(float*)&r);

	if (*(float*)&r != (v2 / v1))
		return false;

	delete verify;
	return true;
}

bool verify_FCVT(const char* trace)
{
	const float v1 = rndf();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S0)] = *(uint32_t*)&v1;
	tb->Verify__DOT__rom__DOT__data[0] = 0xc0007453; // fcvt.w.s	s0,ft0

	evaluate(verify, trace, 1);

	const int32_t r = tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0];
	
	//printf("%f => %d\n", v1, r);

	if (r != (int32_t)v1)
		return false;

	delete verify;
	return true;
}

bool verify_FLW(const char* trace)
{
	const float v1 = rndf();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__ram__DOT__data[0] = *(uint32_t*)&v1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0x10000000;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S0)] = 0;
	tb->Verify__DOT__rom__DOT__data[0] = 0x00042007; // flw	ft0,0(s0)

	evaluate(verify, trace, 1);

	const uint32_t r = tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S0)];
	
	//printf("%f => %d\n", v1, r);

	if (*(float*)&r != v1)
		return false;

	delete verify;
	return true;
}

bool verify_FSW(const char* trace)
{
	const float v1 = rndf();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__ram__DOT__data[0] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0x10000000;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S0)] = *(uint32_t*)&v1;
	tb->Verify__DOT__rom__DOT__data[0] = 0x00042027; // fsw	ft0,0(s0)

	evaluate(verify, trace, 1);

	const uint32_t r = tb->Verify__DOT__ram__DOT__data[0];
	
	//printf("%f => %d\n", v1, r);

	if (*(float*)&r != v1)
		return false;

	delete verify;
	return true;
}

bool verify_FMV_X_W(const char* trace)
{
	const float v1 = rndf();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S0)] = *(uint32_t*)&v1;
	tb->Verify__DOT__rom__DOT__data[0] = 0xe0000453; // fmv.x.w	s0,ft0

	evaluate(verify, trace, 1);

	const uint32_t r = tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0];
	
	//printf("%f => %d\n", v1, r);

	if (r != *(uint32_t*)&v1)
		return false;

	delete verify;
	return true;
}

bool verify_FMV_W_X(const char* trace)
{
	const uint32_t v1 = urnd32();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = v1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S0)] = 0;
	tb->Verify__DOT__rom__DOT__data[0] = 0xf0040053; // fmv.w.x	ft0,s0

	evaluate(verify, trace, 1);

	const uint32_t r = tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S0)];
	
	//printf("%f => %d\n", v1, r);

	if (r != v1)
		return false;

	delete verify;
	return true;
}

bool verify_FEQ(const char* trace)
{
	const float v1 = 1.234f;
	const float v2 = 1.234f;
	const float v3 = -1.234f;

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = ~0U;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S0)] = *(uint32_t*)&v1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S1)] = *(uint32_t*)&v2;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S2)] = *(uint32_t*)&v3;
	tb->Verify__DOT__rom__DOT__data[0] = 0xa0102453; // feq.s	s0,ft0,ft1
	tb->Verify__DOT__rom__DOT__data[1] = 0xa02024d3; // feq.s	feq.s	s1,ft0,ft2

	evaluate(verify, trace, 2);

	//printf("%f => %d\n", v1, r);

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != 1)
		return false;
	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] != 0)
		return false;

	delete verify;
	return true;
}

bool verify_FLT(const char* trace)
{
	const float v1 = 1.234f;
	const float v2 = 1.234f;
	const float v3 = -1.234f;

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = ~0U;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S2] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S0)] = *(uint32_t*)&v1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S1)] = *(uint32_t*)&v2;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S2)] = *(uint32_t*)&v3;
	tb->Verify__DOT__rom__DOT__data[0] = 0xa0101453; // flt.s	s0,ft0,ft1
	tb->Verify__DOT__rom__DOT__data[1] = 0xa02014d3; // flt.s	s1,ft0,ft2
	tb->Verify__DOT__rom__DOT__data[2] = 0xa0011953; // flt.s	s2,ft2,ft0

	evaluate(verify, trace, 3);

	//printf("%d\n", tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0]);
	//printf("%d\n", tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1]);
	//printf("%d\n", tb->Verify__DOT__cpu__DOT__registers__DOT__r[S2]);

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != 0)
		return false;
	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] != 0)
		return false;
	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S2] != 1)
		return false;

	delete verify;
	return true;
}

bool verify_FMADD(const char* trace)
{
	const float v1 = rndf();
	const float v2 = rndf();
	const float v3 = rndf();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S0)] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S1)] = *(uint32_t*)&v1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S2)] = *(uint32_t*)&v2;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[35] = *(uint32_t*)&v3;
	tb->Verify__DOT__rom__DOT__data[0] = 0x1820f043; // fmadd.s	ft0,ft1,ft2,ft3

	evaluate(verify, trace, 1);

	const uint32_t r = tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S0)];
	//printf("%f * %f = %f\n", v1, v2, *(float*)&r);

	if (*(float*)&r != (v1 * v2 + v3))
		return false;

	delete verify;
	return true;
}

bool verify_FMSUB(const char* trace)
{
	const float v1 = rndf();
	const float v2 = rndf();
	const float v3 = rndf();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S0)] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S1)] = *(uint32_t*)&v1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S2)] = *(uint32_t*)&v2;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[35] = *(uint32_t*)&v3;
	tb->Verify__DOT__rom__DOT__data[0] = 0x1820f047; // fmsub.s	ft0,ft1,ft2,ft3

	evaluate(verify, trace, 1);

	const uint32_t r = tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S0)];
	//printf("%f * %f - %f = %f\n", v1, v2, v3, *(float*)&r);

	if (*(float*)&r != (v1 * v2 - v3))
		return false;

	delete verify;
	return true;
}

bool verify_FNMADD(const char* trace)
{
	const float v1 = rndf();
	const float v2 = rndf();
	const float v3 = rndf();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S0)] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S1)] = *(uint32_t*)&v1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S2)] = *(uint32_t*)&v2;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[35] = *(uint32_t*)&v3;
	tb->Verify__DOT__rom__DOT__data[0] = 0x1820f04f; // fnmadd.s	ft0,ft1,ft2,ft3

	evaluate(verify, trace, 1);

	const uint32_t r = tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S0)];
	//printf("%f * %f = %f\n", v1, v2, *(float*)&r);

	if (*(float*)&r != -(v1 * v2 + v3))
		return false;

	delete verify;
	return true;
}

bool verify_FNMSUB(const char* trace)
{
	const float v1 = rndf();
	const float v2 = rndf();
	const float v3 = rndf();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S0)] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S1)] = *(uint32_t*)&v1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S2)] = *(uint32_t*)&v2;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[35] = *(uint32_t*)&v3;
	tb->Verify__DOT__rom__DOT__data[0] = 0x1820f04b; // fnmsub.s	ft0,ft1,ft2,ft3

	evaluate(verify, trace, 1);

	const uint32_t r = tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S0)];
	//printf("%f * %f = %f\n", v1, v2, *(float*)&r);

	if (*(float*)&r != -(v1 * v2 - v3))
		return false;

	delete verify;
	return true;
}

bool verify_FSGNJ(const char* trace)
{
	const float v1 = rndf(); // 1.2f;
	const float v2 = rndf(); //-2.3f;

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S0)] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S1)] = *(uint32_t*)&v1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S2)] = *(uint32_t*)&v2;
	tb->Verify__DOT__rom__DOT__data[0] = 0x20208053; // fsgnj.s	ft0,ft1,ft2

	evaluate(verify, trace, 1);

	uint32_t r = tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S0)];
	float fr = *(float*)&r;

	bool s1 = v1 >= 0.0f;
	bool s2 = v2 >= 0.0f;
	bool sr = fr >= 0.0f;

	if (sr != s2)
	{
		printf("v1 %f, v2 %f, fr %f\n", v1, v2, fr);
		return false;
	}

	const uint32_t b1 = *(uint32_t*)&v1 & 0x7fffffff;
	const uint32_t b2 = r & 0x7fffffff;
	if (b1 != b2)
	{
		printf("b1 %08x, b2 %08x\n", b1, b2);
		return false;
	}

	delete verify;
	return true;
}

bool verify_FSGNJN(const char* trace)
{
	const float v1 = rndf(); // 1.2f;
	const float v2 = rndf(); //-2.3f;

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S0)] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S1)] = *(uint32_t*)&v1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S2)] = *(uint32_t*)&v2;
	tb->Verify__DOT__rom__DOT__data[0] = 0x20209053; // fsgnjn.s	ft0,ft1,ft2

	evaluate(verify, trace, 1);

	uint32_t r = tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S0)];
	float fr = *(float*)&r;

	bool s1 = v1 >= 0.0f;
	bool s2 = v2 >= 0.0f;
	bool sr = fr >= 0.0f;

	if (sr == s2)
	{
		printf("v1 %f, v2 %f, fr %f\n", v1, v2, fr);
		return false;
	}

	const uint32_t b1 = *(uint32_t*)&v1 & 0x7fffffff;
	const uint32_t b2 = r & 0x7fffffff;
	if (b1 != b2)
	{
		printf("b1 %08x, b2 %08x\n", b1, b2);
		return false;
	}

	delete verify;
	return true;
}

bool verify_FSGNJX(const char* trace)
{
	const float v1 = rndf(); // 1.2f;
	const float v2 = rndf(); //-2.3f;

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S0)] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S1)] = *(uint32_t*)&v1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S2)] = *(uint32_t*)&v2;
	tb->Verify__DOT__rom__DOT__data[0] = 0x2020a053; // fsgnjx.s	ft0,ft1,ft2

	evaluate(verify, trace, 1);

	uint32_t r = tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S0)];
	float fr = *(float*)&r;

	bool s1 = v1 >= 0.0f;
	bool s2 = v2 >= 0.0f;
	bool sr = fr >= 0.0f;

	if (sr == s1 ^ s2)
	{
		printf("v1 %f, v2 %f, fr %f\n", v1, v2, fr);
		return false;
	}

	const uint32_t b1 = *(uint32_t*)&v1 & 0x7fffffff;
	const uint32_t b2 = r & 0x7fffffff;
	if (b1 != b2)
	{
		printf("b1 %08x, b2 %08x\n", b1, b2);
		return false;
	}

	delete verify;
	return true;
}

bool verify_FMIN(const char* trace)
{
	const float v1 = rndf();
	const float v2 = rndf();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S0)] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S1)] = *(uint32_t*)&v1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S2)] = *(uint32_t*)&v2;
	tb->Verify__DOT__rom__DOT__data[0] = 0x28208053; // fmin.s	ft0,ft1,ft2

	evaluate(verify, trace, 1);

	uint32_t r = tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S0)];
	if (*(float*)&r != std::min< float >(v1, v2))
	{
		printf("min(%f, %f) = %f\n", v1, v2, *(float*)&r);
		printf("--> %f\n", std::min< float >(v1, v2));
		return false;
	}

	delete verify;
	return true;
}

bool verify_FMAX(const char* trace)
{
	const float v1 = rndf();
	const float v2 = rndf();

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S0)] = 0;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S1)] = *(uint32_t*)&v1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S2)] = *(uint32_t*)&v2;
	tb->Verify__DOT__rom__DOT__data[0] = 0x28209053; // fmax.s	ft0,ft1,ft2

	evaluate(verify, trace, 1);

	uint32_t r = tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S0)];
	if (*(float*)&r != std::max< float >(v1, v2))
	{
		printf("max(%f, %f) = %f\n", v1, v2, *(float*)&r);
		printf("--> %f\n", std::min< float >(v1, v2));
		return false;
	}
	delete verify;
	return true;
}

bool verify_FMIN_FMAX(const char* trace)
{
	const float v1 = rndf();
	const float vmin = rndf();
	const float vmax = vmin + std::abs(rndf());

	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S0)] = *(uint32_t*)&v1;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S1)] = *(uint32_t*)&vmin;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S2)] = *(uint32_t*)&vmax;
	tb->Verify__DOT__rom__DOT__data[0] = 0x28101053; // fmax.s	ft0,ft0,ft1
	tb->Verify__DOT__rom__DOT__data[1] = 0x28200053; // fmin.s	ft0,ft0,ft2

	evaluate(verify, trace, 2);

	uint32_t r = tb->Verify__DOT__cpu__DOT__registers__DOT__r[FPR(S0)];
	float fr = *(float*)&r;

	if (fr < vmin || fr > vmax)
	{
		printf("vmin %f, vmax %f, v1 %f, fr %f\n", vmin, vmax, v1, fr);
		return false;
	}
	delete verify;
	return true;
}

#endif

bool verify_CSRRS(const char* trace)
{
	auto verify = create_soc();
	auto tb = verify->rootp;

	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = 0x00000008;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = 0x00000000;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S2] = 0x00000008;
	tb->Verify__DOT__cpu__DOT__registers__DOT__r[S3] = 0x00000000;
	tb->Verify__DOT__rom__DOT__data[0] = 0x30042473; // csrrs	s0,mstatus,s0
	tb->Verify__DOT__rom__DOT__data[1] = 0x300024f3; // csrrs	s1,mstatus,zero
	tb->Verify__DOT__rom__DOT__data[2] = 0x30093973; // csrrc	s2,mstatus,s2
	tb->Verify__DOT__rom__DOT__data[3] = 0x300039f3; // csrrc	s3,mstatus,zero

	evaluate(verify, trace, 4);

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != 0x00000000)
		return false;
	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] != 0x00000008)
		return false;
	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S2] != 0x00000008)
		return false;
	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S3] != 0x00000000)
		return false;

	return true;
}


bool verify_T0(const char* trace)
{
	auto verify = create_soc();
	auto tb = verify->rootp;

	// tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] = a;
	// tb->Verify__DOT__cpu__DOT__registers__DOT__r[S1] = b;
	tb->Verify__DOT__rom__DOT__data[0] = 0x00100413;
	tb->Verify__DOT__rom__DOT__data[1] = 0x00200493;
	tb->Verify__DOT__rom__DOT__data[2] = 0x00000913;
	tb->Verify__DOT__rom__DOT__data[3] = 0x00000993;
	tb->Verify__DOT__rom__DOT__data[4] = 0x00941663;
	tb->Verify__DOT__rom__DOT__data[5] = 0x0324f433;
	tb->Verify__DOT__rom__DOT__data[6] = 0x0080006f;
	tb->Verify__DOT__rom__DOT__data[7] = 0x07b00913;

	evaluate(verify, trace, 20);

	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S2] != 123)
		return false;
	if (tb->Verify__DOT__cpu__DOT__registers__DOT__r[S0] != 1)
		return false;
		
	delete verify;
	return true;
}

// ========================================================

bool verify(bool (*fn)(const char* trace), const char* name, bool ftrce)
{
	bool result = true;
	char fnf[256];

	sprintf(fnf, "%s.fst", name);

	// traktor::Random seed;

	if (!ftrce)
	{
		uint32_t sd;
		int i;

		for (i = 0; i < ITERATIONS; ++i)
		{
			// sd = seed.next();
			// g_rnd = traktor::Random(sd);

			if (!fn(nullptr))
			{
				result = false;
				break;
			}
		}
	
		// Re-run failed test with tracing enabled.
		if (!result)
		{
			s_randomDevice = new std::random_device();
			printf("Verify failed (at %d / %d), re-run with trace...\n", i, ITERATIONS);
			if (fn(fnf))
				printf("Inconsistent verification.\n");
		}
	}
	else
	{
		if (!fn(fnf))
			result = false;
	}

	return result;
}

#define CHECK(vfn) \
	printf("Running %s...\n", #vfn); \
	if (verify(vfn, #vfn, ftrce)) { printf("%s SUCCEEDED!\n", #vfn); } \
	else { printf("%s FAILED!\n", #vfn); success = false; }

int main(int argc, char **argv)
{
	bool success = true;
	bool ftrce = true;

	// CHECK(verify_ADD);
	// CHECK(verify_ADDI);
	// CHECK(verify_AND);
	// CHECK(verify_ANDI);
	// CHECK(verify_AUIPC);
	// CHECK(verify_BEQ);
	// CHECK(verify_BGE);
	// CHECK(verify_BGEU);
	// CHECK(verify_BLT);
	// CHECK(verify_BLTU);
	// CHECK(verify_BNE);
	// CHECK(verify_DIV);
	// CHECK(verify_UDIV);
	// CHECK(verify_JAL);
	// CHECK(verify_JALR);
	// CHECK(verify_LB);
	// CHECK(verify_LBU);
	// CHECK(verify_LH);
	// CHECK(verify_LHU);
	// CHECK(verify_LUI);
	// CHECK(verify_LW);
	// CHECK(verify_MUL);
	// CHECK(verify_MULH);
	// CHECK(verify_MULHU);
	// CHECK(verify_OR);
	// CHECK(verify_ORI);
	// CHECK(verify_REM);
	// CHECK(verify_REMU);
	// CHECK(verify_REMU2);
	// CHECK(verify_SB);
	// CHECK(verify_SH);
	// CHECK(verify_SLL);
	// CHECK(verify_SLLI);
	// CHECK(verify_SLT);
	// CHECK(verify_SLTI);
	// CHECK(verify_SLTIU);
	// CHECK(verify_SLTU);
	// CHECK(verify_SRA);
	// CHECK(verify_SRAI);
	// CHECK(verify_SRL);
	// CHECK(verify_SRLI);
	// CHECK(verify_SUB);
	// CHECK(verify_SW);
 	// CHECK(verify_XOR);
 	// CHECK(verify_XORI);
	// CHECK(verify_ENDIAN);
	// CHECK(verify_MEM_LOAD_HAZARD);
	// CHECK(verify_PIPELINE);
	// CHECK(verify_PIPELINE_MEMORY);
	// CHECK(verify_PIPELINE_MEMORY_B);

#if defined(CHECK_FPU)

	// CHECK(verify_FADD);
	// CHECK(verify_FSUB);
	// CHECK(verify_FMUL);
	CHECK(verify_FDIV);
	// CHECK(verify_FCVT);
	// CHECK(verify_FLW);
	// CHECK(verify_FSW);
	// CHECK(verify_FMV_X_W);
	// CHECK(verify_FMV_W_X);
	// CHECK(verify_FEQ);
	// CHECK(verify_FLT);
	// CHECK(verify_FMADD);
	// CHECK(verify_FMSUB);
	// CHECK(verify_FNMADD);
	// CHECK(verify_FNMSUB);
	// CHECK(verify_FSGNJ);
	// CHECK(verify_FSGNJN);
	// CHECK(verify_FSGNJX);
	// CHECK(verify_FMIN);
	// CHECK(verify_FMAX);
	// CHECK(verify_FMIN_FMAX);

#endif

	// CHECK(verify_CSRRS);
	// CHECK(verify_T0);

	if (success)
		printf("SUCCESS!\n");
	else
		printf("FAILED!\n");

	return 0;
}