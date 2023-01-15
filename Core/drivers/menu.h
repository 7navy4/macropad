/*
 * menu.h
 *
 *  Created on: Jan 14, 2023
 *      Author: 7navy4
 */

#ifndef DRIVERS_MENU_H_
#define DRIVERS_MENU_H_

struct level {
   char name[16];
   struct level *next;
   struct level *prev;
   struct level *down;
   struct level *up;
   void (*execute)(void);
};




typedef enum task{idleE,upE,downE,nextE,prevE};

void BuildMenu(struct level *currentNode, char name[16], void (*execute)(void) , struct level *prevNode, struct level *nextNode,struct level *upNode,struct level *downNode);
void executeButton(void);
void executeScroll(void);
void executeDisplay(void);
void executeMode(void);


#endif /* DRIVERS_MENU_H_ */
