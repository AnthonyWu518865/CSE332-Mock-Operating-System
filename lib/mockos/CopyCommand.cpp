#include "mockos/CopyCommand.h"

#include <filesystem>
#include <sstream>
#include <iostream>
#include <vector>
#include "mockos/TextFile.h"

CopyCommand::CopyCommand(AbstractFileSystem *s): system(s){}

void CopyCommand::displayInfo() {
    std::cout << "Copy command info: copy copies a file into a new file, copy can be invoked with the command: cp <filename> <newFilename_without_extension>." << std::endl;
}

int CopyCommand::execute (std::string s) {
    istringstream iss(s);

    string existingFile, copiedFile;
    iss >> existingFile >> copiedFile;

    AbstractFile* copyingFile = system -> openFile(existingFile);
    if (!copyingFile) {
        cout << "Error: File not found." << endl;
        return 100;
    }
    //For copying a file and adding it to the file system (fileSys)
    //Need to close the file after opening and adding to it too
    AbstractFile* copy = copyingFile -> clone(copiedFile);
    int appFile = system -> addFile(copy -> getName(), copy);
    system -> closeFile(copyingFile);
    copyingFile = nullptr;

    if (appFile == 0) {
        return 0;
    }

    delete copy;
    return -1;
}