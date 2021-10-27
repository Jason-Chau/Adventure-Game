#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Weapons.h"
#include "enumClasses.h"

int weaponAttached = 0;

<<<<<<< HEAD
WEAPON* initWeapon(char *name, char *class, char *type, int required_STR, int add_STR) {
    WEAPON* w = malloc(sizeof(WEAPON));
=======
WEAPON* initWeapon(char *name, char *required_Class, int type, int required_STR, int add_STR) {
    
    WEAPON* w;
    w = (WEAPON*)malloc(sizeof(WEAPON));
>>>>>>> 1787576bff9f657ece75421cf03693b575796f81
    strcpy(w->name, name);
    strcpy(w->class, class);
    strcpy(w->type,type);
    w->required_STR = required_STR;
    w->add_STR = add_STR;
    return w;

}

void printWeapon(WEAPON *w) {
    printf("********************************\n");
    printf("Name: \t\t\t%s\n", w->name);
    printf("Class: \t\t\t%s\n", w->class);
    printf("Type: \t\t\t%s\n", w->type);
    printf("Required Strength: \t%d\n", w->required_STR);
    printf("+ Strength: \t\t%d\n\n", w->add_STR);
    printf("********************************\n");

    // Need to dynamically print the required stat (DEX / STR / INT) depending on the classes, and additional stats too.
}

void wearWeapon(WEAPON *w, Stats *s) {
    checkWeaponRequirement(w, s);
    printf("********************************\n");
    printf("Putting on \"%s\"...\n", w->name);
    printf("********************************\n");

    weaponAttached = 1;
    s->strength += w->add_STR;

}

void swapWeapon(WEAPON *old, WEAPON *new, Stats *s) {
    if(!weaponAttached) {
        printf("****************************************\n");
        printf("You don't have \"%s\" on !\n", old->name);
        printf("****************************************\n");

        return ;
    }
    if(checkWeaponRequirement(new, s) == 1) {
        printf("**************************************************\n");
        printf("Swapping from \"%s\" to \"%s\"...\n", old->name, new->name);
        printf("**************************************************\n");

        s->strength -= old->add_STR;
        s->strength += new->add_STR;
    }
}

void detachWeapon(WEAPON *w, Stats *s) {
    if(!weaponAttached) {
        printf("****************************************\n");
        printf("You don't have \"%s\" on !\n", w->name);
        printf("****************************************\n");

        return ;
    }
    weaponAttached = 0;
    printf("****************************\n");
    printf("Detaching \"%s\"...\n", w->name);
    printf("****************************\n");
    s->strength -= w->add_STR;
}

int checkWeaponRequirement(WEAPON *w, Stats *s) {
    if(s->strength < w->required_STR) {
        printf("****************************************\n");
        printf("!!! YOU ARE TOO WEAK FOR \"%s\" !!!\n", w->name);
        printf("****************************************\n");

        return 0;
    }
    else return 1;
}
// Once player character wears a certain weapons or armors, implement the function to add corresponding additional stats to the character.