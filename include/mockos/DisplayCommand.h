# pragma once
#include "AbstractCommand.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/AbstractFileSystem.h"

class DisplayCommand: public AbstractCommand {
    AbstractFileFactory* factory;
    AbstractFileSystem* system;
public:
    DisplayCommand(AbstractFileSystem* s,AbstractFileFactory* f);
    ~DisplayCommand() override = default;
    void displayInfo() override;
    int execute(std::string) override;
};
