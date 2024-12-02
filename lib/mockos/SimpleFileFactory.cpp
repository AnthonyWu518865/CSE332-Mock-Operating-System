#include "mockos/SimpleFileFactory.h"
#include "mockos/ImageFile.h"
#include "mockos/TextFile.h"

AbstractFile* SimpleFileFactory::createFile(const std::string& fileName) {
    size_t dotPos = fileName.find_last_of('.');
    if (dotPos == std::string::npos) {
        return nullptr;
    }
    std::string extension = fileName.substr(dotPos + 1);

    AbstractFile* newFile = nullptr;
    if (extension == "txt") {
        newFile = new TextFile(fileName);
    } else if (extension == "img") {
        newFile = new ImageFile(fileName);
    }else {
        return nullptr;
    }
    return newFile;
}
