# pragma once
# include <map>
#include "mockos/AbstractCommand.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/AbstractFileSystem.h"

class CommandPrompt {
    std::map <std::string, AbstractCommand*> promptMap;
    AbstractFileSystem *fileSystem;
    AbstractFileFactory *fileFactory;
protected:
    void listCommands();
    std::string prompt();
    public:
    CommandPrompt(AbstractFileSystem *fileSystem, AbstractFileFactory *fileFactory);
    ~CommandPrompt() = default;
    void setFileSystem(AbstractFileSystem* filePtr);
    void setFileFactory(AbstractFileFactory* fileFactoryPtr);
    int addCommand(std::string command, AbstractCommand* commandPtr);
    int run();

};


