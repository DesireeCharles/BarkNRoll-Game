#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "item.h"
using namespace std;
using std::vector;

class Room {

private:
    string name;
    string description;
    map<string, Room*> exits;
    vector <Item> itemsInRoom;


public:
    int numberOfItems();
    Room(string name, string description);
    void setExits(Room *up, Room *right, Room *down, Room *left);
    string shortDescription();
    string longDescription();
    Room* nextRoom(string direction);
    void addItem(Item *inItem);
    string displayItem();
    string exitString();
    int isItemInRoom(string inString);
    void removeItemFromRoom(int location);
    Item getItem();
};

#endif
