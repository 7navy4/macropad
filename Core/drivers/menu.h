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

#endif /* DRIVERS_MENU_H_ */
