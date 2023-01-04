/*
 * test.h
 *
 *  Created on: Dec 12, 2022
 *      Author: Furkan Ayaz
 */

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include "main.h"



#define RowNumber		3
#define ColumnNumber	4

#define SetOut			1
#define ResetOut		0



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





typedef struct
{
	uint8_t MODIFIER;
	uint8_t RESERVED;
	uint8_t KEYKODE1;
	uint8_t KEYKODE2;
	uint8_t KEYKODE3;
	uint8_t KEYKODE4;
	uint8_t KEYKODE5;
	uint8_t KEYKODE6;
}keyboardHID;


typedef struct{


}Keyboard_HandleTypedef;



GPIO_PinState rowread(uint8_t rowNumber);
void setcolumn(uint8_t columnNumber);
void resetcolumn(uint8_t columnNumber);
uint8_t scan(void);

#endif /* KEYBOARD_H_ */
