#pragma once
#include "AbstractCommand.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/AbstractFileSystem.h"

class CatCommand: public AbstractCommand {
    AbstractFileFactory* factory;
    AbstractFileSystem* system;
public:
    CatCommand(AbstractFileSystem* s,AbstractFileFactory* f);
    ~CatCommand() override = default;
    void displayInfo() override;
    int execute(std::string)override;
};