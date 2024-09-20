//2.61 Write C expressions that evaluate to 1 when the following conditions are true and to 0 when 
//they are false. Assume x is of type int.

//	Any bit of x equals 1.

//	Any bit of x equals 0.

//	Any bit in the least significant byte of x equals 1.

//	Any bit in the most significant byte of x equals 0.

//Your code should follow the bit-level integer coding rules (page 128), with the additional 
//restriction that you may not use equality (==) or inequality (!=) tests.

//Author: Hayden Eubanks
//Date: 21, January 2023

#include <stdio.h>


unsigned int one_bit(unsigned int passedValue);
unsigned int zero_bit(unsigned int passedValue);
unsigned int least_One_bit(unsigned int passedValue);
unsigned int most_Zero_bit(unsigned int passedValue);



int main (void) {
	unsigned int valueToPass = 0xFFFFFF00;
	
	printf("Value: %X\n\n", valueToPass);
	
	printf("Does a one bit exist?: %d\n\n", one_bit(valueToPass));
	printf("Does a zero bit exist?: %d\n\n", zero_bit(valueToPass));
	printf("One bit in least?: %d\n\n", least_One_bit(valueToPass));
	printf("Zero bit in most?: %d\n\n", most_Zero_bit(valueToPass));



}

//The 1 bit function will return 1 if any bit in the value is a 1
unsigned int one_bit(unsigned int passedValue) {

	/*
		This funciton will return one if a 1 exists as a bit of the hex value
		For this reason we can assume that a one exists in the binary meaning the hex value 
		will be non-zero
		
			0x00010000
			
		By performing ~ and ! operations we can isolate the value to see if a one exists and 
		set the funciton to evaluate to true if it does
		       0x00010000
		     ~ 0xFFFEFFFF <- Any starting mixed value will result in a mixed value here
		     ! 0x00000000 <- As the above value is positive, will result in zero
		     ! 0x00000001 <- Opposite of zero is one
		     
		     
		SPECIAL CASE if hex value is all ones
		       0x11111111
		     ~ 0xEEEEEEEE
		     ! 0x00000000 
		     !!0x00000001 <- Results in same outcome
		     
		However if it is all F, 
		       0xFFFFFFFF
		     ~ 0x00000000
		     ! 0x00000001 <- When the value is all F's then should stop at one ! 
		     
	*/
	
	//Check for special case when value is all F's
	if(!~passedValue) {
		//Return value for true when all F's have been used
		return !~passedValue;
	}

	//Otherwise return value indicating if a mixed value
	else {
	
		return !!~passedValue;
	}
}


unsigned int zero_bit(unsigned int passedValue) {

	/*
		   To determine if all values are zero meaning no one bits first use mask to see
		   if a zero bit exists
		    
		    Case 1: All Zeros
		      0x00000000
		 mask 0xFFFFFFFF
		 ---------------
	         ^    0xFFFFFFFF
	         !    0x00000000
	         !!   0x00000001
	         
	         
	              0xFFF0FFFF
		 mask 0xFFFFFFFF
		 ---------------
	         ^    0x000F0000
	         !    0x00000000
	         !!   0x00000001
	*/

	unsigned int mask = 0xFFFFFFFF;
	
	passedValue = passedValue ^ mask;
	
	return !!passedValue;

	
}


unsigned int least_One_bit(unsigned int passedValue) {

	/*
		Case 1: One One value	Case 2: No one value
		      0x0F0F0F0F	     0x000000FF
		mask  0x000000FF	mask 0x000000FF
		----------------	------------------
		&     0x0000000F	&    0x000000FF
		!     0x00000000	!    0x00000000
		!!    0x00000001	!!   0x00000001
		
		
	
		
	*/

	//Mask for filtering out least significant bit pair
	unsigned int mask =0x000000FF;

	passedValue = passedValue & mask;
	
	//Pass to one_bit() function to calculate the rest
	return !!passedValue;
	

}


unsigned int most_Zero_bit(unsigned int passedValue) {

	/*
		Case 1: one Zero	Case 2: Both zeros
		      0x0F0F0F0F	     0x00FFFFFF
		mask  0xFF000000	mask 0xFF000000
		----------------	---------------
		&     0x0F000000	&    0x00000000
		mask  0xFF000000	mask 0xFF000000
		----------------	---------------
		^     0x0F000000	^    0xFF000000
		!     0x00000000	!    0x00000000
		!!    0x00000001	!!   0x00000001
		
		
	*/

	//Mask for filtering out most significant bit pair
	unsigned int mask =0xFF000000;
	
	
	//Filter out most significant
	passedValue = passedValue & mask;
	
	
	
	//Takes exclusive or to locate one values in mask and value
	passedValue = passedValue ^ mask;
	
	
	return  !!passedValue;

}

