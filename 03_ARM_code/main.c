#include "stm32f4xx.h"
#include "main.h"

//
#define StartUp_TimeOut ((uint16_t)0x0500)
#define NVIC_Vect_Tab_RAM



//

void _delay(int nCount)         //0.101us
{
     __IO uint32_t i;   //__IO mean volatile
      for(i=0; nCount*11 > i; i++);
}


void _delay_us(int nCount)
{
     __IO uint32_t i;   //__IO mean volatile
      for(i=0; nCount*110 > i; i++);
}

void _delay_ms(int nCount)
{
     __IO uint32_t i;   //__IO mean volatile
      for(i=0; nCount*110000 > i; i++);
}

void PUT();
void RCC_Con();


static volatile uint32_t TimingDelay;
  
  void TimingDelay_Decrement(void)
  {
    if(TimingDelay != 0x00)
    {
      TimingDelay--;
    }
  }
  
  void SysTick_Handler(void)
  {
    TimingDelay_Decrement();
  }
  
  void Delay(uint32_t nTime)
  {
    TimingDelay = nTime;
    while(TimingDelay != 0);
  }
  
    void delay_ms(void)
  {
    Delay(1000);
  }


int main(void){
     
   RCC->AHB1ENR |= GPIOIEN|GPIOHEN;
   GPIOH->MODER |= GPIO_MODER_MODER2_0|GPIO_MODER_MODER3_0; 
   GPIOH->OSPEEDR |= 0xAAAAAAAA;
   GPIOI->MODER |= GPIO_MODER_MODER8_0|GPIO_MODER_MODER10_0;    
 
  RCC_Con();
  RCC_ClocksTypeDef RCC_Clocks;
  RCC_GetClocksFreq(&RCC_Clocks);  
  SysTick_Config(RCC_Clocks.SYSCLK_Frequency/1000); 
  
   while(1){
     
      GPIOH->BSRRL |= LED3|LED4|LED5|LED6|LED7|LED8|LED9|LED10|LED11|LED12|LED13|LED14|LED15|LED16;
      delay_ms();
      GPIOH->BSRRH |= LED3|LED4|LED5|LED6|LED7|LED8|LED9|LED10|LED11|LED12|LED13|LED14|LED15|LED16;
      delay_ms();
       
        /*PUT(1);
	PUT(1);
	PUT(1);
	PUT(1);
	PUT(1);
	PUT(1);
	PUT(1);
	PUT(1);
		
	PUT(1);
	PUT(1);
	PUT(1);
	PUT(1);
	PUT(1);
	PUT(1);
	PUT(1);
	PUT(1);
		
	PUT(1);
	PUT(1);
	PUT(1);
	PUT(1);
	PUT(1);
	PUT(1);
	PUT(1);
	PUT(1);	*/   
  }
}

void PUT(int i){
	if(i==1){
		GPIOH->BSRRL |= LED1|LED2|LED3|LED4|LED5|LED6|LED7|LED8|LED9|LED10|LED11|LED12|LED13|LED14|LED15|LED16;
		_delay(4);
		GPIOH->BSRRH |= LED1|LED2|LED3|LED4|LED5|LED6|LED7|LED8|LED9|LED10|LED11|LED12|LED13|LED14|LED15|LED16;
		_delay(3);
	}
	else if(i==0){
		GPIOH->BSRRL |= LED1|LED2|LED3|LED4|LED5|LED6|LED7|LED8|LED9|LED10|LED11|LED12|LED13|LED14|LED15|LED16;
		_delay(2);
		GPIOH->BSRRH |= LED1|LED2|LED3|LED4|LED5|LED6|LED7|LED8|LED9|LED10|LED11|LED12|LED13|LED14|LED15|LED16;
		_delay(5);
	}
	else if(i==2){		
		GPIOH->BSRRH |= LED1|LED2|LED3|LED4|LED5|LED6|LED7|LED8|LED9|LED10|LED11|LED12|LED13|LED14|LED15|LED16;
		_delay_us(60);		
	}

	
}
/*
//
uint32_t SysTick_config(uint32_t ticks)
{
  if(ticks > SYSTICK_MAXCOUNT) return(1);
  
  SysTick->LOAD = (ticks & SYSTICK_MAXCOUNT)-1;
  NVIC_SetPriority (SysTick_IRQn,(1<<_NVIC_PRIO_BITS)-1);
  SysTick->VAL = (0x00);
  SysTick->CTRL = (1<<SYSTICK_CLKSOURCE)|(1<<SYSTICK_ENABLE)|(1<<SYSTICK_TICKINT);
  return (0);
}
*/

void RCC_Con(){
  
  int StartUpCounter;
  int HSIStatus;
  
  RCC->CR |=((uint32_t)RCC_CR_HSION);
   do{
     HSIStatus = RCC->CR & RCC_CR_HSIRDY;
     StartUpCounter++;
   }while((HSIStatus == 0)&&(StartUpCounter != StartUp_TimeOut));
   
   FLASH->ACR |= ((uint8_t)0x02);
   RCC->CFGR |= (uint32_t)RCC_CFGR_HPRE_DIV1;
   RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE2_DIV1;
   RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE1_DIV2;
   RCC->PLLCFGR |= (uint32_t)RCC_PLLCFGR_PLLSRC_HSI;
   RCC->PLLCFGR |= (uint32_t)(RCC_PLLCFGR_PLLM_0|RCC_PLLCFGR_PLLM_3);
   RCC->PLLCFGR |= (uint32_t)(RCC_PLLCFGR_PLLN_1|RCC_PLLCFGR_PLLN_4|RCC_PLLCFGR_PLLN_6|RCC_PLLCFGR_PLLN_7); 
   RCC->PLLCFGR |= (uint32_t)(RCC_PLLCFGR_PLLP_1);
   
       
   RCC->CR |= RCC_CR_PLLON;
   while((RCC->CR & RCC_CR_PLLRDY)==0){;}
   
   RCC->CFGR |= (uint32_t)RCC_CFGR_SW_PLL;
   while((RCC->CFGR & (uint32_t)RCC_CFGR_SWS_PLL) != (uint32_t)0x08){;}
  
  
}