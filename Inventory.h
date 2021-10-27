#ifndef INVENTORY_H_
#define INVENTORY_H_

#include "Weapons.h"
#include "Armors.h"
#include "Consumables.h"

typedef struct Inventory_struct {
    struct WEAPON_STRUCT* invWeapon[50];
    struct ARMOR_STRUCT* invArmor[50];
    struct CONSUMABLE_STRUCT* invConsumable[50];
} INVENTORY;

void CreateInventory(INVENTORY* inventory);
void DisplayInventory(INVENTORY* inventory);
void AddWeapon(WEAPON* w, INVENTORY* inventory);
void AddArmor(ARMOR* a, INVENTORY* inventory);
void AddConsumable(CONSUMABLE* c, INVENTORY* inventory);
void RemoveItem(char itemName[50], int itemType, INVENTORY* inventory);
void RemoveWeapon(WEAPON* weapons[50], int target);
void RemoveArmor(ARMOR* armors[50], int target);
void RemoveConsumable(CONSUMABLE* consumables[50], int target);

#endif