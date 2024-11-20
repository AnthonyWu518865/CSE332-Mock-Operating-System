#include <string>
#include <iostream>
#include <vector>
#include "../include/mockos/TextFile.h"


TextFile:: TextFile(const std::string &fileName) : name(fileName) {}

string TextFile::getName() const {
    return this->name;
}
unsigned int TextFile::getSize() const {
    return content.size();
}
int TextFile::write(const vector<char> & newContent) {
    content = newContent;
    return 0;
}
int TextFile :: append(vector<char> & extra) {
    for (int i = 0; i < extra.size(); i++) {
        content.push_back(extra[i]);
    }
    return 0;
}
void TextFile::read() {
    for (const char& c : content) {
        std::cout << c;
    }
    std::cout << std::endl;
}
