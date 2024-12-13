#include "mockos/LSCommand.h"
#include <string>
#include <set>

#include "mockos/MetadataDisplayVisitor.h"

void LSCommand::displayInfo() {
    std::cout << "ls lists out all the different file names, and if input ls -m, then it will display the metadata along with it" << std::endl;
}

int LSCommand::execute(std::string s) {
    std::set<string> curr = system->getFileNames();
    int count = 0;
    if (s == "") {
        for (std::set<string>::iterator it = curr.begin(); it != curr.end(); it++) {
            count += 1;
            if (count == 2) {
                count = 0;
                cout << endl;
            }
            std::cout << *it;
        }
    }
    else if (s == "-m") {
        MetadataDisplayVisitor visitor;
        for(std::set<string>::iterator it = curr.begin(); it != curr.end(); it++) {
            AbstractFile* pointer = system->openFile(*it);
            pointer->accept(&visitor);
        }
    }
    else {
        std::cout << "Command not found" << std::endl;
        displayInfo();
    }

}
