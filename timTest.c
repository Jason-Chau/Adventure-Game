#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "characterStats.h"
#include "Weapons.h"
#include "Armors.h"
#include "Consumables.h"
#include "Inventory.h"
#include "Mob.h"


int main() {
    WEAPON* w = initWeapon("Test Weapon", "Warrior", 1, 4, 3);
    ARMOR* a = initArmor("Test Armor", "Warrior", 1, 4, 10);
    //CONSUMABLE c = initConsumables("Test Consumable", 1, 5);

    WEAPON* wI[50];
    wI[0] = w;

    ARMOR* aI[50];
    aI[0] = a;
    printf("hello\n");
    INVENTORY* inv;
    CreateInventory(inv, wI, aI, NULL);

    //WEAPON* w2 = inv->invWeapon[0];
    //printf("%s", w2->name);

    
}