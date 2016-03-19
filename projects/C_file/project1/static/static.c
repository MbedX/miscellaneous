#include <stdio.h>

char** message1();
char** message2();

int main(){

   char** s = NULL;
   char** t = NULL;
//   s = message1();
//   t = message2();
//   printf("Message1: %s Address: %x\nMessage2: %s Address %x\n",*s,s,*t,t);
   printf("Message1: %s\n",*(message1()));
   return 0;
}

char** message1(){
   static char* p = "Hello";
   
   return &p;
}

char** message2(){
   static char* p = "goodbye";
   return &p;
}
