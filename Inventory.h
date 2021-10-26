#ifndef INVENTORY_H_
#define INVENTORY_H_

#include "Weapons.h"
#include "Armors.h"
#include "Consumables.h"

typedef struct Inventory_struct {
    struct WEAPON* invWeapon[50];
    struct ARMOR* invArmor[50];
    struct CONSUMABLE* invConsumable[50];
} INVENTORY;

void CreateInventory(INVENTORY* inventory, WEAPON* weapons[50], ARMOR* armors[50], CONSUMABLE* consumables[50]);
void DisplayInventory(WEAPON* weapons[50], ARMOR* armors[50], CONSUMABLE* consumables[50]);
void AddWeapon(WEAPON* w, INVENTORY* inventory);
void AddArmor(ARMOR* a, INVENTORY* inventory);
void AddConsumable(CONSUMABLE* c, INVENTORY* inventory);
void RemoveItem(char itemName[50], int itemType, INVENTORY* inventory);
void RemoveWeapon(WEAPON* weapons[50], int target);
void RemoveArmor(ARMOR* armors[50], int target);
void RemoveConsumable(CONSUMABLE* consumables[50], int target);

#endif