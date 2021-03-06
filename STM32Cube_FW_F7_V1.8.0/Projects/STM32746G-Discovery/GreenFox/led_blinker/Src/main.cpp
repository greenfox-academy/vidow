 /**
  ******************************************************************************
  * @file    Templates/Src/main.c 
  * @author  MCD Application Team
  * @version V1.0.3
  * @date    22-April-2016 
  * @brief   STM32F7xx HAL API Template project 
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2016 STMicroelectronics</center></h2>
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
#include "main.h"

/** @addtogroup STM32F7xx_HAL_Examples
  * @{
  */

/** @addtogroup Templates
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void Error_Handler(void);
static void MPU_Config(void);
static void CPU_CACHE_Enable(void);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */

void AllLedsOn(){

  GPIOF->ODR |= (1 << 6);
  GPIOF->ODR |= (1 << 7);
  GPIOA->ODR |= 1;
  GPIOF->ODR |= (1 << 10);
  GPIOF->ODR |= (1 << 8);
  GPIOF->ODR |= (1 << 9);

}

void AllLedsOff(){

  GPIOF->ODR &= ~(1 << 6);
  GPIOF->ODR &= ~(1 << 7);
  GPIOA->ODR &= ~(1 << 0);
  GPIOF->ODR &= ~(1 << 10);
  GPIOF->ODR &= ~(1 << 8);
  GPIOF->ODR &= ~(1 << 9);

}

void OneDChaseLight(int _delay){



  GPIOF->ODR |= (1 << 7); // First green led (A4 pin on board)
  HAL_Delay(_delay);
  GPIOF->ODR &= ~(1 << 7);

  GPIOA->ODR |= 1;
  HAL_Delay(_delay);
  GPIOA->ODR &= ~(1 << 0);

  GPIOF->ODR |= (1 << 10);
  HAL_Delay(_delay);
  GPIOF->ODR &= ~(1 << 10);

  GPIOF->ODR |= (1 << 8);
  HAL_Delay(_delay);
  GPIOF->ODR &= ~(1 << 8);

  GPIOF->ODR |= (1 << 9);
  HAL_Delay(_delay);
  GPIOF->ODR &= ~(1 << 9);

  GPIOF->ODR |= (1 << 6);
  HAL_Delay(_delay);
  GPIOF->ODR &= ~(1 << 6); //Last green led (A5 pin on board)

}

void TwoDChaseLight(int _delay){

  GPIOF->ODR |= (1 << 7);
  GPIOF->ODR |= (1 << 6);
  HAL_Delay(_delay);
  GPIOF->ODR &= ~(1 << 7);
  GPIOF->ODR &= ~(1 << 6);

  GPIOA->ODR |= 1;
  GPIOF->ODR |= (1 << 9);
  HAL_Delay(_delay);
  GPIOA->ODR &= ~(1 << 0);
  GPIOF->ODR &= ~(1 << 9);

  GPIOF->ODR |= (1 << 10);
  GPIOF->ODR |= (1 << 8);
  HAL_Delay(_delay);
  GPIOF->ODR &= ~(1 << 10);
  GPIOF->ODR &= ~(1 << 8);

  GPIOA->ODR |= 1;
  GPIOF->ODR |= (1 << 9);
  HAL_Delay(_delay);
  GPIOA->ODR &= ~(1 << 0);
  GPIOF->ODR &= ~(1 << 9);

}

