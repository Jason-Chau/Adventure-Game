#ifndef ENUM_CLASSES_H
#define ENUM_CLASSES_H

typedef enum Classes  {
  Warrior,
  Mage,
  Thief
} Classes;

typedef struct characterStats {
  char name[50];
  Classes class;
  int health;
  int mana;
  int hitPoints;
  int currentHP;
  int armorClass;
  int strength;
  int dexterity;
  int intelligence;
  int hit;
  int damage;
  double trapDetection;
} Stats;

Stats* newCharacter(Classes class, char name[50]);

Stats initHitDamage(int hit, int damage);

void DisplayStats(Stats *target);

int SetName(Stats *target, char name[50]);

#endif