#ifndef MAP_HEADER
#define MAP_HEADER
#include <stdbool.h>

#define num_rooms 5


typedef struct Map_Struct{
    struct Room* rooms[num_rooms];          
}Map;
 
typedef struct Room_Struct{ 
    bool explored; 
    struct Room* N_Room;
    struct Room* W_Room;
    struct Room* E_Room;
    struct Room* S_Room;
}Room;

void CreateRandomMap(Map* m);
void CreateTestMap(Map* m); 
Room* CreateRoom();
void Connect_Rooms(Room* r1, Room* r2, int direction); 
void Print_Full_Map(Map* m); 

#endif