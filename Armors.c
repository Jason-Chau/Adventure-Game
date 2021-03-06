#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Weapons.h"
#include "Armors.h"
#include "enumClasses.h"
#include "Consumables.h"

struct INVENTORY_STRUCT;
typedef struct INVENTORY_STRUCT INVENTORY;
void RemoveItem(char *name, int type, INVENTORY *inv);
void RemoveWeapon(WEAPON* weapons[50], int target);
void RemoveWeapon(WEAPON* weapons[50], int target);
void RemoveArmor(ARMOR* armors[50], int target);
void RemoveConsumable(CONSUMABLE* consumables[50], int target);
void AddWeapon(WEAPON* w, INVENTORY* inventory);
void AddArmor(ARMOR* a, INVENTORY* inventory);
void AddConsumable(CONSUMABLE* c, INVENTORY* inventory);

int armorAttached = 0;


ARMOR* initArmor(char *name, int type, int required_STR, int add_AC) {
    ARMOR* a = malloc(sizeof(ARMOR));
    strcpy(a->name, name);
    a->type = type;
    a->required_STR = required_STR;
    a->add_AC = add_AC;
    return a;
}

void printArmor(ARMOR *a) {
    printf("********************************\n");
    printf("Name: \t\t\t%s\n", a->name);
    //printf("Type: \t\t\t%d\n", a->type);
    printf("Required Strength: \t%d\n", a->required_STR);
    printf("+ Armor Class: \t\t%d\n\n", a->add_AC);
    printf("********************************\n");
}

void swapArmor(ARMOR *old, ARMOR *new, Stats *s, INVENTORY *inv) {
    
    if(checkArmorRequirement(new, s)) {
        printf("**************************************************\n");
        printf("Swapping from \"%s\" to \"%s\"...\n", old->name, new->name);
        printf("**************************************************\n");
        ARMOR* a = (ARMOR*)malloc(sizeof(ARMOR));
        s->currentArmor = new;
        //strcpy(s->currentArmor, new->name);
        RemoveItem(new->name, new->type, inv);
        AddArmor(old, inv);
        s->armorClass -= old->add_AC;
        s->armorClass += new->add_AC;
    }
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