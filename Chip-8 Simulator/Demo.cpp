/*
* 
*  Author: Robert Stroud
*  Last Updated: 9/13/2020
* 
*  Description: This is the demonstration class that contains a main function that will be used to demostrate developing functionality of the project.
* 
*/

#include "Memory.h"

int main()
{
	Memory mem = new Memory();
	mem.load("./c8games/PONG");

	//Prints preloaded data.
	for (int i = 0; i < 80; i++)
	{
		printf("%b\n", (int)mem.getMemByte(i));
	}

	//prints loaded data. 
	for (int j = 512; i < 528; i++)
	{
		printf("%x\n", (int)mem.getMemByte(j));
	}
}