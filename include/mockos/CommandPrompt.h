# pragma once
# include <map>
#include "mockos/AbstractCommand.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/AbstractFileSystem.h"

class CommandPrompt {
protected:
    std::map <std::string, AbstractCommand*> promptMap;
    AbstractFileSystem *fileSystem;
    AbstractFileFactory *fileFactory;
    void listCommands();
    std::string prompt();
public:
    CommandPrompt() = default;
    ~CommandPrompt() = default;
    void setFileSystem(AbstractFileSystem* filePtr);
    void setFileFactory(AbstractFileFactory* fileFactoryPtr);
    int addCommand(std::string command, AbstractCommand* commandPtr);
    int run();

};


