#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "characterStats.h"

Stats initCharacterStats(char* name, char* race, char* class, int hitPoints, int armorClass, int strength, int dexterity, int intelligence) {
    Stats s;
    strcpy(s.name, name);
    strcpy(s.race, race);
    strcpy(s.class, class);
    s.hitPoints = hitPoints;
    s.armorClass = armorClass;
    s.strength = strength;
    s.dexterity = dexterity;
    s.intelligence = intelligence;
    return s;
}

void printCharacter(Stats s) {
    printf("Name: %s\n", s.name);
    printf("Race: %s\n", s.race);
    printf("Class: %s\n", s.class);
    printf("HP: %d\n", s.hitPoints);
    printf("AC: %d\n", s.armorClass);
    printf("STR: %d\n", s.strength);
    printf("DEX: %d\n", s.dexterity);
    printf("INT: %d\n", s.intelligence);
}