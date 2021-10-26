#include "characterStats.h"

#ifndef ARMORS_H
#define ARMORS_H

typedef struct ARMOR_STRUCT {
    char name[30];
    char type[30];
    char required_Class[30];
    int required_STR;
    int add_AC;
} ARMOR;

ARMOR initArmor(char *name, char *required_Class, char *type, int required_STR, int add_AC);
void printArmor(ARMOR w);
Stats wearArmor(ARMOR w, Stats s);
Stats swapArmor(ARMOR w1, ARMOR w2, Stats s);
Stats detachArmor(ARMOR a, Stats s);
void checkArmorRequirement(ARMOR a, Stats s);

#endif