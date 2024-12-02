#include "mockos/SimpleFileSystem.h"
#include "mockos/ImageFile.h"
#include "mockos/TextFile.h"


SimpleFileSystem::~SimpleFileSystem() {
    for (auto& file : files) {
        delete file.second;
    }
}


int SimpleFileSystem::addFile(const std::string& filename, AbstractFile* file) {
    if (files.find(filename) != files.end() || file == nullptr) {
        return -1;
    }
    files.insert({filename, file});
    return 0;
}

int SimpleFileSystem::createFile(const std::string& filename) {
    if (files.find(filename) != files.end()) {
        cout << "File " << filename << " already exists." << endl;
        return -1;
    }
    size_t dotPos = filename.find_last_of('.');
    if (dotPos == std::string::npos) {
        cout << "File " << filename << " does not exist." << endl;
        return -2;
    }
    std::string extension = filename.substr(dotPos + 1);

    AbstractFile* newFile = nullptr;
    if (extension == "txt") {
        newFile = new TextFile(filename);
    } else if (extension == "img") {
        newFile = new ImageFile(filename);
    }else {
        cout << "File type" << filename << " is not compatible." << endl;
        return -3;
    }
    files.insert({filename, newFile});
    return 0;
}

AbstractFile* SimpleFileSystem::openFile(const std::string& filename) {
    auto it = files.find(filename);
    if (it == files.end()) {
        return nullptr;
    }
    if (openFiles.find(it->second) != openFiles.end()) {
        return nullptr;
    }
    openFiles.insert(it->second);
    return it->second;
}
int SimpleFileSystem::closeFile(AbstractFile* file) {
    auto it = openFiles.find(file);
    if (it == openFiles.end()) {
        cout << "File cannot be found." << endl;
        return -1;
    }
    openFiles.erase(it);
    return 0;
}


int SimpleFileSystem::deleteFile(const std::string& filename) {
    auto it  = files.find(filename);
    if (it == files.end()) {
        cout << "File cannot be found." << endl;
        return -1;
    }
    if(openFiles.find(it->second) != openFiles.end()) {
        cout << "File " << filename << " is open." << endl;
        return -2;
    }

    delete it->second;
    files.erase(it);
    return 0;
}