/*
 * menu.c
 *
 *  Created on: Jan 14, 2023
 *      Author: 7navy4
 */


#include "menu.h"
#include "main.h"
#include "string.h"


struct level  *currentM;

struct level buttonM,displayM,modeM;
struct level allM,pressedM;
struct level kicadM,eagleM,photoshopM,premiereM,customM;
struct level scroll;

void BuildMenu(struct level *currentNode, char name[16], void (*execute)(void) , struct level *prevNode, struct level *nextNode,struct level *upNode,struct level *downNode)
{
    strcpy(currentNode->name, name);
    currentNode->prev = prevNode;
    currentNode->next = nextNode;
    currentNode->up = upNode;
    currentNode->down = downNode;
    currentNode->execute = execute;
}


void Up(struct level **currentNode)
{
  if( (*currentNode) ->up != 0)
  (*currentNode) = (*currentNode)->up;
}

void Down(struct level **currentNode)
{
  if( (*currentNode) ->down != 0)
  (*currentNode) = (*currentNode)->down;
}

void Next(struct level **currentNode)
{
	if((*currentNode)->execute != 0)
	{
		//ExecuteTask((*currentNode)->execute);
	}
	else if((*currentNode)->next != 0)
	{
		(*currentNode) = (*currentNode)->next;
	}
}

void Prev(struct level **currentNode)
{
  if( (*currentNode) ->prev != 0)
  (*currentNode) = (*currentNode)->prev;
}


void ExecuteTask(struct level *currentNode){

}

void MenuTransition(uint8_t task){



	switch(task)
	{
		case idleE:
		break;
		case upE:
		break;
		case downE:
		break;
		case nextE:
		break;
		case prevE:
		break;
		default:
		break;

	}
}

