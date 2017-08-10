#include <stdio.h>

int decode2(int x, int y, int z){
	                        //line1: %edx = y
	int t1 = y - z;         //line2: %edx = t1 = %edx - z = y - z
	                        //line3: %eax = %edx = y - z
	                        //line4: %eax = %eax << 31
	int t2 = (t1<<31)>>31;  //line5: t2 = %eax = %eax >> 31 (arithmeric right shift)
    t1 = x * t1;            //line6: %edx = t1 = %edx * x = t1 * x
    t2 = t2 ^ t1;           //line7: %eax = %eax ^ %edx

    return t2;              //return value in %eax
}

int main(){
	printf("%d\n", decode2(1, 2, 4));
	printf("%d\n", decode2(-4, -8, -12));
}