#include "mockos/CommandPrompt.h"
#include "mockos/AbstractCommand.h"
#include <sstream>

void CommandPrompt::setFileSystem(AbstractFileSystem * filePtr) {
    AbstractFileSystem *fileSystem = filePtr;
}

void CommandPrompt::setFileFactory(AbstractFileFactory * fileFactoryPtr) {
    AbstractFileFactory *fileFactory = fileFactoryPtr;
}

int CommandPrompt::addCommand(std::string command, AbstractCommand *commandPtr) {
    promptMap.insert({command, commandPtr});
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
        std::string command = prompt();
        if (command == "q") {
            std::cout << "quit." << std::endl;
            return 10;
        }else if (command == "help") {
            listCommands();
        }else {
            std::string space = " ";
            int num  = command.find(space);
            if(num == std::string::npos) {
                promptMap.find(command);
                if(promptMap.find(command) != promptMap.end()) {
                    std::string empty = " ";
                    return promptMap[command]->execute(empty);
                    // if(promptMap[command]->execute(empty) != 0) {
                    //     std::cout << "Command failed. 1"  << std::endl;
                    //     return promptMap[command]->execute(empty);
                    // }
                }else {
                    std::cout << "Command not found.1 " << std::endl;
                    return 21;
                }
            }else {
                std::istringstream iss(command);
                std::string first, second;
                iss>>first>> second;
                //std::getline (iss, rest);
                if(first == "help") {
                    // std::string second;
                    // iss>>first>>second;
                    if(promptMap.find(second) != promptMap.end()) {
                        promptMap[second]->displayInfo();
                    }else {
                        std::cout << second << "Command not found. 2" << std::endl;
                        return 22;
                    }
                }else {
                    if(promptMap.find(first) != promptMap.end()) {
                        std::cout << second << "Command found." << std::endl;
                        if (promptMap[command]->execute(second) != 0) {
                            std::cout << "Command failed 2."  << std::endl;
                            return 23;
                        }
                        return 0;
                    }else {
                        std::cout << "Command not found. 3" << std::endl;
                        return 24;
                    }
                }
            }
        }
    }
}




