
#pragma once
#include <vector>
using namespace std;

class AbstractFile {
public:
    virtual ~AbstractFile() = 0;
    virtual void read() = 0;
    virtual int write(vector<char> & data) = 0;
    virtual int append(vector<char> data) = 0;
    virtual unsigned int getSize() = 0;
    virtual string getName() = 0;
};
