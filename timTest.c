#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "characterStats.h"
#include "Weapons.h"
#include "Armors.h"
#include "Consumables.h"
#include "Inventory.h"
#include "Mob.h"
#include "Map.h"

int main() {
    printf("test\n");
    WEAPON* w = (WEAPON*)malloc(sizeof(WEAPON));
    w = initWeapon("Test Weapon", "Warrior", 0, 4, 3);
    WEAPON* w2 = (WEAPON*)malloc(sizeof(WEAPON));
    w2 = initWeapon("Test Weapon 2", "Warrior", 0, 4, 3);
    WEAPON* w3 = (WEAPON*)malloc(sizeof(WEAPON));
    w3 = initWeapon("Test Weapon 3", "Warrior", 0, 4, 3);

    ARMOR* a = (ARMOR*)malloc(sizeof(ARMOR));
    a = initArmor("Test Armor", "Warrior", 1, 4, 10);

    CONSUMABLE* c = (CONSUMABLE*)malloc(sizeof(CONSUMABLE));
    c = initConsumables("Test Consumable", 2, 5);

    INVENTORY* inv;
    inv = (INVENTORY*)malloc(sizeof(INVENTORY));
    CreateInventory(inv);
    
    WEAPON* wTest = inv->invWeapon[1];
    printf("TEST 2 %s\n", wTest->name);
    DisplayInventory(inv);
    AddWeapon(w, inv);
    AddWeapon(w2, inv);
    AddWeapon(w3, inv);
    AddArmor(a, inv);
    AddConsumable(c, inv);
    DisplayInventory(inv);
    RemoveItem("Test Weapon 2", 0, inv);
    DisplayInventory(inv);
    
}