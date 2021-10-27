#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "enumClasses.h"
#include <time.h> 
//#include "characterStats.h"
#include "map.h"

Room* current_room = NULL; 

//menu function for executing commands, will add more later
void menu(char c){
    if(c == 'm')
    {
        char direction;
        printf("Enter in (N,W,E,S) for your desired direction\n"); // enter direction
        scanf(" %c",&direction);
        current_room = Move_Rooms(current_room,direction); // changes current_room to the new room you moved into
    }
} 

int main() {
    Stats *Test = newCharacter(Warrior, "First Character");
    DisplayStats(Test);
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

}