#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "characterStats.h"
#include "enumClasses.h"
#include "Weapons.h"
#include "Inventory.h"

int main() {

    Stats *Test1 = newCharacter(Warrior, "First Character");
    DisplayStats(Test1);

    // Stats *Test2 = newCharacter(Mage, "Second Character");
    // DisplayStats(Test2);

    // Stats *Test3 = newCharacter(Thief, "Third Character");
    // DisplayStats(Test3);

    INVENTORY *inv = (INVENTORY*) malloc(sizeof(INVENTORY));
    
    CreateInventory(inv);
    WEAPON *LumberAxe = initWeapon("Lumber Axe", "Warriors", 0, 10, 20);
    AddWeapon(LumberAxe, inv);
    //wearWeapon(LumberAxe, Test1, inv);
    DisplayInventory(inv);
}