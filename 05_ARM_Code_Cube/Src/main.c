/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  *
  * COPYRIGHT(c) 2015 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

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

static volatile uint32_t TimingDelay;

void Delay(uint32_t nTime)
{
  TimingDelay = nTime;
  while(TimingDelay != 0);
}

void delay_s(void)
{
  Delay(5000000);
}
void delay_ms(void)
{
  Delay(5000);
}
void delay_us(void)
{
  Delay(5);
}

void delay_60us(void)
{
  Delay(350);
}
void delay_800ns(void)
{
  Delay(4);
}

void delay_400ns(void)
{
  Delay(2);
}

void delay_200ns(void)
{
  Delay(1);
}

unsigned int k=0x0000;

void G_ON(){
  
        for(int j=1 ; j < 4 ; j++){
            HAL_GPIO_WritePin(GPIOF, k, GPIO_PIN_RESET);
            delay_400ns();                
            HAL_GPIO_WritePin(GPIOF, k, GPIO_PIN_SET);
            delay_800ns();
        }
        
        HAL_GPIO_WritePin(GPIOF, k, GPIO_PIN_RESET);
        delay_800ns();                
        HAL_GPIO_WritePin(GPIOF, k, GPIO_PIN_SET);
        delay_400ns();
        
        for(int j=1 ; j < 21 ; j++){
            HAL_GPIO_WritePin(GPIOF, k, GPIO_PIN_RESET);
            delay_400ns();                
            HAL_GPIO_WritePin(GPIOF, k, GPIO_PIN_SET);
            delay_800ns();
        }
}

void R_ON(){
  
        for(int j=1 ; j < 12 ; j++){
            HAL_GPIO_WritePin(GPIOF, k, GPIO_PIN_RESET);
            delay_400ns();                
            HAL_GPIO_WritePin(GPIOF, k, GPIO_PIN_SET);
            delay_800ns();
        }
        
        HAL_GPIO_WritePin(GPIOF, k, GPIO_PIN_RESET);
        delay_800ns();                
        HAL_GPIO_WritePin(GPIOF, k, GPIO_PIN_SET);
        delay_400ns();
        
        for(int j=1 ; j < 13 ; j++){
            HAL_GPIO_WritePin(GPIOF, k, GPIO_PIN_RESET);
            delay_400ns();                
            HAL_GPIO_WritePin(GPIOF, k, GPIO_PIN_SET);
            delay_800ns();
        }
}

void B_ON(){
  
        for(int j=1 ; j < 20 ; j++){
            HAL_GPIO_WritePin(GPIOF, k, GPIO_PIN_RESET);
            delay_400ns();                
            HAL_GPIO_WritePin(GPIOF, k, GPIO_PIN_SET);
            delay_800ns();
        }
        
        HAL_GPIO_WritePin(GPIOF, k, GPIO_PIN_RESET);
        delay_800ns();                
        HAL_GPIO_WritePin(GPIOF, k, GPIO_PIN_SET);
        delay_400ns();
        
        for(int j=1 ; j < 5 ; j++){
            HAL_GPIO_WritePin(GPIOF, k, GPIO_PIN_RESET);
            delay_400ns();                
            HAL_GPIO_WritePin(GPIOF, k, GPIO_PIN_SET);
            delay_800ns();
        }
}

void OFF(){    
        
        for(int j=1 ; j < 25 ; j++){
            HAL_GPIO_WritePin(GPIOF, 0xffff, GPIO_PIN_RESET);
            delay_400ns();                
            HAL_GPIO_WritePin(GPIOF, 0xffff, GPIO_PIN_SET);
            delay_800ns();
        }
}

void PUT(int i){
  
	if(i==1){
		HAL_GPIO_WritePin(GPIOF, 0xffff, GPIO_PIN_RESET);
                delay_800ns();                
                HAL_GPIO_WritePin(GPIOF, 0xffff, GPIO_PIN_SET);
                delay_400ns();                
	}
        
	else if(i==0){
		HAL_GPIO_WritePin(GPIOF, 0xffff, GPIO_PIN_RESET);
                delay_400ns();                              
                HAL_GPIO_WritePin(GPIOF, 0xffff, GPIO_PIN_SET);
                delay_800ns();               
	}
        
	else if(i==2){		
		HAL_GPIO_WritePin(GPIOF, 0xffff, GPIO_PIN_SET);                
                delay_60us(); 
	}	
}

void PUT_3(int i){
  
	if(i==1){
		HAL_GPIO_WritePin(GPIOF, 0x0f00, GPIO_PIN_RESET);
                delay_800ns();                
                HAL_GPIO_WritePin(GPIOF, 0x0f00, GPIO_PIN_SET);
                delay_400ns();                
	}
        
	else if(i==0){
		HAL_GPIO_WritePin(GPIOF, 0x0f00, GPIO_PIN_RESET);
                delay_400ns();                              
                HAL_GPIO_WritePin(GPIOF, 0x0f00, GPIO_PIN_SET);
                delay_800ns();               
	}
        
	else if(i==2){		
		HAL_GPIO_WritePin(GPIOF, 0x0f00, GPIO_PIN_SET);                
                delay_60us(); 
	}	
}