int main(void)
{

  /* This project template calls firstly two functions in order to configure MPU feature 
     and to enable the CPU Cache, respectively MPU_Config() and CPU_CACHE_Enable().
     These functions are provided as template implementation that User may integrate 
     in his application, to enhance the performance in case of use of AXI interface 
     with several masters. */ 
  
  /* Configure the MPU attributes as Write Through */
  MPU_Config();

  /* Enable the CPU Cache */
  CPU_CACHE_Enable();

  /* STM32F7xx HAL library initialization:
       - Configure the Flash ART accelerator on ITCM interface
       - Configure the Systick to generate an interrupt each 1 msec
       - Set NVIC Group Priority to 4
       - Low Level Initialization
     */
  HAL_Init();

  /* Configure the System clock to have a frequency of 216 MHz */
  SystemClock_Config();


  /* Add your application code here     */
//  BSP_LED_Init(LED_GREEN);
//  BSP_LED_On(LED_GREEN);
//  BSP_LED_Off(LED_GREEN);


  //BSP_LED_Init(LED_GREEN)

  __HAL_RCC_GPIOA_CLK_ENABLE();    // we need to enable the GPIOA port's clock first
  __HAL_RCC_GPIOF_CLK_ENABLE();    // we need to enable the GPIOF port's clock first
  __HAL_RCC_GPIOC_CLK_ENABLE();    // we need to enable the GPIOC port's clock first

//Requires for the first led
  GPIO_InitTypeDef tda;            // create a config structure
  tda.Pin = GPIO_PIN_0;            // this is about PIN 0
  tda.Mode = GPIO_MODE_OUTPUT_PP;  // Configure as output with push-up-down enabled
  tda.Pull = GPIO_PULLDOWN;        // the push-up-down should work as pulldown
  tda.Speed = GPIO_SPEED_HIGH;     // we need a high-speed output

  HAL_GPIO_Init(GPIOA, &tda);      // initialize the pin on GPIOA port with HAL
//Requires for the other 5 leds
  GPIO_InitTypeDef tdf;            // create a config structure
  tdf.Pin = GPIO_PIN_10 | GPIO_PIN_9 | GPIO_PIN_8 | GPIO_PIN_7 | GPIO_PIN_6;            // this is about PIN 10
  tdf.Mode = GPIO_MODE_OUTPUT_PP;  // Configure as output with push-up-down enabled
  tdf.Pull = GPIO_PULLDOWN;        // the push-up-down should work as pulldown
  tdf.Speed = GPIO_SPEED_HIGH;     // we need a high-speed output

  HAL_GPIO_Init(GPIOF, &tdf);      // initialize the pin on GPIOA port with HAL

//Requires for the button.
  GPIO_InitTypeDef tdc;            // create a config structure
  tdc.Pin = GPIO_PIN_7;            // this is about PIN 10
  tdc.Mode = GPIO_MODE_INPUT;  // Configure as output with push-up-down enabled
  tdc.Pull = GPIO_PULLUP;        // the push-up-down should work as pullup
  tdc.Speed = GPIO_SPEED_HIGH;     // we need a high-speed output

  HAL_GPIO_Init(GPIOC, &tdc);      // initialize the pin on GPIOA port with HAL

  /* Infinite loop */

				///////////////////////////////////////////
				// Adding LED struct and defined the leds//
				///////////////////////////////////////////
 struct LED {
	  	  GPIO_InitTypeDef a;
	  	  GPIO_TypeDef *b;
  };

 struct LED L0 = {tda, GPIOA};
 struct LED L1 = {tdf, GPIOF};
 struct LED L2 = {tdf, GPIOF};
 struct LED L3 = {tdf, GPIOF};
 struct LED L4 = {tdf, GPIOF};
 struct LED L5 = {tdf, GPIOF};

 struct LED led_array[5];
 led_array[0] = L0;
 led_array[1] = L1;
 led_array[2] = L2;
 led_array[3] = L3;
 led_array[4] = L4;
 led_array[5] = L5;


  int counter = 0;
  bool state = false;

  while (1)
  {
				 ///////////////////////////////////////
				 //Day 1, Introduction to STM32, GPIO//
				 /////////////////////////////////////
/*
	  //HAL_Delay(200); //Green led flashes every 2 sec.
	  BSP_LED_Toggle(LED_GREEN);
	  HAL_Delay(200);


	  //TODO:
	  //Flash the ledwith 200 ms period time
*/
				////////////////////////////////
				//Day 2 project, first circuit//
				////////////////////////////////

//All leds blinking using HAL GPIO.

//	  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_6, GPIO_PIN_SET);    // setting the pin to 8
//	  HAL_Delay(1000);										 // wait a second
//	  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_6, GPIO_PIN_RESET);  // setting the pin to 0
//
//	  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_SET);    // setting the pin to 8
//	  HAL_Delay(1000);										 // wait a second
//	  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);  // setting the pin to 0
//
//	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);    // setting the pin to 1
//	  HAL_Delay(1000);                                       // wait a second
//	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);  // setting the pin to 0
//
//	  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);   // setting the pin to 10
//	  HAL_Delay(1000);                                       // wait a second
//	  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET); // setting the pin to 0
//
//	  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET);    // setting the pin to 8
//	  HAL_Delay(1000);										 // wait a second
//	  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);  // setting the pin to 0
//
//	  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);    // setting the pin to 9
//	  HAL_Delay(1000);
//	  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);  // setting the pin to 0

//All leds blinking using ODR.

//	  GPIOF->ODR |= (1 << 6);           // set the lowest bit to 8, leave the others as they are (this will set the lowest bit - PIN 0 - to 1)
//	  HAL_Delay(1000);                  // wait a second
//	  GPIOF->ODR &= ~(1 << 6);
//
//	  GPIOF->ODR |= (1 << 7);           // set the lowest bit to 8, leave the others as they are (this will set the lowest bit - PIN 0 - to 1)
//	  HAL_Delay(1000);                  // wait a second
//	  GPIOF->ODR &= ~(1 << 7);
//
//	  GPIOA->ODR |= 1;          		// set the lowest bit to 1, leave the others as they are (this will set the lowest bit - PIN 0 - to 1)
//	  HAL_Delay(1000);                  // wait a second
//	  GPIOA->ODR &= ~(1 << 0); 			// this will set the lowest bit (PIN 0) to 0. Guess why! - Because 0xFFFFFFFE is many 0 and 1 thus it negates the first line, aka sets the state to 0.
//
//	  GPIOF->ODR |= (1 << 10);          // set the lowest bit to 10, leave the others as they are (this will set the lowest bit - PIN 0 - to 1)
//	  HAL_Delay(1000);                  // wait a second
//	  GPIOF->ODR &= ~(1 << 10); 		// this will set the lowest bit (PIN 0) to 0.
//
//	  GPIOF->ODR |= (1 << 8);           // set the lowest bit to 8, leave the others as they are (this will set the lowest bit - PIN 0 - to 1)
//	  HAL_Delay(1000);                  // wait a second
//	  GPIOF->ODR &= ~(1 << 8); 			// this will set the lowest bit (PIN 0) to 0.
//
//	  GPIOF->ODR |= (1 << 9);           // set the lowest bit to 9, leave the others as they are (this will set the lowest bit - PIN 0 - to 1)
//	  HAL_Delay(1000);                  // wait a second
//	  GPIOF->ODR &= ~(1 << 9); 			// this will set the lowest bit (PIN 0) to 0.

					/////////////////////////////////
					// Day 3 project, GPIO practice//
					/////////////////////////////////

// Leds lights up upon a press of a button and go off upon pressing again, however it is not stable, using functions.

		  if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7) == 0) {
			  counter++;
			  HAL_Delay(10);
			  if (counter > 1)
				  counter = 0;
		  }

		  if (counter == 0) {

			AllLedsOff();

		  }
		  else if (counter == 1) {

			AllLedsOn();

		  }

