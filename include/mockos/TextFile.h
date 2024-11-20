# pragma once
#include "AbstractFile.h"
using namespace std;
#include <string>
#include <iostream>
#include <vector>

class TextFile : public abstract_file{
private:
    std::vector<char> content;
    std::string name;

public:

    TextFile(const string &fileName);

    string getName() const override;
    unsigned int getSize() const override;
    int write(const vector<char> & newContent) override;
    int append(vector<char> & extra) override;
    void read() override;
};