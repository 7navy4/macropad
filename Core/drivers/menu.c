/*
 * menu.c
 *
 *  Created on: Jan 14, 2023
 *      Author: 7navy4
 */

/*------------------------------------------------------------------------------------*/
#include "menu.h"
#include "main.h"
#include "string.h"
#include "ssd1306.h"

#include "port.h"

/*------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------*/








void InitMenu(){


	/*Prev Next Up Down*/
	BuildMenu(&mainM, "Main", 1, executeMain, 0, &buttonM, 0, 0);
	BuildMenu(&buttonM, "Button", 2, executeButton, &mainM, &displayM, 0, &scrollM);
	BuildMenu(&scrollM, "Scroll",  2, executeScroll, &mainM, 0, &buttonM, 0);
	BuildMenu(&displayM, "Display", 2, executeDisplay, &buttonM, &allM, 0, &modeM);
	BuildMenu(&modeM, 	"Mode", 2, executeMode, &buttonM, &eagleM, &displayM, 0);
	BuildMenu(&allM, "All", 2, executeAll, &displayM, 0, 0, &pressedM);
	BuildMenu(&pressedM, "Pressed", 2, executePressed, &displayM, 0, &allM, 0);
	BuildMenu(&eagleM, "Eagle", 7, executeEagle, &modeM, 0, 0, &kicadM);
	BuildMenu(&kicadM, "Kicad", 7, executeKicad, &modeM, 0, &eagleM, &photosopM);
	BuildMenu(&photosopM, "Photoshop", 7, executePhotoshop, &modeM, 0, &kicadM, &premiereM);
	BuildMenu(&premiereM, "Premiere", 7, executePremiere, &modeM, 0, &photosopM, &custom1);
	BuildMenu(&custom1, "Custom 1", 7, executeCustom1,	&modeM, 0, &premiereM, &custom2);
	BuildMenu(&custom2, "Custom 2", 7, executeCustom2,	&modeM, 0, &custom1, &custom3);
	BuildMenu(&custom3, "Custom 3", 7, executeCustom3,	&modeM, 0, &custom2, 0);
	currentM=&mainM;
}

/*------------------------------------------------------------------------------------*/
void executeMain(){
	//Print Buttons
}
/*------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------*/
void executeButton(){
	//Write Button To screen
}
/*------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------*/
void executeScroll(){

}
/*------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------*/
void executeDisplay(){

}
/*------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------*/
void executeMode(){

}

/*------------------------------------------------------------------------------------*/
void executeAll()
{
	DisplayOption = DisplayAll;
	DisplaySaved();
}
/*------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------*/
void executePressed()
{
	DisplayOption = DisplayPressed;
	DisplaySaved();
}
/*------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------*/
void executeEagle()
{
	ButtonMode = ModeEagle;
	DisplaySaved();
}
/*------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------*/
void executeKicad()
{
	ButtonMode = ModeKicad;
	DisplaySaved();
}
/*------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------*/
void executePhotoshop()
{
	ButtonMode = ModePhotoshop;
	DisplaySaved();
}
/*------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------*/
void executePremiere()
{
	ButtonMode = ModePremiere;
	DisplaySaved();
}
/*------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------*/
void executeCustom1()
{
	ButtonMode = ModeCustom1;
	DisplaySaved();
}
/*------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------*/
void executeCustom2()
{
	ButtonMode = ModeCustom2;
	DisplaySaved();
}
/*------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------*/
void executeCustom3()
{
	ButtonMode = ModeCustom2;
	DisplaySaved();
}
/*------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------*/
void BuildMenu(struct level *currentNode, char name[16], uint8_t numberOfSiblings, void (*execute)(void) , struct level *prevNode, struct level *nextNode,struct level *upNode,struct level *downNode)
{
    strcpy(currentNode->name, name);

   	currentNode->numberOfSiblings=numberOfSiblings;
    currentNode->prev = prevNode;
    currentNode->next = nextNode;
    currentNode->up = upNode;
    currentNode->down = downNode;
    currentNode->execute = execute;
}
/*------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------*/
void Up(struct level **currentNode)
{
  if( (*currentNode) ->up != 0)
  (*currentNode) = (*currentNode)->up;
}
/*------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------*/
void Down(struct level **currentNode)
{
  if( (*currentNode) ->down != 0)
  {
	(*currentNode) = (*currentNode)->down;
	setCursorPosition();
  }
}
/*------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------*/
void Next(struct level **currentNode)
{
	if((*currentNode)->execute != 0)
	{
		(*currentNode)->execute();
	}
	if((*currentNode)->next != 0)
	{
		(*currentNode) = (*currentNode)->next;

		setCursorPosition();
	}
}
/*------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------*/
void Prev(struct level **currentNode)
{
  if( (*currentNode) ->prev != 0)
  (*currentNode) = (*currentNode)->prev;
}
/*------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------*/
void MenuTransition(uint8_t *task){



	switch(*task)
	{
		case idleE:

			break;
		case upE:
			Up(&currentM);
			upMenuItem(currentM);
			drawMenu(currentM, cursorPosition);
			*task=idleE;
			break;
		case downE:
			Down(&currentM);
			downMenuItem(currentM);
			drawMenu(currentM, cursorPosition);
			*task=idleE;
			break;
		case nextE:
			Next(&currentM);
			drawMenu(currentM, cursorPosition);
			*task=idleE;
			break;
		case prevE:
			Prev(&currentM);
			if(strcmp(currentM->name,"Main") == 0){
				menuFlag = 0;

			}else
			{
			  setCursorPosition();
			  drawMenu(currentM, cursorPosition);
			}
			*task=idleE;
			break;
		default:
			break;

	}
}
/*------------------------------------------------------------------------------------*/



