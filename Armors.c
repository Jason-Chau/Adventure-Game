#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "characterStats.h"
#include "Armors.h"

int armorAttached = 0;

ARMOR* initArmor(char *name, char *required_Class, int type, int required_STR, int add_AC) {
    ARMOR* a;
    strcpy(a->name, name);
    strcpy(a->required_Class, required_Class);
    a->type = type;
    a->required_STR = required_STR;
    a->add_AC = add_AC;
    return a;
}

void printArmor(ARMOR a) {
    printf("********************************\n");
    printf("Name: \t\t\t%s\n", a.name);
    printf("Class: \t\t\t%s\n", a.required_Class);
    printf("Type: \t\t\t%s\n", a.type);
    printf("Required Strength: \t%d\n", a.required_STR);
    printf("+ Armor Class: \t\t%d\n\n", a.add_AC);
    printf("********************************\n");
}

void wearArmor(ARMOR *a, Stats *s) {
    checkArmorRequirement(a, s);
    printf("********************************\n");
    printf("Putting on \"%s\"...\n", a->name);
    printf("********************************\n");

    armorAttached = 1;
    s->armorClass += a->add_AC;
}

void swapArmor(ARMOR *old, ARMOR *new, Stats *s) {
    if(!armorAttached) {
        printf("****************************************\n");
        printf("You don't have \"%s\" on !\n", old->name);
        printf("****************************************\n");

        return ;
    }
    if(checkArmorRequirement(new, s)) {
        printf("**************************************************\n");
        printf("Swapping from \"%s\" to \"%s\"...\n", old->name, new->name);
        printf("**************************************************\n");

        s->armorClass -= old->add_AC;
        s->armorClass += new->add_AC;
    }
}

void detachArmor(ARMOR *a, Stats *s) {
    if(!armorAttached) {
        printf("****************************************\n");
        printf("You don't have \"%s\" on !\n", a->name);
        printf("****************************************\n");

        return ;
    }
    armorAttached = 0;
    printf("****************************\n");
    printf("Detaching \"%s\"...\n", a->name);
    printf("****************************\n");

    s->armorClass -= a->add_AC;
}

int checkArmorRequirement(ARMOR *a, Stats *s) {
    if(s->strength < a->required_STR) {
        printf("****************************************\n");
        printf("!!! YOU ARE TOO WEAK FOR \"%s\" !!!\n", a->name);
        printf("****************************************\n");

        return 0;
    }
    else return 1;
}