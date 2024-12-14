#include "mockos/MacroCommand.h"
#include <sstream>
#include <iostream>
#include "mockos/AbstractParsingStrategy.h"

MacroCommand::MacroCommand(AbstractFileSystem *s) : fileSys(s), strategy(nullptr) {}

void MacroCommand::displayInfo() {
    std::cout << "Touch command info: touch creates a file, touch can be invoked with the command: touch <filename>" << std::endl;
    //std:: cout <<
}

int MacroCommand::execute (std::string s) {
    vector <string> parsedInput = strategy -> parse(s);
    if (parsedInput.empty() == true) {
        std::cerr << "Error: no argument." << endl;
        return -1;
    }
    int i = 0;
    for (AbstractCommand* abcmd : commands) {
        if (i < parsedInput.size()) {
            int parsedResult = abcmd -> execute(parsedInput[i]);
            if (parsedResult != 0) {
                cerr << "Command execution failed with input: " << parsedInput[i] << " and error code: " << parsedResult << endl;
            }
            if (i + 1 < parsedInput.size()) {
                ++i;
            }
            else {
                cerr << "Error: not enough inputs." << endl;
                return -1;
            }
        }
        cout << "Successful parsing." << endl;
        return 0;
    }
}

std::vector<std::string> MacroCommand::addCommand(AbstractCommand* command) {
    std::vector<std::string> a;
    return vector<std::string>();
}
void MacroCommand::setParseStrategy(AbstractParsingStrategy* strategy) {
    if ()
}