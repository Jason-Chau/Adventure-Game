#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Weapons.h"
#include "Armors.h"
#include "Consumables.h"

#include "Inventory.h"

void CreateInventory(INVENTORY* inventory) {
    //need to either read in inventory from save file or hard code items to be in inventory and
    //pass those items in through the arrays above
    WEAPON* w = (WEAPON*)malloc(sizeof(WEAPON));
    w = initWeapon("", 0, -1, -1);
    ARMOR* a = (ARMOR*)malloc(sizeof(ARMOR));
    a = initArmor("", 1, -1, -1);
    CONSUMABLE* c = (CONSUMABLE*)malloc(sizeof(CONSUMABLE));
    c = initConsumables("", 2, 0);
    for(int i=0; i<50; ++i) {
        inventory->invWeapon[i] = w;
        inventory->invArmor[i] = a;
        inventory->invConsumable[i] = c;
    }
    printf("TEST %s\n", inventory->invWeapon[1]);
    /*
    for(int i=0; i<50; ++i) {
        inventory->invWeapon[i] = weapons[i];
        inventory->invArmor[i] = armors[i];

        //inventory->invConsumable[i] = consumables[i];
    }
    */
    //printf("TEST %s\n", inventory->invWeapon[1]);

}

void DisplayInventory(INVENTORY* inventory) {
    //if the errors cant be fixed, can change function to pass in the
    //three arrays instead of inventory
    int i=0;
    printf("Weapons:\n");
    WEAPON* w = (WEAPON*)malloc(sizeof(WEAPON));
    w = inventory->invWeapon[0]; 
    while(strcmp(w->name, "")!=0) {
        printf("%s\n", w->name);
        ++i;
        w = inventory->invWeapon[i];
    }
    i=0;
    ARMOR* a = (ARMOR*)malloc(sizeof(ARMOR));
    a = inventory->invArmor[0];
    printf("Armor:\n");
    while(strcmp(a->name, "")!=0) {
        printf("%s\n", a->name);
        ++i;
        a = inventory->invArmor[i];
    }
    i=0;

    
    CONSUMABLE* c = (CONSUMABLE*)malloc(sizeof(CONSUMABLE));
    c = inventory->invConsumable[0];
    printf("Consumables:\n");
    while(strcmp(c->name, "")!=0) {
        printf("%s\n", c->name);
        ++i;
        c = inventory->invConsumable[i];
    }
    
}



void DisplayWeapons(INVENTORY* inventory) {
    int i=0;
    WEAPON* w = (WEAPON*)malloc(sizeof(WEAPON));
    w = inventory->invWeapon[0];
    printf("Consumables:\n");
    while(strcmp(w->name, "")!=0) {
        printf("%s\n", w->name);
        ++i;
        w = inventory->invWeapon[i];
    }
    
}

void DisplayArmor(INVENTORY* inventory) {
    int i=0;
    ARMOR* a = (ARMOR*)malloc(sizeof(ARMOR));
    a = inventory->invArmor[0];
    printf("Consumables:\n");
    while(strcmp(a->name, "")!=0) {
        printf("%s\n", a->name);
        ++i;
        a = inventory->invArmor[i];
    }
    
}

void DisplayConsumables(INVENTORY* inventory) {
    int i=0;
    CONSUMABLE* c = (CONSUMABLE*)malloc(sizeof(CONSUMABLE));
    c = inventory->invConsumable[0];
    printf("Consumables:\n");
    while(strcmp(c->name, "")!=0) {
        printf("%s\n", c->name);
        ++i;
        c = inventory->invConsumable[i];
    }
    
}

WEAPON* FindWeapon(INVENTORY* inventory, char itemName[50]) {
    int i=0;
    WEAPON* w = (WEAPON*)malloc(sizeof(WEAPON));
    w = inventory->invWeapon[0];
    while(strcmp(w->name, "")!=0) {
        if (strcmp(w->name, itemName)==0) {
            return w;
        }
        ++i;
        w = inventory->invWeapon[i];
    }
    w = inventory->invWeapon[49];
    return w;
}

ARMOR* FindArmor(INVENTORY* inventory, char itemName[50]) {
    int i=0;
    ARMOR* a = (ARMOR*)malloc(sizeof(ARMOR));
    a = inventory->invArmor[0];
    while(strcmp(a->name, "")!=0) {
        if (strcmp(a->name, itemName)==0) {
            return a;
        }
        ++i;
        a = inventory->invArmor[i];
    }
    a = inventory->invArmor[49];
    return a;
}

CONSUMABLE* FindConsumable(INVENTORY* inventory, char itemName[50]) {
    int i=0;
    CONSUMABLE* c = (CONSUMABLE*)malloc(sizeof(CONSUMABLE));
    c = inventory->invConsumable[0];
    while(strcmp(c->name, "")!=0) {
        if (strcmp(c->name, itemName)==0) {
            return c;
        }
        ++i;
        c = inventory->invConsumable[i];
    }
    c = inventory->invConsumable[49];
    return c;
}

void AddWeapon(WEAPON* w, INVENTORY* inventory) {
    WEAPON* wep = (WEAPON*)malloc(sizeof(WEAPON));
    for(int i = 0; i<50; ++i) {
        wep = inventory->invWeapon[i];
        if (strcmp(wep->name, "") == 0) {
            inventory->invWeapon[i] = w;
            break;
        }
    }
}

void AddArmor(ARMOR* a, INVENTORY* inventory) {
    ARMOR* arm = (ARMOR*)malloc(sizeof(ARMOR));
    for(int i = 0; i<50; ++i) {
        arm = inventory->invArmor[i];
        if (strcmp(arm->name, "") == 0) {
            inventory->invArmor[i] = a;
            break;
        }
    }
}

void AddConsumable(CONSUMABLE* c, INVENTORY* inventory) {
    CONSUMABLE* cons = (CONSUMABLE*)malloc(sizeof(CONSUMABLE));
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
        WEAPON* w = (WEAPON*)malloc(sizeof(WEAPON));
        for(int i = 0; i<50; ++i) {
            w = inventory->invWeapon[i];
            if(strcmp(w->name, itemName)==0) {
                RemoveWeapon(inventory->invWeapon, i);
            }
        }
    }
    else if(itemType == 1) {
        ARMOR* a = (ARMOR*)malloc(sizeof(ARMOR));
        for(int i = 0; i<50; ++i) {
            a = inventory->invArmor[i];
            if(strcmp(a->name, itemName)==0) {
                RemoveArmor(inventory->invArmor, i);
            }
        }
    }
    
    else if (itemType == 2){
        CONSUMABLE* c;
        for(int i = 0; i<50; ++i) {
            c = inventory->invConsumable[i];
            if(strcmp(c->name, itemName)==0) {
                RemoveConsumable(inventory->invConsumable, i);
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
    WEAPON* w = (WEAPON*)malloc(sizeof(WEAPON));
    w = initWeapon("", -1, -1, -1);
    weapons[49] = w;
}
void RemoveArmor(ARMOR* armors[50], int target) {
    for(int i=target; i < 49; ++i) {
        armors[i] = armors[i+1];
    }
    ARMOR* a = (ARMOR*)malloc(sizeof(ARMOR));
    a = initArmor("", -1, -1, -1);
    armors[49] = a;
}
void RemoveConsumable(CONSUMABLE* consumables[50], int target) {
    for(int i=target; i < 49; ++i) {
        consumables[i] = consumables[i+1];
    }
    CONSUMABLE* c = (CONSUMABLE*)malloc(sizeof(CONSUMABLE));
    c = initConsumables("", 2, 0);
    consumables[49] = c;
}
