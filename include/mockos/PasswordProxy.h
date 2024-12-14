# pragma once
#include "mockos/AbstractFile.h"
#include <string>

class PasswordProxy: public AbstractFile {
    AbstractFile* filePointer;
    std::string password;
    public:
    PasswordProxy(AbstractFile* currFile, std::string pass);
    ~PasswordProxy();
    std::vector<char> read() override;
    int write(const std::vector<char>& data) override;
    int append(std::vector<char>& data) override;
    unsigned int getSize() const override;
    std::string getName() const override;
    void accept(AbstractFileVisitor* file) override;
    AbstractFile* clone(std::string copy)  override;

protected:
    std::string passwordPrompt();
    bool check(std::string input);
};