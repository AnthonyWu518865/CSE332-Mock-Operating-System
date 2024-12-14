# pragma once
#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/AbstractFileSystem.h"
#include <vector>
#include <string>

class MacroCommand: public AbstractCommand {
    AbstractFileSystem* system;
public:
    MacroCommand(AbstractFileSystem* s);
    ~MacroCommand();
    void displayInfo() override;
    int execute(std::string) override;
    std::vector<std::string>addCommand(AbstractCommand* command);
    void setParseStrategy(AbstractParsingStrategy* strategy);

private:
    vector <AbstractCommand*> commands;
    AbstractParsingStrategy* strategy;
    AbstractFileSystem* fileSys;
};