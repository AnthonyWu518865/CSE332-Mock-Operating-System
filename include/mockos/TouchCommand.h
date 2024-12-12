# pragma once
#include "AbstractCommand.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/AbstractFileSystem.h"

class TouchCommand: public AbstractCommand {
    AbstractFileFactory* factory;
    AbstractFileSystem* system;
    public:
    TouchCommand(AbstractFileSystem* s,AbstractFileFactory* f);
    ~TouchCommand() override = default;
    void displayInfo() override;
    int execute(std::string) override;
};
