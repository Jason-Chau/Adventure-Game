#ifndef Mob_H_
#define Mob_H_

typedef struct Mob_struct {
    char name[50];
    int hitPoints;
    int armorClass;
    int hit;
    int damage;
    int currentHP;
    struct INVENTORY* loot;
} Mob;


Mob CreateMob(char name[50], int hitPoints, int armorClass, int hit, int damage, int currentHP);

#endif