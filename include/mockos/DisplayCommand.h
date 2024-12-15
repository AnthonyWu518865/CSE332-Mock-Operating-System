# pragma once
#include "AbstractCommand.h"
#include "BasicDisplayVisitor.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/AbstractFileSystem.h"

class DisplayCommand: public AbstractCommand {

public:
    DisplayCommand(AbstractFileSystem* s);
    void displayInfo() override;
    int execute(std::string) override;

private:
    AbstractFileSystem* system;
    BasicDisplayVisitor visitorDisplay;
};
