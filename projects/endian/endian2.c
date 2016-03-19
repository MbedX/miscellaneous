#include <stdio.h>

int main(){
   unsigned int num = 0x01000000;
   char *c = (char *)&num;
   int i = 0;
   for(i = 0; i < sizeof(num); i++){
      printf("Address of byte %d: %x Contents of byte %d: %x\n",i,&c[i],i,*(c+i));
   }
   if(!*(c)){
      printf("LITTLE ENDIAN\n");

   }
   else{
      printf("BIG ENDIAN\n");
   }
   return 0;
}
