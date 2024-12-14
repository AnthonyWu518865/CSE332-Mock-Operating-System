# pragma once
#include "AbstractCommand.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/AbstractFileSystem.h"

class CopyCommand: public AbstractCommand {
    AbstractFileSystem* system;
public:
    CopyCommand(AbstractFileSystem* s);
    ~CopyCommand() override = default;
    void displayInfo() override;
    int execute(std::string) override;

private:
    AbstractFileSystem* fileSys;
};
