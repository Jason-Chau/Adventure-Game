#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "characterStats.h"

int main() {
    Stats Test = initCharacterStats("First Character", "Human", "Warrior", 20, 10, 15, 14, 13);
    printCharacter(Test);
}