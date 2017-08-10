#include <stdio.h>
#include <stdlib.h> 

int main(void){
        //Prompts the user for an integer array length.
        int a,i,j,p,q,min,swap;
        printf("Please enter a number as the array length\n");
        scanf("%d",&a);//get integer from user
        //Uses the malloc() function to allocate the array
        int *arrayp;
        arrayp = (int *)malloc(a);
        //judge if malloc() succeeds
        if (arrayp == NULL) exit(1);

        //Prompts the user to enter an integer for each array element
        printf("Please enter %d integers as elements in the array\n",a);
        for (i=0;i<a;i++){//get a integers
        	int n;
        	scanf("%d",&n);//get one integer once
        	arrayp[i] = n;//store the value in the array
        }
       

        //Sorts the array in ascending order using Selection Sort
        for (p=0;p<(a-1);p++){//p<a-1 because the last one is the min for itself
        	min =p;
        	for(q = p+1;q<a;q++){//compare all others with min
        		if (arrayp[min]>arrayp[q]){
        			min = q;
        		}
        	}
        	if(min != p){//swap smaller forward 
                swap = arrayp[p];
                arrayp[p] = arrayp[min];
                arrayp[min] = swap;
        	}
        }

        //Prints the sorted contents of the array
        printf("Sorted array in ascending order:\n");
        for (j = 0;j<a;j++){
        	printf("%d\n",arrayp[j]);
        }

        //Frees the memory allocated for the array using the free() function.
        free(arrayp);
}