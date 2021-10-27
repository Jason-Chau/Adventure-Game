#include <string.h>
#include "Consumables.h"
//#include "characterStats.h"
#include "Inventory.h"
#include "enumClasses.h"

CONSUMABLE initConsumables(char *name, int type, int amountHPHeal) {
    CONSUMABLE c;
    strcpy(c.name, name);
    c.type = type;
    c.amountHPHeal = amountHPHeal;
    return c;
}

// Heal HP when item is consumed
Stats consumeItem(Stats s, CONSUMABLE c) {

    if(s.currentHitPoints == s.hitPoints) {
        printf("You already have full HP\n");
    }
    // When current HP + amount HP heals is greater than max of character's HP, then it will just heal up to character's max HP.
    else if(s.currentHitPoints + c.amountHPHeal > s.hitPoints) {
        printf("Consuming potion \"%s\"..\nCurrent HP: %d\n", c.name, s.hitPoints);
        s.currentHitPoints = s.hitPoints;
    }
    else {
        s.currentHitPoints += s.currentHitPoints + c.amountHPHeal;
    }

    //RemoveItem(c.name, c.type, inventory);
}

// Inventory updateInven() {
    // need a function to keep updating inventory whenever character consumes items
    // or loot items 
// }


