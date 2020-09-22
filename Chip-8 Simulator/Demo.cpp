/*
* 
*  Author: Robert Stroud
*  Last Updated: 9/13/2020
* 
*  Description: This is the demonstration class that contains a main function that will be used to demostrate developing functionality of the project.
* 
*/

#include "Memory.h"
#include "Values.h"
#include "Registers.h"

int main()
{
	Registers* registers = new Registers();
	Memory* mem = new Memory(registers);
	mem->load(0);

	//Prints preloaded data.
	for (int i = 0; i < 80; i++)
	{
		printf("%x\n", (int)mem->getMemByte(i));
	}
	printf("\n");
	for (int j = 0x200; j < 0x2F0; j++)
	{
		if (((j - 0x200) % 16) == 0)
		{
			printf("\n");
		}
		printf("%02x  ", (int)mem->getMemByte(j));
	}
}