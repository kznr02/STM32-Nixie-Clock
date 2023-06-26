/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define CS1_1_Pin GPIO_PIN_0
#define CS1_1_GPIO_Port GPIOA
#define CS1_2_Pin GPIO_PIN_1
#define CS1_2_GPIO_Port GPIOA
#define CS1_3_Pin GPIO_PIN_2
#define CS1_3_GPIO_Port GPIOA
#define CS1_4_Pin GPIO_PIN_3
#define CS1_4_GPIO_Port GPIOA
#define CS2_1_Pin GPIO_PIN_4
#define CS2_1_GPIO_Port GPIOA
#define CS2_2_Pin GPIO_PIN_5
#define CS2_2_GPIO_Port GPIOA
#define CS2_3_Pin GPIO_PIN_6
#define CS2_3_GPIO_Port GPIOA
#define CS2_4_Pin GPIO_PIN_7
#define CS2_4_GPIO_Port GPIOA
#define CS4_1_Pin GPIO_PIN_0
#define CS4_1_GPIO_Port GPIOB
#define CS4_2_Pin GPIO_PIN_1
#define CS4_2_GPIO_Port GPIOB
#define SPI2_DC_Pin GPIO_PIN_12
#define SPI2_DC_GPIO_Port GPIOB
#define SPI2_RST_Pin GPIO_PIN_14
#define SPI2_RST_GPIO_Port GPIOB
#define CS3_1_Pin GPIO_PIN_8
#define CS3_1_GPIO_Port GPIOA
#define CS3_2_Pin GPIO_PIN_9
#define CS3_2_GPIO_Port GPIOA
#define CS3_3_Pin GPIO_PIN_10
#define CS3_3_GPIO_Port GPIOA
#define CS3_4_Pin GPIO_PIN_11
#define CS3_4_GPIO_Port GPIOA
#define KEY3_Pin GPIO_PIN_12
#define KEY3_GPIO_Port GPIOA
#define KEY3_EXTI_IRQn EXTI15_10_IRQn
#define KEY2_Pin GPIO_PIN_15
#define KEY2_GPIO_Port GPIOA
#define KEY2_EXTI_IRQn EXTI15_10_IRQn
#define SPI2_CS_Pin GPIO_PIN_3
#define SPI2_CS_GPIO_Port GPIOB
#define LED1_Pin GPIO_PIN_4
#define LED1_GPIO_Port GPIOB
#define KEY1_Pin GPIO_PIN_5
#define KEY1_GPIO_Port GPIOB
#define KEY1_EXTI_IRQn EXTI9_5_IRQn
#define IIC_SCL_Pin GPIO_PIN_6
#define IIC_SCL_GPIO_Port GPIOB
#define IIC_SDA_Pin GPIO_PIN_7
#define IIC_SDA_GPIO_Port GPIOB
#define CS4_3_Pin GPIO_PIN_8
#define CS4_3_GPIO_Port GPIOB
#define CS4_4_Pin GPIO_PIN_9
#define CS4_4_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
