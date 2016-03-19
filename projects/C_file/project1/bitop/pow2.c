#include <stdio.h>

bool power2(unsigned int num);

int main(int argc, char* argv[]){
   if(argc != 2){
      printf("\nERROR: WRONG NUMBER OF ARGUEMENTS\n");
      exit(-1);
   }
   int num = atoi(argv[1]);
   if(num < 0){
      printf("\nERROR: Number must be a positive integer\n");
      exit(-1);
   }
   if(power2(num)){
      printf("\n%d is a power of 2\n",num);
   }
   else{
      printf("\n%d is not a power of 2\n",num);
   }
   return 0;
}
bool power2(unsigned int n){
  return ((s & (~s + 1)) == s);
}

