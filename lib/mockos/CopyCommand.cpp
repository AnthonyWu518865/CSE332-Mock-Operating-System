#include "mockos/CopyCommand.h"

#include <filesystem>
#include <sstream>
#include <iostream>
#include <vector>
#include "mockos/TextFile.h"

CopyCommand::CopyCommand(AbstractFileSystem *s): system(s){}

void CopyCommand::displayInfo() {
    std::cout << "Touch command info: touch creates a file, touch can be invoked with the command: touch <filename>" << std::endl;
}

int CopyCommand::execute (std::string s) {
    istringstream iss(s);

    string existingFile, copiedFile;
    iss >> existingFile >> copiedFile;

    AbstractFile* copyingFile = fileSys -> openFile(existingFile);
    if (!copyingFile) {
        cout << "Error: File not found." << endl;
        return 100;
    }

    //For copying a file and adding it to the file system (fileSys)
    //Need to close the file after opening and adding to it too
    AbstractFile* copy = copyingFile -> clone(copiedFile);
    int appFile = fileSys -> addFile(copy -> getName(), copy);
    fileSys -> closeFile(copy);
    copyingFile = nullptr;

    if (appFile == 0) {
        return 0;
    }

    delete copy;
    return -1;
}