//#include "characterStats.h"
#ifndef WEAPONS_H
#define WEAPONS_H

//#include "enumClasses.h"
//#include "Inventory.h"
struct characterStats;
typedef struct characterStats Stats;
struct INVENTORY_STRUCT;
typedef struct INVENTORY_STRUCT INVENTORY;

typedef struct WEAPON_STRUCT {
    char name[30];
    int type;
    int required_STR;
    int add_STR;
} WEAPON;

WEAPON* initWeapon(char *name, int type, int required_STR, int add_STR);
void printWeapon(WEAPON *w, Stats *s);
void wearWeapon(WEAPON *w, Stats *s, INVENTORY *inv);
void swapWeapon(WEAPON *w1, WEAPON *w2, Stats *s, INVENTORY *inv);
void detachWeapon(WEAPON *w, Stats *s, INVENTORY *inv);
int checkWeaponRequirement(WEAPON *w, Stats *s);



#endif