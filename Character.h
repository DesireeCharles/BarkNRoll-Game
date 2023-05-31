#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "ZorkUL.h"

#include <string>
using namespace std;
#include <vector>
using std::vector;


class Character {

public:
    void addItems(string Item);
    virtual void specialAction() = 0;
    Character(int special_weapom, int special_bullets) : special_weapom(100), special_bullets(100) {}
    Character(string description);
    string shortDescription();
    string longDescription();

private:
    int 100;
    int 100;
    string description;
    vector < string > itemsInCharacter;




union chracterunion {
    int weapon_number;
    float weight_weapon;
    char nameinitial_weapon;
};

};

#endif /*CHARACTER_H_
