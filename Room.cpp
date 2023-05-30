#include "Room.h"
#include "Command.h"


Room::Room(string name, string description) {
    this->name = name;
    this->description = description;
}

void Room::setExits(Room *up, Room *right, Room *down, Room *left) {
    if (up != NULL)
        exits["up"] = up;
    if (right != NULL)
        exits["right"] = right;
    if (down != NULL)
        exits["down"] = down;
    if (left != NULL)
        exits["left"] = left;
}

string Room::shortDescription() {
    //    return "Current location = " + name;
    return name;
}

string Room::longDescription() {
    return description;
}

string Room::exitString() {
    string returnString = "options: ";
    for (map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)
        // Loop through map
        returnString += "  " + i->first;	// access the "first" element of the pair (direction as a string)
    return returnString + "\n";
}

Room* Room::nextRoom(string direction) {
    map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
    if (next == exits.end())
        return NULL; // if exits.end() was returned, there's no room in that direction.
    return next->second; // If there is a room, remove the "second" (Room*)
        // part of the "pair" (<string, Room*>) and return it.
}

void Room::addItem(Item *inItem) {
    //cout <<endl;
    //cout << "Just added" + inItem->getLongDescription();
    itemsInRoom.push_back(*inItem);
}

string Room::displayItem() {
    string tempString;
    int sizeItems = (itemsInRoom.size());
    if (sizeItems < 1) {
        tempString = "no items in room";
    }
    else if (sizeItems > 0) {
        for (int n = 0; n < sizeItems; n++) {
            tempString = tempString + itemsInRoom[n].getShortDescription() + "  " ;
        }
    }
    return tempString;
}


Item Room::getItem(){
    return itemsInRoom.at(0);
}

int Room::numberOfItems() {
    return itemsInRoom.size();
}

int Room::isItemInRoom(string inString)
{
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        return false;
    }
    else if (itemsInRoom.size() > 0) {
        int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            // compare inString with short description
            int tempFlag = inString.compare( itemsInRoom[x].getShortDescription());
            if (tempFlag == 0) {
                itemsInRoom.erase(itemsInRoom.begin()+x);
                return x;
            }
            x++;
        }
    }
    return -1;
}


