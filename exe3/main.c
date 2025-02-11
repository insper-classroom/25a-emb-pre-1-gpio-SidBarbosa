#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_G_PIN = 26;
const int BTN_R_PIN = 28;

const int LED_G_PIN = 6;
const int LED_R_PIN = 4;


int main() {
  stdio_init_all();
  
  gpio_init(BTN_G_PIN);
  gpio_set_dir(BTN_G_PIN, GPIO_IN);
  gpio_pull_up(BTN_G_PIN);

  gpio_init(BTN_R_PIN);
  gpio_set_dir(BTN_R_PIN, GPIO_IN);
  gpio_pull_up(BTN_R_PIN);

  gpio_init(LED_G_PIN);
  gpio_set_dir(LED_G_PIN, GPIO_OUT);

  gpio_init(LED_R_PIN);
  gpio_set_dir(LED_R_PIN, GPIO_OUT);

  int c1 =1,c2=1;

  while(true){
    if(!gpio_get(BTN_G_PIN)){
      c1 ++;
      if(c1 % 2 == 0){
        gpio_put(LED_G_PIN, 1);
      }else{
        gpio_put(LED_G_PIN, 0);
      }
      while(!gpio_get(BTN_G_PIN)){
      }
    }else if(!gpio_get(BTN_R_PIN)){
      c2 ++;
      if(c2 % 2 == 0){
        gpio_put(LED_R_PIN, 1);
      }else{
        gpio_put(LED_R_PIN, 0);
      }
      while(!gpio_get(BTN_R_PIN)){
      }
    }
  }    
}
