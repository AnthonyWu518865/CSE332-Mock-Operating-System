#include "mockos/TouchCommand.h"
#include <sstream>
#include "mockos/PasswordProxy.h"
#include <iostream>

TouchCommand::TouchCommand(AbstractFileSystem *s, AbstractFileFactory *f): system(s), factory(f){}

void TouchCommand::displayInfo() {
    std::cout << "Touch command info: touch creates a file, touch can be invoked with the command: touch <filename>" << std::endl;
}

int TouchCommand::execute(std::string s) {
    std::string space = " ";
    auto num  = s.find(space);
    if(num != std::string::npos) {
        std::istringstream iss(s);
        std::string first, second;
        iss>>first>>second;
        if(second != "-p") {
            cout<< "invalid command."<<endl;
            return 90;
        }
        AbstractFile *file = factory->createFile(first);
        if(file == nullptr) {
            return 11;
        }
        std:: cout << "File created successfully" << std:: endl;
        std::cout << "Enter password: " << std::endl;
        std::string password;
        std::getline(std::cin, password);
        AbstractFile* curr = new PasswordProxy(file, password);
        int result = system->addFile(first, curr);
        if(result != 0) {
            delete file;
            return 13;
        }
        std:: cout << "File added successfully" << std::endl;
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
    }
    return 0;
}

