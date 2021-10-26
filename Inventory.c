#include <stdio.h>
#include <string.h>

#include "Weapons.h"
#include "Armors.h"
//#include "Consumables.h"

#include "Inventory.h"

void CreateInventory(INVENTORY* inventory, WEAPON* weapons[50], ARMOR* armors[50], CONSUMABLE* consumables[50]) {
    //need to either read in inventory from save file or hard code items to be in inventory and
    //pass those items in through the arrays above
    WEAPON* w;
    w = inventory->invWeapon[0];
    printf("TEST %s\n", inventory->invWeapon[0]);
    for(int i=0; i<50; ++i) {
        inventory->invWeapon[i] = weapons[i];
        inventory->invArmor[i] = armors[i];

        //inventory->invConsumable[i] = consumables[i];
    }
    

}
/*
void DisplayInventory(INVENTORY* inventory) {
    //if the errors cant be fixed, can change function to pass in the
    //three arrays instead of inventory
    int i=0;
    printf("Weapons:\n");
    WEAPON* w = inventory->invWeapon[0]; 
    while(strcmp(w->name, "")!=0) {
        printf("%s\n", w->name);
        ++i;
        w = inventory->invWeapon[i];
    }
    i=0;
    ARMOR* a = inventory->invArmor[0];
    printf("Armor:\n");
    while(strcmp(a->name, "")!=0) {
        printf("%s\n", a->name);
        ++i;
        a = inventory->invArmor[i];
    }
    i=0;
    CONSUMABLE* c = inventory->invConsumable[0];
    printf("Consumables:\n");
    while(strcmp(c->name, "")!=0) {
        printf("%s\n", c->name);
        ++i;
        c = inventory->invConsumable[i];
    }
}

void AddWeapon(WEAPON* w, INVENTORY* inventory) {
    WEAPON* wep;
    for(int i = 0; i<50; ++i) {
        wep = inventory->invWeapon[i];
        if (strcmp(wep->name, "") == 0) {
            inventory->invWeapon[i] = w;
            break;
        }
    }
}

void AddArmor(ARMOR* a, INVENTORY* inventory) {
    ARMOR* arm;
    for(int i = 0; i<50; ++i) {
        arm = inventory->invArmor[i];
        if (strcmp(arm->name, "") == 0) {
            inventory->invArmor[i] = a;
            break;
        }
    }
}

void AddConsumable(CONSUMABLE* c, INVENTORY* inventory) {
    CONSUMABLE* cons;
    for(int i = 0; i<50; ++i) {
        cons = inventory->invConsumable[i];
        if (strcmp(cons->name, "") == 0) {
            inventory->invConsumable[i] = c;
            break;
        }
    }
}

void RemoveItem(char itemName[50], int itemType, INVENTORY* inventory){
    //itemType 0=weapon, 1=armor, 2=consumable
    if (itemType == 0) {
        WEAPON* w;
        for(int i = 0; i<50; ++i) {
            w = inventory->invWeapon[i];
            if(strcmp(w->name, itemName)==0) {
                RemoveWeapon(inventory->invWeapon, i);
            }
        }
    }
    else if(itemType == 1) {
        ARMOR* a;
        for(int i = 0; i<50; ++i) {
            a = inventory->invArmor[i];
            if(strcmp(a->name, itemName)==0) {
                RemoveWeapon(inventory->invArmor, i);
            }
        }
    }
    else if (itemType == 2){
        CONSUMABLE* c;
        for(int i = 0; i<50; ++i) {
            c = inventory->invConsumable[i];
            if(strcmp(c->name, itemName)==0) {
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
*/