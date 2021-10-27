//#include "characterStats.h"
#ifndef ARMORS_H
#define ARMORS_H

#include "enumClasses.h"
//#include "Inventory.h"

typedef struct ARMOR_STRUCT {
    char name[30];
    int type;
    char class[30];
    int required_STR;
    int add_AC;
} ARMOR;

ARMOR* initArmor(char *name, char *class, int type, int required_STR, int add_AC);
void printArmor(ARMOR *w);
void wearArmor(ARMOR *w, Stats *s);
void swapArmor(ARMOR *w1, ARMOR *w2, Stats *s);
void detachArmor(ARMOR *a, Stats *s);
int checkArmorRequirement(ARMOR *a, Stats *s);

// ARMOR *initArmor(char *name, char *class, int type, int required_STR, int add_AC);
// void printArmor(ARMOR *w);
// void wearArmor(ARMOR *w, Stats *s, INVENTORY *inv);
// void swapArmor(ARMOR *w1, ARMOR *w2, Stats *s,  INVENTORY *inv);
// void detachArmor(ARMOR *a, Stats *s, INVENTORY *inv);
// int checkArmorRequirement(ARMOR *a, Stats *s);

#endif