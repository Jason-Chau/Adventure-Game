#include <stdio.h>
#include <string.h>

#include "Weapons.c"
#include "Armors.c"
//#include "Consumables.c"

#include "Inventory.h"

void CreateInventory(INVENTORY* inventory, WEAPON* weapons[50], ARMOR* armors[50], CONSUMABLE* consumables[50]) {
    //need to either read in inventory from save file or hard code items to be in inventory and
    //pass those items in through the arrays above
}


void DisplayInventory(INVENTORY* inventory) {
    //if the errors can be fixed, can change function to pass in the
    //three arrays instead of inventory
    int i=0;
    printf("Weapons:\n");
    while(strcmp(inventory->invWeapon[i]->name, "")!=0) {
        printf("%s\n", inventory->invWeapon[i]->name);
    }
    i=0;
    printf("Armor:\n");
    while(strcmp(inventory->invArmor[i]->name, "")!=0) {
        printf("%s\n", inventory->invArmor[i]->name);
    }
    i=0;
    printf("Consumables:\n");
    while(strcmp(inventory->invConsumable[i]->name, "")!=0) {
        printf("%s\n", inventory->invConsumable[i]->name);
    }
}

void AddWeapon(WEAPON* w, INVENTORY* inventory) {
    for(int i = 0; i<50; ++i) {
        if (strcmp(inventory->invWeapon[i]->name, "") == 0) {
            inventory->invWeapon[i] = w;
            break;
        }
    }
}

void AddArmor(ARMOR* a, INVENTORY* inventory) {
    for(int i = 0; i<50; ++i) {
        if (strcmp(inventory->invArmor[i]->name, "") == 0) {
            inventory->invArmor[i] = a;
            break;
        }
    }
}

void AddConsumable(CONSUMABLE* c, INVENTORY* inventory) {
    for(int i = 0; i<50; ++i) {
        if (strcmp(inventory->invConsumable[i]->name, "") == 0) {
            inventory->invConsumable[i] = c;
            break;
        }
    }
}

void RemoveItem(char itemName[50], int itemType, INVENTORY* inventory){
    //itemType 0=weapon, 1=armor, 2=consumable
    if (itemType == 0) {
        for(int i = 0; i<50; ++i) {
            if(strcmp(inventory->invWeapon[i]->name, itemName)==0) {
                RemoveWeapon(inventory->invWeapon, i);
            }
        }
    }
    else if(itemType == 1) {
        for(int i = 0; i<50; ++i) {
            if(strcmp(inventory->invArmor[i]->name, itemName)==0) {
                RemoveWeapon(inventory->invArmor, i);
            }
        }
    }
    else if (itemType == 2){
        for(int i = 0; i<50; ++i) {
            if(strcmp(inventory->invConsumable[i]->name, itemName)==0) {
                RemoveWeapon(inventory->invConsumable, i);
            }
        }
    }
    else {
        printf("Error, invalid item type!");
    }

}

void RemoveWeapon(WEAPON* weapons[50], int target) {
    for(int i=target; i < 49; ++i) {
        weapons[i] = weapons[i+1];
    }
}
void RemoveArmor(ARMOR* armors[50], int target) {
    for(int i=target; i < 49; ++i) {
        armors[i] = armors[i+1];
    }
}
void RemoveConsumable(CONSUMABLE* consumables[50], int target) {
    for(int i=target; i < 49; ++i) {
        consumables[i] = consumables[i+1];
    }
}