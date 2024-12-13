#pragma once
#include "AbstractCommand.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/AbstractFileSystem.h"

class RemoveCommand: public AbstractCommand {
    AbstractFileFactory* factory;
    AbstractFileSystem* system;
public:
    RemoveCommand(AbstractFileSystem* s,AbstractFileFactory* f);
    ~RemoveCommand() override = default;
    void displayInfo() override;
    int execute(std::string)override;
};