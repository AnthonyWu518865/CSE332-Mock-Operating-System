# pragma once
#include <string>

class AbstractCommand {
public:
    virtual ~AbstractCommand() = default;
    virtual int execute(std::string);
    virtual void displayInfo();

};

