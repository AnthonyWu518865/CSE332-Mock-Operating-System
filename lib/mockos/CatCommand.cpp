#include "mockos/CatCommand.h"
#include <string>
#include <set>
#include <sstream>
#include "mockos/BasicDisplayVisitor.h"


CatCommand::CatCommand(AbstractFileSystem *s): system(s){}

void CatCommand::displayInfo() {
    std::cout << "The Cat command is used to " << std::endl;
}

int CatCommand::execute(std::string s) {
    std::string space = " ";
    auto num  = s.find(space);
    if(num != std::string::npos) {
        std::istringstream iss(s);
        std::string first, second;
        iss>>first>>second;
        AbstractFile* file = system->openFile(first);
        BasicDisplayVisitor displayVisitor;
        file->accept(&displayVisitor);
        std::cout << "Enter data you would like to append to the existing file. Enter :wq to save the file and exit, enter :q to exit without saving." << std::endl;
        std::string input;
        std::vector<char> currContent;
        while (true) {
            std::getline(std::cin, input);
            if(input == ":wq") {
                currContent.pop_back();
                if (file->append(currContent) != 0) {
                    std::cout << "Content failed to append" << std:: endl;
                    return 26;
                }
                std::cout << "Content appended" << std::endl;
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
    else {
        AbstractFile* file = system->openFile(s);
        std::cout << "Enter data you would like to append to the existing file. Enter :wq to save the file and exit, enter :q to exit without saving." << std::endl;
        std::string input;
        std::vector<char> currContent;
        while (true) {
            std::getline(std::cin, input);
            if(input == ":wq") {
                currContent.pop_back();
                if(file->write(currContent) != 0) {
                    std:: cout << "Content failed to overwrite" << std::endl;
                    return 25;
                }
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
