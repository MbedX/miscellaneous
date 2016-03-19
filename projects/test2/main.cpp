#include <iostream>
#include "shapes.h"
using namespace std;

int main(){
   shape * shape1 = new Rectangle(3,4);
   cout << "Area of shape1: " << shape1->area() << endl;
   delete shape1;
   return 0;
}
