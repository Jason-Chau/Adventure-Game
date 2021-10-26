#ifndef CHARACTER_STATS_H_
#define CHARACTER_STATS_H_

typedef struct characterStats {
    char name[50];
    char race[50];
    char class[50];
    int hitPoints;
    int armorClass;
    int strength;
    int dexterity;
    int intelligence;
    //Declaring the variables necessary for a character's stats
} Stats;

Stats initCharacterStats(char* name, char* race, char* class, int hitPoints, int armorClass, int strength, int dexterity, int intelligence);
//Initializing the character's stats

void printCharacter();
//Prints out the result of the newly created character

#endif