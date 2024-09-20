//2.60 Suppose we number the bytes in a w-bit word from 0 (least significant) to w/8 – 1 (most 
//significant). Write code for the following C function, which will return an unsigned value in which 
//byte i of argument x has been replaced by byte b:
//unsigned replace_byte (unsigned x, int i, unsigned char b);
//Here are some examples showing how the function should work:
//replace_byte(0x12345678, 2, 0xAB) --> 0x12AB5678
//replace_byte(0x12345678, 0, 0xAB) --> 0x123456AB

//Author: Hayden Eubanks
//Date: 21, January 2023

#include <stdio.h>


//Function decleration
unsigned replace_byte (unsigned x, int i, unsigned char b);

int main(void) {

	printf("Original Value: 0x12345678\n\nInsertion Value: 0xAB\n\n");



	printf("Replacing at Index 2: %.8X\n\n", replace_byte(0x12345678, 2, 0xAB));
	printf("Replacing at Index 0: %.8X\n\n", replace_byte(0x12345678, 0, 0xAB));
}


//This function will replace the bytes at the correct index with the entered replacement bits
/*
	0x12345678
	  ^ ^ ^ ^
	  | | | |
    index 3 2 1 0	 
    
    
    This function works by creating a mask that eliminates the bits at the desired index
    
    example: Deleting bytes at index two
    
    	x -> 0x12345678
    	~m-> 0xFF00FFFF
    	---------------
    	& -> 0x12005678
    	
    	
    	The replacement value is then shifted left by the index value 16^i
    	
    	ex: b -> 0xAB << i << 3
*/	
unsigned replace_byte(unsigned x, int i, unsigned char b) {
	
	unsigned int mask = 0x000000FF;
	
	//Change to unsigned int for bit shift application
	unsigned int bVal = b;
	
	//The shift value for setting the mask and replacement value to the correct index
	int shiftValue = i << 3;
	
	//Move mask by shift value to apply at correct position
	mask = mask << shiftValue;  
	
	//Combine x and opposite of max to produce zeros values at index
	x = x & ~mask;
	
	//Shift the insertion value to correct index
	bVal = bVal << shiftValue;

	//Combine x and insertion value
	x = x | bVal;
	
	
	return x;

}
