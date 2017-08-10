/* Answer of A:
The value of sizeof(val) is unsigned. When a expression has both unsigned 
and signed values, its result is unsigned. So (maxbytes - sizeof(val)) is 
a unsigned which is forever bigger than or equal 0;
*/
#include <stdio.h>
#include <string.h>

void copy_int(int val, void *buf, int maxbytes)
{
	if (maxbytes >= sizeof(val)){
		memcpy(buf,(void *)&val, sizeof(val));
	    printf("We made it.\n");
	}
}

int main(){
    int a[5];
    copy_int(4,a,3);/* example fail*/
    copy_int(4,a,4);/* example work*/
}