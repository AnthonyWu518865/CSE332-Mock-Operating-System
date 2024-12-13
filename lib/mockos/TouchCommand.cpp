#include "mockos/TouchCommand.h"
#include <string>

TouchCommand::TouchCommand(AbstractFileSystem *s, AbstractFileFactory *f): system(s), factory(f){}

void TouchCommand::displayInfo() {
    std::cout << "Touch command info: touch creates a file, touch can be invoked with the command: touch <filename>" << std::endl;
}

int TouchCommand::execute(std::string s) {
    AbstractFile *file = factory->createFile(s);
    if(file == nullptr) {
        return 11;
    }
    std:: cout << "File created successfully" << std:: endl;
    int result = system->addFile(s, file);
    if(result != 0) {
        delete file;
        return 13;
    }
    std:: cout << "File added successfully" << std::endl;
    return 0;
}

