#include <stdio.h>

void memrep(char *c, int n){
   int i;
   for(i = 0; i < n; i++){
      printf("%.2x ", c[i]);
   }
   printf("\n");
}

int main(){
   int num = 0x01234567;
   memrep((char *)&num,sizeof(num));
   getchar();
   return 0;

}
