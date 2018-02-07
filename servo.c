//Servo controlling module //
//                         //
// by Raoul Nuccetelli     //


#include <stdio.h>
#define PI 180

int calculateAngle(int currentPos,signed int angle){
	if (currentPos+angle>2*PI){
		return currentPos+angle-2*PI;
	}
	else if(currentPos+angle<0){
		return currentPos+angle+2*PI;
	}
	else{
		return angle;
	}
}

void moveCamera(signed int angle){

	//pwm
}

void initGPIO(){


	printf("Up and running!\n");
}

void closeGPIO(){

	printf("All GPIO connections closed!\n");
}