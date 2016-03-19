#include <stdio.h>
#include <stdlib.h>

#define MIN(A,B) (A <= B ? A : B)

void main(int argc, char *argv[]){
   if(argc != 3){
      printf("\nERROR: Wrong number of Arguments\n");
      exit(1);
   }
   int a,b,min;
   int* p1[2];
   p1[0] = &a;
   p1[1] = &b;
   printf("\nAddress of p1[0]: %x Address of p1[1]: %x\n",p1[0],p1[1]);
   *(int*)(&a + 1) = -1;
   int* const temp = p1[0];
   a = atoi(argv[1]);
   b = atoi(argv[2]);

   min = MIN(*p1[0]++,*p1[1]);

   printf("\nA: %d  B: %d MIN: %d\n",*p1[0],*p1[1],min);
   printf("Before: %d At: %d After: %d\n",*(p1[0]-1),*p1[0],*(p1[0]+1));
   printf("\nAfter: \nAddress of p1[0]: %x Address of p1[1]: %x\n",p1[0],p1[1]);
}
