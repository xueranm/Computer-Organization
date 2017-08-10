#include <stdio.h>
//because 13 is too big to test when typing in the integers in array
//change to 3, work the same
#define M 3
typedef int Marray_t[M][M];
//Credit: Learn from Yu Yifan
void transpose(Marray_t A) {
	int i, j;
	for (i = 0; i < M; i++){
		    //pass in the address of A in i row, 0 column
             int *p = &A[i][0];
            //pass in the address of A in 0 row, i column
             int *q = &A[0][i];

		for (j = 0; j < i; j++) {
			//pass the value of p to t
			int t = *p;
			// pass the value of q to p
			*p = *q;
			//pass the value of t to q
			*q = t;
			//p points to next value in A in i row 
			p++;
			//q points to next value in A in i column
			q = q+M;
		}
	}
}

int main(){
	int i,j;
	Marray_t A = {{1,2,3,},{4,5,6,},{7,8,9}};
	for (i =0;i<M;i++){
		for (j = 0; j<M;j++){
		    printf("Before transpose, values of A[%d][%d] = %d\n",i,j,A[i][j]);
		    
	    }
	}
	transpose(A);
	
	
	for (i =0;i<M;i++){
		for (j = 0; j<M;j++){
		    printf("After transpose, values of A[%d][%d] = %d\n",i,j,A[i][j]);
		    
	    }
	}
	
}