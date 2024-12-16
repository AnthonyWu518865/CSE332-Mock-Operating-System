#include "mockos/RemoveCommand.h"
#include <string>
#include <set>


RemoveCommand::RemoveCommand(AbstractFileSystem *s): system(s){}
void RemoveCommand::displayInfo() {
    std::cout << "rm deletes file, it can be invoked with the command: rm <filename>. " << std::endl;
}

int RemoveCommand::execute(std::string fn) {
    if (fn.empty()) {
        cout<< "Error: Empty file name." << endl;
        return 5; //Unique error code
    }

    int deleteResult = system -> deleteFile(fn); //Allows for safe deletion of files
    if (deleteResult == 0) {
        return 0;
    }
    return deleteResult;
}