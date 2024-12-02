#pragma once
#include <iostream>
#include "AbstractFile.h"

using namespace std;

//createFile takes in a std::string argument
class AbstractFileFactory {
    public :
    virtual AbstractFile* createFile(const string& fileName = 0);

    //destructor
    virtual ~AbstractFileFactory() = default;
};

