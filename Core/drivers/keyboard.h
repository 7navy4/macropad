/*
 * test.h
 *
 *  Created on: Dec 12, 2022
 *      Author: Furkan Ayaz
 */

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include "main.h"
#include "usb_device.h"
#include "port.h"


#define RowNumber		3
#define ColumnNumber	4





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