// Leds light up using true/false bool.

//		  if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7) == 1) {
//			  HAL_Delay(10);
//			  if (counter > 1)
//				  counter = 0;
//		  }
//
//		  if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7) == 1) {
//
//			  GPIOF->ODR &= ~(1 << 6);
//			  GPIOF->ODR &= ~(1 << 7);
//			  GPIOA->ODR &= ~(1 << 0);
//			  GPIOF->ODR &= ~(1 << 10);
//			  GPIOF->ODR &= ~(1 << 8);
//			  GPIOF->ODR &= ~(1 << 9);
//
//		  }
//
//		  else if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7) == 1) {
//
//			  GPIOF->ODR |= (1 << 6);
//		  	  GPIOF->ODR |= (1 << 7);
//		  	  GPIOA->ODR |= 1;
//		  	  GPIOF->ODR |= (1 << 10);
//		  	  GPIOF->ODR |= (1 << 8);
//		  	  GPIOF->ODR |= (1 << 9);
//
//		  }


//One direction chase light with function with adjustable delay.


//	  OneDChaseLight(1000);

//Two direction chase light with function with adjustable delay.

//	  TwoDChaseLight(150);

//Chase light where pressing the button switches between One and Two direction chase light with constant delay.

//	  if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7) == 0) {
//		  counter++;
//		  HAL_Delay(10);
//		  if (counter > 1)
//			  counter = 0;
//	  }
//
//	  if (counter == 0) {
//
//		  OneDChaseLight(250);
//
//	  }
//	  else if (counter == 1) {
//
//		  TwoDChaseLight(250);
//
//	  }

//Switching speed between One direction chase light with a press of the button.

//	  if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7) == 0) {
//		  counter++;
//		  HAL_Delay(10);
//		  if (counter > 2)
//			  counter = 0;
//	  }
//
//	  if (counter == 0) {
//		  OneDChaseLight(500);
//	  }
//	  if (counter == 1) {
//		  OneDChaseLight(100);
//	  }
////Extra function which switches to Two direction light.
//	  if (counter == 2) {
//		  TwoDChaseLight(250);
//	  }

  }
}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 216000000
  *            HCLK(Hz)                       = 216000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 4
  *            APB2 Prescaler                 = 2
  *            HSE Frequency(Hz)              = 25000000
  *            PLL_M                          = 25
  *            PLL_N                          = 432
  *            PLL_P                          = 2
  *            PLL_Q                          = 9
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale1 mode
  *            Flash Latency(WS)              = 7
  * @param  None
  * @retval None
  */
static void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 432;  
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 9;
  if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /* activate the OverDrive to reach the 216 Mhz Frequency */
  if(HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }
  
  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;  
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;  
  if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
static void Error_Handler(void)
{
  /* User may add here some code to deal with this error */
  while(1)
  {
  }
}

/**
  * @brief  Configure the MPU attributes as Write Through for SRAM1/2.
  * @note   The Base Address is 0x20010000 since this memory interface is the AXI.
  *         The Region Size is 256KB, it is related to SRAM1 and SRAM2  memory size.
  * @param  None
  * @retval None
  */
static void MPU_Config(void)
{
  MPU_Region_InitTypeDef MPU_InitStruct;
  
  /* Disable the MPU */
  HAL_MPU_Disable();

  /* Configure the MPU attributes as WT for SRAM */
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.BaseAddress = 0x20010000;
  MPU_InitStruct.Size = MPU_REGION_SIZE_256KB;
  MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER0;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
  MPU_InitStruct.SubRegionDisable = 0x00;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);

  /* Enable the MPU */
  HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}

/**
  * @brief  CPU L1-Cache enable.
  * @param  None
  * @retval None
  */
static void CPU_CACHE_Enable(void)
{
  /* Enable I-Cache */
  SCB_EnableICache();

  /* Enable D-Cache */
  SCB_EnableDCache();
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
