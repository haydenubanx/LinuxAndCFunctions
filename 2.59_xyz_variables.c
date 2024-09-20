//2.59 Write a C expression that will yield a word consisting of the least significant byte of x and 
//the remaining bytes of y. For operands x = 0x89ABCDEF and y = 0x76543210, this would give 
//0x765432EF.

//Author: Hayden Eubanks
//Date: 21, January 2023

#include <stdio.h>


int main(void) {

	//Assign Value to x
	int x = 0x89ABCDEF;
	
	//Assign Value for y
	int y = 0x76543210;
	
	//Print Results
	/*
		The print results line works by first taking the value for x and masking it through 
		0xff which will only keep the last two digits...
		
		x --> 0x89ABCDEF
		m --> 0x000000FF
		----------------
		& --> 0x000000EF
		
		Then masks y with the opposite mask of ~0xff to remove only the the last 2 digits...
		
		y --> 0x76543210
		~m -> 0xFFFFFF00
		----------------
		& --> 0x76543200
		
		In this example it will produce...
		
		x --> 0x000000EF
		y --> 0x76543200
		----------------
		| --> 0x765432EF <-- The bitwise OR operation will then take the non-zero values
	*/
	printf("Original X: 0x%X \n\nOriginal Y: 0x%X \n\n New Value: 0x%X\n\n",x,y, (x & 0xff) | (y & ~0xff));


}
