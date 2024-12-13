#include "mockos/MacroCommand.h"
#include <sstream>
#include <iostream>

MacroCommand::MacroCommand(AbstractFileSystem *s): system(s){}

void MacroCommand::displayInfo() {
    std::cout << "Touch command info: touch creates a file, touch can be invoked with the command: touch <filename>" << std::endl;
}

int MacroCommand::execute (std::string s) {
    return 0;
}
std::vector<std::string> MacroCommand::addCommand(AbstractCommand* command) {
    std::vector<std::string> a;
    return vector<std::string>();
}
void MacroCommand::setParseStrategy(AbstractParsingStrategy* strategy) {
}