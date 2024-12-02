# pragma once
#ifndef IMAGEFILE_H
#define IMAGEFILE_h
#include <vector>
#include <string>
#include "AbstractFile.h"

class ImageFile : public AbstractFile{
private:
    std:: string filename;
    std::vector <char> contents ;
    char size;

public:
    ImageFile(const std::string& filename);

    //unsigned int getSize(const vector<char> &data) const;
    unsigned int getSize() const override;
    unsigned int getDimensions();
    std::string getName() const override;
    int write(const std::vector<char> & data) override;
    int append(std::vector<char> & extra) override;
    std::vector<char> read() override;
    void accept(AbstractFileVisitor* abstract_file_visitor) override;
};

#endif