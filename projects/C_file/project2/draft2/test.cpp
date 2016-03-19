#include <iostream>
#include <stdlib.h>
using namespace std;

void change(int *num);

int main(){
	int x[4] = {1,2,3,4};
	for(int i = 0; i < 4; i++){
		cout << x[i] << " ";
        }
	cout << endl;
	change(x);
	for(int j = 0; j < 4; j++){
	
		cout << x[j] << " ";
	}
	cout << endl;
	return 0;
	
}
void change(int num[]){
	num[0] = 5;
        num[1] = 6;
	num[2] = 7;
	num[3] = 8;
}
