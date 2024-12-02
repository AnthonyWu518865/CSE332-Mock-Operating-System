#include <string>
#include <iostream>
#include <vector>
#include "mockos/TextFile.h"
#include "mockos/AbstractFileVisitor.h"

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
vector<char> TextFile::read() {
    // for (const char& c : content) {
    //     std::cout << c;
    // }
    // std::cout << std::endl;
    return content;
}

void TextFile::accept(AbstractFileVisitor* abstract_file_visitor) {
    abstract_file_visitor->visit_TextFile(this);
}
