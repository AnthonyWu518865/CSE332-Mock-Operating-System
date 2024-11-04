


# pragma once
#include "AbstractFile.h"
using namespace std;

class TextFile : public AbstractFile{
public:
    TextFile(string name) {
        this->name = name;
    }
    string getName() {
        return this->name;
    }
    unsigned int getSize() {
        return content.size();
    }
    int write(vector<char> & newContent) {
        content = newContent;
        return 0;
    }
    int append(vector<char> extra) {
        for (int i = 0; i < extra.size(); i++) {
            content.push_back(extra[i]);
        }
        return 0;
    }
    void read() {
        for (int i = 0; i < content.size(); i++) {
            cout << content[i] << " ";
        }
    }


private:
    vector<char> content;
    string name;
};
