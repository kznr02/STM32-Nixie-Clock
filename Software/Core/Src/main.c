/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "oled.h"
#include "wifi.h"
#include "string.h"
#include "DS3231_IIC.h"
#include "K155ID1.h"
#include "jansson.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */



#define SOFT_DELAY		Delay(0x4FFFFF);
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

uint8_t RxBuf[BufSize];
uint8_t RxChar;									//单字接收缓存
extern char* SysTime1;					//纯数字时间存储区
int i = 0;											//接收缓存index
uint8_t JSON_RCVD = 0;					//json接受软标志位
uint8_t IT_Status = 0;					//软中断标志位
extern _calendar_obj calendar;	//日历结构�?
extern char Timejson[64];		//时钟json报文

extern Nixie Nixie_One;
extern Nixie Nixie_Two;
extern Nixie Nixie_Three;
extern Nixie Nixie_Four;

uint8_t ON_OFF_STA = 1;
uint8_t TUBE_CNT = 0;
#define TUBE_CNT_LIMIT 10


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
int CharToInt(char * string, int pos1, int pos2);   //字符（串）转int型函�?
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  MX_USART3_UART_Init();
  MX_SPI2_Init();
  /* USER CODE BEGIN 2 */
	OLED_Init();
	WIFI_Init();
	I2C_DS3231_Init();
	Nixie_Self_Chk();
	HAL_UART_Receive_IT(&huart3,&RxChar,1);
	HAL_TIM_Base_Start_IT(&htim2);
	OLED_Clear();
	OLED_Clock();
	OLED_ShowNum(16,5,calendar.sec,2,16);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		if(JSON_RCVD == 1)
		{
			json_error_t error;
			json_t *root;
			root = json_loads(Timejson,0, &error);
			if(json_is_object(root))
			{
				SysTime1 = (char *)json_string_value(json_object_get(root, "sysTime1"));
				json_decref(root);
				IT_Status = 1;			
				JSON_RCVD = 0;
			}
		}
		if(IT_Status == 1)
		{
			IT_Status = 0;
			I2C_DS3231_SetTime(CharToInt(SysTime1,1,4),
													CharToInt(SysTime1,5,6),
													CharToInt(SysTime1,7,8),
													CharToInt(SysTime1,9,10),
													CharToInt(SysTime1,11,12),
													CharToInt(SysTime1,13,14));
		}
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		
		
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV2;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
int CharToInt(char * string, int pos1, int pos2)
{
	int res=0;
	int tmp;
	int gap = pos2 - pos1;
	for(int i=0;i<=gap;i++)
	{
		tmp = (int)string[pos1+i-1]-48;
		for(int k=0;k<gap-i;k++)
		{
            tmp*=10;
        }
        res+=tmp;
	}
    return res;
}
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	switch(GPIO_Pin)
	{
		case KEY1_Pin :
		{
			if(ON_OFF_STA == 0)
			{
				Nixie_Display_Set(ALL,ON);
				ON_OFF_STA = 1;
				TUBE_CNT = 0;
			}
		}
		case KEY2_Pin :
		{
			WIFI_GetTime();
			JSON_RCVD = 1;
			IT_Status = 1;
		}
		case KEY3_Pin :
		{
		}
	} 
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	TUBE_CNT++;
		if(ON_OFF_STA == 1 && TUBE_CNT > TUBE_CNT_LIMIT)
		{
			Nixie_Display_Set(ALL,OFF);
			TUBE_CNT = 0;
			ON_OFF_STA = 0;
		}
		HAL_GPIO_TogglePin(GPIOB ,GPIO_PIN_4);
		I2C_DS3231_getTime();
		OLED_Clock();
		OLED_ShowNum(16,5,calendar.sec,2,16);
		if(ON_OFF_STA == 1)
		Nixie_Num_Set(ALL,ALL_CURR);
}




void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	RxBuf[i++] = RxChar;
	if(huart->Instance == USART3)
	{
		if(RxBuf[i-1] == 0x0A && RxBuf[i-2] == 0x0D)
		{
			memset(RxBuf,0x00,i);
			i = 0;
		}
		
		if(RxBuf[i-1] == 0x7D && RxBuf[i-2] == 0x22)
		{
			strcpy(Timejson, (char *)RxBuf);
			memset(RxBuf,0x00,i);
			i = 0;
			JSON_RCVD = 1;
		}	
	}
	HAL_UART_Receive_IT(&huart3,&RxChar,1);
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
 // __disable_irq();
  while (1)
 {
   }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
