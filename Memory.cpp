/*
	File: Memory.cpp
	Desc: Implementation of the Memory Section of the CHIP 8 Simulator. This houses the RAM and Program Stack of the CHIP-8 as well as the numerical value of the stack pointer.
	Author: Robert Stroud
	Last Updated: 9/8/2020
*/
#include <cstdint>
#include <iostream>
#include "Memory.h"

/*
* 
*	Constructor: Memory
*	Description: Resets the Program Stack and RAM to their initial states. This includes reloading the prequired info required by the interpreter into RAM.
* 
*/
Memory::Memory()
{
	reset();
}

/*
* 
*	Function: getMemByte
*	Description: The accessor funtion of the general RAM of the CHIP-8 this will be used to retrieve values from memory in other parts of the Simulator.
* 
*/
uint8_t Memory::getMemByte(uint64_t byteAddress)
{
	if (byteAddress > 4095 || byteAddress < 0x200) {
		std::cout << "Error getting memory value from " << byteAddress;
		return -1; ;
	}
	return memory[byteAddress];
}

/*
* 
*	Function putMemByte
*	Description: The mutator function of the general RAM of the CHIP-8 this will be used to modify the memory of the system by other parts of the simulator.
* 
*/
void Memory::putMemByte(uint64_t byteAddress, uint8_t value)
{
	if (byteAddress > 4095 || byteAddress < 0x200) {
		std::cout << "Error inserting memory value: " << value << " into RAM at position: " << byteAddress;
	}
	else {
		memory[byteAddress] = value;
	}
}

/*
* 
*	Function: pop
*	Description: Pops the value on the top of the stack, because this is the program stack this value should be some form of address, and then updates the stack pointer.
* 
*/
uint16_t Memory::pop()
{
	uint16_t result = -1;
	if (stackPointer <= 0) {
		std::cout << "Error in retrieving stack data, either nothing is on the stack or sp has been corrupted.";
	}
	else {
		result = stack[stackPointer];
		stackPointer--;
	}
	return result;
}

/*
* 
*	Function: push
*	Description: Pushs a value onto the stack if there is room and updates the stack pointer. If there is not room it will print an error and not update the stack.
* 
*/
void Memory::push(uint16_t value)
{
	if (stackPointer < 15) {
		stack[stackPointer] = value;
		stackPointer++;
	}
	else {
		std::cout << "Error there is no more room on the stack, no changes will be made.";
	}
}

/*
* 
*	Function: reset
*	Description: Resets the RAM, Program Stack, and Stack Pointer to their initial states and then loads the prequired data into RAM.
* 
*/
void Memory::reset()
{
	for (int i = 0; i < MEM_SIZE; i++)
		memory[i] = 0;
	for (int j = 0; j < STACK_SIZE; j++)
		stack[j] = 0;
	stackPointer = 0;
	Memory::preload();
}

/*
* 
*	Function: preload
*	Description: This function is used to preload data nessecary for the interpreter into the System Area of RAM.
* 
*/
void Memory::preload()
{
	//Sprite data for the graphic of 0.
	memory[0] = 0xF0; memory[1] = 0x90; memory[2] = 0x90; memory[3] = 0x90; memory[4] = 0xF0;
	//Sprite data for the graphic of 1.
	memory[5] = 0x20; memory[6] = 0x60; memory[7] = 0x20; memory[8] = 0x20; memory[9] = 0x70;
	//Sprite data for the graphic of 2.
	memory[10] = 0xF0; memory[11] = 0x10; memory[12] = 0xF0; memory[13] = 0x80; memory[14] = 0xF0;
	//Sprite data for the graphic of 3.
	memory[15] = 0xF0; memory[16] = 0x10; memory[17] = 0xF0; memory[18] = 0x10; memory[19] = 0xF0;
	//Sprite data for the graphic of 4.
	memory[20] = 0x90; memory[21] = 0x90; memory[22] = 0xF0; memory[23] = 0x10; memory[24] = 0x10;
	//Sprite data for the graphic of 5.
	memory[25] = 0xF0; memory[26] = 0x80; memory[27] = 0xF0; memory[28] = 0x10; memory[29] = 0xF0;
	//Sprite data for the graphic of 6.
	memory[30] = 0xF0; memory[31] = 0x80; memory[32] = 0xF0; memory[33] = 0x90; memory[34] = 0xF0;
	//Sprite data for the graphic of 7.
	memory[35] = 0xF0; memory[36] = 0x10; memory[37] = 0x20; memory[38] = 0x40; memory[39] = 0x40;
	//Sprite data for the graphic of 8.
	memory[40] = 0xF0; memory[41] = 0x90; memory[42] = 0xF0; memory[43] = 0x90; memory[44] = 0xF0;
	//Sprite data for the graphic of 9.
	memory[45] = 0xF0; memory[46] = 0x90; memory[47] = 0xF0; memory[48] = 0x10; memory[49] = 0xF0;
	//Sprite data for the graphic of A.
	memory[50] = 0xF0; memory[51] = 0x90; memory[52] = 0xF0; memory[53] = 0x90; memory[54] = 0x90;
	//Sprite data for the graphic of B.
	memory[55] = 0xE0; memory[56] = 0x90; memory[57] = 0xE0; memory[58] = 0x90; memory[59] = 0xE0;
	//Sprite data for the graphic of C.
	memory[60] = 0xF0; memory[61] = 0x80; memory[62] = 0x80; memory[63] = 0x80; memory[64] = 0xF0;
	//Sprite data for the graphic of D.
	memory[65] = 0xE0; memory[66] = 0x90; memory[67] = 0x90; memory[68] = 0x90; memory[69] = 0xE0;
	//Sprite data for the graphic of E.
	memory[70] = 0xF0; memory[71] = 0x80; memory[72] = 0xF0; memory[73] = 0x80; memory[74] = 0xF0;
	//Sprite data for the graphic of F.
	memory[75] = 0xF0; memory[76] = 0x80; memory[77] = 0xF0; memory[78] = 0x80; memory[79] = 0x80;
}