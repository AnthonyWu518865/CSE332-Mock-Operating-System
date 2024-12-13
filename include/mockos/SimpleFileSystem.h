# pragma once
#ifndef SIMPLEFILESYSTEM_H
#define SIMPLEFILESYSTEM_h
#include "AbstractFileSystem.h"
#include "AbstractFile.h"
#include <string>
#include <map>
#include <set>

class SimpleFileSystem : public AbstractFileSystem {
private:
    std::map<std::string, AbstractFile*> files;
    std::set <AbstractFile*> openFiles;
public:
    ~SimpleFileSystem() override;

    virtual int addFile(const std::string& filename, AbstractFile* file) override;
    virtual int createFile(const std::string& filename) override;
    virtual int deleteFile(const std::string& filename) override;
    virtual AbstractFile* openFile(const std::string& filename) override;
    virtual int closeFile(AbstractFile* file) override;
    std::set<std::string> getFileNames() override;

};




#endif
