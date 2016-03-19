#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
using namespace std;
#define MAX 64

void GPIOenable(int pin, char strng[], char val[], char dir[]);
void GPIOexport(FILE *gpiofile, char strng[], char setval[]);

int main(){
        int GPIOPin = 60;
	FILE *LEDHandle = NULL;
	char setValue[4], GPIOString[4],GPIOValue[MAX], GPIODirection[MAX];
	GPIOenable(GPIOPin, GPIOString, GPIOValue, GPIODirection);

        //export the pin
	GPIOexport(LEDHandle, GPIOString, setValue);


	//set the direction of the pin
	if((LEDHandle = fopen(GPIODirection, "rb+")) == NULL){
		printf("Cannot open direction handle.\n");
		return 1;
	}
	strcpy(setValue, "out");
	fwrite(&setValue, sizeof(char), 3, LEDHandle);
	fclose(LEDHandle);

	//flash the LED
	int times = 20; 
	for(int i=0; i<(times*2); i++){
		if((LEDHandle = fopen(GPIOValue, "rb+")) == NULL){
			printf("Cannot open value handle.\n");
			return 1;
		}
		if((i%2)==1){
			strcpy(setValue,"0");
		}
		else{
			strcpy(setValue,"1");
		}
		fwrite(&setValue, sizeof(char), 1, LEDHandle);
		fclose(LEDHandle);
	//	sleep(10);
		usleep(500000);
	}
	
	//unexport the pin
	if((LEDHandle = fopen("/sys/class/gpio/unexport", "ab")) == NULL){
		printf("Cannot unexport the GPIO pin.\n");
		return 1;
	}
	strcpy(setValue, GPIOString);
	fwrite(&setValue, sizeof(char), 2, LEDHandle);
	fclose(LEDHandle);

	cout << "GPIO LED Flash Pin:" << GPIOPin << " end" << endl;

	return 0;
}

void GPIOenable(int pin,char strng[], char val[], char dir[]){

	cout << "GPIO LED Flash Pin:" << pin << " start" << endl;
	sprintf(strng, "%d", pin);
	sprintf(val, "/sys/class/gpio/gpio%d/value", pin);
	sprintf(dir, "/sys/class/gpio/gpio%d/direction", pin);
	
}

void GPIOexport(FILE *gpiofile, char strng[], char setval[]){
	if((gpiofile = fopen("/sys/class/gpio/export", "ab")) == NULL){
		printf("Cannot export the GPIO pin.\n");
	}
	else{
		strcpy(setval, strng);
		fwrite(&setval, sizeof(char), 2, gpiofile);
		fclose(gpiofile);
	}
}
