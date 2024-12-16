#include "mockos/TouchCommand.h"
#include <sstream>
#include "mockos/PasswordProxy.h"
#include <iostream>

//Taken from studio 21 code - use of password proxy
TouchCommand::TouchCommand(AbstractFileSystem *s, AbstractFileFactory *f): system(s), factory(f){}

//Touch command info for user
void TouchCommand::displayInfo() {
    std::cout << "Touch command info: touch creates a file, touch can be invoked with the command: touch <filename>" << std::endl;
}

int TouchCommand::execute(std::string s) {
    std::string space = " "; //Looks for a space and then a -p (down below) after the name of the file name
    auto num  = s.find(space);
    if(num != std::string::npos) {
        std::istringstream iss(s);
        std::string first, second; //First: file name, Seconds: -p (if there is one)
        iss>>first>>second;
        if(second != "-p") { //Password-protected file
            cout<< "invalid command."<<endl;
            return 90;
        }
        AbstractFile *file = factory->createFile(first); //Creation of a new file
        if(file == nullptr) {
            return 11;
        }
        std:: cout << "File created successfully" << std:: endl;
        std::cout << "Enter password: " << std::endl; //Assigning of the password to the file
        std::string password;
        std::getline(std::cin, password);
        AbstractFile* curr = new PasswordProxy(file, password);

        //Needed to add the file into the file system, deletes original file if failed
        //Prevention of a memory leak
        int result = system->addFile(first, curr);

        if(result != 0) {
            delete file;
            return 13;
        }
        std:: cout << "File added successfully" << std::endl;
    }
    else {
        AbstractFile *file = factory->createFile(s); //Again, new file creation (no -p (password protection))
        if(file == nullptr) {
            return 11;
        }
        std:: cout << "File created successfully" << std:: endl;
        int result = system->addFile(s, file); //Again, added to file system (no -p (password protection))
        if(result != 0) {
            delete file;
            return 13;
        }
        std:: cout << "File added successfully" << std::endl;
    }
    return 0;
}

