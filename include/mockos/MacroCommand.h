# pragma once
#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/AbstractFileSystem.h"
#include <vector>
#include <string>

class MacroCommand: public AbstractCommand {
public:
    MacroCommand(AbstractFileSystem* s);
    ~MacroCommand();
    void displayInfo() override;
    int execute(std::string) override;
    void addCommand(AbstractCommand* command);
    void setParseStrategy(AbstractParsingStrategy* strategy);

private:
    vector <AbstractCommand*> commands;
    AbstractParsingStrategy* pStrategy;
    AbstractFileSystem* fileSys;
};