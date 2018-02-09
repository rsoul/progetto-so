#include "servo.h"

int main(){
	initGPIO();
	testRotation();
	closeGPIO();
}
