#ifndef MAP_HEADER
#define MAP_HEADER
#include <stdbool.h>

#define num_rooms 5

 
typedef struct Room_Struct{ 
    //struct Encounters* encounters[random_num];
    bool explored; 
    struct Room_Struct* N_Room;
    struct Room_Struct* W_Room;
    struct Room_Struct* E_Room;
    struct Room_Struct* S_Room;
    bool final;
}Room;

typedef struct Map_Struct{
    struct Room_Struct* rooms[num_rooms];          
}Map;

void CreateRandomMap(Map* m);
void CreateTestMap(Map* m); 
Room* CreateRoom();
void Connect_Rooms(Room* r1, Room* r2, int direction); 
void Print_Full_Map(Map* m); 

#endif 