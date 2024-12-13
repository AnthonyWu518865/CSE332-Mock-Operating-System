#include "mockos/CommandPrompt.h"
#include "mockos/AbstractCommand.h"
#include <sstream>

void CommandPrompt::setFileSystem(AbstractFileSystem * filePtr) {
    fileSystem = filePtr;
}

void CommandPrompt::setFileFactory(AbstractFileFactory * fileFactoryPtr) {
    fileFactory = fileFactoryPtr;
}

int CommandPrompt::addCommand(std::string command, AbstractCommand *commandPtr) {
    auto check = promptMap.insert({command, commandPtr});
    if(check.second == false) {
        return 15;
    }
    return 0;
}

void CommandPrompt::listCommands() {
    for(const auto &promptMap : promptMap) {
        std::cout << promptMap.first << std::endl;
    }
}

std::string CommandPrompt::prompt() {
    std::cout << "Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command."<< std::endl;
    std::cout<< "$  ";
    std::string input;
    std::getline(std::cin, input);
    return input;
}

int CommandPrompt::run() {
    while (true) {
        std::string input = prompt();
        if (input == "q") {
            std::cout << "quit." << std::endl;
            return 10;
        }else if (input == "help") {
            listCommands();
        }else {
            std::string space = " ";
            unsigned int num  = input.find(space);
            if(num == std::string::npos) {
                //promptMap.find(command);
                if(promptMap.find(input) != promptMap.end()) {
                    std::string empty = " ";
                     promptMap[input]->execute(empty);
                    if(promptMap[input]->execute(empty) != 0) {
                        std::cout << "Command failed. 1"  << std::endl;
                    }
                    //     return promptMap[command]->execute(empty);
                    // }
                }else {
                    std::cout << "Command not found.1 " << std::endl;
                }
            }else {
                std::istringstream iss(input);
                std::string first, second;
                iss>>first>>second;
                std::getline (iss, second);
                if(first == "help") {
                    // std::string second;
                    // iss>>first>>second;
                    if(promptMap.find(second) != promptMap.end()) {
                        promptMap[second]->displayInfo();
                    }else {
                        std::cout << "Command not found. 2" << std::endl;
                    }
                }else {
                    if(promptMap.find(first) != promptMap.end()) {
                        std::cout << "Command found." << std::endl;
                        if (promptMap[first]->execute(second) != 0) {
                            std::cout << "Command failed 2."  << std::endl;
                        }
                    }else {
                        std::cout << "Command not found. 3" << std::endl;
                    }
                }
            }
        }
    }
}




