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
    int limit = length -3;//the final 3 need be add seperately
	data_t *udata = get_vec_start(u);
	data_t *vdata = get_vec_start(v);
    //4 different accumulators
	data_t sum = (data_t) 0;
    data_t sum1 = (data_t) 0;
    data_t sum2 = (data_t) 0;
    data_t sum3 = (data_t) 0;


	for (i = 0; i < limit; i += 4) {
		sum = sum + udata[i] * vdata[i];
        sum1 = sum1 + udata[i+1] * vdata[i+1];
        sum2 = sum2 + udata[i+2] * vdata[i+2];
        sum3 = sum3 + udata[i+3] * vdata[i+3];
	}
    //the final 3 need be add seperately
    for (; i <length;i++){
        sum += udata[i] * vdata[i];
    }
	*dest = sum + sum1 + sum2 + sum3;
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

    data_t *dest;
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

