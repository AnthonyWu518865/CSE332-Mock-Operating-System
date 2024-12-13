# pragma once
#include "AbstractCommand.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/AbstractFileSystem.h"

class DisplayCommand: public AbstractCommand {
    AbstractFileSystem* system;
public:
    DisplayCommand(AbstractFileSystem* s);
    ~DisplayCommand() override = default;
    void displayInfo() override;
    int execute(std::string) override;
};
