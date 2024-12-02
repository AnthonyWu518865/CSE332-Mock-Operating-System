#pragma once

#include <mockos/AbstractFileFactory.h>

class SimpleFileFactory : public AbstractFileFactory {
public :
    AbstractFile* createFile(const std::string& fileName);
};
