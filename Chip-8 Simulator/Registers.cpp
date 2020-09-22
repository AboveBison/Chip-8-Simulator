/*
* 
*  File: Registers.cpp
*  Desc: This is the file that will be used to house all the registers that the CHIP-8 uses including program counter, stack pointer, and timer registers. This class will 
*		 also handle modification and access of those registers.
*  Author: Robert Stroud
*  Last Updated: 9/22/2020
*/

#include <cstdint>
#include "Registers.h"
#include "Values.h"

/*
* 
*  Constructor: Registers
*  Desc: The constructor will initialize all register values to zero except for the program counter which will be initialized to the start of the program.
* 
*/
Registers::Registers()
{
	for (int i = 0; i < REG_NUM; ++i)
		regs[i] = 0;
	index = 0;
	sound = 0;
	delay = 0;
	programCounter = 0x200;
	stackPointer = 0;
}

/*
* 
*  Function: generalGet
*  Desc: This function will be given an input of 0-F and will return the register with that given value. registers are named v0-vF. If inputed value is invalid the function will return -1.
* 
*/
uint8_t Registers::generalGet(int value)
{
	if (value >= 0 && value <= 15)
		return regs[value];
	else
		return -1;
}

/*
* 
*  Functoin generalPut
*  Desc: This function will take a input for register and an input for value. If the register input is not valid not changes will be made.
* 
*/
void Registers::generalPut(int ind, uint8_t value)
{
	if (ind >= 0 && ind <= 15)
		regs[ind] = value;
}

/* 
* 
*  Function: indexGet
*  Desc: This function will return the value of the index register.
* 
*/
uint16_t Registers::indexGet()
{
	return index;
}

/*
* 
*  Function: indexPut
*  Desc: This will update the index register with the value that is given as input to the function.
* 
*/
void Registers::indexPut(uint16_t value)
{
	index = value;
}

/*
* 
*  Function: getSound
*  Desc: This function will return the value of the sound timer.
* 
*/
uint8_t Registers::getSound()
{
	return sound;
}

/*
*
*  Function: putSound
*  Desc: This function will update the sound timer register with the value that is given as input to the function.
*
*/
void Registers::putSound(uint8_t value)
{
	sound = value;
}

/*
*
*  Function: getDelay
*  Desc: This function will return the value of the delay timer.
*
*/
uint8_t Registers::getDelay()
{
	return delay;
}

/*
*
*  Function: putDelay
*  Desc:This function will update the delay regiseter with the value that is fed into the function.
*
*/
void Registers::putDelay(uint8_t value)
{
	delay = value;
}

/*
*
*  Function: getStack
*  Desc: This function will return the value of the stackpointer.
*
*/
uint8_t Registers::getStack()
{
	return stackPointer;
}

/*
*
*  Function: putSTack
*  Desc:This function will update the stack pointer with the value that is fed into the function.
*
*/
void Registers::putStack(uint8_t value)
{
	stackPointer = value;
}

/*
*
*  Function: getPC
*  Desc: This function will return the value of the programCounter.
*
*/
uint16_t Registers::getPC()
{
	return programCounter;
}

/*
*
*  Function: putPC
*  Desc:This function will update the program counter with the value that is fed into the function.
*
*/
void Registers::putPC(uint16_t value)
{
	if (value >= 0x200)
		programCounter = value;
}