# pragma once
#include "AbstractFile.h"
#include "AbstractFileVisitor.h"
using namespace std;
#include <string>
#include <iostream>
#include <vector>

class TextFile : public AbstractFile{
private:
    std::vector<char> content;
    std::string name;

public:
    TextFile(const string &fileName);
    string getName() const override;
    unsigned int getSize() const override;
    int write(const vector<char> & newContent) override;
    int append(vector<char> & extra) override;
    vector<char> read() override;
    void accept(AbstractFileVisitor* abstract_file_visitor) override;
    //Used to clone in copyCommand
    AbstractFile* clone(std::string) override;
};