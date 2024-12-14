#include "mockos/CopyCommand.h"
#include <sstream>
#include <iostream>
#include <vector>

CopyCommand::CopyCommand(AbstractFileSystem *s): system(s){}

void CopyCommand::displayInfo() {
    std::cout << "Touch command info: touch creates a file, touch can be invoked with the command: touch <filename>" << std::endl;
}

int CopyCommand::execute (std::string s) {
    istringstream iss(s);

    string existingFile, copiedFile;
    iss >> existingFile >> copiedFile;

    return 0;
}