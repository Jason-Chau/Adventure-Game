#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
//#include "characterStats.h"
//#include "Weapons.h"
//#include "Armors.h"
//#include "Consumables.h"
#include "Inventory.h"
#include "Mob.h"
//#include "Map.h"
#include "enumClasses.h"


void Trap(Stats* p) {
    //make sure you #include <time.h> 
    srand((int)time(0));
    int trapDetectionDC = 12 + rand()%8 + 1;
    int trapDodgeDC = 8 + rand()%10 + 1;
    //trap spotted?
    if ((rand()%20)+p->trapDetection+1 >= trapDetectionDC) {
        printf("You've spotted a trap! You avoid it with ease.\n");
        //add experience?
    }
    else if ((rand()%20)+2 >= trapDodgeDC){
        printf("You set off a trap but quickly dodge, avoiding harm!\n");
    }
    else {
        //can change the way trap damage is calculated later (probably based on level), for now its 1-10 damage
        int d = (rand() % 9) + 1;
        p->currentHP -= d;
        printf("You set off a trap and take %d damage. Ouch!\n", d);
    }
}

void Combat(Stats* p, Mob* m, INVENTORY* inv) {
    //make sure you #include <time.h> 
    srand((int)time(0));
    printf("Combat begins! Enemies: %s\n", m->name);

    while(p->currentHP > 0 && m->currentHP > 0) {
        
        while(1) {
            printf("Player turn. Choose an action (attack, consume)\n");
            char pAction[50];
            scanf("%[^\n]%*c", pAction);
            if(strcmp(pAction, "attack") == 0) {
            // player attacking
                if(((rand()%20)+6) > m->armorClass-1) {
                    m->currentHP -= p->strength;
                    printf("You hit %s for %d damage!\n", m->name, p->strength);
                }
                else {
                    printf("You miss %s!\n", m->name);
                }
                break;
            }
            else if (strcmp(pAction, "consume") == 0) {
                char iName[50];
                printf("Which consumable would you like to consume? You have:\n");
                DisplayConsumables(inv);

                scanf("%[^\n]%*c", iName);
                printf("ITEM SELECTED: %s\n", iName);
                
                CONSUMABLE* c;
                c = FindConsumable(inv, iName);
                if (strcmp(c->name, iName)==0) {
                    consumeItem(p, c, inv);
                    break;
                }
                else{
                    printf("Item not found.\n");
                    break;
                }
                
                
            }
            printf("Invalid Command, try again.\n");
        }
        if (m->currentHP <= 0) {
            break;
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
        DropLoot(m, m->loot, inv);
    }
    
}

int main() {
    
    srand((int)time(0));
    Stats *Test1 = newCharacter(Warrior, "First Character");
    DisplayStats(Test1);

    //INVENTORY* mInv;
    //mInv = (INVENTORY*)malloc(sizeof(INVENTORY));
    printf("mob test\n");
    Mob* m;
    m = CreateGoblin();
    //m = CreateMob("Test Mob", 50, 15, 20, 5, 50, mInv);
    
    INVENTORY *inv = (INVENTORY*) malloc(sizeof(INVENTORY));
    
    CreateInventory(inv);
    WEAPON *LumberAxe = initWeapon("Lumber Axe", 0, 10, 20);
    AddWeapon(LumberAxe, inv);
    CONSUMABLE* c = initConsumables("Test Consumable", 2, 5);
    AddConsumable(c, inv);
    DisplayInventory(inv);
    wearWeapon(LumberAxe, Test1, inv);
    DisplayInventory(inv);
    DisplayStats(Test1);
    
    //DisplayInventory(m->loot);
    
    Combat(Test1, m, inv);
    DisplayInventory(inv);

    
    /*

    printf("enter input2\n");
    char input2[50];
    scanf("%[^\n]%*c", input2);
    printf("output: %s\n", input2);
    printf("enter input\n");
    char input[50];
    scanf("%[^\n]%*c", input);
    printf("output: %s\n", input);
    INVENTORY* mInv;
    mInv = (INVENTORY*)malloc(sizeof(INVENTORY));
    Mob* m;
    m = CreateMob("Test Mob", 50, 15, 6, 5, 50, mInv);
    Stats *Test = newCharacter(Warrior, "First Character");
    DisplayStats(Test);

    WEAPON *GodButcher = initWeapon("God Butcher", "Warrior", 0, 10, 5);
    WEAPON *LumberAxe = initWeapon("Lumber Axe", "Warrior", 0, 10, 15);
    printWeapon(GodButcher);
    //wearWeapon(GodButcher, Test);
    DisplayStats(Test);
    //swapWeapon(GodButcher, LumberAxe, Test);
    DisplayStats(Test);

    INVENTORY* inv;
    inv = (INVENTORY*)malloc(sizeof(INVENTORY));
    CreateInventory(inv);
    AddWeapon(GodButcher, inv);
    DisplayInventory(inv);
    Combat(Test, m);
    */

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

