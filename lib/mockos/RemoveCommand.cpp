#include "mockos/RemoveCommand.h"
#include <string>
#include <set>

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