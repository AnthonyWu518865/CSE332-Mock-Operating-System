#include "mockos/TouchCommand.h"
#include <sstream>
#include "mockos/PasswordProxy.h"

TouchCommand::TouchCommand(AbstractFileSystem *s, AbstractFileFactory *f): system(s), factory(f){}

void TouchCommand::displayInfo() {
    std::cout << "Touch command info: touch creates a file, touch can be invoked with the command: touch <filename>" << std::endl;
}

int TouchCommand::execute(std::string s) {
    std::string space = " ";
    unsigned int num  = s.find(space);
    if(num != std::string::npos) {
        std::istringstream iss(s);
        std::string first, second;
        iss>>first>>second;
        AbstractFile *file = factory->createFile(first);
        if(file == nullptr) {
            return 11;
        }
        std:: cout << "File created successfully" << std:: endl;
        if (second == "-p") {
            std::cout << "Enter password: " << std::endl;
            std::string password;
            std::cin >> password;
            PasswordProxy curr(file, password);
        }
        int result = system->addFile(first, file);
        if(result != 0) {
            delete file;
            return 13;
        }
        std:: cout << "File added successfully" << std::endl;
        return 0;
    }
    else {
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
}

