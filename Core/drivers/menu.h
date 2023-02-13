/*
 * menu.h
 *
 *  Created on: Jan 14, 2023
 *      Author: 7navy4
 */

#ifndef DRIVERS_MENU_H_
#define DRIVERS_MENU_H_

#include "main.h"

#define UpState		0
#define DownState	1

#define maxNumberOfMenuItems	7
#define maxCharacterOfMenuItem	10
struct level  mainM,*currentM;
struct level 	buttonM,scrollM,
				displayM,modeM,
				allM,pressedM,
				eagleM,kicadM,photosopM,premiereM,custom1,custom2,custom3;

struct level {
   char name[16];
   uint8_t numberOfSiblings;
   struct level *next;
   struct level *prev;
   struct level *down;
   struct level *up;
   void (*execute)(void);
};

typedef enum task{idleE,upE,downE,nextE,prevE};

void InitMenu(void);
void BuildMenu(struct level *currentNode, char name[16], uint8_t numberOfSiblings, void (*execute)(void) , struct level *prevNode, struct level *nextNode,struct level *upNode,struct level *downNode);
void executeMain(void);
void executeButton(void);
void executeScroll(void);
void executeDisplay(void);
void executeMode(void);
void executeAll(void);
void executePressed(void);
void executeEagle(void);
void executeKicad(void);
void executePhotoshop(void);
void executePremiere(void);
void executeCustom1(void);
void executeCustom2(void);
void executeCustom3(void);

void Up(struct level **currentNode);
void Down(struct level **currentNode);
void Next(struct level **currentNode);
void Prev(struct level **currentNode);
void MenuTransition(uint8_t *task);
void drawMenuItem(char *str, uint8_t line,uint8_t invert);
void drawMenu(struct level *currentNode, uint8_t selectedItem);
void downMenuItem(struct level *currentNode);
void upMenuItem(struct level *currentNode);










#endif /* DRIVERS_MENU_H_ */
