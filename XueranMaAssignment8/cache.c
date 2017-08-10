#include <stdio.h>
#include <stdlib.h> 

//Define a struct to represent a cache block.
typedef unsigned char *byte_pointer;

//learn from assignment1 for print out as individual bytes
void show_bytes(byte_pointer start, int len){
	int i;
	for (i=0;i<len;i++)
	     printf("%.2x",start[i]);
	//printf("\n");
}

//define struct to represent a cache block
struct cache_block
{
	unsigned char v; //valid
	unsigned int tag; //tag
	unsigned int value; //value
	
};

int main()
{
	//Allocate enough memory to hold 16 cache blocks (1 per set).
	struct cache_block* cache = (struct cache_block*)malloc(16*sizeof(struct cache_block));

	//Initialize your cache such that all blocks are invalid.
    for (int i=0;i<16;i++){
    	cache[i].v = '0';
    }
    char a;
    int istrue=1;
    while(istrue==1){
    	//Repeatedly prompt the user
    	printf("%s\n","\nEnter 'r' for read, 'w' for write, 'p' to print, 'q' to quit: " );
    	scanf("%s",&a); //get an order from user
    	//when 'q', quit the loop
        if (a=='q'){
            //quit the loop
            istrue =0;
        //when 'w', write the cache
    	}else if (a =='w'){
    		printf("%s\n", "Enter a 32-bit unsigned hex address : " );
    		unsigned int x, value, s, t;
    		scanf("%x",&x); //get address
    		printf("%s\n","Enter a 32-bit unsigned hex value : " );
            scanf("%x",&value); //get value to write
            // get the 4 bits of set number without tag bits and offset bits
            s = x;
            s = s <<26 >>28;
            //get the 26 bits of tag without set number bits and offset bits
            t = x;
            t = t >> 6;
            //check if an valid block exits, then evict it, print it
            if (cache[s].v=='1'){
            	unsigned int old_t, old_v;
            	old_t = cache[s].tag;
            	old_v = cache[s].value;
            	printf("evicting block: -set: %x -tag: %x -valid: 1 -value: ",s,old_t );
            	show_bytes((byte_pointer)&old_v,4);
            	printf("\n");
            } 
            // print the wrote block  
            cache[s].v = '1';
            cache[s].tag = t;
            cache[s].value = value;
            printf("wrote set: %x -tag: %x -valid: 1 -value: ",s,t);
            show_bytes((byte_pointer)&value,4);
        
        //when 'r', read the cache
    	}else if(a=='r'){
            printf("%s\n", "Enter a 32-bit unsigned hex address : " );
            unsigned int x, t_a, t_c, s, o;
            unsigned int value;
            scanf("%x",&x); // get the address to read
            // get the 4 bits of set number without tag bits and offset bits
            s = x;
            s = s<<26 >>28;
            //get the 26 bits of tag without set number bits and offset bits
            t_a = x;
            t_a = t_a >> 6;
            //get the final 2bits, which is offset 
            o = x;
            o = o<<30>>30;
            //print the set number and tag to find
            printf("looking for set: %x and tag: %x\n" ,s,t_a);
            // if no valid block exits, print miss
            if (cache[s].v=='0'){
            	printf("%s","No valid set found - miss!");
            //if valid block exits, print it
            }else{
            	t_c = cache[s].tag;
                value = cache[s].value; 
                byte_pointer pvalue = &value;
                short int n_value = pvalue[o];
            	printf("found set: %x -tag: %x -offset: %x -valid: 1 -value: ",s,t_c,o);
            	show_bytes((byte_pointer) &n_value, 1);
                //tag matches, print hit, else print miss
            	if (t_a==t_c){
            		printf("\n%s","hit!");
            	}else{
            		printf("\n%s","Tags don't match! - miss!");
            	}

            }
          
        //when 'p', print all the valid blocks
    	}else if(a=='p'){
            for (int i=0;i<16;i++){
            	if (cache[i].v=='1'){
            		printf("set: %x -tag: %x -valid: 1 -value: ",i,cache[i].tag);
            		show_bytes((byte_pointer)&cache[i].value,4);
            		printf("\n");
            	}

    	}
            }

    }

	//free the memory
	free(cache);
	
	return 0;
}