/*------------------------------------------------------------------------------------*/


void drawMenuItem(char *str, uint8_t line,uint8_t invert)
{
	ssd1306_SetCursor(10, (line-1)*19+2);
	ssd1306_WriteString("          ", Font_11x18,White);
	ssd1306_SetCursor(10, (line-1)*19+2);
	ssd1306_WriteString(str, Font_11x18, invert==0 ? White : Black);

}
void drawMenu(struct level *currentNode, uint8_t selectedItem){
	ssd1306_Fill(Black);



	if(cursorPosition == topMenuPosition)
	{
		drawMenuItem(currentM->name, 1, White);
		if(bottomMenuPosition >= topMenuPosition + 1)
		drawMenuItem(currentM->down->name, 2, Black);
		if(bottomMenuPosition == topMenuPosition + 2)
		drawMenuItem(currentM->down->down->name, 3, Black);

	}else if(cursorPosition - 1 == topMenuPosition)
	{
		drawMenuItem(currentM->up->name, 1, Black);
		drawMenuItem(currentM->name, 2, White);
		if(bottomMenuPosition == topMenuPosition + 2)
		drawMenuItem(currentM->down->name, 3, Black);
	}else if(cursorPosition - 2 == topMenuPosition)
	{
		drawMenuItem(currentM->up->up->name, 1, Black);
		drawMenuItem(currentM->up->name, 2, Black);
		drawMenuItem(currentM->name, 3, White);
	}
	ssd1306_UpdateScreen(&hi2cScreen);

}
/*------------------------------------------------------------------------------------*/

void setCursorPosition(){
	topMenuPosition = 1;
	bottomMenuPosition = currentM->numberOfSiblings <=3 ? currentM->numberOfSiblings : 3;
	cursorPosition = 1;

}

void downMenuItem(struct level *currentNode)
{
	cursorPosition++;
	if(cursorPosition>bottomMenuPosition && cursorPosition <= currentNode->numberOfSiblings)
	{
		topMenuPosition++;
		bottomMenuPosition++;
	}
	if(cursorPosition > currentNode->numberOfSiblings)
	{
		cursorPosition = currentNode->numberOfSiblings;
	}
}

void upMenuItem(struct level *currentNode){
	cursorPosition--;
	if(cursorPosition<topMenuPosition && cursorPosition>0)
	{
		topMenuPosition--;
		bottomMenuPosition--;
	}
	if(cursorPosition < 1)
	{
		cursorPosition = 1;
	}
}

void buttonControl()
{
	pressedButton = scan();

	//keystroke(key, modifier);


}

void encoderControl(){
	if(menuFlag==0)
	{
		if(readRotary1Button==GPIO_PIN_RESET)
		{
			if(HAL_GetTick() - menuEnterStartTime > menuDebounceTime)
			{
				menuFlag=1;
				rotary1Counter=0x0FFFFFFF;
				prevRotary1Counter=0x0FFFFFFF;
				setCursorPosition();
				drawMenu(currentM,1);
				while(readRotary1Button==GPIO_PIN_RESET);
			}

		}else{
			menuEnterStartTime = HAL_GetTick();
		}
	}
	else if(menuFlag==1)
		{

			MenuTransition(&nodeTransition);
			nodeTransition=0;
			if(prevRotary1Counter != rotary1Counter){
				if(prevRotary1Counter > rotary1Counter)
				{
					nodeTransition = downE;
				}else if(prevRotary1Counter < rotary1Counter)
				{
					nodeTransition = upE;
				}
			}
			if(HAL_GetTick() - menuEnterStartTime > ButtonDebounceTime)
			{
				if(readRotary1Button==GPIO_PIN_RESET)
				{
					nodeTransition = nextE;
					menuEnterStartTime = HAL_GetTick();
				}else if(readRotary2Button==GPIO_PIN_RESET)
				{
					nodeTransition = prevE;
					menuEnterStartTime = HAL_GetTick();
				}
			}
			prevRotary1Counter=rotary1Counter;


		}
}

void displayControl()
{
	if(menuFlag == 0){
		if(DisplayOption == DisplayAll)
		{

		}else if(DisplayOption == DisplayPressed)
		{

		}
		if(ButtonMode == ModeEagle)
		{

		}else if(ButtonMode == ModeEagle)
		{

		}else if(ButtonMode == ModePhotoshop)
		{

		}else if(ButtonMode == ModePremiere)
		{

		}else if(ButtonMode == ModeCustom1)
		{

		}else if(ButtonMode == ModeCustom2)
		{

		}else if(ButtonMode == ModeCustom3)
		{

		}
	}
}

void DisplaySaved(){

	ssd1306_Fill(Black);
	ssd1306_SetCursor(30, 20);
	ssd1306_WriteString("Saved", Font_11x18, Black);
	ssd1306_UpdateScreen(&hi2cScreen);
	HAL_Delay(750);
	ssd1306_Fill(Black);

}
