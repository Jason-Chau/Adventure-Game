#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "characterStats.h"
#include "enumClasses.h"
#include "Weapons.h"
#include "Inventory.h"
#include "map.h"
//#include "Encounter.c"
Room* current_room = NULL;
Stats *Test1 = NULL;
INVENTORY *inv = NULL;

Room* Move_Rooms(char c, Room* c_room){
    switch(c)
    {
        case 'N':
        if(c_room->N_Room != NULL)
            c_room = c_room->N_Room;
        break;
        case 'S':
        if(c_room->S_Room != NULL)
            c_room = c_room->S_Room;
        break;
        case 'E':
        if(c_room->E_Room != NULL)
            c_room = c_room->E_Room;
        break;
        case 'W':
        if(c_room->W_Room != NULL)
            c_room = c_room->W_Room;
        break;
    }
    return c_room;
}

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
    printf("Press (t) to detect traps");
}

void menu(char c){
    switch(c)
    {
        case 'm':
            Look_Around(current_room); //function to look at possible room options
            printf("Please enter a direction in which you wish to proceed(N S E W): ");
            char direction;
            current_room = Move_Rooms(direction,current_room); //goes to desired room or doesnt go anywhere if NULL direction
            Look_Around(current_room); //looks around new room
        break;
        case 's':
            DisplayStats(Test1);
        break;
        case 'i':
            DisplayInventory(inv);
        break;
        case 'e':
            printf("Please enter the name of a weapon from your inventory to equip: ");
            char weapon[50];
            scanf("%s",weapon);
            for(int i = 0; i < 50; i++)
            {
                if(strcmp(weapon,inv->invWeapon[i]->name)==0) //tries to find weapon in inv
                {
                    WEAPON * w = inv->invWeapon[i];
                    wearWeapon(Test1,w,inv);
                }
            }
        break;
        case 'a':
            printf("Please enter the name of an armor from your inventory to equip: ");
            char armor[50];
            scanf("%s",armor);
            for(int i = 0; i < 50; i++)
            {
                if(strcmp(armor,inv->invArmor[i]->name)==0)  //tries to find armor in inv
                {
                    ARMOR * a = inv->invArmor[i];
                    wearArmor(Test1,a,inv);
                }
            }
        break;
        case 'h': //fix me
            printf("Please enter the name of a weapon from your inventory to equip: ");
            char weapon[50];
            scanf("%s",weapon);
            for(int i = 0; i < 50; i++)
            {
                if(strcmp(weapon,inv->invWeapon[i]->name)==0)  //tries to find weapon in inv
                {
                    WEAPON * w = inv->invWeapon[i];
                    //WEAPON * w2 = current weapon;
                    //swapWeapon(w,w2,Test1,inv);
                }
            }
        break;
        case 'n': //fix me
            printf("Please enter the name of an armor from your inventory to equip: ");
            char armor[50];
            scanf("%s",armor);
            for(int i = 0; i < 50; i++)
            {
                if(strcmp(armor,inv->invArmor[i]->name)==0) //tries to find armor in inv
                {
                    ARMOR * a = inv->invArmor[i];
                    //ARMOR * a2 = current armor;
                    //swapArmor(a,a2,Test1,inv);
                }
            }
        break;
        case 'u':
        //fix dont know how to set up, how do you know whats equiped?
        break;
        case 'o':
        //fix dont know how to set up, how do you know whats equiped?
        break;
        case 'c': //fix me
            printf("Please enter the name of the consumable from your inventory to eat: ");
            char food[50];
            scanf("%s",food);
            for(int i = 0; i < 50; i++)
            {
                if(strcmp(armor,inv->invConsumable[i]->name)==0) //tries to find consumable in inv?
                {
                    CONSUMABLE * c = inv->invConsumable[i];
                    consumeItem(Test1,c); //problem, how is it connected to inventory?
                }
            }
        break;
        case 't':
        //fix dont know how to set up
        break;
    }

}

int main() {
    int userClassInput;
    char userNameInput[50];

    printf("Enter the name of your character:\n");
    fgets(userNameInput, 50, stdin);
    scanf("%[^\n]%*c", userNameInput);
    printf("Enter your class, 0 = Warrior, 1 = Mage, 2 = Thief:\n");
    scanf("%d", &userClassInput);
    //*Test1 = newCharacter(userClassInput, userNameInput); 
    DisplayStats(Test1);

    Test1 = newCharacter(Warrior, "First Character"); 
    //DisplayStats(Test1);

    print_menu();

    // Stats *Test2 = newCharacter(Mage, "Second Character");
    // DisplayStats(Test2);

    // Stats *Test3 = newCharacter(Thief, "Third Character");
    // DisplayStats(Test3);

    inv = (INVENTORY*) malloc(sizeof(INVENTORY));
    
    CreateInventory(inv);
    // WEAPON *LumberAxe = initWeapon("Lumber Axe", "Warriors", 0, 10, 20);
    // AddWeapon(LumberAxe, inv);
    // //wearWeapon(LumberAxe, Test1, inv);
    // DisplayInventory(inv);

      
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