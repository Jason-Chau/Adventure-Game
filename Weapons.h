#include "characterStats.h"

#ifndef WEAPONS_H
#define WEAPONS_H

typedef struct WEAPON_STRUCT {
    char name[30];
    char type[30];
    char required_Class[30];
    int required_STR;
    int add_STR;
} WEAPON;

WEAPON initWeapon(char *name, char *required_Class, char *type, int required_STR, int add_STR);

void printWeapon(WEAPON w);
Stats wearWeapon(WEAPON w, Stats s);
Stats swapWeapon(WEAPON w1, WEAPON w2, Stats s);
Stats detachWeapon(WEAPON w, Stats s);
void checkWeaponRequirement(WEAPON w, Stats s);
#endif