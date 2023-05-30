#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
using namespace std;
//
class ZorkUL {
private:

    Parser parser;
    Room *currentRoom;
    string nextRoom;
    void createRooms();
    string goRoom(Command command);
    void createItems();
    void displayItems();
    std::string printHelp();
    std::string getIntro();





public:
    ZorkUL();
    string go(string direction);
    std::string processCommand(Command command);
    std::string printWelcome();
    string play();
    string getCurrentRoomDesc();
    string getCurrentRoomItems();
    string getCurrentRoomExits();
    string checkRoom();
    string getInventory();
    Room *start, *Gloomweavers,*Safe1, *Embermaws,*Safe2, *Wispfiends,*Safe3, *Mindflayers,*Safe4, *Chronomancers,*Safe5, *Boss;
    vector <Item> inventory;

};

#endif /*ZORKUL_H_*/
