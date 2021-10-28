#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Consumables.h"
//#include "characterStats.h"
//#include "Inventory.h"
#include "enumClasses.h"

CONSUMABLE* initConsumables(char *name, int type, int amountHPHeal) {
    CONSUMABLE* c;
    c = (CONSUMABLE*)malloc(sizeof(CONSUMABLE));
    strcpy(c->name, name);
    c->type = type;
    c->amountHPHeal = amountHPHeal;
    return c;
}

// Heal HP when item is consumed

void consumeItem(Stats *s, CONSUMABLE *c) {

    if(s->currentHP == s->hitPoints) {
        printf("You already have full HP\n");
    }
    // When current HP + amount HP heals is greater than max of character's HP, then it will just heal up to character's max HP.
    else if(s->currentHP + c->amountHPHeal > s->hitPoints) {
        printf("Consuming potion \"%s\"..\nCurrent HP: %d", c->name, s->currentHP);
        s->currentHP = s->hitPoints;
        printf(" -> %d\n", s->currentHP);
    }
    else {
        printf("Consuming potion \"%s\"..\nCurrent HP: %d", c->name, s->currentHP);
        s->currentHP += c->amountHPHeal;
        printf(" -> %d\n", s->currentHP);
    }

    //RemoveItem(c.name, c.type, inventory);
}

// Inventory updateInven() {
    // need a function to keep updating inventory whenever character consumes items
    // or loot items 
// }


