#ifndef PARSER_H_
#define PARSER_H_

#include "Command.h"
#include "CommandWords.h"

class Parser {
private:
    CommandWords *commands;

public:
    Parser();
    Command* getCommand();
    std::string showCommands();
};

#endif /*PARSER_H_*/
