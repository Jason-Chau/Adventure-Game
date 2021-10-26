#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "map.h"



//function to construct map randomly
void CreateRandomMap(Map* m){
    time_t t;
    srand((unsigned) time(&t));  
    Room* room = CreateRoom(); 
    m->rooms[0] = room;  //starting room  
    int i = 0;
    room = m->rooms[0];     
    int count = 0;

    while(i != num_rooms) //only makes number of rooms in num_rooms
    {
        room = m->rooms[i - (rand() % (count+1))]; //chooses the new room based off of the last created rooms
        count = 0;
        for(int j = 0; j < 4; j++)
        {
            int x = rand() % 4;
            switch(x){
                case 0: //North
                    if(room->N_Room == NULL) 
                    {
                        if(i != num_rooms) 
                        {
                            Room* room1 = CreateRoom(); //creates new room
                            m->rooms[i] = room1;
                            Connect_Rooms(room, room1,x);
                            i++; //increases current room count expidite exiting loop
                            count++; //counts the number of side rooms
                        }
                    }
                    break;
                case 1: //West
                    if(room->W_Room == NULL)
                    {
                        if(i != num_rooms)
                        {
                            Room* room1 = CreateRoom();
                            m->rooms[i] = room1;
                            Connect_Rooms(room, room1,x);
                            i++;
                            count++;
                        }
                    }
                    break;
                case 2: //East
                    if(room->E_Room == NULL)
                    {
                        if(i != num_rooms)
                        {
                            Room* room1 = CreateRoom();
                            m->rooms[i] = room1;
                            Connect_Rooms(room, room1,x);
                            i++;
                            count++;
                        }
                    }
                    break;
                case 3: //South
                    if(room->S_Room == NULL)
                    {
                        if(i != num_rooms)
                        {
                            Room* room1 = CreateRoom();
                            m->rooms[i] = room1;
                            Connect_Rooms(room, room1,x);
                            i++;
                            count++;
                        }
                    }
                    break;
            }
        }
    }
}

//function to construct test map
void CreateTestMap(Map* m){
    Room* r1 = CreateRoom();
    Room* r2 = CreateRoom();
    Room* r3 = CreateRoom();
    Room* r4 = CreateRoom();
    Room* r5 = CreateRoom();
    m->rooms[0] = r1; 
    m->rooms[1] = r2;
    m->rooms[2] = r3;
    m->rooms[3] = r4;
    m->rooms[4] = r5;
    
    Connect_Rooms(m->rooms[0], m->rooms[1],2);
    Connect_Rooms(m->rooms[1],m->rooms[2],0);
    Connect_Rooms(m->rooms[2],m->rooms[3],2);
    Connect_Rooms(m->rooms[3],m->rooms[4],3);


    /*      
            r3------>r4
            ^         |
            |         |
            |         v
    r1----->r2        r5

    ****   MAP   ****
    */
}

//creates room with all the potential paths as null
Room* CreateRoom()
{
    Room* r;
    r = (Room*)malloc(sizeof(Room));
    r->explored = false;
    r->N_Room = NULL;
    r->W_Room = NULL;
    r->E_Room = NULL;
    r->S_Room = NULL;
    return r;
}

//connects 2 rooms based on int direction entered
void Connect_Rooms(Room* r1, Room* r2, int direction){
    switch(direction){
        case 0: //North
            r1->N_Room = r2;
            r2->S_Room = r1;
            break;
        case 1: //West
            r1->W_Room = r2;
            r2->E_Room = r1;
            break;
        case 2: //East
            r1->E_Room = r2;
            r2->W_Room = r1;
            break;
        case 3: //South
            r1->S_Room = r2;
            r2->N_Room = r1;
            break;
    }
}

void Print_Full_Map(Map* m){
    for(int i = 0; i < num_rooms; i++)
    {
        printf("In room %d you can go ", i);
        Room* r = m->rooms[i];
        if(r->N_Room != NULL)
            printf("North ");
        if(r->E_Room != NULL)
            printf("East ");
        if(r->W_Room != NULL)
            printf("West ");
        if(r->S_Room != NULL)
            printf("South ");
        printf("\n\n");
    }
}