#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Weapons.h"
#include "characterStats.h"

WEAPON initWeapon(char *name, char *required_Class, char *type, int required_STR, int add_STR) {
    WEAPON w;
    strcpy(w.name, name);
    strcpy(w.required_Class, required_Class);
    strcpy(w.type, type);
    w.required_STR = required_STR;
    w.add_STR = add_STR;
    return w;
}

void printWeapon(WEAPON w) {
    printf("********************************\n");
    printf("Name: \t\t\t%s\n", w.name);
    printf("Class: \t\t\t%s\n", w.required_Class);
    printf("Type: \t\t\t%s\n", w.type);
    printf("Required Strength: \t%d\n", w.required_STR);
    printf("+ Strength: \t\t%d\n\n", w.add_STR);
    printf("********************************\n");

    // Need to dynamically print the required stat (DEX / STR / INT) depending on the classes, and additional stats too.
}

Stats wearWeapon(WEAPON w, Stats s) {
    s.strength += w.add_STR;
    return s;
}

Stats swapWeapon(WEAPON old, WEAPON new, Stats s) {
    s.strength -= old.add_STR;
    s.strength += new.add_STR;
    return s;
}

// Once player character wears a certain weapons or armors, implement the function to add corresponding additional stats to the character.