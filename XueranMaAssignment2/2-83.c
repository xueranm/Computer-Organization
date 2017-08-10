#include <stdio.h>

unsigned f2u(float f){
	typedef union{
		float f;
		unsigned i;
	} u;
	u u1;
	u1.f = f;
	return u1.i;
}
int float_le(float x, float y)
{
	unsigned ux = f2u(x);
	unsigned uy = f2u(y);

	unsigned sx = ux >> 31;
	unsigned sy = uy >> 31;
    
    /* return 1 if x <= y, else 0*/
	return (ux <<1 ==0 && uy <<1 ==0)|| /*x= y =0*/
	(sx && !sy)||                       /* x <0, y>=0*/
	(!sx && !sy && ux <= uy)||          /* x>=0,y>=0*/
	(sx && sy && ux >= uy);             /*x<0, y<0 */
}


int main()
{
	int a = float_le(1.0,2.0);
	int b = float_le(-5,5);
	int c = float_le(12.375, 11.375);
	printf("float_le(1.0,2.0): %X\nfloat_le(-5,5): %X\nfloat_le(12.375,11.375): %X\n",a,b,c);
}