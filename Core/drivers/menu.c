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


/*------------------------------------------------------------------------------------*/
char MainMenuItems[][maxCharacterOfMenuItem]		={"Button","Scroll"};
char ButtonMenuItems[][maxCharacterOfMenuItem]	={"Display","Mode"};
char DisplayMenuItems[][maxCharacterOfMenuItem]	={"All","Pressed"};
char ModeMenuItems[][maxCharacterOfMenuItem]		={"Kicad","Eagle","Phtshop","Premiere","Custom 1","Custom 2", "Custom 3"};
/*------------------------------------------------------------------------------------*/

void InitMenu(){


	/*--------------------------------------------------------------------------------*/
	BuildMenu(&mainM, "Main",MainMenuItems, 2, executeMain, 0, &buttonM, 0, 0);
	/*--------------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------------*/
	BuildMenu(&buttonM, "Button", ButtonMenuItems, 2, executeButton, &mainM, &displayM, &scrollM, &scrollM);
	BuildMenu(&scrollM, "Scroll", 0, 0, executeScroll, &mainM, 0, &buttonM, &buttonM);
	/*--------------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------------*/
	BuildMenu(&displayM, "Display", DisplayMenuItems, 2, executeDisplay, &buttonM, 0, &modeM, &modeM);
	BuildMenu(&modeM, 	"Mode", ModeMenuItems, 7, executeMode, &buttonM, 0, &displayM, &displayM);
	/*--------------------------------------------------------------------------------*/


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

/*------------------------------------------------------------------------------------*/
void BuildMenu(struct level *currentNode, char name[16],char menuitems[][maxCharacterOfMenuItem],uint8_t numberOfMenuItems, void (*execute)(void) , struct level *prevNode, struct level *nextNode,struct level *upNode,struct level *downNode)
{
    strcpy(currentNode->name, name);
    for(int i=0; i<numberOfMenuItems;i++)
    {
    	strcpy(currentNode->menuitems[i],menuitems[i]);
    }
   	currentNode->numberOfMenuItems=numberOfMenuItems;
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
  (*currentNode) = (*currentNode)->down;
}
/*------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------*/
void Next(struct level **currentNode)
{
	if((*currentNode)->execute != 0)
	{
		(*currentNode)->execute;
	}
	else if((*currentNode)->next != 0)
	{
		(*currentNode) = (*currentNode)->next;
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
			*task=idleE;
			break;
		case downE:
			Down(&currentM);
			*task=idleE;
			break;
		case nextE:
			Next(&currentM);
			*task=idleE;
			break;
		case prevE:
			Prev(&currentM);
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
	ssd1306_WriteString(str, Font_11x18, invert==0?White:Black);

}
void drawMenu(struct level *currentNode, uint8_t selectedItem, uint8_t upDownState){

	if(currentNode->numberOfMenuItems<bottomMenuPosition)
	{
		bottomMenuPosition=currentNode->numberOfMenuItems;
	}

	for(int i=topMenuPosition; i<=bottomMenuPosition;i++)
	{
		drawMenuItem(currentNode->menuitems[i-1], i-topMenuPosition+1, selectedItem==i?White:Black);
	}
	ssd1306_UpdateScreen(&hi2cScreen);

}
/*------------------------------------------------------------------------------------*/

void downMenuItem(struct level *currentNode)
{
	cursorPosition++;
	if(cursorPosition>bottomMenuPosition && cursorPosition<=currentNode->numberOfMenuItems)
	{
		topMenuPosition++;
		bottomMenuPosition++;
	}
	if(cursorPosition>currentNode->numberOfMenuItems)
	{
		cursorPosition=currentNode->numberOfMenuItems;
	}
}

void upMenuItem(struct level *currentNode){
	cursorPosition--;
	if(cursorPosition<topMenuPosition && cursorPosition>0)
	{
		topMenuPosition--;
		bottomMenuPosition--;
	}
	if(cursorPosition<1)
	{
		cursorPosition=1;
	}
}



