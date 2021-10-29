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
char difficulty = 'n';

void Combat(Stats* p, Mob* m, INVENTORY* inv) {
    srand((int)time(0));
    printf("\nCombat begins! Enemies: %s\n", m->name);
    while(p->currentHP > 0 && m->currentHP > 0) {
        
        while(1) {
            printf("\nPlayer turn. Choose an action (a = attack, c = consume): ");
            char c;
            scanf(" %c",&c);
            printf("\n");

            if(c == 'a') {
            // player attacking
                if(((rand()%20)+p->hit) > m->armorClass-1) {
                    m->currentHP -= p->strength;
                    printf("You hit %s for %d damage!\n", m->name, p->strength);
                }
                else {
                    printf("You miss %s!\n", m->name);
                }
                break;
            }
            else if (c == 'c') {
            // player consuming item
                char iName[50];
                printf("Which consumable would you like to consume? You have:\n");
                DisplayConsumables(inv);

                scanf(" %[^\n]%*c", iName);
                printf("ITEM SELECTED: %s\n", iName);
                
                CONSUMABLE* c;
                c = FindConsumable(inv, iName);
                if (strcmp(c->name, iName)==0) {
                    consumeItem(p, c, inv);
                    break;
                }
                else{
                    printf("Item not found.\n");
                    break;
                }
                
                
            }
            printf("Invalid Command, try again.\n");
            break;
        }
        //check if the monster is dead
        if (m->currentHP <= 0) {
            break;
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
    //check if player is dead
    if (p->currentHP <= 0) {
        printf("\nYou lost the fight and are now dead. :( \n\n");
        //call some sort of function that runs on player death
        return;
    }
    else {
        printf("\nYou defeated the %s!\n", m->name);
        DropLoot(m, m->loot, inv);
    }
    
}

void Trap(Stats* p) {
    //make sure you #include <time.h> 
    srand((int)time(0));
    int trapDetectionDC = 12 + rand()%8 + 1;
    int trapDodgeDC = 8 + rand()%10 + 1;
    //trap spotted?
    if ((rand()%20)+p->trapDetection+1 >= trapDetectionDC) {
        printf("\nYou've spotted a trap! You avoid it with ease.\n");
        //add experience?
    }
    else if ((rand()%20)+p->dodgeChance >= trapDodgeDC){
        printf("\nYou set off a trap but quickly dodge, avoiding harm!\n");
    }
    else {
        //can change the way trap damage is calculated later (probably based on level), for now its 1-10 damage
        int d = (rand() % 10) + 2;
        if(difficulty == 'e')
        {
            d /=2;
        }
        else if(difficulty == 'h')
        {
            d *= 2;
        }
        p->currentHP -= d;
        printf("\nYou set off a trap and take %d damage. Ouch!\n", d);
    }
}


void Exit(Stats* p) {
    // Player escapes the dungeon and wins or moves onto next floor
    if (p->currentHP >= 0) {
        printf("You found the exit door and escaped the dungeon!\n\n");
    }
}

//function for deciding if there will be an encounter
void Seek_Encounter(){
    srand((int)time(0));
    int x = rand() % 3;
    int y = rand() % 3;
    int z = rand() % 3;
    Mob* m = NULL;
    Mob* m2 = NULL;
    switch(x)
    {
        case 0:
            
            if (y == 0) {
                m = CreateGoblin(difficulty);
                Combat(Test1, m, inv);
            }
            else if (y == 1) {
                m = CreateBandit(difficulty);
                Combat(Test1, m, inv);
            }
            else {
                m = CreateOgre(difficulty);
                Combat(Test1, m, inv);
            }
            
        break;
        case 1:
            Trap(Test1);
        break;
    }
    x = rand() % 2;
    if (Test1->currentHP <= 0) {
        exit(1);
    }
    switch(x)
    {
        case 0:
            if (z == 0) {
                m2 = CreateGoblin(difficulty);
                Combat(Test1, m2, inv);
            }
            else if (z == 1) {
                m2 = CreateBandit(difficulty);
                Combat(Test1, m2, inv);
            }
            else {
                m2 = CreateOgre(difficulty);
                Combat(Test1, m2, inv);
            }
        break;
        case 1:
            Trap(Test1);
        break;
    }
    if (Test1->currentHP <= 0) {
        exit(1);
    }
}

Room* Move_Rooms(char c, Room* c_room){
    switch(c)
    {
        case 'n':
        if(c_room->N_Room != NULL)
        {
            c_room->explored = true;
            c_room = c_room->N_Room;
            if(!c_room->explored)
                Seek_Encounter();
        }
        break;
        case 's':
        if(c_room->S_Room != NULL)
        {
            c_room->explored = true;
            c_room = c_room->S_Room;
            if(!c_room->explored)
                Seek_Encounter();
        }
        break;
        case 'e':
        if(c_room->E_Room != NULL)
        {
            c_room->explored = true;
            c_room = c_room->E_Room;
            if(!c_room->explored)
                Seek_Encounter();
        }
        break;
        case 'w':
        if(c_room->W_Room != NULL)
        {
            c_room->explored = true;
            c_room = c_room->W_Room;
            if(!c_room->explored)
                Seek_Encounter();
        }
        break;
    }
    return c_room;
}

void print_menu(){
    printf("\nPress (m) for Movement\t\t||");
    printf("\tPress (s) for Stats\t\t||");
    printf("\tPress (i) to display inventory\t\n");
    printf("Press (w) to swap weapon\t|| ");
    printf("\tPress (a) to swap armor\t\t|| ");
    printf("\tPress (c) to use consumable\t\n");
    printf("*** Press (q) to quit ***\n");
}

void menu(char c){
    switch(c)
    {
        case 'm':
            Look_Around(current_room); //function to look at possible room options
            printf("\n");
            printf("Please enter a direction in which you wish to proceed(n s e w): ");
            char direction;
            scanf(" %c",&direction);
            current_room = Move_Rooms(direction,current_room); //goes to desired room or doesnt go anywhere if NULL direction
        break;
        case 's':
            DisplayStats(Test1);
        break;
        case 'i':
            DisplayInventory(inv);
            printf("\n");
        break;
        case 'w':
            //swap weapon
            printf("Which weapon would you like to equip? You have:\n");
            DisplayWeapons(inv);
            char iName[50];
            scanf(" %[^\n]%*c", iName);
            printf("ITEM SELECTED: %s\n", iName);
                
            WEAPON* w;
            w = FindWeapon(inv, iName);
            if (strcmp(w->name, iName)==0) {
                swapWeapon(Test1->currentWeapon, w, Test1, inv);
                printWeapon(Test1->currentWeapon);
            }
            else{
                printf("Item not found.\n");
            }
            
        break;
        case 'a':
            printf("Which armor would you like to equip? You have:\n");
            DisplayArmor(inv);
            char iName2[50];
            scanf(" %[^\n]%*c", iName2);
            printf("ITEM SELECTED: %s\n", iName2);
                
            ARMOR* a;
            a = FindArmor(inv, iName2);
            if (strcmp(a->name, iName2)==0) {
                swapArmor(Test1->currentArmor, a, Test1, inv);
                printArmor(Test1->currentArmor);
            }
            else{
                printf("Item not found.\n");
            }
            
        break;
        case 'c': //fix me
            
            printf("Which consumable would you like to consume? You have:\n");
            DisplayConsumables(inv);
            char iName3[50];

            scanf(" %[^\n]%*c", iName3);
            printf("ITEM SELECTED: %s\n", iName3);
                
            CONSUMABLE* c;
            c = FindConsumable(inv, iName3);
            if (strcmp(c->name, iName3)==0) {
                consumeItem(Test1, c, inv);
            }
            else{
                printf("Item not found.\n");
            }
        break;
    }

}

int main() {
    int userClassInput;
    char userNameInput[50];

    printf("Enter the name of your character:\n");
    scanf("%[^\n]%*c", userNameInput);
    printf("Enter your class, 0 = Warrior, 1 = Mage, 2 = Thief:\n");
    scanf("%d", &userClassInput);
    if (userClassInput < 0 || userClassInput > 2) {
        printf("Invalid Input\n");
        return 0;
    }
    Test1 = newCharacter(userClassInput, userNameInput); 
    printf("Enter difficulty 'e' = Easy, 'n' = Normal, 'h' = Hard:\n");
    scanf(" %c", &difficulty);
    DisplayStats(Test1);
    

    print_menu();

    inv = (INVENTORY*) malloc(sizeof(INVENTORY));
    
    CreateInventory(inv);

    WEAPON* bow = (WEAPON*)malloc(sizeof(WEAPON));
    bow = initWeapon("Bow", 0, 7, 8);
    AddWeapon(bow, inv);
    ARMOR* leather = (ARMOR*)malloc(sizeof(ARMOR));
    leather = initArmor("Leather", 1, 11, 2);
    AddArmor(leather, inv);
    CONSUMABLE* bread = (CONSUMABLE*)malloc(sizeof(CONSUMABLE));
    bread = initConsumables("Bread", 2, 5);
    AddConsumable(bread, inv);

    WEAPON* axe = (WEAPON*)malloc(sizeof(WEAPON));
    axe = initWeapon("Axe",  0, 14, 10);
    AddWeapon(axe, inv);
    ARMOR* chainmail = (ARMOR*)malloc(sizeof(ARMOR));
    chainmail = initArmor("Chainmail", 1, 16, 5);
    AddArmor(chainmail, inv);
    CONSUMABLE* potion = (CONSUMABLE*)malloc(sizeof(CONSUMABLE));
    potion = initConsumables("Potion", 2, 12);
    AddConsumable(potion, inv);
    
    WEAPON* sword = (WEAPON*)malloc(sizeof(WEAPON));
    sword = initWeapon("Sword", 0, 10, 11);
    AddWeapon(sword, inv);
    ARMOR* platemail = (ARMOR*)malloc(sizeof(ARMOR));
    platemail = initArmor("Platemail", 1,18, 8);
    AddArmor(platemail, inv);
    CONSUMABLE* steak = (CONSUMABLE*)malloc(sizeof(CONSUMABLE));
    steak = initConsumables("Steak", 2, 15);
    AddConsumable(steak, inv);
    

      
    char c;
    Map* map; 
    map = (Map*)malloc(num_rooms * sizeof(Room*)); //allocating memory for all the rooms
    CreateRandomMap(map); //creates a random map
    //Print_Full_Map(map); //prints it, will comment out for real version
    printf("Enter your menu selection: ");
    current_room = map->rooms[0]; //sets current room to the first one in array
    //Look_Around(r);
    scanf(" %c",&c);
    printf("\n");
    while(c != 'q')
    {
        menu(c); //execute menu
        //print menu
        if(current_room->final == true)
        {
            printf("\n");
            Exit(Test1);
            break;
        }
        //check to see if player is alive
        if (Test1->currentHP > 0) {
            print_menu();
            printf("Enter your new choice: ");
            scanf(" %c",&c);
            printf("\n");
        }
        else {
            break;
        }  
    } 
    
    free(map);
    free(Test1->currentWeapon);
    free(Test1->currentArmor);
    free(inv);
}