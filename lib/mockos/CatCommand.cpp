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
    std::string space = " "; //Space indicates two parts to the input
    auto num  = s.find(space);
    if(num != std::string::npos) {
        std::istringstream iss(s);
        std::string first, second;
        iss>>first>>second;

        AbstractFile* file = system->openFile(first); //Opening of the file when a " " exists before the append command

        if (file == nullptr) {
            return 27; //Unique error code of 27 if the file does not exist/fail
        }
        BasicDisplayVisitor displayVisitor;
        file->accept(&displayVisitor);
        std::cout << "Enter data you would like to append to the existing file. Enter :wq to save the file and exit, enter :q to exit without saving." << std::endl;
        std::string input;
        std::vector<char> currContent;
        while (true) {
            std::getline(std::cin, input);
            if(input == ":wq") { //Saving of changes + q (exit)
                currContent.pop_back();
                if (file->append(currContent) != 0) {
                    std::cout << "Content failed to append" << std:: endl;
                    system->closeFile(file);
                    return 26; //Unique error code of 26 to indicate failed append command
                }
                std::cout << "Content appended" << std::endl;
                system->closeFile(file);
                break;
            }
            else if (input == ":q") { //Just exit (q), no saving
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
            std::getline(std::cin, input); //Getline -> goes through the input line-by-line
            if(input == ":wq") { //If save and exit is called, the new content is removed and what has already been collected is appended to the file
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
            else if (input == ":q") { //Leaves loop without saving, and only quitting (q)
                system->closeFile(file);
                break;
            }
            else {
                for (const char &c : input) {
                    currContent.push_back(c);
                }
                currContent.push_back('\n'); //Puts a new character in a new line for each new line of an input
            }
        }
    }

    return 0;
}
