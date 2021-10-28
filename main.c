#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "characterStats.h"
#include "enumClasses.h"

int main() {

    Stats *Test1 = newCharacter(Warrior, "First Character");
    DisplayStats(Test1);

int main() {
    //Stats *Test = newCharacter(Warrior, "First Character");
    //DisplayStats(Test);
    char c;
    Map* map; 
    map = (Map*)malloc(num_rooms * sizeof(Room*)); //allocating memory for all the rooms
    CreateRandomMap(map); //creates a random map
    Print_Full_Map(map); //prints it, will comment out for real version
    printf("Enter your menu selection: ");
    current_room = map->rooms[0]; //sets current room to the first one in array
    //Look_Around(r);
    scanf(" %c",&c);
    while(c != 'q')
    {
        menu(c); //execute menu
        //print menu
        Look_Around(current_room); //function to look at possible room options
        printf("Enter your new choice: \n");
        scanf(" %c",&c);
    } 
    Stats *Test2 = newCharacter(Mage, "Second Character");
    DisplayStats(Test2);

    Stats *Test3 = newCharacter(Thief, "Third Character");
    DisplayStats(Test3);

    //Map* map;
    //map = (Map*)malloc(num_rooms*sizeof(Room*));
    //CreateRandomMap(map);
    //Print_Full_Map(map);
}