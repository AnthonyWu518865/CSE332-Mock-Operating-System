# pragma once
using namespace std;
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

    int coordinatetoIndex (int x, int y);
public:
    ImageFile(const std::string& filename);

    //unsigned int getSize(const vector<char> &data) const;

    unsigned int getSize() const override;
    std::string getName() const override;
    int write(const vector<char> & data) override;
    int append(vector<char> & extra) override;
    void read() override;

};

#endif