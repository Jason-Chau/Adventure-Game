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
    m = CreateMob("Goblin", 20, 15, 5, 5, 30, mInv);
    
    return m;
}

Mob* CreateOgre() {

    INVENTORY* mInv;
    mInv = (INVENTORY*)malloc(sizeof(INVENTORY));
    CreateInventory(mInv);

    WEAPON *Club = initWeapon("Club", 0, 15, 8);
    AddWeapon(Club, mInv);
    
    Mob* m;
    m = CreateMob("Ogre", 50, 18, 8, 15, 80, mInv);
    
    return m;
}

void DropLoot(Mob* m, INVENTORY* loot, INVENTORY* inventory) {
    int i = 0;
    printf("Loot dropped! You got: \n");
    //checking each inventory array (weapons, armor, consumables) and stopping
    //as soon as we hit an empty slot (name = "")
    
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
