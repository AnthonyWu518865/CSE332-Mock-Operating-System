#include "mockos/PasswordProxy.h"

#include <iostream>
#include <ostream>
#include <string>
#include <vector>

PasswordProxy::PasswordProxy(AbstractFile *currFile, std::string pass): filePointer(currFile), password(pass){};

PasswordProxy::~PasswordProxy() {
    delete filePointer;
}

std::string PasswordProxy::passwordPrompt() {
    std::cout << "Password prompt: ";
    std::string input;
    std::cin >> input;
    std::cin.ignore();
    return input;
}

bool PasswordProxy::check(std::string input) {
    if (input == password) {
        return true;
    }
    return false;
}
std::vector<char> PasswordProxy:: read() {
    std::string reader = passwordPrompt();
    if (check(reader)) {
        return filePointer->read();
    }
    return {};
}
int PasswordProxy::write(const std::vector<char>& data) {
    std::string reader = passwordPrompt();
    if (check(reader)) {
        return filePointer->write(data);
    }
    return -8;
}
int PasswordProxy:: append(std::vector<char>& data) {
    std::string reader = passwordPrompt();
    if (check(reader)) {
        return filePointer->append(data);
    }
    return -9;
}
unsigned int PasswordProxy::getSize() const{
    return filePointer->getSize();
};
std::string PasswordProxy::getName() const {
    return filePointer->getName();
};
void PasswordProxy:: accept(AbstractFileVisitor* file) {
    std::string reader = passwordPrompt();
    if (check(reader)) {
        return filePointer->accept(file);
    }
}

AbstractFile* PasswordProxy:: clone(std::string copy) {
    AbstractFile *cloneFile = filePointer -> clone(copy);
    return new PasswordProxy(cloneFile, this->password);
}