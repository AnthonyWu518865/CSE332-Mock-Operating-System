#include "mockos/RemoveCommand.h"
#include <string>
#include <set>

RemoveCommand::RemoveCommand(AbstractFileSystem *s, AbstractFileFactory *f): system(s), factory(f){}

void RemoveCommand::displayInfo() {
    std::cout << "Remove command info: remove deleted a file, remove can be invoked with the command: rm <filename>" << std::endl;
}

int RemoveCommand::execute(std::string s) {
    if (system->deleteFile(s) != 0) {
        std::cerr << "Error deleting file " << s << std::endl;
        return 20;
    }
    std::cout << "Delete Successful" << std::endl;
    return 0;
}