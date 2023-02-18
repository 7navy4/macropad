/*
 * keyboard.c
 *
 *  Created on: Dec 7, 2022
 *      Author: Furkan Ayaz
 */


#include "keyboard.h"


uint8_t modeEagleKeys[DisplayRowSize][DisplayColumnSize] = {
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

};
char  modeEagleNames[DisplayRowSize][DisplayColumnSize] = {
		{"Dp"}, {"Gr"}, {"Mv"}, {"Mr"},
		{"Rt"}, {"Al"}, {"Cp"}, {"Pt"},
		{"Dl"}, {"Rt"}, {"Rp"}, {"Hl"}

};

uint8_t modeKicad[1][1] = {
0
};
static uint16_t rowPin[RowNumber]={PinRow1,PinRow2,PinRow3};
static uint16_t columnPin[ColumnNumber]={PinColumn1,PinColumn2,PinColumn3,PinColumn4};
static GPIO_TypeDef *rowPort[RowNumber]={PortRow1,PortRow2,PortRow1};
static GPIO_TypeDef *columnPort[ColumnNumber]={PortColumn1,PortColumn2,PortColumn3,PortColumn4};




extern USBD_HandleTypeDef hUsbDeviceFS;
keyboardHID keyboardhid = {0,0,0,0,0,0,0,0};





GPIO_PinState rowread(uint8_t rowNumber){
	return HAL_GPIO_ReadPin(rowPort[rowNumber],rowPin[rowNumber]);
}

void setcolumn(uint8_t columnNumber){
	HAL_GPIO_WritePin(columnPort[columnNumber],columnPin[columnNumber], GPIO_PIN_SET);
	for(int i=1;i<columnNumber;i++){
		HAL_GPIO_WritePin(columnPort[(columnNumber+i)%columnNumber],columnPin[(columnNumber+i)%columnNumber], GPIO_PIN_RESET);
	}
}

void resetcolumn(uint8_t columnNumber){
	HAL_GPIO_WritePin(columnPort[columnNumber],columnPin[columnNumber], GPIO_PIN_RESET);
}

uint8_t scan(){
	uint8_t pressedButton=0;

	for(int i=0; i<ColumnNumber;i++)
	{

		HAL_Delay(1);
		setcolumn(i);
		for(int j=0;j<RowNumber;j++)
		{
			if(rowread(j)==GPIO_PIN_SET)
			{
				pressedButton=j*4+i+1;
				resetcolumn(i);
				return pressedButton;

			}

			for(volatile int i=0; i<100;i++);
		}
		resetcolumn(i);
	}
	return pressedButton;
}





void keystroke(uint8_t key, uint8_t modifier){
	  keyboardhid.MODIFIER=modifier;
	  keyboardhid.KEYKODE1=key;
	  USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t *)&keyboardhid, sizeof(keyboardhid));
	  HAL_Delay(5);
	  keyboardhid.KEYKODE1=0x00;
	  keyboardhid.MODIFIER=0x00;
	  USBD_HID_SendReport(&hUsbDeviceFS,(uint8_t *)&keyboardhid,sizeof(keyboardhid));
}








