#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "enumClasses.h"

// Creates player and sets class.
Stats* newCharacter(Classes class, char name[50]) {
  // Allocate memory to player pointer.
  Stats *newCharacter = malloc(sizeof(Stats));
  SetName(newCharacter, name);

  // Assign stats based on the given class.
  switch(class) {
    case Warrior:
    newCharacter->hitPoints = 100;
    newCharacter->armorClass = 20;
    newCharacter->strength = 15;
    newCharacter->dexterity = 10;
    newCharacter->intelligence = 5;
    newCharacter->class = Warrior;
    break;
  case Mage:
    newCharacter->hitPoints = 100;
    newCharacter->armorClass = 5;
    newCharacter->strength = 5;
    newCharacter->dexterity = 10;
    newCharacter->intelligence = 15;
    newCharacter->class = Mage;
    break;
  case Thief:
    newCharacter->hitPoints = 100;
    newCharacter->armorClass = 10;
    newCharacter->strength = 10;
    newCharacter->dexterity = 15;
    newCharacter->intelligence = 5;
    newCharacter->class = Thief;
    break;
  default:
    newCharacter->hitPoints = 10;
    newCharacter->mana = 0;
    break;
  }
  return(newCharacter); // Return memory address of player.
}
int SetName(Stats *target, char name[50]) {
    strcpy(target->name, name);
    return(0);
}

void DisplayStats(Stats *target)  {
    printf("\nName: %s\n", target->name);
    printf("HP: %d\n", target->hitPoints);
    printf("AC: %d\n", target->armorClass);
    printf("STR: %d\n", target->strength);
    printf("DEX: %d\n", target->dexterity);
    printf("INT: %d\n\n", target->intelligence);
}