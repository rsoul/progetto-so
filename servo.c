//Servo controlling module //
//                         //
// by Raoul Nuccetelli     //
// using pin 2 for 5v      //
// using pin 6 for ground  //
// using pin 12(GPIO 18) to modulate PWM    //
#include <stdio.h>
#include <bcm2835.h>
#include <stdlib.h>
#include "servo.h"


#define PI 180
#define PIN RPI_GPIO_P1_12
#define CHANNEL 0
#define RANGE 1024

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

void moveCamera(signed int angle,int currentPos){
	//clockwise
	if (angle>0){
		bcm2835_pwm_set_data(CHANNEL,110);
		bcm2835_delayMicroseconds(800000*(angle/PI));
		bcm2835_pwm_set_data(CHANNEL,0);
		currentPos-=angle; //update position
	}
	//counterclockwise
	else if(angle<0){
		bcm2835_pwm_set_data(CHANNEL,30);
		bcm2835_delayMicroseconds(200000*(-angle/PI));
		bcm2835_pwm_set_data(CHANNEL,0);
		currentPos+=angle; //update position
	}
 }

void initGPIO(){
	if(bcm2835_init()){
		bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_ALT5); 	
		bcm2835_pwm_set_clock(375);
    	bcm2835_pwm_set_mode(CHANNEL, 1, 1);
    	bcm2835_pwm_set_range(CHANNEL, RANGE);
		printf("Servo up and running!\n");}
	else{
		printf("Unable to initialize GPIO... Shutting down.\n");
		exit(EXIT_FAILURE);
	}
}

void closeGPIO(){
	if(bcm2835_close()){
		printf("All GPIO connections closed!\n");}
	else{
		printf("Unable to close GPIO \n");
		exit(EXIT_FAILURE);
	}
}
