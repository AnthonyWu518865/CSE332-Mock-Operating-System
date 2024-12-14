#include "mockos/DisplayCommand.h"
#include <sstream>

#include "mockos/BasicDisplayVisitor.h"
#include "mockos/PasswordProxy.h"

DisplayCommand::DisplayCommand(AbstractFileSystem *s): system(s){}

void DisplayCommand::displayInfo() {
    std::cout << "" << std::endl;
}

// how do we make sure that it succeeds
int DisplayCommand::execute(std::string s) {
    std::string space = " ";
    auto num  = s.find(space);
    if(num != std::string::npos) {
        std::istringstream iss(s);
        std::string first, second;
        iss>>first>>second;
        AbstractFile *file = system->openFile(first);
        if (second == "-d") {
            vector<char> unformatted = file->read();
            for (const char a : unformatted) {
                cout << a << " ";
            }
        }
        system->closeFile(file);
    }
    else {
        AbstractFile *file = system->openFile(s);
        BasicDisplayVisitor visitorDisplay;
        file->accept(&visitorDisplay);
        system->closeFile(file);
    }
    return 0;
}