void PUT_1(int i){
  
	if(i==1){
		HAL_GPIO_WritePin(GPIOF, 0xf000, GPIO_PIN_RESET);
                delay_800ns();                
                HAL_GPIO_WritePin(GPIOF, 0xf000, GPIO_PIN_SET);
                delay_400ns();                
	}
        
	else if(i==0){
		HAL_GPIO_WritePin(GPIOF, 0xf000, GPIO_PIN_RESET);
                delay_400ns();                              
                HAL_GPIO_WritePin(GPIOF, 0xf000, GPIO_PIN_SET);
                delay_800ns();               
	}
        
	else if(i==2){		
		HAL_GPIO_WritePin(GPIOF, 0xf000, GPIO_PIN_SET);                
                delay_60us(); 
	}	
}
void PUT_2(int i){
  
	if(i==1){
		HAL_GPIO_WritePin(GPIOF, 0x00f0, GPIO_PIN_RESET);
                delay_800ns();                
                HAL_GPIO_WritePin(GPIOF, 0x00f0, GPIO_PIN_SET);
                delay_400ns();                
	}
        
	else if(i==0){
		HAL_GPIO_WritePin(GPIOF, 0x00f0, GPIO_PIN_RESET);
                delay_400ns();                              
                HAL_GPIO_WritePin(GPIOF, 0x00f0, GPIO_PIN_SET);
                delay_800ns();               
	}
        
	else if(i==2){		
		HAL_GPIO_WritePin(GPIOF, 0x00f0, GPIO_PIN_SET);                
                delay_60us(); 
	}	
}

/* USER CODE END 0 */

int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();

  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */

    //  HAL_GPIO_WritePin(GPIOF, 0xffff, GPIO_PIN_RESET);
    //   delay_s();                
    //  HAL_GPIO_WritePin(GPIOF, 0xffff, GPIO_PIN_SET);
    // delay_s();  
  
   k=0x0004;
   R_ON();
   k=0x0010;
   B_ON();
   k=0x0040;
   G_ON();
   delay_s();
   
   OFF();
   delay_ms();
   k=0x0010;
   G_ON();
   k=0x0040;
   R_ON();
   k=0x0002;
   B_ON();
   delay_s();
   
   OFF();
   delay_ms();
   k=0x0040;
   B_ON();
   k=0x0002;
   G_ON();
   k=0x0008;
   R_ON();
   delay_s();
   
   OFF();
   delay_ms();
   k=0x0002;
   B_ON();
   k=0x0008;
   G_ON();
   k=0x0020;
   R_ON();
   delay_s();
   
   OFF();
   delay_ms();
   k=0x0008;
   B_ON();
   k=0x0020;
   G_ON();
   k=0x0080;
   R_ON();
   delay_s();   
   
   OFF();
   delay_s();
  
  /* 
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(1);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
      
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(1);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   
   delay_s();
   
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(1);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
      
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(1);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   
   delay_s();

   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(1);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(1);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
      
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   
   delay_s();
   
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   PUT_1(0);
   
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
      
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   PUT_2(0);
   
   delay_s();
  */
  /*  
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT_1(1);
  PUT_2(0);
  PUT(0);
  PUT(0);
  PUT(0); 
  
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT_1(0);
  PUT_2(1);
  PUT(0);
  PUT(0);
  PUT(0);
  
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  delay_s();
 
  
  
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT_1(0);
  PUT_2(1);
  PUT(0);
  PUT(0);
  PUT(0);
  
  
  
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT_1(1);
  PUT_2(0);
  PUT(0);
  PUT(0);
  PUT(0);
  
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  delay_s(); 
  */
  /*
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  
  PUT(1);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  delay_s();
 
  
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  
  PUT(1);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  
  PUT(1);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  delay_s();
 
  
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  
  PUT(1);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  delay_s();

  
  PUT(1);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  
  PUT(1);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  PUT(0);
  delay_s();
*/
  
  /*
  HAL_GPIO_WritePin(GPIOF, 0xfffc, GPIO_PIN_SET);
  delay_s();
   
  HAL_GPIO_WritePin(GPIOF, 0xfffc, GPIO_PIN_RESET);
  delay_s(); 
  */
  
  }
  /* USER CODE END 3 */

}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

  __PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 5;
  RCC_OscInitStruct.PLL.PLLN = 225;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  HAL_PWREx_ActivateOverDrive();

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_PCLK1
                              |RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);

  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/5000000);

  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __GPIOF_CLK_ENABLE();
  __GPIOH_CLK_ENABLE();

  /*Configure GPIO pins : PF1 PF2 PF3 PF4 
                           PF5 PF6 PF7 PF8 
                           PF9 PF10 PF11 PF12 
                           PF13 PF14 PF15 */
  GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4 
                          |GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8 
                          |GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12 
                          |GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
