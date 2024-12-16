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
    //Additional macrocommand (cat + ds)
    std::cout << "catds (catds<filename>): this command creates and edits a file and lists all of its contents" << std::endl;
}

int MacroCommand::execute (std::string s) {
    vector <string> parsedInput = pStrategy -> parse(s);
    //Splitting of the strings into multiple parts (parsing)
    if (parsedInput.empty() == true) {
        std::cerr << "Error: no argument." << endl;
        return -1; //Unique error code of -1 when there is no input, or if the parsing command fails to properly execute
    }

    if (commands.empty() == true) {
        cerr << "Error: There are no commands added." << endl;
        return 89; //Unique error code of 89 when there is no command
    }

    int i = 0;
    for (AbstractCommand* command : commands) { //Adds each parsed input into parsedInput[i]
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
    commands.push_back(command); //Needed in the main file, adding different commands
}
void MacroCommand::setParseStrategy(AbstractParsingStrategy* strategy) {
    pStrategy = strategy;
}