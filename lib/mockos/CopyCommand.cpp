#include "mockos/CopyCommand.h"
#include <sstream>
#include <iostream>

CopyCommand::CopyCommand(AbstractFileSystem *s): system(s){}

void CopyCommand::displayInfo() {
    std::cout << "Touch command info: touch creates a file, touch can be invoked with the command: touch <filename>" << std::endl;
}

int CopyCommand::execute (std::string s) {
    return 0;
}