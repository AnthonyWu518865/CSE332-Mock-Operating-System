#include "mockos/DisplayCommand.h"
#include <sstream>
#include "mockos/BasicDisplayVisitor.h"
#include "mockos/PasswordProxy.h"

DisplayCommand::DisplayCommand(AbstractFileSystem *s): system(s){}

void DisplayCommand::displayInfo() {
    std::cout << "ds (ds<filename>): displays a formatted file." << std::endl;
    std::cout << "ds (ds<filename> -d): displays an unformatted file." << std::endl;
}

int DisplayCommand::execute(std::string input) {
    std::istringstream iss(input);
    std::string filename, foruf;
    iss >> filename;

    std::string space = " ";

    if((iss >> foruf) && foruf != "-d") {
        std::cout << "Error: Must indicate unformatted files/data with '-d'." << std::endl;
        return 84;
    }

    AbstractFile *file = system -> openFile(filename);

    if (file == NULL) {
        std::cout << "Error: Unable to find file." << std::endl;
        return 85;
    }

    if (foruf == "-d") {
        vector <char> buffer = file -> read();
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