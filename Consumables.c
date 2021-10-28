#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Consumables.h"
#include "enumClasses.h"
#include "Weapons.h"
#include "Armors.h"

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

CONSUMABLE* initConsumables(char *name, int type, int amountHPHeal) {
    CONSUMABLE* c;
    c = (CONSUMABLE*)malloc(sizeof(CONSUMABLE));
    strcpy(c->name, name);
    c->type = type;
    c->amountHPHeal = amountHPHeal;
    return c;
}

// Heal HP when item is consumed

void consumeItem(Stats *s, CONSUMABLE *c, INVENTORY *inv) {

    if(s->currentHP == s->hitPoints) {
        printf("You already have full HP\n");
    }
    // When current HP + amount HP heals is greater than max of character's HP, then it will just heal up to character's max HP.
    else if(s->currentHP + c->amountHPHeal > s->hitPoints) {
        printf("Consuming potion \"%s\"..\nCurrent HP: %d", c->name, s->currentHP);
        s->currentHP = s->hitPoints;
        printf(" -> %d\n", s->currentHP);
        RemoveItem(c->name, c->type, inv);

    }
    else {
        printf("Consuming potion \"%s\"..\nCurrent HP: %d", c->name, s->currentHP);
        s->currentHP += c->amountHPHeal;
        printf(" -> %d\n", s->currentHP);
        RemoveItem(c->name, c->type, inv);

    }

}

// Inventory updateInven() {
    // need a function to keep updating inventory whenever character consumes items
    // or loot items 
// }


