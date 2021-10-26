#include "characterStats.h"

#ifndef WEAPONS_H
#define WEAPONS_H

typedef struct WEAPON_STRUCT {
    char name[30];
    int type;
    char required_Class[30];
    int required_STR;
    int add_STR;
} WEAPON;

WEAPON initWeapon(char *name, char *required_Class, int type, int required_STR, int add_STR);
void printWeapon(WEAPON w);
void wearWeapon(WEAPON *w, Stats *s);
void swapWeapon(WEAPON *w1, WEAPON *w2, Stats *s);
void detachWeapon(WEAPON *w, Stats *s);
int checkWeaponRequirement(WEAPON *w, Stats *s);
#endif