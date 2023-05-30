#include "CommandWords.h"

vector<string> CommandWords::validCommands;

/**
 * Constructor -- initialise the command words.
 */
CommandWords::CommandWords() {
    // Populate the vector if we haven't already.
    if (validCommands.empty()) {
        validCommands.push_back("\n start \n");
        validCommands.push_back("exit \n");
        validCommands.push_back("commands \n");
        validCommands.push_back("map \n");
        validCommands.push_back("yes \n");
        validCommands.push_back("no \n");
        validCommands.push_back("up \n");
        validCommands.push_back("down \n");
        validCommands.push_back("left \n");
        validCommands.push_back("right \n");
        validCommands.push_back("drop \n");

    }
}

/**
 * Check whether a given String is a valid command word.
 * Return true if it is, false if it isn't.
 **/
bool CommandWords::isCommand(string aString) {
    for (unsigned int i = 0; i < validCommands.size(); i++)
    {
        if (validCommands[i].compare(aString) == 0)
            return true;
    }
    // if we get here, the string was not found in the commands
    return false;
}

/*
 * Print all valid commands to System.out.
 */
std::string CommandWords::showAll() {
    std::string output;
    //Loops through validCommands and prints each to the screen.
    for (unsigned int i = 0; i < validCommands.size(); i++)
    {
        output += validCommands[i] + " ";
    }
    return "valid commands are: " + output;
}

