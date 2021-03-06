#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Weapons.h"
#include "enumClasses.h"
#include "Armors.h"
#include "Consumables.h"

struct INVENTORY_STRUCT;
typedef struct INVENTORY_STRUCT INVENTORY;
void DisplayConsumables(INVENTORY* inventory);
CONSUMABLE* FindConsumable(INVENTORY* inventory, char itemName[50]);
void DisplayWeapons(INVENTORY* inventory);
void DisplayArmor(INVENTORY* inventory);
WEAPON* FindWeapon(INVENTORY* inventory, char itemName[50]);
ARMOR* FindArmor(INVENTORY* inventory, char itemName[50]);
void RemoveItem(char *name, int type, INVENTORY *inv);
void RemoveWeapon(WEAPON* weapons[50], int target);
void RemoveArmor(ARMOR* armors[50], int target);
void RemoveConsumable(CONSUMABLE* consumables[50], int target);
void AddWeapon(WEAPON* w, INVENTORY* inventory);
void AddArmor(ARMOR* a, INVENTORY* inventory);
void AddConsumable(CONSUMABLE* c, INVENTORY* inventory);

int weaponAttached = 0;

WEAPON* initWeapon(char *name, int type, int required_STR, int add_STR) {
    WEAPON* w = malloc(sizeof(WEAPON));
    strcpy(w->name, name);
    w->type = type;
    w->required_STR = required_STR;
    w->add_STR = add_STR;
    return w;
}

void printWeapon(WEAPON* w) {
    printf("********************************\n");
    printf("Name: \t\t\t%s\n", w->name);
    //printf("Type: \t\t\t%s\n", w->type);
    printf("Required Strength: \t%d\n", w->required_STR);
    printf("+ Strength: \t\t%d\n\n", w->add_STR);
    printf("********************************\n");

    // Need to dynamically print the required stat (DEX / STR / INT) depending on the classes, and additional stats too.
}


void swapWeapon(WEAPON *old, WEAPON *new, Stats *s, INVENTORY *inv) {

    if(checkWeaponRequirement(new, s) == 1) {
        printf("**************************************************\n");
        printf("Swapping from \"%s\" to \"%s\"...\n", old->name, new->name);
        printf("**************************************************\n");
        WEAPON* w = (WEAPON*)malloc(sizeof(WEAPON));
        s->currentWeapon = new;
        RemoveItem(new->name, new->type, inv);
        AddWeapon(old, inv);
        s->strength -= old->add_STR;
        s->strength += new->add_STR;
        s->hit = s->strength / 2;
    }
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