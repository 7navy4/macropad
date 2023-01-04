/*
 * keyboard.c
 *
 *  Created on: Dec 7, 2022
 *      Author: Furkan Ayaz
 */


#include "keyboard.h"


extern USBD_HandleTypeDef hUsbDeviceFS;

keyboardHID keyboardhid = {0,0,0,0,0,0,0,0};





static uint16_t rowPin[RowNumber]={PinRow1,PinRow2,PinRow3};
static uint16_t columnPin[ColumnNumber]={PinColumn1,PinColumn2,PinColumn3,PinColumn4};
static GPIO_TypeDef *rowPort[RowNumber]={PortRow1,PortRow2,PortRow1};
static GPIO_TypeDef *columnPort[ColumnNumber]={PortColumn1,PortColumn2,PortColumn3,PortColumn4};

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
		setcolumn(i);
		for(int j=0;j<RowNumber;j++)
		{
			if(rowread(j)==GPIO_PIN_SET)
			{
				pressedButton=j*4+i+1;
				resetcolumn(i);
				return pressedButton;
			}

		}
		resetcolumn(i);
	}
	return pressedButton;
}
