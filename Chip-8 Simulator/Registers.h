#pragma once
#ifndef REGISTER_H
#define REGISTER_H

#include <cstdint>

class Registers
{
	private:
		//These are the 16 general purpose registers for the Simulator.
		uint8_t v0, v1, v2, v3, v4, v5, v6, v7 ,v8, v9, vA, vB, vC, vD, vE, vF;
		uint8_t regs[16] = {v0, v1, v2, v3, v4, v5, v6, v7 ,v8, v9, vA, vB, vC, vD, vE, vF};

		//This is the index register used to hold memory addresses.
		uint16_t index;

		//These are the registers that will be decremented at a rate of 60hz.
		uint8_t sound;
		uint8_t delay;

		//These are special registers that have specialized access.
		uint16_t programCounter;
		uint8_t stackPointer;

	public:
		//Constructor
		Registers();

		//Functions used to access and modify general registers.
		uint8_t		generalGet(int ind);
		void		generalPut(int ind, uint8_t value);

		//Functions used to access and modify index register.
		uint16_t	indexGet();
		void		indexPut(uint16_t value);

		//Functions used to access and modify sound and delay registers.
		uint8_t		getSound();
		uint8_t		getDelay();
		void		putSound(uint8_t value);
		void		putDelay(uint8_t value);

		//Functions used to access and modify the stack pointer, only called from memory. 
		uint8_t		getStack();
		void		putStack(uint8_t addr);

		//Functions used to access and modify the program counter.
		uint16_t	getPC();
		void		putPC(uint16_t value);
};
#endif 

