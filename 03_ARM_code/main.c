#include "main.h"

static void delay_int_count(volatile unsigned int nTime){
  for(;nTime>0;nTime--);
}

int main(void){
    (*(volatile unsigned*)0x40023830)|=0x000001ff;
    
    (*(volatile unsigned*)0x40021C00)|=0x55555555;  //H   
    (*(volatile unsigned*)0x40022000)|=0x55555555;  //I
    
  
  while(1){
    GPIOH_BSRR |= S_LED3|S_LED4;
    GPIOI_BSRR |= S_LED9|S_LED11;   
    delay_int_count(600000); 
    
    GPIOH_BSRR |= R_LED3|R_LED4; 
    GPIOI_BSRR |= R_LED9|R_LED11;  
    delay_int_count(600000); 
  }
}