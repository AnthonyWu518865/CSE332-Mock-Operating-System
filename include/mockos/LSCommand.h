#pragma once
#include "AbstractCommand.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/AbstractFileSystem.h"

class LSCommand: public AbstractCommand {
    AbstractFileSystem* system;
public:
    LSCommand(AbstractFileSystem* s);
    ~LSCommand() override = default;
    void displayInfo() override;
    int execute(std::string)override;
};