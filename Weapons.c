#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct WEAPON_STRUCT {
    char name[30];
    char class[20];
    char type[30];
    int required_STR;
    int add_STR;
} WEAPON;

WEAPON initWeapon(char *name, char *class, char *type, int required_STR, int add_STR) {
    WEAPON w;
    strcpy(w.name, name);
    strcpy(w.class, class);
    strcpy(w.type, type);
    w.required_STR = required_STR;
    w.add_STR = add_STR;
    return w;
}

void printWeapon(WEAPON w) {
    printf("***************************\n");
    printf("Name: \t\t\t%s\n", w.name);
    printf("Class: \t\t\t%s\n", w.class);
    printf("Type: \t\t\t%s\n", w.type);
    printf("Required Strength: \t%d\n", w.required_STR);
    printf("+ Strength: \t\t%d\n\n", w.add_STR);
    printf("***************************\n");

    // Need to dynamically print the required stat (DEX / STR / INT) depending on the classes, and additional stats too.
}

int main() {
    WEAPON GodButcher = initWeapon("God Butcher", "Warrior", "Sword", 50, 15);
    WEAPON LumberAxe = initWeapon("Lumber Axe", "Warrior", "Axe", 100, 25);
    printWeapon(GodButcher);
    printWeapon(LumberAxe);
}

// Once player character wears a certain weapons or armors, implement the function to add corresponding additional stats to the character.