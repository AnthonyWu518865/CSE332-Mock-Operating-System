#pragma once
#include "AbstractCommand.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/AbstractFileSystem.h"

class RemoveCommand: public AbstractCommand {
    AbstractFileSystem* system;
public:
    RemoveCommand(AbstractFileSystem* s);
    ~RemoveCommand() override = default;
    void displayInfo() override;
    int execute(std::string)override;
};