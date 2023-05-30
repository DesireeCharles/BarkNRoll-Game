#include <iostream>
#include <string>

using namespace std;
#include "ZorkUL.h"

ZorkUL::ZorkUL() {
    createRooms();
}

void ZorkUL::createRooms()  {

    start = new Room("start", "You are about to embark on an adventure with Athena. Defeat the enemies to save the animals and make sure to visit Safe Zone rooms to acquire items for them.");
    Gloomweavers = new Room("Gloomweavers", "You are in Chronomancer's room. A powerful sorcerers who can manipulate time,\n"
                                            " slowing down or speeding up the player's movements or attacks, or even reversing \n"
                                            "time to heal themselves. Can you handle it? Read the question in the image and answer 'yes' or 'no'.\n"
                                            " If you guess the correct answer Chronomancer will give you the cat, if you guess the wrong answer you will have to fight Chronomancer.");
    Safe1 = new Room( "Safe1","You are in the safe zone. Athena found a bone to give to the dog.");
        Safe1->addItem(new Item("bone"));
    Embermaws = new Room("Embermaws", "You are in Embermaws's room. fiery creatures that leave trails of flames in their wake,\n"
                                      " forcing the player to carefully navigate the battlefield to avoid taking damage. \n"
                                      "Can you handle it? Read the question in the image and answer 'yes' or 'no'. If you guess the correct answer \n"
                                      "Embermaws will give you the raccoon, if you guess the wrong answer you will have to fight Embermaws.");
    Safe2 = new Room( "Safe2","You are in the safe zone. Athena found food to give to the raccoon.");
        Safe2->addItem(new Item("food"));
    Wispfiends = new Room("Wispfiends","You are in Wispfiend's room. An Ethereal creatures that can phase through walls and obstacles, making \n"
                                        " them difficult to corner or trap. Can you handle it? Read the question in the image and answer 'yes' or 'no'. \n"
                                        "If you guess the correct answer Wispfiend will give you the cow, if you guess the wrong answer you will have to fight Wispfiend.");
    Safe3 = new Room( "Safe3","You are in the safe zone. Athena found grass to give to the cow.");
        Safe3->addItem(new Item("grass"));
    Mindflayers = new Room("Mindflayers","You are in Mindflayer's room. creatures with powerful psychic abilities that can manipulate the player's thoughts, \n"
                                          "causing them to attack their allies or be unable to attack at all. Can you handle it? Read the question in the image and answer 'yes' or 'no'. \n"
                                          "If you guess the correct answer Mindflayer will give you the panda, if you guess the wrong answer you will have to fight Mindflayer.");
    Safe4 = new Room( "Safe4","You are in the safe zone. Athena found bamboo to give to the panda.");
        Safe4->addItem(new Item("bamboo"));
    Chronomancers = new Room("Chronomancers","You are in Chronomancer's room. A powerful sorcerers who can manipulate time, slowing down or speeding up the player's movements or attacks, \n"
                                              "or even reversing time to heal themselves. Can you handle it? Read the question in the image and answer 'yes' or 'no'. If you guess the correct \n"
                                              "answer Chronomancer will give you the cat, if you guess the wrong answer you will have to fight Chronomancer.");
    Safe5 = new Room( "Safe5","You are in the safe zone. Athena found milk to give to the cat.");
        Safe5->addItem(new Item("milk"));
    Boss = new Room("Boss","You are in Titan's room. A hulking symbiotic, godlike creature that can manipulate the very fabric of reality. It has the power to warp space and time, \n "
                            "creating portals that lead to other dimensions and eras.Can you handle it? Be careful, Titan is Venom's cousin. Read the question in the image and answer \n"
                            "'yes' or 'no'. If you guess the correct answer Titan will give you the hamster, if you guess the wrong answer you will have to fight Titan.");




    //(N, E, S, W) ->  (up, right, down, left)
    start->setExits(NULL, Gloomweavers, NULL, NULL);
    Gloomweavers->setExits(Safe1, Embermaws, NULL, start);
    Safe1->setExits(NULL, NULL, Gloomweavers, NULL);
    Embermaws->setExits(NULL, Safe2, Wispfiends, Gloomweavers);
    Safe2->setExits(NULL, NULL, NULL, Embermaws);
    Wispfiends->setExits(Embermaws, NULL, Safe3, Mindflayers);
    Safe3->setExits(Wispfiends, NULL, NULL, NULL);
    Mindflayers->setExits(NULL, Wispfiends, Chronomancers, Safe4);
    Safe4->setExits(NULL, Mindflayers, NULL, NULL);
    Chronomancers->setExits(Mindflayers,NULL,Safe5,Boss);
    Safe5->setExits(Chronomancers, NULL, NULL, NULL);
    Boss->setExits(NULL,Chronomancers,NULL,NULL);

    currentRoom = start;
}




