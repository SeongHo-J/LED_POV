#include "stm32f4xx.h"
#include "main.h"

void Delay(uint32_t nCount)
{
     __IO uint32_t i;   //__IO mean volatile
      for(i=0; nCount > i; i++);
}

int main(void){
   RCC->AHB1ENR |= GPIOIEN|GPIOHEN;
   GPIOH->MODER |= GPIO_MODER_MODER2_0|GPIO_MODER_MODER3_0;  
   GPIOI->MODER |= GPIO_MODER_MODER8_0|GPIO_MODER_MODER10_0;    
    
  
  while(1){
    GPIOH->BSRRL |= LED3|LED4;
    GPIOI->BSRRL |= LED9|LED11;   
    Delay(10000000); 
    
    GPIOH->BSRRH |= LED3|LED4; 
    GPIOI->BSRRH |= LED9|LED11;  
    Delay(10000000); 
  }
}