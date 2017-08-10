#include <stdio.h>
#include <stdlib.h> 
typedef struct ELE *tree_ptr;

struct ELE {
    long val;
    tree_ptr left;
    tree_ptr right;
 };
//find the most left of the tree
long trace(tree_ptr tp){
 	
 	long result=0;//%eax = 0
    // tp == 0 jump to .L3, else jump to .L5
 	while(tp!=0){
        result = tp ->val; //movq (%rdi), %rax
        tp = tp->left;//movq 16(%rdi), %rdi
 	}
 	return result;
 }

int main()
 {  //the root.left.left
    struct ELE t4 = {.val =9, .left=NULL, .right = NULL};
    //the root.right
 	struct ELE t3 = {.val = 5, .left = NULL, .right =NULL};
    //the root.left
 	struct ELE t2 = {.val = 4, .left = &t4, .right = NULL};
 	//define the root
 	struct ELE t1 = {.val = 3, .left = &t2, .right = &t3};
 	//trace from the root and find the most left one
    long value = trace(&t1);
    printf("The leftest value of the tree is %ld\n",value);
 	return 0;
 }