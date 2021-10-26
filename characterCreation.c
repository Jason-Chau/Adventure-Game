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
    int damage;
    int hit;
} Character;

Character initCharacterStats(char* name, char* race, char* class, int hitPoints, int armorClass, int strength, int dexterity, int intelligence) {
    Character c;
    strcpy(c.name, name);
    strcpy(c.race, race);
    strcpy(c.class, class);
    c.hitPoints = hitPoints;
    c.armorClass = armorClass;
    c.strength = strength;
    c.dexterity = dexterity;
    c.intelligence = intelligence;
    return c;
}

void printCharacter(Character c) {
    printf("Name: %s\n", c.name);
    printf("Race: %s\n", c.race);
    printf("Class: %s\n", c.class);
    printf("HP: %d\n", c.hitPoints);
    printf("AC: %d\n", c.armorClass);
    printf("STR: %d\n", c.strength);
    printf("DEX: %d\n", c.dexterity);
    printf("INT: %d\n", c.intelligence);
}

int main() {
    Character Test = initCharacterStats("First Character", "Human", "Warrior", 20, 10, 15, 14, 13);
    printCharacter(Test);
}