#include <iostream>
#include <mutex>
#include <thread>
#include <cstdlib>

//using namespace std;
std::mutex mx;

void print_block(int n, char c){
   mx.lock();
   for(int i = 0; i < n; i++) {std::cout << c;}
   std::cout << std::endl;
   mx.unlock();
}

int main(){
   std::thread t1(print_block,50,'*');
   std::thread t2(print_block,50,'+');

   t1.join();
   t2.join(); 

   return 0;
}
