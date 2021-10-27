
#ifndef CONSUMABLES_H
#define CONSUMABLES_H

typedef struct CONSUMABLE_STRUCT {
    char name[50];
    int type;
    int amountHPHeal;
} CONSUMABLE;

CONSUMABLE* initConsumables(char *name, int type, int amountHPHeal);
//Stats consumeItem(Stats s, CONSUMABLE c);
#endif
