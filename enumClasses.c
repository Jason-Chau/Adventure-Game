#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "enumClasses.h"
#include "Weapons.h"
#include "Armors.h"

// Creates player and sets class.
Stats* newCharacter(Classes class, char name[50]) {
  // Allocate memory to player pointer.
  Stats* newCharacter = malloc(sizeof(Stats));
  SetName(newCharacter, name);
  /*
  INVENTORY* inv;
  inv = (INVENTORY*)malloc(sizeof(INVENTORY));
  newCharacter->inventory = inv;
  CreateInventory(inv);
  */
  Stats s;
  WEAPON* w = (WEAPON*)malloc(sizeof(WEAPON));
  ARMOR* a = (ARMOR*)malloc(sizeof(ARMOR));
  // Assign stats based on the given class.
  switch(class) {
    case Warrior: {
      newCharacter->hitPoints = 100;
      newCharacter->currentHP = 100;
      newCharacter->armorClass = 12;
      newCharacter->strength = 20;
      newCharacter->dexterity = 10;
      newCharacter->intelligence = 5;
      newCharacter->class = Warrior;
      newCharacter->trapDetection = 0.5 * newCharacter->intelligence;
      newCharacter->dodgeChance = 0.5 * newCharacter->dexterity;
      newCharacter->hit = newCharacter->strength / 2;
      
      w = initWeapon("Fists", 0, 0, 5);
      newCharacter->currentWeapon = w;
      
      a = initArmor("Clothes", 1, 0, 5);
      newCharacter->currentArmor = a;
      strcpy(newCharacter->className, "Warrior");
      break;
    }
    case Mage: {
      newCharacter->hitPoints = 100;
      newCharacter->currentHP = 100;
      newCharacter->armorClass = 5;
      newCharacter->strength = 5;
      newCharacter->dexterity = 5;
      newCharacter->intelligence = 20;
      newCharacter->class = Mage;
      newCharacter->trapDetection = 0.5 * newCharacter->intelligence;
      newCharacter->dodgeChance = 0.5 * newCharacter->dexterity;
      newCharacter->hit = newCharacter->strength / 2;

      w = initWeapon("Fists", 0, 0, 5);
      newCharacter->currentWeapon = w;
      
      a = initArmor("Clothes", 1, 0, 5);
      newCharacter->currentArmor = a;
      strcpy(newCharacter->className, "Mage");
      break;
    }
    case Thief: {
      newCharacter->hitPoints = 100;
      newCharacter->currentHP = 100;
      newCharacter->armorClass = 10;
      newCharacter->strength = 10;
      newCharacter->dexterity = 15;
      newCharacter->intelligence = 10;
      newCharacter->class = Thief;
      newCharacter->trapDetection = 0.5 * newCharacter->intelligence;
      newCharacter->dodgeChance = 0.5 * newCharacter->dexterity;
      newCharacter->hit = newCharacter->strength / 2;

      w = initWeapon("Fists", 0, 0, 5);
      newCharacter->currentWeapon = w;
      
      a = initArmor("Clothes", 1, 0, 5);
      newCharacter->currentArmor = a;
      strcpy(newCharacter->className, "Thief");
      break;
    }
  }
  return(newCharacter);
}

Stats initHitDamage(int hit, int damage) {
  Stats s;
  s.hit = hit;
  s.damage = damage;
  return s;
}

int SetName(Stats* target, char name[50]) {
  strcpy(target->name, name);
  return(0);
}

void DisplayStats(Stats* target)  {
  printf("\n************************************");
  printf("\n\tName: %s\n", target->name);
  printf("\tClass: %s\n", target->className);
  printf("\tHP: %d / %d\n", target->currentHP, target->hitPoints);
  printf("\tAC: %d\n", target->armorClass);
  printf("\tSTR: %d\n", target->strength);
  printf("\tDEX: %d\n", target->dexterity);
  printf("\tINT: %d\n", target->intelligence);
  printf("\tHIT BONUS: %d\n", target->hit);
  printf("\tArmor Equipped: %s\n", target->currentArmor);
  printf("\tWeapon Equipped: %s\n", target->currentWeapon);
  printf("\tTrap Detection Level: %.1lf\n", target->trapDetection);
  printf("\tDodge Chance: %.1lf\n", target->dodgeChance);
  printf("************************************\n");
}