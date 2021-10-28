#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "enumClasses.h"
#include "Weapons.h"
#include "Inventory.h"
#include "map.h"
#include "Mob.h"
//#include "Encounter.c"
Room* current_room = NULL;
Stats *Test1 = NULL;
INVENTORY *inv = NULL;

void Combat(Stats* p, Mob* m) {
    //make sure you #include <time.h> 
    srand((int)time(0));
    printf("Combat begins! Enemies: %s\n", m->name);

    while(p->currentHP > 0 && m->currentHP > 0) {
        printf("Player turn. Choose an action (attack)\n");
        char pAction[50];
        scanf("%s", pAction);
        if(strcmp(pAction, "a") == 0) {
        // player attacking
            if(((rand()%20)+6) > m->armorClass-1) {
                m->currentHP -= p->strength;
                printf("You hit %s for %d damage!\n", m->name, p->strength);
                if (m->currentHP <= 0) {
                    break;
                }
            }
            else {
                printf("You miss %s!\n", m->name);
            }
        }

        // monster attacking
        if(((rand()%20)+m->hit) > p->armorClass-1) {
            p->currentHP -= m->damage;
            printf("%s hits you for %d damage! You have %d hp left.\n", m->name, m->damage, p->currentHP);
        }
        else {
            printf("You avoid %s's attack!\n", m->name);
        }
    }

    if (p->currentHP <= 0) {
        printf("You lost the fight and are now dead. :( \n");
        //call some sort of function that runs on player death
    }
    else {
        printf("You defeated the %s!\n");
        //DropLoot(m, p->inventory);
    }
    
}

void Trap(Stats* p) {
    //make sure you #include <time.h> 
    srand((int)time(0));
    int trapDetectionDC = 12 + rand()%8 + 1;
    int trapDodgeDC = 8 + rand()%10 + 1;
    //trap spotted?
    if ((rand()%20)+p->trapDetection+1 >= trapDetectionDC) {
        printf("You've spotted a trap! You avoid it with ease.\n");
        //add experience?
    }
    else if ((rand()%20)+2 >= trapDodgeDC){
        printf("You set off a trap but quickly dodge, avoiding harm!\n");
    }
    else {
        //can change the way trap damage is calculated later (probably based on level), for now its 1-10 damage
        int d = (rand() % 9) + 1;
        p->currentHP -= d;
        printf("You set off a trap and take %d damage. Ouch!\n", d);
    }
}

/*
void Loot(Stats* p, char lootTable[50], int numDrops) {
    //read in the lootTable from file or hard code it
    printf("You stumble upon treasures, loot to your heart's content! You find:\n");
    char loot[numDrops];
    if(int i=0; i < numDrops; ++i) {
        //drops numDrops number of random items from the given loot table. Player can type the item's drop number in to take it,
        //or #all to take all loot dropped.
        loot[i] = lootTable[rand()%50];
        printf("%s\n", loot[i]);
        //needs to add item in loot to inventory based on the name of the item
        //p->INVENTORY += loot[i];
    }
}
 */
void Exit() {
    // Player escapes the dungeon and wins or moves onto next floor
    printf("You found the exit door and escape the dungeon!\n");
}

//function for deciding if there will be an encounter
void Seek_Encounter(){
    srand((int)time(0));
    int x = rand() % 3;
    switch(x)
    {
        case 0:
            //Combat(Test1,Mob);
        break;
        case 1:
            Trap(Test1);
        break;
    }
    x = rand() % 2;
    switch(x)
    {
        case 0:
            //Combat(Test1,Mob);
        break;
        case 1:
            Trap(Test1);
        break;
    }
}

Room* Move_Rooms(char c, Room* c_room){
    switch(c)
    {
        case 'N':
        if(c_room->N_Room != NULL)
        {
            c_room = c_room->N_Room;
            Seek_Encounter();
        }
        break;
        case 'S':
        if(c_room->S_Room != NULL)
        {
            c_room = c_room->S_Room;
            Seek_Encounter();
        }
        break;
        case 'E':
        if(c_room->E_Room != NULL)
        {
            c_room = c_room->E_Room;
            Seek_Encounter();
        }
        break;
        case 'W':
        if(c_room->W_Room != NULL)
        {
            c_room = c_room->W_Room;
            Seek_Encounter();
        }
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
    printf("Press (t) to detect traps\n");
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
                    wearWeapon(w,Test1,inv);
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
                    wearArmor(a,Test1,inv);
                }
            }
        break;
        case 'h': //fix me
            printf("Please enter the name of a weapon from your inventory to equip: ");
            char weapon2[50];
            scanf("%s",weapon2);
            for(int i = 0; i < 50; i++)
            {
                if(strcmp(weapon2,inv->invWeapon[i]->name)==0)  //tries to find weapon in inv
                {
                    WEAPON * w = inv->invWeapon[i];
                    //WEAPON * w2 = current weapon;
                    //swapWeapon(w,w2,Test1,inv);
                }
            }
        break;
        case 'n': //fix me
            printf("Please enter the name of an armor from your inventory to equip: ");
            char armor2[50];
            scanf("%s",armor2);
            for(int i = 0; i < 50; i++)
            {
                if(strcmp(armor2,inv->invArmor[i]->name)==0) //tries to find armor in inv
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
                    //consumeItem(Test1,c); //problem, how is it connected to inventory?
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
    scanf("%s", userNameInput);
    printf("Enter your class, 0 = Warrior, 1 = Mage, 2 = Thief:\n");
    scanf("%d", &userClassInput);
    //*Test1 = newCharacter(userClassInput, userNameInput); 
    DisplayStats(Test1);

    Test1 = newCharacter(Warrior, "First Character"); 
    if (userClassInput != 1 || userClassInput != 2 || userClassInput != 3) {
    if (userClassInput < 0 || userClassInput > 2) {
        printf("Invalid Input\n");
        return 0;
    }
    Stats *Test1 = newCharacter(userClassInput, userNameInput); 
    DisplayStats(Test1);
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
        if(current_room->final == true)
        {
            Exit();
            break;
        }
        Look_Around(current_room); //function to look at possible room options
        printf("Enter your new choice: \n");
        scanf(" %c",&c);
    } 
}}