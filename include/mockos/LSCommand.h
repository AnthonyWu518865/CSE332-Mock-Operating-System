#pragma once
#include "AbstractCommand.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/AbstractFileSystem.h"

class LSCommand: public AbstractCommand {
    AbstractFileFactory* factory;
    AbstractFileSystem* system;
public:
    LSCommand(AbstractFileSystem* s,AbstractFileFactory* f);
    ~LSCommand() override = default;
    void displayInfo() override;
    int execute(std::string)override;
};