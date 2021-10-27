#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "characterStats.h"
#include "enumClasses.h"

int main() {
    //Stats Test = initCharacterStats("First Character", "Human", "Warrior", 20, 10, 15, 14, 13);
    //printCharacter(Test);

    Stats *Test = newCharacter(Warrior, "First Character");
    DisplayStats(Test);
}