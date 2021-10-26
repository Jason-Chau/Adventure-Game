#include <stdio.h>
#include <string.h>

#include "Mob.h"
#include "Inventory.c"

Mob CreateMob(char name[50], int hitPoints, int armorClass, int hit, int damage, int currentHP, INVENTORY* inventory) {
    //read in data to create mob
    Mob m;
    strcpy(m.name, name);
    m.hitPoints = hitPoints;
    m.armorClass = armorClass;
    m.hit = hit;
    m.damage = damage;
    m.currentHP = currentHP;
    m.loot = inventory;
    return m;
}

void DropLoot(Mob m, INVENTORY* inventory) {
    int i = 0;
    printf("Loot dropped! You got: \n");
    //weapons
    while(strcmp(m.loot->invWeapon[i]->name) != 0) {
        AddWeapon(m.loot->invWeapon[i], inventory);
        printf("%s\n", m.loot->invWeapon[i]->name);
        ++i;
    }
    i = 0;
    //armor
    while(strcmp(m.loot->invArmor[i]->name) != 0) {
        AddArmor(m.loot->invArmor[i], inventory);
        printf("%s\n", m.loot->invArmor[i]->name);
        ++i;
    }
    i = 0;
    //consumables
    while(strcmp(m.loot->invConsumable[i]->name) != 0) {
        AddConsumable(m.loot->invConsumable[i], inventory);
        printf("%s\n", m.loot->invConsumable[i]->name);
        ++i;
    }
}