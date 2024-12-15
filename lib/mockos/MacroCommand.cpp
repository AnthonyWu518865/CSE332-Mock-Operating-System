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
    std::cout << "You can run different commands:" << endl;
    std::cout << "Touch command info (touchls): touch creates a file, touch can be invoked with the command: touch <filename>" << std::endl;
    std::cout << "catds <filename>: displays file contents." << endl;
    std::cout << "touchcatds <filename>: creates, writes, and displays the file's information/content." << endl;
    std::cout << "rn <filename> <newName>: for renaming files." << endl;
}

int MacroCommand::execute (std::string s) {
    vector <string> parsedInput = pStrategy -> parse(s);
    if (parsedInput.empty() == true) {
        std::cerr << "Error: no argument." << endl;
        return -1;
    }

    if (commands.empty() == true) {
        cerr << "Error: There are no commands added." << endl;
    }

    int i = 0;
    for (AbstractCommand* command : commands) {
        if (i < parsedInput.size()) {
            int parsedResult = command -> execute(parsedInput[i]);
            if (parsedResult != 0) {
                cerr << "Error: Command execution failed with input: " << parsedInput[i] << " and error code: " << parsedResult << endl;
            }
            if (i + 1 < parsedInput.size()) {
                ++i;
            }
        }
        else {
            cerr << "Error: not enough inputs." << endl;
            return -1;
        }
    }
    cout << "Successful parsing." << endl;
    return 0;
}

void MacroCommand::addCommand(AbstractCommand* command) {
    commands.push_back(command);
}
void MacroCommand::setParseStrategy(AbstractParsingStrategy* strategy) {
    //if (pStrategy) {
        delete pStrategy;
   // }
    //pStrategy = strategy;
}