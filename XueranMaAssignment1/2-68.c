#include <stdio.h>
/*credits:https://github.com/Tomilla/CS-APP2e/blob/master/Solution/Chapter%202/S2HP_2.68.c
*/
int lower_one_mask(int n){
	return (2<<(n-1))-1;
}

int main(){
	unsigned n = 1;
	unsigned m = 2;
	unsigned t = 3;
	unsigned p = 5;
	printf("%u\n%u\n%u\n%u\n", lower_one_mask(n), lower_one_mask(m), lower_one_mask(t),lower_one_mask(p));
}