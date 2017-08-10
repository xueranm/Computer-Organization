#include <stdio.h>
/*credits: learn from https://github.com/xinqiu/MyCode/blob/master/CSAPP/Chap2/2-60.c
*/
unsigned replace_byte(unsigned x, int i, unsigned char b)
{
	return ~(~x | (0xFF << (i * 8)))|((unsigned)b << (i * 8));
}

int main()
{
	unsigned x = 0x12345678;
	int i = 2;
	int j = 0;
	char b = 0xAB;
	printf("%X\n%X\n", replace_byte(x, i, b),replace_byte(x,j,b));
	return 0;
}