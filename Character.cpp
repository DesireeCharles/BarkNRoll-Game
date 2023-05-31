//#include "Character.h"

class Character {
public:
    //operator overloading
    Character operator+(const Character& Item) {
        Character result;
        // change here
        return result;
    }
};

struct Character_bit {
    int big_weapon : 4;  // 4-bit integer
    bool small_weapon : 1;  // 1-bit boolean
};

//Characterx::Characterx(string description) {
//    this->description = description;
//}
//void Characterx::addItem(Item &item) {
//    itemsInCharacter.push_back(item);
//}
//void Characterx::addItem(Item *item) {
//    itemsInCharacter.push_back(*item);
//    delete item;
//}
//string Characterx::longDescription()
//{
//  string ret = this->description;
//  ret += "\n Item list:\n";
//  for (vector<Item>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++)
//    ret += "\t"+ (*i).getLongDescription() + "\n";
//  return ret;
//}

//class character:public item, public room { //Multiple inheritance

//};




