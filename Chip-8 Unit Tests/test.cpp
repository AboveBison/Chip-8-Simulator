#include <cstdint>
#include <cstdio>
#include "pch.h"
#include "../Chip-8 Simulator/Memory.h"
#include "../Chip-8 Simulator/Memory.cpp"
#include "../Chip-8 Simulator/Registers.h"
#include "../Chip-8 Simulator//Registers.cpp"

TEST(MemoryTest, ramAccess) {
	Registers* registers = new Registers();
	Memory* mem = new Memory(registers);
	uint8_t expected = 1;
	mem->putMemByte(512, 1);
	EXPECT_EQ(expected, mem->getMemByte(512));
}

TEST(MemoryTest, stackAccess) {
	Registers* registers = new Registers();
	Memory* mem = new Memory(registers);
	uint16_t expected = 1;
	mem->push(1);
	EXPECT_EQ(expected, mem->pop());
}

TEST(MemoryTest, preloadTest) {
	Registers* registers = new Registers();
	Memory* mem = new Memory(registers);
	uint8_t expected1 = 0xF0;
	uint8_t expected2 = 0x80;
	uint8_t expected3 = 0;
	EXPECT_EQ(expected1, mem->getMemByte(0));
	EXPECT_EQ(expected2, mem->getMemByte(79));
	EXPECT_EQ(expected3, mem->getMemByte(80));
}

TEST(MemoryTest, loadTest) {
	Registers* registers = new Registers();
	Memory* mem = new Memory(registers);
	mem->load(0);
	uint8_t expBeg[8] = {0x6A, 0x02, 0x6B, 0x0C, 0x6C, 0x3F, 0x6D, 0x0C };
	uint8_t expEnd[8] = {0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

	for (int i = 0; i < 8; ++i)
	{
		EXPECT_EQ(expBeg[i], mem->getMemByte(i + 0x200));
	}

	for (int j = 0; j < 8; ++j)
	{
		EXPECT_EQ(expEnd[j], mem->getMemByte(j + 0x2F0));
	}
}

TEST(RegisterTest, generalTest) {
	Registers* registers = new Registers();
	for (int i = 0; i < 16; ++i)
		registers->generalPut(i, (uint8_t)i);
	for (int j = 0; j < 16; ++j)
		EXPECT_EQ(registers->generalGet(j), j);
}

TEST(RegisterTest, timerTest) {
	Registers* registers = new Registers();
	registers->putDelay((uint8_t)10);
	registers->putSound((uint8_t)10);

	EXPECT_EQ(registers->getDelay(), 10);
	EXPECT_EQ(registers->getSound(), 10);
}

TEST(RegisterTest, specialTest) {
	Registers* registers = new Registers();
	Memory* mem = new Memory(registers);
	registers->indexPut((uint16_t)512);
	registers->putPC((uint16_t)0x100);
	mem->push(0);
	mem->push(0);
	mem->push(0);

	EXPECT_EQ(registers->getStack(), (uint8_t)3);
	EXPECT_EQ(registers->getPC(), (uint16_t)0x100);
	EXPECT_EQ(registers->indexGet(), (uint16_t)0x200);

}