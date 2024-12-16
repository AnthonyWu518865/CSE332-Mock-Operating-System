#include "mockos/MacroCommand.h"
#include <sstream>
#include <iostream>
#include "mockos/AbstractParsingStrategy.h"

//Constructor
MacroCommand::MacroCommand(AbstractFileSystem *s) : fileSys(s), pStrategy(nullptr) {}

//Destructor with safe delete
MacroCommand::~MacroCommand() {
    delete pStrategy;
}

void MacroCommand::displayInfo() {
    std::cout << "Touch command info (touchls): touch creates a file, touch can be invoked with the command: touch <filename>" << std::endl;
    std::cout << "rn (rn <filename>): this command renames the file and deletes the original file." << std::endl;
}

int MacroCommand::execute (std::string s) {
    vector <string> parsedInput = pStrategy -> parse(s);
    if (parsedInput.empty() == true) {
        std::cerr << "Error: no argument." << endl;
        return -1;
    }

    if (commands.empty() == true) {
        cerr << "Error: There are no commands added." << endl;
        return 89;
    }

    int i = 0;
    for (AbstractCommand* command : commands) {
        int result = command->execute(parsedInput[i]);
        if (result != 0) {
            return 87;
        }
        i++;
    }
    cout << "Successful parsing." << endl;
    return 0;
}

void MacroCommand::addCommand(AbstractCommand* command) {
    commands.push_back(command);
}
void MacroCommand::setParseStrategy(AbstractParsingStrategy* strategy) {
    //if (pStrategy) {
        //delete pStrategy;
   // }
    pStrategy = strategy;
}