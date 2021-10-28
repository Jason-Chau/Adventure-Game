
#include "enumClasses.h"

#ifndef CONSUMABLES_H
#define CONSUMABLES_H

struct characterStats;
typedef struct characterStats Stats;
struct INVENTORY_STRUCT;
typedef struct INVENTORY_STRUCT INVENTORY;

typedef struct CONSUMABLE_STRUCT {
    char name[50];
    int type;
    int amountHPHeal;
} CONSUMABLE;

CONSUMABLE* initConsumables(char *name, int type, int amountHPHeal);
void consumeItem(Stats *s, CONSUMABLE *c, INVENTORY *inv);
//Stats consumeItem(Stats s, CONSUMABLE c);
#endif
