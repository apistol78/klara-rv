if ((word & 0x7f) == 0x73)
{
	// 
	if ((word & 0xffffffff) == 0x10500073)	// WFI
	{
		m_waitForInterrupt = true;
	}
	// CSR
	else if ((word & 0x0000707f) == 0x00006073)	// CSRRSI
	{
		log::info << L"CSRRSI" << Endl;
	}
	// CSR
	else if ((word & 0xffffffff) == 0x30200073)	// MRET
	{
		returnFromInterrupt();
	}
	// CSR
	else if ((word & 0x0000707f) == 0x00003073)	// CSRRC
	{
		const auto f = FormatCSR::parse(word);
		const uint32_t data = readCSR(f.csr);
		const uint32_t tmp = R_u(f.rs1);
		R_u(f.rd) = data;
		writeCSR(f.csr, R_u(f.rd) & ~tmp);
	}
	// CSR
	else if ((word & 0x0000707f) == 0x00001073)	// CSRRW
	{
		const auto f = FormatCSR::parse(word);
		R_s(f.rd) = readCSR(f.csr);
		writeCSR(f.csr, R_s(f.rs1));
	}
	// CSR
	else if ((word & 0x0000707f) == 0x00007073)	// CSRRCI
	{
		log::info << L"CSRRCI" << Endl;
	}
	// CSR
	else if ((word & 0x0000707f) == 0x00002073)	// CSRRS
	{
		const auto f = FormatCSR::parse(word);
		const uint32_t data = readCSR(f.csr);
		const uint32_t tmp = R_u(f.rs1);
		R_u(f.rd) = data;
		writeCSR(f.csr, R_u(f.rd) | tmp);
	}
	// CSR
	else if ((word & 0x0000707f) == 0x00005073)	// CSRRWI
	{
		log::info << L"CSRRWI" << Endl;
	}
	// CSR
	else if ((word & 0xffffffff) == 0x00000073)	// ECALL
	{
		ecall();
	}
	// CSR
	else if ((word & 0xffffffff) == 0x00100073)	// EBREAK
	{
		return false;
	}
}
else if ((word & 0x7f) == 0x63)
{
	// B
	if ((word & 0x0000707f) == 0x00000063)	// BEQ
	{
		const auto f = FormatB::parse(word);
		if (R_s(f.rs1) == R_s(f.rs2))
			PC_NEXT = PC + f.imm;
	}
	// B
	else if ((word & 0x0000707f) == 0x00007063)	// BGEU
	{
		const auto f = FormatB::parse(word);
		if (R_u(f.rs1) >= R_u(f.rs2))
			PC_NEXT = PC + f.imm;
	}
	// B
	else if ((word & 0x0000707f) == 0x00005063)	// BGE
	{
		const auto f = FormatB::parse(word);
		if (R_s(f.rs1) >= R_s(f.rs2))
			PC_NEXT = PC + f.imm;
	}
	// B
	else if ((word & 0x0000707f) == 0x00004063)	// BLT
	{
		const auto f = FormatB::parse(word);
		if (R_s(f.rs1) < R_s(f.rs2))
			PC_NEXT = PC + f.imm;
	}
	// B
	else if ((word & 0x0000707f) == 0x00006063)	// BLTU
	{
		const auto f = FormatB::parse(word);
		if (R_u(f.rs1) < R_u(f.rs2))
			PC_NEXT = PC + f.imm;
	}
	// B
	else if ((word & 0x0000707f) == 0x00001063)	// BNE
	{
		const auto f = FormatB::parse(word);
		if (R_s(f.rs1) != R_s(f.rs2))
			PC_NEXT = PC + f.imm;
	}
}
else if ((word & 0x7f) == 0x13)
{
	// I
	if ((word & 0x0000707f) == 0x00002013)	// SLTI
	{
		const auto f = FormatI::parse(word);
		R_u(f.rd) = (R_s(f.rs1) < f.imm) ? 1 : 0;
	}
	// I
	else if ((word & 0x0000707f) == 0x00003013)	// SLTIU
	{
		const auto f = FormatI::parse(word);
		R_u(f.rd) = (R_u(f.rs1) < f.imm) ? 1 : 0;
	}
	// I
	else if ((word & 0x0000707f) == 0x00006013)	// ORI
	{
		const auto f = FormatI::parse(word);
		R_u(f.rd) = R_u(f.rs1) | f.imm;
	}
	// I
	else if ((word & 0x0000707f) == 0x00000013)	// ADDI
	{
		const auto f = FormatI::parse(word);
		R_s(f.rd) = R_s(f.rs1) + f.imm;
	}
	// I
	else if ((word & 0x0000707f) == 0x00007013)	// ANDI
	{
		const auto f = FormatI::parse(word);
		R_u(f.rd) = R_u(f.rs1) & f.imm;
	}
	// I
	else if ((word & 0x0000707f) == 0x00004013)	// XORI
	{
		const auto f = FormatI::parse(word);
		R_u(f.rd) = R_u(f.rs1) ^ f.imm;
	}
	// R
	else if ((word & 0xfc00707f) == 0x00001013)	// SLLI
	{
		const auto f = FormatR::parse(word);
		R_s(f.rd) = R_s(f.rs1) << ((word >> 20) & 0x1f);
	}
	// R
	else if ((word & 0xfc00707f) == 0x00005013)	// SRLI
	{
		const auto f = FormatR::parse(word);
		R_u(f.rd) = R_u(f.rs1) >> ((word >> 20) & 0x1f);
	}
	// R
	else if ((word & 0xfc00707f) == 0x40005013)	// SRAI
	{
		const auto f = FormatR::parse(word);
		const int32_t sh = (int32_t)((word >> 20) & 0x1f);
		R_s(f.rd) = R_s(f.rs1) >> sh;
	}
}
else if ((word & 0x7f) == 0x0f)
{
	// I
	if ((word & 0x0000707f) == 0x0000000f)	// FENCE
	{
		flushCaches();
	}
}
else if ((word & 0x7f) == 0x67)
{
	// I
	if ((word & 0x0000707f) == 0x00000067)	// JALR
	{
		const auto f = FormatI::parse(word);
		const uint32_t tmp = PC_NEXT;
		PC_NEXT = (R(f.rs1) + f.imm) & ~1;
		R_u(f.rd) = tmp;
	}
}
else if ((word & 0x7f) == 0x03)
{
	// I
	if ((word & 0x0000707f) == 0x00000003)	// LB
	{
		const auto f = FormatI::parse(word);
		R_s(f.rd) = (int8_t)MEM_RD_U8(R_u(f.rs1) + f.imm);
	}
	// I
	else if ((word & 0x0000707f) == 0x00005003)	// LHU
	{
		const auto f = FormatI::parse(word);
		R(f.rd) = MEM_RD_U16(R(f.rs1) + f.imm);			
	}
	// I
	else if ((word & 0x0000707f) == 0x00002003)	// LW
	{
		const auto f = FormatI::parse(word);
		R_s(f.rd) = (int32_t)MEM_RD(R_u(f.rs1) + f.imm);
	}
	// I
	else if ((word & 0x0000707f) == 0x00001003)	// LH
	{
		const auto f = FormatI::parse(word);
		R_s(f.rd) = (int16_t)MEM_RD_U16(R_u(f.rs1) + f.imm);
	}
	// I
	else if ((word & 0x0000707f) == 0x00004003)	// LBU
	{
		const auto f = FormatI::parse(word);
		R_u(f.rd) = MEM_RD_U8(R_u(f.rs1) + f.imm);
	}
}
else if ((word & 0x7f) == 0x6f)
{
	// J
	if ((word & 0x0000007f) == 0x0000006f)	// JAL
	{
		const auto f = FormatJ::parse(word);
		R_u(f.rd) = PC_NEXT;
		PC_NEXT = PC + f.imm;
	}
}
else if ((word & 0x7f) == 0x33)
{
	// R
	if ((word & 0xfe00707f) == 0x02003033)	// MULHU
	{
		const auto f = FormatR::parse(word);
		const uint64_t lh = (uint64_t)R(f.rs1);
		const uint64_t rh = (uint64_t)R(f.rs2);
		R(f.rd) = (lh * rh) >> 32;
	}
	// R
	else if ((word & 0xfe00707f) == 0x02007033)	// REMU
	{
		const auto f = FormatR::parse(word);
		const uint32_t dividend = R_u(f.rs1);
		const uint32_t divisor = R_u(f.rs2);
		if (divisor == 0)
			R_u(f.rd) = dividend;
		else
			R_u(f.rd) = dividend % divisor;
	}
	// R
	else if ((word & 0xfe00707f) == 0x00006033)	// OR
	{
		const auto f = FormatR::parse(word);
		R_u(f.rd) = R_u(f.rs1) | R_u(f.rs2);
	}
	// R
	else if ((word & 0xfe00707f) == 0x02002033)	// MULHSU
	{
		const auto f = FormatR::parse(word);
		const int64_t lh = (int64_t)R_s(f.rs1);
		const uint64_t rh = (uint64_t)R(f.rs2);
		R_s(f.rd) = (lh * rh) >> 32;
	}
	// R
	else if ((word & 0xfe00707f) == 0x02006033)	// REM
	{
		const auto f = FormatR::parse(word);
		const int32_t dividend = R_s(f.rs1);
		const int32_t divisor = R_s(f.rs2);
		if (divisor == 0)
			R_s(f.rd) = dividend;
		else if (dividend == std::numeric_limits< int32_t >::lowest() && divisor == -1)
			R_s(f.rd) = 0;
		else
			R_s(f.rd) = dividend % divisor;
	}
	// R
	else if ((word & 0xfe00707f) == 0x00001033)	// SLL
	{
		const auto f = FormatR::parse(word);
		R_s(f.rd) = R_s(f.rs1) << R_u(f.rs2);
	}
	// R
	else if ((word & 0xfe00707f) == 0x00004033)	// XOR
	{
		const auto f = FormatR::parse(word);
		R_u(f.rd) = R_u(f.rs1) ^ R_u(f.rs2);
	}
	// R
	else if ((word & 0xfe00707f) == 0x40000033)	// SUB
	{
		const auto f = FormatR::parse(word);
		R_s(f.rd) = R_s(f.rs1) - R_s(f.rs2);
	}
	// R
	else if ((word & 0xfe00707f) == 0x20002033)	// SH1ADD
	{
		const auto f = FormatR::parse(word);
		R_s(f.rd) = (R_s(f.rs1) << 1) + R_s(f.rs2);
	}
	// R
	else if ((word & 0xfe00707f) == 0x20004033)	// SH2ADD
	{
		const auto f = FormatR::parse(word);
		R_s(f.rd) = (R_s(f.rs1) << 2) + R_s(f.rs2);
	}
	// R
	else if ((word & 0xfe00707f) == 0x20006033)	// SH3ADD
	{
		const auto f = FormatR::parse(word);
		R_s(f.rd) = (R_s(f.rs1) << 3) + R_s(f.rs2);
	}
	// R
	else if ((word & 0xfe00707f) == 0x00003033)	// SLTU
	{
		const auto f = FormatR::parse(word);
		R_u(f.rd) = (R_u(f.rs1) < R_u(f.rs2)) ? 1 : 0;
	}
	// R
	else if ((word & 0xfe00707f) == 0x00002033)	// SLT
	{
		const auto f = FormatR::parse(word);
		R_u(f.rd) = (R_s(f.rs1) < R_s(f.rs2)) ? 1 : 0;
	}
	// R
	else if ((word & 0xfe00707f) == 0x40005033)	// SRA
	{
		const auto f = FormatR::parse(word);
		const int32_t sh = R_s(f.rs2);
		if (sh >= 0)
			R_s(f.rd) = R_s(f.rs1) >> sh;
		else
			log::error << L"SRA, shift by negative not supported!" << Endl;
	}
	// R
	else if ((word & 0xfe00707f) == 0x00005033)	// SRL
	{
		const auto f = FormatR::parse(word);
		R_u(f.rd) = R_u(f.rs1) >> R_u(f.rs2);
	}
	// R
	else if ((word & 0xfe00707f) == 0x02001033)	// MULH
	{
		const auto f = FormatR::parse(word);
		const int64_t lh = (int64_t)R_s(f.rs1);
		const int64_t rh = (int64_t)R_s(f.rs2);
		R_s(f.rd) = (lh * rh) >> 32;
	}
	// R
	else if ((word & 0xfe00707f) == 0x00000033)	// ADD
	{
		const auto f = FormatR::parse(word);
		R_s(f.rd) = R_s(f.rs1) + R_s(f.rs2);
	}
	// R
	else if ((word & 0xfe00707f) == 0x02005033)	// DIVU
	{
		const auto f = FormatR::parse(word);
		const uint32_t dividend = R_u(f.rs1);
		const uint32_t divisor = R_u(f.rs2);
		if (divisor ==  0)
			R_u(f.rd) = 0xffffffff;
		else		
			R_u(f.rd) = dividend / divisor;
	}
	// R
	else if ((word & 0xfe00707f) == 0x02004033)	// DIV
	{
		const auto f = FormatR::parse(word);
		const int32_t dividend = R_s(f.rs1);
		const int32_t divisor = R_s(f.rs2);
		if (divisor == 0)
			R_s(f.rd) = -1;
		else if (dividend == std::numeric_limits< int32_t >::lowest() && divisor == -1)
			R_s(f.rd) = std::numeric_limits< int32_t >::lowest();
		else
			R_s(f.rd) = dividend / divisor;
	}
	// R
	else if ((word & 0xfe00707f) == 0x00007033)	// AND
	{
		const auto f = FormatR::parse(word);
		R_u(f.rd) = R_u(f.rs1) & R_u(f.rs2);
	}
	// R
	else if ((word & 0xfe00707f) == 0x02000033)	// MUL
	{
		const auto f = FormatR::parse(word);
		R_s(f.rd) = R_s(f.rs1) * R_s(f.rs2);
	}
}
else if ((word & 0x7f) == 0x3b)
{
	// R
	if ((word & 0xfe00707f) == 0x0800003b)	// ADDUW
	{
		const auto f = FormatR::parse(word);
		R_u(f.rd) = R_u(f.rs1) + R_u(f.rs2);
	}
	// R
	else if ((word & 0xfe00707f) == 0x2000203b)	// SH1ADDUW
	{
		const auto f = FormatR::parse(word);
		R_u(f.rd) = (R_u(f.rs1) << 1) + R_u(f.rs2);
	}
	// R
	else if ((word & 0xfe00707f) == 0x2000403b)	// SH2ADDUW
	{
		const auto f = FormatR::parse(word);
		R_u(f.rd) = (R_u(f.rs1) << 2) + R_u(f.rs2);
	}
	// R
	else if ((word & 0xfe00707f) == 0x2000603b)	// SH3ADDUW
	{
		const auto f = FormatR::parse(word);
		R_u(f.rd) = (R_u(f.rs1) << 3) + R_u(f.rs2);
	}
}
else if ((word & 0x7f) == 0x1b)
{
	// R
	if ((word & 0xfc00707f) == 0x0800101b)	// SLLIUW
	{
		const auto f = FormatR::parse(word);
		R_u(f.rd) = R_u(f.rs1) << ((word >> 20) & 0x1f);
	}
}
else if ((word & 0x7f) == 0x53)
{
	// R
	if ((word & 0xfff0007f) == 0xc0000053)	// FCVT_W_S
	{
		const auto f = FormatR::parse(word);
		R_s(f.rd) = (int32_t)FR(f.rs1);
	}
	// R
	else if ((word & 0xfe00007f) == 0x00000053)	// FADD
	{
		const auto f = FormatR::parse(word);
		FR(f.rd) = FR(f.rs1) + FR(f.rs2);
	}
	// R
	else if ((word & 0xfff0007f) == 0xd0000053)	// FCVT_S_W
	{
		const auto f = FormatR::parse(word);
		FR(f.rd) = (float)R_s(f.rs1);
	}
	// R
	else if ((word & 0xfff0007f) == 0xc0100053)	// FCVT_WU_S
	{
		const auto f = FormatR::parse(word);
		R_u(f.rd) = (uint32_t)std::max(FR(f.rs1), 0.0f);
	}
	// R
	else if ((word & 0xfe00007f) == 0x18000053)	// FDIV
	{
		const auto f = FormatR::parse(word);
		FR(f.rd) = FR(f.rs1) / FR(f.rs2);
	}
	// R
	else if ((word & 0xfff0007f) == 0xd0100053)	// FCVT_S_WU
	{
		const auto f = FormatR::parse(word);
		FR(f.rd) = (float)R_u(f.rs1);
	}
	// R
	else if ((word & 0xfe00707f) == 0xa0000053)	// FLE
	{
		const auto f = FormatR::parse(word);
		R(f.rd) = (FR(f.rs1) <= FR(f.rs2) ? 1 : 0);
	}
	// R
	else if ((word & 0xfe00707f) == 0xa0002053)	// FEQ
	{
		const auto f = FormatR::parse(word);
		R(f.rd) = (FR(f.rs1) == FR(f.rs2) ? 1 : 0);
	}
	// R
	else if ((word & 0xfe00707f) == 0x28001053)	// FMAX
	{
		const auto f = FormatR::parse(word);
		FR(f.rd) = std::max(FR(f.rs1), FR(f.rs2));
	}
	// R
	else if ((word & 0xfe00707f) == 0x28000053)	// FMIN
	{
		const auto f = FormatR::parse(word);
		FR(f.rd) = std::min(FR(f.rs1), FR(f.rs2));
	}
	// R
	else if ((word & 0xfe00007f) == 0x08000053)	// FSUB
	{
		const auto f = FormatR::parse(word);
		FR(f.rd) = FR(f.rs1) - FR(f.rs2);
	}
	// R
	else if ((word & 0xfe00707f) == 0x20002053)	// FSGNJX
	{
		const auto f = FormatR::parse(word);
		const uint32_t tmp1 = FR_u(f.rs1);
		const uint32_t tmp2 = FR_u(f.rs2);
		FR_u(f.rd) = (tmp1 & 0x7fffffff) | ((tmp2 & 0x80000000) ^ (tmp1 & 0x80000000));
	}
	// R
	else if ((word & 0xfe00007f) == 0x10000053)	// FMUL
	{
		const auto f = FormatR::parse(word);
		FR(f.rd) = FR(f.rs1) * FR(f.rs2);
	}
	// R
	else if ((word & 0xfe00707f) == 0x20000053)	// FSGNJ
	{
		const auto f = FormatR::parse(word);
		const uint32_t tmp1 = FR_u(f.rs1);
		const uint32_t tmp2 = FR_u(f.rs2);
		FR_u(f.rd) = (tmp1 & 0x7fffffff) | (tmp2 & 0x80000000);
	}
	// R
	else if ((word & 0xfe00707f) == 0x20001053)	// FSGNJN
	{
		const auto f = FormatR::parse(word);
		const uint32_t tmp1 = FR_u(f.rs1);
		const uint32_t tmp2 = FR_u(f.rs2);
		FR_u(f.rd) = (tmp1 & 0x7fffffff) | ((tmp2 & 0x80000000) ^ 0x80000000);
	}
	// R
	else if ((word & 0xfe00707f) == 0xa0001053)	// FLT
	{
		const auto f = FormatR::parse(word);
		R(f.rd) = (FR(f.rs1) < FR(f.rs2) ? 1 : 0);
	}
}
else if ((word & 0x7f) == 0x43)
{
	// R4
	if ((word & 0x0600007f) == 0x00000043)	// FMADD
	{
		const auto f = FormatR4::parse(word);
		FR(f.rd) = FR(f.rs1) * FR(f.rs2) + FR(f.rs3);
	}
}
else if ((word & 0x7f) == 0x47)
{
	// R4
	if ((word & 0x0600007f) == 0x00000047)	// FMSUB
	{
		const auto f = FormatR4::parse(word);
		FR(f.rd) = FR(f.rs1) * FR(f.rs2) - FR(f.rs3);
	}
}
else if ((word & 0x7f) == 0x4f)
{
	// R4
	if ((word & 0x0600007f) == 0x0000004f)	// FNMADD
	{
		const auto f = FormatR4::parse(word);
		FR(f.rd) = -(FR(f.rs1) * FR(f.rs2)) - FR(f.rs3);
	}
}
else if ((word & 0x7f) == 0x4b)
{
	// R4
	if ((word & 0x0600007f) == 0x0000004b)	// FNMSUB
	{
		const auto f = FormatR4::parse(word);
		FR(f.rd) = -(FR(f.rs1) * FR(f.rs2)) + FR(f.rs3);
	}
}
else if ((word & 0x7f) == 0x23)
{
	// S
	if ((word & 0x0000707f) == 0x00002023)	// SW
	{
		const auto f = FormatS::parse(word);
		MEM_WR(R_u(f.rs1) + f.imm, R_u(f.rs2));
	}
	// S
	else if ((word & 0x0000707f) == 0x00000023)	// SB
	{
		const auto f = FormatS::parse(word);
		MEM_WR_U8(R_u(f.rs1) + f.imm, (uint8_t)R_u(f.rs2));
	}
	// S
	else if ((word & 0x0000707f) == 0x00001023)	// SH
	{
		const auto f = FormatS::parse(word);
		MEM_WR_U16(R_u(f.rs1) + f.imm, R_u(f.rs2));
	}
}
else if ((word & 0x7f) == 0x17)
{
	// U
	if ((word & 0x0000007f) == 0x00000017)	// AUIPC
	{
		const auto f = FormatU::parse(word);
		R_u(f.rd) = PC + f.imm;
	}
}
else if ((word & 0x7f) == 0x37)
{
	// U
	if ((word & 0x0000007f) == 0x00000037)	// LUI
	{
		const auto f = FormatU::parse(word);
		R_s(f.rd) = f.imm;
	}
}
else
{
	log::error << L"Unknown instruction, " << str(L"%08x", word) << Endl;
	return false;
}
return true;
