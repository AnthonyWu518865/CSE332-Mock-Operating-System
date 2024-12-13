# pragma once
#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/AbstractFileSystem.h"

class MacroCommand: public AbstractCommand {
    AbstractFileSystem* system;
public:
    MacroCommand(AbstractFileSystem* s);
    ~MacroCommand() override = default;
    void displayInfo() override;
    int execute(std::string) override;
    std::vector<std::string>addCommand(AbstractCommand* command);
    void setParseStrategy(AbstractParsingStrategy* strategy);
};