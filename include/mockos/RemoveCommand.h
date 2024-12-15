#pragma once
#include "AbstractCommand.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/AbstractFileSystem.h"

class RemoveCommand: public AbstractCommand {
    AbstractFileSystem* system;
public:
    RemoveCommand(AbstractFileSystem* s) : system(s) {}
    virtual ~RemoveCommand(){}
    virtual void displayInfo() override {
        cout << "rm<filename>: remove command, removes a file from the file system" << endl;
    }
    virtual int execute(std::string)override;
};