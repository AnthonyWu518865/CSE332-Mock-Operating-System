#pragma once
#include "AbstractFile.h"
#include "mockos/AbstractFileFactory.h"

class SimpleFileFactory : public AbstractFileFactory {
public :
    AbstractFile* createFile(const std::string& fileName) override;
};
