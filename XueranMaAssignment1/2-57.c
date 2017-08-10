#include <stdio.h>
/*credits: learn from figure 2.4 in textbook
*/
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len){
	int i;
	for (i=0;i<len;i++)
	     printf("%.2x",start[i]);
	printf("\n");
}

void show_short(short int x){
	show_bytes((byte_pointer) &x, sizeof(short int));
}

void show_long(long int x){
	show_bytes((byte_pointer) &x, sizeof(long int));
}

void show_double(double x){
	show_bytes((byte_pointer) &x, sizeof(double));
}
void show_char(char x){
	show_bytes((byte_pointer) &x, sizeof(char));
}


int main(void){
	short int s_int = 8;
	long int l_int =  88;
	double d_flt =   888;

	show_short(s_int);
	show_long(l_int);
	show_double(d_flt);

	return 0;
}