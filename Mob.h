#ifndef Mob_H_
#define Mob_H_

#include "Inventory.h"

typedef struct Mob_struct {
    char name[50];
    int hitPoints;
    int armorClass;
    int hit;
    int damage;
    int currentHP;
    //struct Inventory_struct* loot;
} Mob;


Mob* CreateMob(char name[50], int hitPoints, int armorClass, int hit, int damage, int currentHP, INVENTORY* inventory);

#endif