std::string ZorkUL::printWelcome() {
    return getIntro();
}

std::string ZorkUL::getIntro(){
    return "The Great Animal Rescue is about to begin.\n"
           "Athena and you are on a mission to rescue animals that have been trapped in various locations. You must defeat all the monsters in order to be able to \n"
           "rescue all the animals.\n"
           "No animal is left behind. \n"
           "You will encounter animals in need of rescue in each level.\n"
           "Use your skills to overcome challenges and save the animals.\n"
           "And remember, go to the Safe Zone to be able to get extra powers. \n"
           "Oh yeah , these animals are different, keep this in mind."
           "Good luck!";
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
std::string ZorkUL::processCommand(Command command) {
    if (command.isUnknown()) {
        return "invalid input";
    }

    std::string commandWord = command.getCommandWord();
    if (commandWord.compare("info") == 0)
        return printHelp();

    else if (commandWord.compare("map") == 0)
    {
        string mapText ="                          [Safe1]                                      \n"
                         "                            |                                             \n"
                         "                            |                                             \n"
                         "      [Start]       --- [Gloomweavers] --- [Embermaws] --- [Safe2]  \n"
                         "                                                |                         \n"
                         "      [Safe4] --- [Mindflayers]  --- [Wispfiends]                   \n"
                         "                           |                    |                         \n"
                         "                           |                    |                         \n"
                         "            [Boss] --- [Chronomancers] --- [Safe3]                  \n"
                         "                           |                                              \n"
                         "                           |                                              \n"
                         "                       [Safe5]                                     \n";

        return mapText;
    }

    else if (commandWord.compare("go") == 0){
        nextRoom = goRoom(command);
        return nextRoom;
    }


    else if (commandWord.compare("put") == 0)
    {

    }
    else if (commandWord.compare("quit") == 0) {
        if (command.hasSecondWord())
            return "overdefined input";
        //			cout << "overdefined input"<< endl;
        else
            return ""; /**signal to quit*/
    }
    else if (commandWord.compare("confirm")==0){
        return "";
    }
    return "";
}
/** COMMANDS **/
std::string ZorkUL::printHelp() {
    return parser.showCommands();
}

string ZorkUL::goRoom(Command command) {
    if (!command.hasSecondWord()) {
        return "incomplete input";
    }

    string direction = command.getSecondWord();

    // Try to leave current room.
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
        //		cout << "underdefined input"<< endl;
        return "underdefined input";
    else {
        currentRoom = nextRoom;
        //        cout << currentRoom->longDescription() << endl;
        getCurrentRoomDesc();
        return currentRoom->shortDescription();
    }
}


string ZorkUL::go(string direction) {
    //Make the direction lowercase
    //transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    //Move to the next room
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL)
        return("direction null");
    else
    {
        currentRoom = nextRoom;
        return currentRoom->longDescription();
    }
}
//
string ZorkUL::getCurrentRoomDesc(){ //current location
    return currentRoom->longDescription() + "\n";
}

string ZorkUL::getCurrentRoomItems(){
    return currentRoom->displayItem();
}

string ZorkUL::getCurrentRoomExits(){
    return currentRoom->exitString();
}


string ZorkUL::checkRoom(){
    return currentRoom->shortDescription();
}

string ZorkUL::getInventory(){
    string tempString;
    int sizeItems = (inventory.size());
    if (sizeItems < 1) {
        tempString = "no items in room";
    }
    else if (sizeItems > 0) {
        for (int n = 0; n < sizeItems; n++) {
            tempString = tempString + inventory[n].getShortDescription()+ "\n" ;
        }
    }
    return tempString;
}
