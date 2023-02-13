/*
 * port.h
 *
 *  Created on: Dec 24, 2022
 *      Author: Furkan Ayaz
 */

#ifndef PORT_H_
#define PORT_H_

#include "main.h"


extern I2C_HandleTypeDef hi2c1;

#define SetOut			GPIO_PIN_SET
#define ResetOut		GPIO_PIN_RESET

#define PortRow1			GPIOB
#define PortRow2			GPIOB
#define PortRow3			GPIOB

#define PortColumn1			GPIOA
#define PortColumn2			GPIOB
#define PortColumn3			GPIOA
#define PortColumn4			GPIOB

#define PinRow1				GPIO_PIN_2
#define PinRow2				GPIO_PIN_10
#define PinRow3				GPIO_PIN_11

#define PinColumn1			GPIO_PIN_7
#define PinColumn2			GPIO_PIN_0
#define PinColumn3			GPIO_PIN_6
#define PinColumn4			GPIO_PIN_1



#define rEncoder1ButonPort		GPIOA
#define rEncoder2ButonPort		GPIOA

#define rEncoder1ButonPin		GPIO_PIN_10
#define rEncoder2ButonPin		GPIO_PIN_9

#define readRotary1Button	HAL_GPIO_ReadPin(rEncoder1ButonPort,rEncoder1ButonPin)
#define readRotary2Button	HAL_GPIO_ReadPin(rEncoder2ButonPort,rEncoder2ButonPin)


#define hi2cScreen			hi2c1



#endif /* PORT_H_ */
