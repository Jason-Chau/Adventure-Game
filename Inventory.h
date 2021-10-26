#ifndef INVENTORY_H_
#define INVENTORY_H_

#include "Weapons.c"
//#include "Armors.c"
//#include "Consumables.c"

typedef struct Inventory_struct {
    struct WEAPON* invWeapon[50];
    struct ARMOR* invArmor[50];
    struct CONSUMABLE* invConsumable[50];
} INVENTORY;

void CreateInventory(INVENTORY* inventory, WEAPON* weapons[50], ARMOR* armors[50], CONSUMABLE* consumables[50]);
void DisplayInventory(WEAPON* weapons[50], ARMOR* armors[50], CONSUMABLE* consumables[50]);
void RemoveItem(char itemName[50], int itemType, INVENTORY* inventory);
void RemoveWeapon(WEAPON* weapons[50], int target);
void RemoveArmor(ARMOR* armors[50], int target);
void RemoveConsumable(CONSUMABLE* consumables[50], int target);

#endif