#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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

    srand((int)time(0));
    if ((rand()%2) == 0) {
        CONSUMABLE* ChickenNug = initConsumables("Chicken Nugget", 2, 10);
        AddConsumable(ChickenNug, mInv);
    }
    WEAPON *Dagger = initWeapon("Dagger", 0, 0, 5);
    AddWeapon(Dagger, mInv);
    
    Mob* m;
    m = CreateMob("Goblin", 30, 15, 5, 5, 30, mInv);
    
    return m;
}

Mob* CreateBandit() {

    INVENTORY* mInv;
    mInv = (INVENTORY*)malloc(sizeof(INVENTORY));
    CreateInventory(mInv);

    srand((int)time(0));
    if ((rand()%2) == 0) {
        CONSUMABLE* GreaterPotion = initConsumables("Greater Potion", 2, 50);
        AddConsumable(GreaterPotion, mInv);
    }
    WEAPON *silverDagger = initWeapon("Silvered Dagger", 0, 0, 10);
    AddWeapon(silverDagger, mInv);
    
    Mob* m;
    m = CreateMob("Bandit", 45, 18, 6, 8, 45, mInv);
    
    return m;
}

Mob* CreateOgre() {

    INVENTORY* mInv;
    mInv = (INVENTORY*)malloc(sizeof(INVENTORY));
    CreateInventory(mInv);

    CONSUMABLE* OgreLeg = initConsumables("Ogre Leg", 2, 30);
    AddConsumable(OgreLeg, mInv);

    WEAPON *Club = initWeapon("Club", 0, 15, 14);
    AddWeapon(Club, mInv);
    
    Mob* m;
    m = CreateMob("Ogre", 80, 18, 8, 15, 80, mInv);
    
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
