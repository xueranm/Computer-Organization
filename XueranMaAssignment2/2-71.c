/* Answer of A:
     The wrong with this code is that the integer returned is not signed. 
     First, when the word right shifts, it's still a unsigned value and its 
     right shift is logical shift which adds 0's at the leading.
     In addition, &0xFF clears off everything to 0's except for the byte.
     So the first bite is forever 0, and the returned value is forever unsigned.
*/
#include <stdio.h>

typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum)
{   /* Move the byte to the most significant position
	and change unsigned to signed.*/
	int byte = word << ((3-bytenum)<<3);
    /*sign extension to 32 bits*/
	return byte >>24;
} 

int main(void){
	int x = 0x22998811;
	/* 0 and 3 are positive signed, 1 and 2 are negative signed.*/ 
	printf("0:%X\n1:%X\n2:%X\n3:%X\n", xbyte(x, 0),xbyte(x, 1),xbyte(x, 2),xbyte(x, 3) );
}