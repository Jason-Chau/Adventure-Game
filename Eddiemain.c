#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "characterStats.h"
#include "enumClasses.h"
#include "Weapons.h"
#include "Inventory.h"
#include "Armors.h"

int main() {

    Stats *Test1 = newCharacter(Warrior, "First Character");
    DisplayStats(Test1);

    // Stats *Test2 = newCharacter(Mage, "Second Character");
    // DisplayStats(Test2);

    // Stats *Test3 = newCharacter(Thief, "Third Character");
    // DisplayStats(Test3);

    INVENTORY *inv = (INVENTORY*) malloc(sizeof(INVENTORY));
    
    CreateInventory(inv);
    WEAPON *LumberAxe = initWeapon("Lumber Axe", 0, 10, 5);
    WEAPON *GodButcher = initWeapon("God Butcher", 0, 100, 15);

    ARMOR *BabySuit = initArmor("Baby Suit",  1, 10, 5);
    ARMOR *CaptainSuit = initArmor("Captain Suit", 1, 100, 10);

    // CONSUMABLE *c = initConsumables("Fairy's Elixir", 2, 10);
    // AddConsumable(c, inv);
    // DisplayInventory(inv);
    // consumeItem(Test1, c, inv);
    // DisplayInventory(inv);

    AddWeapon(LumberAxe, inv);
    AddArmor(BabySuit, inv);
    DisplayInventory(inv);

    // printWeapon(LumberAxe, Test1);
    // wearWeapon(LumberAxe, Test1, inv);

    // swapWeapon(LumberAxe, GodButcher, Test1, inv);
    // detachWeapon(GodButcher, Test1, inv);
    //wearArmor(BabySuit, Test1, inv);
    wearArmor(BabySuit, Test1, inv);
    swapArmor(BabySuit,CaptainSuit,Test1, inv);
    DisplayStats(Test1);
    detachArmor(CaptainSuit, Test1, inv);
    DisplayStats(Test1);
    // DisplayInventory(inv);

    // swapWeapon(LumberAxe, GodButcher, Test1, inv);
    // swapArmor(BabySuit, CaptainSuit, Test1, inv);
    // DisplayStats(Test1);
    // DisplayInventory(inv);

    // detachWeapon(GodButcher, Test1, inv);
    // detachArmor(CaptainSuit, Test1, inv);
    // DisplayStats(Test1);
    // DisplayInventory(inv);
    // wearWeapon(LumberAxe, Test1, inv);
    // DisplayInventory(inv);

    // swapWeapon(LumberAxe, GodButcher, Test1, inv);
    // DisplayInventory(inv);

    // AddArmor(BabySuit, inv);
    // DisplayInventory(inv);

    // wearArmor(BabySuit, Test1, inv);
    // DisplayInventory(inv);

    // swapArmor(BabySuit, CaptainSuit, Test1, inv);
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