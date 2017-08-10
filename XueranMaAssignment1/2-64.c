#include <stdio.h>
/*credit: learn from https://github.com/Tomilla/CS-APP2e/blob/master/Solution/Chapter%202/S2HP_2.64.c
*/
/* Return 1 when any odd bit of x equals 1; 0 otherwise.
Assume w=32. */
int any_odd_one(unsigned x){
	return !!(x & 0xAAAAAAAA);
}

int main(){
	unsigned x = 0x0;
	unsigned y = 0x1;
	unsigned z = 0x2;
	unsigned q = 0x3;
	unsigned p = 0xFFFFFFFF;
	unsigned t = 0x55555555;
	printf("%X\n%X\n%X\n%X\n%X\n%X\n", any_odd_one(x),any_odd_one(y),any_odd_one(z),any_odd_one(q),any_odd_one(p),any_odd_one(t));
}