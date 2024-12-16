#include "mockos/CatCommand.h"
#include <string>
#include <set>
#include <sstream>
#include "mockos/BasicDisplayVisitor.h"


CatCommand::CatCommand(AbstractFileSystem *s): system(s){}

void CatCommand::displayInfo() {
    std::cout << "The Cat command is used to write to a file. Cat command can be invoked by cat <filename> for overwrite or cat <filename> -a for append." << std::endl;
}

int CatCommand::execute(std::string s) {
    std::string space = " ";
    auto num  = s.find(space);
    if(num != std::string::npos) {
        std::istringstream iss(s);
        std::string first, second;
        iss>>first>>second;
        AbstractFile* file = system->openFile(first);
        if (file == nullptr) {
            return 27;
        }
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
                    system->closeFile(file);
                    return 26;
                }
                std::cout << "Content appended" << std::endl;
                system->closeFile(file);
                break;
            }
            else if (input == ":q") {
                system->closeFile(file);
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
        if (file == nullptr) {
            return 27;
        }
        std::cout << "Enter data you would like to append to the existing file. Enter :wq to save the file and exit, enter :q to exit without saving." << std::endl;
        std::string input;
        std::vector<char> currContent;
        while (true) {
            std::getline(std::cin, input);
            if(input == ":wq") {
                currContent.pop_back();
                if(file->write(currContent) != 0) {
                    std:: cout << "Content failed to overwrite" << std::endl;
                    system->closeFile(file);
                    return 25;
                }
                std::cout << "Content overwritten" << std::endl;
                system->closeFile(file);
                break;
            }
            else if (input == ":q") {
                system->closeFile(file);
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
