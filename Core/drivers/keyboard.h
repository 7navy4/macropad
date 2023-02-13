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
#include "usbd_hid.h"
#include "port.h"


#define RowNumber		3
#define ColumnNumber	4


typedef enum key{
	KeyNone = 0x00,
	KeyA = 0x04,
	KeyB,
	KeyC,
	KeyD,
	KeyE,
	KeyF,
	KeyG,
	KeyH,
	KeyI,
	KeyJ,
	KeyK,
	KeyL,
	KeyM,
	KeyN,
	KeyO,
	KeyP,
	KeyQ,
	KeyR,
	KeyS,
	KeyT,
	KeyU,
	KeyV,
	KeyW,
	KeyX,
	KeyY,
	KeyZ,
	KeyEnter =	0x28,
	KeyESC,
	KeyDel,
	KeyTab,
	KeySpace,
	KeyF1	=	0x3A,
	KeyF2,
	KeyF3,
	KeyF4,
	KeyF5,
	KeyF6,
	KeyF7,
	KeyF8,
	KeyF9,
	KeyF10,
	KeyF11,
	KeyF12,
	Ralt	=	0b01000000,
	Rshift 	= 	0b00100000,
	Rctrl	=	0b00010000,
	Lalt	=	0b00000100,
	Lshift	=	0b00000010,
	Lctrl	=	0b00000001

};
/*

uint8_t modeEagle[12][7] = {
		{KeyD, KeyI, KeyS, KeyP, KeyL, KeyA, KeyY},
		{KeyG, KeyR, KeyO, KeyU, KeyP},
		{KeyM, KeyO, KeyV, KeyE},
		{KeyM, KeyI, KeyR, KeyR, KeyO, KeyR},
		{KeyR, KeyO, KeyT, KeyA, KeyT, KeyE},
		{KeyA, KeyL, KeyI, KeyG, KeyN},
		{KeyC, KeyO, KeyP, KeyY},
		{KeyP, KeyA, KeyS, KeyT, KeyE},
		{KeyD, KeyE, KeyL, KeyE, KeyT, KeyE},
		{KeyR, KeyO, KeyU, KeyT, KeyE},
		{KeyR, KeyI, KeyP, KeyU, KeyP},
		{KeyH, KeyO, KeyL, KeyE},

};*/


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


uint8_t scan(void);
GPIO_PinState rowread(uint8_t rowNumber);
void setcolumn(uint8_t columnNumber);
void resetcolumn(uint8_t columnNumber);
void keystroke(uint8_t key, uint8_t modifier);


#endif /* KEYBOARD_H_ */
