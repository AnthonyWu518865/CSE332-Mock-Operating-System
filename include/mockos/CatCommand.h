#pragma once
#include "AbstractCommand.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/AbstractFileSystem.h"

class CatCommand: public AbstractCommand {
    AbstractFileSystem* system;
public:
    CatCommand(AbstractFileSystem* s);
    ~CatCommand() override = default;
    void displayInfo() override;
    int execute(std::string)override;
};