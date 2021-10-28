#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "enumClasses.h"

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
  // Assign stats based on the given class.
  switch(class) {
    case Warrior: {
      newCharacter->hitPoints = 100;
      newCharacter->currentHP = 100;
      newCharacter->armorClass = 20;
      newCharacter->strength = 20;
      newCharacter->dexterity = 10;
      newCharacter->intelligence = 5;
      newCharacter->class = Warrior;
      newCharacter->trapDetection = 0.5 * newCharacter->intelligence;
      newCharacter->dodgeChance = 0.5 * newCharacter->dexterity;
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
      strcpy(newCharacter->className, "Thief");
      break;
    }
    default: {
      newCharacter->hitPoints = 10;
      newCharacter->currentHP = 10;

      newCharacter->mana = 0;
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
  printf("\nName: %s\n", target->name);
  printf("Class: %s\n", target->className);
  printf("HP: %d / %d\n", target->currentHP, target->hitPoints);
  printf("AC: %d\n", target->armorClass);
  printf("STR: %d\n", target->strength);
  printf("DEX: %d\n", target->dexterity);
  printf("INT: %d\n", target->intelligence);
  printf("Trap Detection Level: %.1lf\n", target->trapDetection);
  printf("\n");
}