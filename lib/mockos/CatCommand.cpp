#include "mockos/CatCommand.h"
#include <string>
#include <set>
#include <sstream>
#include "mockos/BasicDisplayVisitor.h"


void CatCommand::displayInfo() {
    std::cout << "" << std::endl;
}

int CatCommand::execute(std::string s) {
    std::string space = " ";
    unsigned int num  = s.find(space);
    if(num != std::string::npos) {
        std::istringstream iss(s);
        std::string first, second;
        iss>>first>>second;
        AbstractFile* file = system->openFile(first);
        if(second == "-a") {
            BasicDisplayVisitor displayVisitor;
            file->accept(&displayVisitor);
            std::cout << "Enter data you would like to append to the existing file. Enter :wq to save the file and exit, enter :q to exit without saving." << std::endl;
            std::string input;
            std::vector<char> currContent;
            while (true) {
                std::getline(std::cin, input);
                if(input == ":wq") {
                    file->append(currContent);
                    std::cout << "Content appended" << std::endl;
                    return 21;
                }
                else if (input == ":q") {
                    return 22;
                }
                else {
                    for (const char &c : input) {
                        currContent.push_back(c);
                    }
                    currContent.push_back('\n');
                }
            }
        }
    }
    else {
        AbstractFile* file = system->openFile(s);
        std::cout << "Enter data you would like to append to the existing file. Enter :wq to save the file and exit, enter :q to exit without saving." << std::endl;
        std::string input;
        std::vector<char> currContent;
        while (true) {
            std::getline(std::cin, input);
            if(input == ":wq") {
                file->write(currContent);
                std::cout << "Content overwritten" << std::endl;
                break;
            }
            else if (input == ":q") {
                break;
            }
            else {
                for (const char &c : input) {
                    currContent.push_back(c);
                }
                currContent.push_back('\n');
            }
        }
    }
    return 0;
}
