#include "mockos/CommandPrompt.h"
#include "mockos/AbstractCommand.h"
#include <sstream>
CommandPrompt::CommandPrompt(AbstractFileSystem *fileSystem, AbstractFileFactory *fileFactory): fileSystem(nullptr), fileFactory(nullptr){};

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
            if(num == std::string::npos ) {
                promptMap.find(command);
                if(promptMap.find(command) != promptMap.end()) {
                    std::string empty = "";
                    if(promptMap[command]->execute(empty) != 0) {
                        std::cout << "Command failed."  << std::endl;
                    }
                }else {
                    std::cout << "Command not found." << std::endl;
                }
            }else {
                std::istringstream iss(command);
                std::string first, rest;
                iss>>first;
                std::getline (iss, rest);
                if(first == "help") {
                    std::string second;
                    iss>>second;
                    if(promptMap.find(second) != promptMap.end()) {
                        promptMap[second]->displayInfo();
                    }else {
                        std::cout << "Command not found." << std::endl;
                    }
                }else {
                    if(promptMap.find(first) != promptMap.end()) {
                        if (promptMap[command]->execute(rest) != 0) {
                            std::cout << "Command failed."  << std::endl;
                        }
                    }else {
                        std::cout << "Command not found." << std::endl;
                    }
                }
            }
        }
    }
}




