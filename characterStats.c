#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct characterStats {
    char name[50];
    char race[50];
    char class[50];
    int hitPoints;
    int armorClass;
    int strength;
    int dexterity;
    int intelligence;
    //Initializing the variables necessary for a character's stats
} Stats;

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

int main() {
    Stats Test = initCharacterStats("First Character", "Human", "Warrior", 20, 10, 15, 14, 13);
    printCharacter(Test);
}