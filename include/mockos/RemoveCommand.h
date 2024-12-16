#pragma once
#include "AbstractCommand.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/AbstractFileSystem.h"

class RemoveCommand: public AbstractCommand {
    AbstractFileSystem* system;
public:
    RemoveCommand(AbstractFileSystem* s);
    virtual ~RemoveCommand(){}
    virtual void displayInfo() override;
    virtual int execute(std::string)override;
};