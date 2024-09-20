//2.64 Write code to implement the following function:

/* Return 1 when any odd bit of x equals 1; 0 otherwise.
   Assume w=32 */
//int any_odd_one(unsigned x);

//Your function should follow the bit-level integer coding rules (page 128), except that you may 
//assume that data type int has w = 32 bits.

//Author: Hayden Eubanks
//Date: 21, January 2023

#include <stdio.h>

//Function Definition
int any_odd_one(unsigned x);

int main (void) {

	//Will evaluate True for any_odd_one()
	unsigned int word = 0xF0F0F0F0;

	printf("Is there an odd bit of 1 in %X?: %d\n\n", word, any_odd_one(word));
	
	//This will evaluate to false
	word = 0x0F0F0F0F;
	
	printf("Is there an odd bit of 1 in %X?: %d\n\n", word, any_odd_one(word));

}


int any_odd_one(unsigned x) {


	/*
		This function works by first isolating the odd values and then checking if they
		contain one values
		
		Example:
			     0xF0F0F0F0
			mask 0xF0F0F0F0
			---------------
			&    0xF0F0F0F0
			!    0x00000000
			!!   0x00000001
	
	
	*/
	
	//This mask ensures we are only looking at the odd values
	unsigned int mask = 0xF0F0F0F0;
	
	//Taking the AND isolates the odd values
	x = x & mask;
	
	//This will ensure that true is returned iff an odd value exists
	return !!(x);

}
