#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "characterStats.h"
//#include "Weapons.h"
//#include "Armors.h"
//#include "Consumables.h"
//#include "Inventory.h"
#include "Mob.h"
//#include "Map.h"
#include "enumClasses.h"

void Combat(Stats* p, Mob* m) {
    printf("Combat begins! Enemies: %s\n", m->name);

    while(p->currentHP > 0 && m->currentHP > 0) {
        printf("Player turn. Choose an action (attack)\n");
        char pAction[50];
        scanf("%s", pAction);
        if(strcmp(pAction, "attack") == 0) {
        // player attacking
            if(((rand()%20)+6) > m->armorClass-1) {
                m->currentHP -= p->strength;
                printf("You hit %s for %d damage!\n", m->name, p->strength);
                if (m->currentHP <= 0) {
                    break;
                }
            }
            else {
                printf("You miss %s!\n", m->name);
            }
        }

        // monster attacking
        if(((rand()%20)+m->hit) > p->armorClass-1) {
            p->currentHP -= m->damage;
            printf("%s hits you for %d damage! You have %d hp left.\n", m->name, m->damage, p->currentHP);
        }
        else {
            printf("You avoid %s's attack!\n", m->name);
        }
    }

    if (p->currentHP <= 0) {
        printf("You lost the fight and are now dead. :( \n");
        //call some sort of function that runs on player death
    }
    else {
        printf("You defeated the %s!\n");
        //DropLoot(m, p->inventory);
    }
    
}

int main() {
    INVENTORY* mInv;
    mInv = (INVENTORY*)malloc(sizeof(INVENTORY));
    Mob* m;
    m = CreateMob("Test Mob", 50, 15, 6, 5, 50, mInv);
    Stats *Test = newCharacter(Warrior, "First Character");
    DisplayStats(Test);

    WEAPON *GodButcher = initWeapon("God Butcher", "Warrior", 0, 10, 5);
    WEAPON *LumberAxe = initWeapon("Lumber Axe", "Warrior", 0, 10, 15);
    printWeapon(GodButcher);
    wearWeapon(GodButcher, Test);
    DisplayStats(Test);
    swapWeapon(GodButcher, LumberAxe, Test);
    DisplayStats(Test);

    INVENTORY* inv;
    inv = (INVENTORY*)malloc(sizeof(INVENTORY));
    CreateInventory(inv);
    AddWeapon(GodButcher, inv);
    DisplayInventory(inv);
    //Combat(Test, m);

    /*
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
    */
}

