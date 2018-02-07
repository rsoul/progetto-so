//Servo controlling module //
//                         //
// by Raoul Nuccetelli     //
// using pin 2 for 5v      //
// using pin 6 for ground  //
// using pin 12(GPIO 18) for GPIO    //


#include <stdio.h>
#include <bcm2835.h>
#define PI 180
#define PIN RPI_GPIO_P1_12
#define CHANNEL 0
#define RANGE 2000

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
 //devo testare per poter scrivere questa funzione
}

void testRotation(){
	for (int i = 0; i <5; i++)
	{
		bcm2835_gpio_write(PIN,HIGH);
		bcm2835_delay(1000);
	}

	for (int i = 0; i < 5; i++)
	{
		bcm2835_gpio_write(PIN,LOW);
		bcm2835_delay(1000);
	}
}

void initGPIO(){
	if(bcm2835_init()){
		bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP); 	
		bcm2835_pwm_set_clock(BCM2835_PWM_CLOCK_DIVIDER_16);
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