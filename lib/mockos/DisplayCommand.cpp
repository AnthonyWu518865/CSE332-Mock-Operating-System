#include "mockos/DisplayCommand.h"
#include <sstream>
#include "mockos/BasicDisplayVisitor.h"
#include "mockos/PasswordProxy.h"

//Constructor
DisplayCommand::DisplayCommand(AbstractFileSystem *s): system(s){}

void DisplayCommand::displayInfo() { //Indicates what "-d" means after the filename
    std::cout << "ds (ds<filename>): displays a formatted file." << std::endl; //Formatted file (no "-d")
    std::cout << "ds (ds<filename> -d): displays an unformatted file." << std::endl; //Unformatted file
}

int DisplayCommand::execute(std::string input) {
    std::istringstream iss(input);
    std::string filename, foruf;
    iss >> filename;
    std::string space = " ";

    //Similar to other functions - checks to see if "-d" exists -> if formatting is wrong, a unique error code of 84 is shown
    if((iss >> foruf) && foruf != "-d") {
        std::cout << "Error: Must indicate unformatted files/data with '-d'." << std::endl;
        return 84;
    }

    AbstractFile *file = system -> openFile(filename);

    if (file == nullptr) {
        std::cout << "Error: Unable to find file." << std::endl;
        return 85; //Unique error code of 85 if the file doesn't exist (can't open the file)
    }

    if (foruf == "-d") { //For unformatted files -> reads file and iterates through characters
        vector <char> buffer = file->read();
        for (char x : buffer) {
            std:: cout << x;
        }
        std::cout << std::endl;
    }
    else {
        file -> accept(&visitorDisplay);
    }
    system -> closeFile(file);
    return 0;
}