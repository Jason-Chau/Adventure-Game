#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct WEAPON_STRUCT {
    char class[20];
    char type[30];
    int required_STR;
    int add_STR;
} WEAPON;

WEAPON setClass(WEAPON w, char *class) {
    strcpy(w.class, class);
    return w;
}

WEAPON initWeapon(WEAPON w, char *class, char *type, int required_STR, int add_STR) {
    w = setClass(w, class);
    strcpy(w.type, type);
    w.required_STR = required_STR;
    w.add_STR = add_STR;
    return w;
}

void printWeapon(WEAPON w) {
    printf("***************************\n");
    printf("Class: \t\t\t%s\n", w.class);
    printf("Type: \t\t\t%s\n", w.type);
    printf("Required Strength: \t%d\n", w.required_STR);
    printf("+ Strength: \t\t%d\n\n", w.add_STR);
    printf("***************************\n");

}
int main() {
    WEAPON Blade = initWeapon(Blade, "Warrior", "Sword", 50, 15);
    WEAPON OakAxe = initWeapon(OakAxe, "Warrior", "Axe", 100, 25);
    printWeapon(Blade);
    printWeapon(OakAxe);

}
