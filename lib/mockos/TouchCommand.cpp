#include "mockos/TouchCommand.h"
#include <string>

TouchCommand::TouchCommand(AbstractFileSystem *s, AbstractFileFactory *f): system(s), factory(f){}

void TouchCommand::displayInfo() {
    std::cout << "Touch command info: touch creates a file, touch can be invoked with the command: touch <filename>" << std::endl;
}

int TouchCommand::execute(std::string s) {
    AbstractFile *file = factory->createFile(s);
    int result = system->addFile(s, file);
    if(file == nullptr) {
        std::cerr << "File Creation failed." << std::endl;
        return 11;
    }
    if(result != 0) {
        std::cerr << "Adding File failed." << std::endl;
        delete file;
        return 13;
    }
    return 0;
}


