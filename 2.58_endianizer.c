//2.58 Write a procedure is_little_endian that will return 1 when compiled and run on a little-endian 
//machine, and will return 0 when compiled and run on a big-endian machine. This program should run 
//on any machine, regardless of its word size.


//This program will make a function call to a function that will examine the first byte in the integer
//and determine if it is running in little or big endian mode

//Author: Hayden Eubanks
//Date: 21, January 2023


#include <stdio.h>

//Function prototype for endianizer function
int is_little_endian(unsigned char);

//Main Program
int main(void) {

	
	//Hex value to be endianized
	unsigned char initialHexValue = 0x01;
	
	
	printf("Initial hexedecimal value is 0x%.8x \n\n", initialHexValue);

	printf("Discovering Endian Type\n\n");

	//Function call to discover if which endian type is being used
	is_little_endian(initialHexValue);
	
	printf("Exiting Program\n\n");
}


//Function to check if Hex value is of big or little endian type
int is_little_endian(unsigned char hexValue) {

	//Endian Type is initialized to 2 to not enter if statement unless endian type is discovered
	int endianType = 2;
	
	//Define type for pointing to each byte in word
	typedef unsigned char* pointerToByte;
	
	//Variable to store first index of hex value
	pointerToByte pointerToHexval= (pointerToByte) &hexValue;
	
	
	//If the first element in the hex value is a equal to the same as the total value of integer
	if(pointerToHexval[0] == hexValue) {
		//Little endian type has been used (0x00000001[0] -> 0x01 == 1)
		endianType = 1;
	
	}
	
	//Otherwise, it the first index is a 0, then Big endian is employed
	else if (pointerToHexval[0] == 00) {
		//(0x00000001[0] -> 0x00 == 0)
		endianType = 0;
	}
	
	else {
		printf("Error Occurred: Endian Type Not Discovered\n\n");
	}
	
	
	//If the entered type is for little Endian
	if(endianType == 1) {
		
		printf("Little Endian has been employed to produce first block containing 0x%.2x\n\n", pointerToHexval[0]);

	}
	
	//If entered type is for big endian
	else if (endianType == 0) {
	
	
		printf("Big Endian has been employed to produce first block containing 0x%.2x\n\n", pointerToHexval[0]);
	}
	
	
	return endianType;

}

