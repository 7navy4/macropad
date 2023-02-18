/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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

#define DisplayRowSize		12
#define DisplayColumnSize	7

uint8_t cursorPosition,topMenuPosition,bottomMenuPosition,nodeTransition;
uint16_t DisplayOption,ButtonMode;
uint32_t Button,rotary1Counter,rotary2Counter,prevRotary1Counter;
char DisplayBuffer[DisplayRowSize][DisplayColumnSize];
volatile uint32_t lastDebounceTime,menuEnterStartTime,displayStartTime;


#define menuDebounceTime			1000
#define ButtonDebounceTime 			350
#define TransitionDelayCount		2
#define ButtonDisplayTime			500

typedef enum{
	DisplayOptionAddres,
	ButtonModeAddres
}EeAddresses;

typedef enum{
	DisplayAll,
	DisplayPressed
}Dmode;

typedef enum{
	ModeEagle,
	ModeKicad,
	ModePhotoshop,
	ModePremiere,
	ModeCustom1,
	ModeCustom2,
	ModeCustom3
}Bmode;



uint8_t pressedButton,menuFlag,displayFlag,updateFlag, buttonMode;


/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

void systemInit(void);
void systemControl(void);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
