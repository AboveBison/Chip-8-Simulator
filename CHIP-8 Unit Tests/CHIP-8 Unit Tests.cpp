#include "pch.h"
#include "CppUnitTest.h"
#include "../Memory.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CHIP8UnitTests
{
	TEST_CLASS(CHIP8UnitTests)
	{
	public:
		
		TEST_METHOD(MemoryRAMTest)
		{
			Memory * mem = new Memory();
			mem->putMemByte(512, 1);
			Assert::AreEqual((uint8_t) 1, mem->getMemByte(512));
			delete mem;
		}

		TEST_METHOD(MemoryStackTest)
		{
			Memory* mem = new Memory();
			mem->push(512);
			Assert::AreEqual((uint16_t)512, mem->pop());
			delete mem;
		}

		TEST_METHOD(MemoryPreloadTest)
		{
			Memory* mem = new Memory();
			Assert::AreEqual((uint8_t)0x80, mem->getMemByte(79));
			Assert::AreEqual((uint8_t)0, mem->getMemByte(80));
		}
	};
}
