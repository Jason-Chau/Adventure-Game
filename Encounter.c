#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Encounter.c"
#include "Mob.c"
#include "characterStats.c"

//void CreateEncounter() {}

void Combat(Stats* p, Mob* m) {
    printf("Combat begins! Enemies: %s\n", m->name);

    while(p->currentHP > 0 && m->currentHP > 0) {
        printf("Player turn. Choose an action (attack)\n");
        char pAction[50];
        scanf("%s", pAction);
        if(strcmp(pAction, "attack") = 0) {
        // player attacking
            if(((rand()%20)+p->hit) > m->armorClass-1) {
                m->currentHP -= p->damage;
                printf("You hit %s for %d damage!\n", m->name, p->damage);
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
        DropLoot(m, p->inventory);
    }
    
}

void Trap(Player* p) {
    //its harder to spot traps than to dodge them once set off
    int trapDetectionDC = 12 + rand()%8 + 1;
    int trapDodgeDC = 6 + rand()%10 + 1;
    //trap spotted?
    if ((rand()%20)+p->perception+1 >= trapDetectionDC) {
        printf("You've spotted a trap! You avoid it with ease.\n");
        //add experience?
    }
    else if ((rand()%20)+p->dodge+1 >= trapDodgeDC){
        printf("You set off a trap but quickly dodge, avoiding harm!\n");
    }
    else {
        //can change the way trap damage is calculated later (probably based on level), for now its 1-10 damage
        int d = (rand() % 9) + 1;
        p->currentHP -= d;
        printf("You set off a trap and take %d damage. Ouch!\n", %d);
    }
}

void Loot(Player* p, char lootTable[50], int numDrops) {
    //read in the lootTable from file or hard code it
    printf("You stumble upon treasures, loot to your heart's content! You find:\n");
    char loot[numDrops];
    if(int i=0; i < numDrops; ++i) {
        //drops numDrops number of random items from the given loot table. Player can type the item's drop number in to take it,
        //or #all to take all loot dropped.
        loot[i] = lootTable[rand()%50];
        printf("%s\n", loot[i]);
        //needs to add item in loot to inventory based on the name of the item
        //p->INVENTORY += loot[i];
    }
}

void Exit() {
    // Player escapes the dungeon and wins or moves onto next floor
    printf("You found the exit door and escape the dungeon!\n");
}





/*
Player struct = Player
    player hp = Player->CURRENT_HP
Mob struct = Mob
    mob hp = Mob->CURRENT_HP
*/
