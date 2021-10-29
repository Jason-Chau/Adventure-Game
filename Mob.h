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
    struct INVENTORY_STRUCT* loot;
} Mob;


Mob* CreateMob(char name[50], int hitPoints, int armorClass, int hit, int damage, int currentHP, INVENTORY* inventory);
Mob* CreateGoblin(char difficulty);
Mob* CreateOgre(char difficulty); 
Mob* CreateBandit(char difficulty);
void DropLoot(Mob* m, INVENTORY* loot, INVENTORY* inventory);
#endif