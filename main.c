#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "enumClasses.h"
#include "Weapons.h"
#include "Inventory.h"
//#include "Encounter.c"

void print_menu(){
    printf("Press (m) for Movement || ");
    printf("Press (s) for Stats || ");
    printf("Press (i) to display inventory||\n");
    printf("Press (e) to equip a weapon|| ");
    printf("Press (a) to equip armor|| ");
    printf("Press (h) to swap weapon||\n");
    printf("Press (n) to swap armor|| ");
    printf("Press (u) to unequip weapon|| ");
    printf("Press (o) to unequip armor||\n");
    printf("Press (c) to use consumable|| ");
    printf("Press (t) to detect traps\n");
}

int main() {
    int userClassInput;
    char userNameInput[50];

    printf("Enter the name of your character:\n");
    scanf("%s", userNameInput);
    printf("Enter your class, 0 = Warrior, 1 = Mage, 2 = Thief:\n");
    scanf("%d", &userClassInput);
    if (userClassInput != 1 || userClassInput != 2 || userClassInput != 3) {
        printf("Invalid Input\n");
        scanf("%d", &userClassInput);
        return (0);
    }
    else if (isdigit(userClassInput) == 0) {
        printf("Invalid Input.\n");
        scanf("%d", &userClassInput);
        return (0);
    }
    Stats *Test1 = newCharacter(userClassInput, userNameInput); 
    DisplayStats(Test1);
    //DisplayStats(Test1);

    print_menu();

    // Stats *Test2 = newCharacter(Mage, "Second Character");
    // DisplayStats(Test2);

    // Stats *Test3 = newCharacter(Thief, "Third Character");
    // DisplayStats(Test3);

    // INVENTORY *inv = (INVENTORY*) malloc(sizeof(INVENTORY));
    
    // CreateInventory(inv);
    // WEAPON *LumberAxe = initWeapon("Lumber Axe", "Warriors", 0, 10, 20);
    // AddWeapon(LumberAxe, inv);
    // //wearWeapon(LumberAxe, Test1, inv);
    // DisplayInventory(inv);

      /*
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
    */
}