#include <stdio.h>
#include <stdlib.h>
#include <bcm2835.h>
int main(int argc, char** argv) {
  if (!bcm2835_init())
        return 1;
 bcm2835_gpio_fsel(18,BCM2835_GPIO_FSEL_ALT5 );    
 bcm2835_gpio_fsel(13,BCM2835_GPIO_FSEL_ALT0 );    
 
 bcm2835_pwm_set_clock(2);
 
 bcm2835_pwm_set_mode(0, 1, 1);
 bcm2835_pwm_set_range(0,2);
 bcm2835_pwm_set_data(0,1);
   
 bcm2835_pwm_set_mode(1, 1, 1);
 bcm2835_pwm_set_range(1,8);
 bcm2835_pwm_set_data(1,2);
 return (EXIT_SUCCESS);
}
