#include <stdio.h>  /* printf, scanf, NULL */
#include <stdlib.h>  /* malloc, free, rand, system */
#include <string.h>
#include <sys/time.h> /*for caculate time*/

#define VECTOR_SIZE 20000000
typedef long long data_t;
typedef data_t *vec_ptr;
data_t * get_vec_start(vec_ptr v) {
    return v;
}

int vec_length(vec_ptr v) {
    return VECTOR_SIZE;
}



void inner4(vec_ptr u, vec_ptr v, data_t *dest){
    long int i;
    int length = vec_length(u);
	data_t *udata = get_vec_start(u);
	data_t *vdata = get_vec_start(v);
	data_t sum = (data_t) 0;
	for (i = 0; i < length; i++) {
		sum = sum + udata[i] * vdata[i];
	}
	*dest = sum;
}
int main(){
	vec_ptr a = (data_t*) malloc(sizeof(data_t) * VECTOR_SIZE);
	vec_ptr b = (data_t*) malloc(sizeof(data_t) * VECTOR_SIZE);
	data_t i = 0;
	data_t p = 3;

    for (int j = 0; j<VECTOR_SIZE;j++){
    	a[j]=i;
        i++;
    }
    for (int j = 0; j<VECTOR_SIZE;j++){
    	b[j]=p;
        p++;
    }
    //printf("%s\n", "number in a and b:");
    for (int q = 0;q<VECTOR_SIZE;q++){
    	//printf("%llu %llu\n",a[q],b[q]);

    }

    data_t* dest;
    data_t init = 0;
    dest = &init;
    //time starts
    struct timeval start;
    gettimeofday(&start, NULL);
    
    

    inner4(a,b,dest);
    //time finishes
    struct timeval current;
    gettimeofday(&current, NULL);
    //caculate the time between start and finish
    long long elapsed = 1000000LL*(current.tv_sec - start.tv_sec) + (current.tv_usec - start.tv_usec);
    printf("%s\n","Time spent:" );
    printf("%f\n",elapsed/1000000.0);


    data_t result = *dest;
    printf("number of dest:%llu\n",result);


}

