#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Mob.h"
#include "Inventory.h"

Mob* CreateMob(char name[50], int hitPoints, int armorClass, int hit, int damage, int currentHP, INVENTORY* inventory) {
    //read in data to create mob
    Mob* m = malloc(sizeof(Stats));;
    strcpy(m->name, name);
    m->hitPoints = hitPoints;
    m->armorClass = armorClass;
    m->hit = hit;
    m->damage = damage;
    m->currentHP = currentHP;
    m->loot = inventory;
    return m;
}


Mob* CreateGoblin() {
    INVENTORY* mInv;
    mInv = (INVENTORY*)malloc(sizeof(INVENTORY));
    CreateInventory(mInv);
    WEAPON *Dagger = initWeapon("Dagger", 0, 0, 5);
    AddWeapon(Dagger, mInv);
    Mob* m;
    m = CreateMob("Goblin", 20, 10, 5, 5, 30, mInv);
    //DisplayInventory(m->loot);
    return m;
}

void DropLoot(Mob* m, INVENTORY* loot, INVENTORY* inventory) {
    int i = 0;
    printf("Loot dropped! You got: \n");
    //weapons
    WEAPON* w = loot->invWeapon[0];
    while(strcmp(w->name, "") != 0) {
        AddWeapon(w, inventory);
        printf("%s\n", w->name);
        ++i;
        w = loot->invWeapon[i];
    }
    i = 0;
    //armor
    ARMOR* a = loot->invArmor[0];
    while(strcmp(a->name, "") != 0) {
        AddArmor(a, inventory);
        printf("%s\n", a->name);
        ++i;
        a = loot->invArmor[i];
    }
    i = 0;
    //consumables
    CONSUMABLE* c = loot->invConsumable[0];
    while(strcmp(c->name, "") != 0) {
        AddConsumable(c, inventory);
        printf("%s\n", c->name);
        ++i;
        c = loot->invConsumable[i];
    }
}
