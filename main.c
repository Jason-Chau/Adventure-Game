#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "characterStats.h"
#include "enumClasses.h"

int main() {

    Stats *Test1 = newCharacter(Warrior, "First Character");
    DisplayStats(Test1);

    Stats *Test2 = newCharacter(Mage, "Second Character");
    DisplayStats(Test2);

    Stats *Test3 = newCharacter(Thief, "Third Character");
    DisplayStats(Test3);

    //Map* map;
    //map = (Map*)malloc(num_rooms*sizeof(Room*));
    //CreateRandomMap(map);
    //Print_Full_Map(map);
}