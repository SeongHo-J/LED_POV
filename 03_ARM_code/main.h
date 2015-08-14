#include <stdint.h>

#define  GPIOAEN RCC_AHB1ENR_GPIOAEN
#define  GPIOBEN RCC_AHB1ENR_GPIOBEN 
#define  GPIOCEN RCC_AHB1ENR_GPIOCEN 
#define  GPIODEN RCC_AHB1ENR_GPIODEN 
#define  GPIOEEN RCC_AHB1ENR_GPIOEEN 
#define  GPIOFEN RCC_AHB1ENR_GPIOFEN 
#define  GPIOGEN RCC_AHB1ENR_GPIOGEN 
#define  GPIOHEN RCC_AHB1ENR_GPIOHEN 
#define  GPIOIEN RCC_AHB1ENR_GPIOIEN 

#define LED1  ((uint16_t)0x0001)
#define LED2  ((uint16_t)0x0002) 
#define LED3  ((uint16_t)0x0004) 
#define LED4  ((uint16_t)0x0008) 
#define LED5  ((uint16_t)0x0010) 
#define LED6  ((uint16_t)0x0020) 
#define LED7  ((uint16_t)0x0040) 
#define LED8  ((uint16_t)0x0080) 
#define LED9  ((uint16_t)0x0100) 
#define LED10 ((uint16_t)0x0200) 
#define LED11 ((uint16_t)0x0400) 
#define LED12 ((uint16_t)0x0800) 
#define LED13 ((uint16_t)0x1000) 
#define LED14 ((uint16_t)0x2000) 
#define LED15 ((uint16_t)0x4000) 
#define LED16 ((uint16_t)0x8000)