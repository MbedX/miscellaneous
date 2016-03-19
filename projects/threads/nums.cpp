#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 5
struct nums{
  int times;
  int num;
};
void *printhello(void *threadarg){
   struct nums *data;
   data = (struct nums *)threadarg;
   for(int i = 0; i < data->times;i++){
      cout << data->num;
   }
   pthread_exit(NULL);
}

int main(){

   pthread_t threads[NUM_THREADS];
   struct nums numarray[NUM_THREADS];
   int rc;
   int i;
   for(i = 0; i < NUM_THREADS; i++){
      cout << "main(): create thread, " << i << endl;
      numarray[i].times = 2000;
      numarray[i].num = i;
      rc = pthread_create(&threads[i],NULL,printhello,(void *)&numarray[i]);
      if(rc){
         cout << "Error:unable to create thread, " << rc << endl;
         exit(-1);
      }
      rc = pthread_join(threads[i],NULL);
      if(rc){
         cout << "ERROR: unable to join threads" << endl;
         exit(-1);
      }
   }
   pthread_exit(NULL);
}
