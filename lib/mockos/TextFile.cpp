#include <string>
#include <iostream>
#include <vector>
#include "mockos/TextFile.h"
#include "mockos/AbstractFileVisitor.h"
#include "mockos/TextFile.h"

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
    content.insert(content.end(), extra.begin(), extra.end());
    return 0;
}
vector<char> TextFile::read() {
    return content;
}

void TextFile::accept(AbstractFileVisitor* abstract_file_visitor) {
    abstract_file_visitor->visit_TextFile(this);
}

AbstractFile* TextFile::clone(string strFile) {
    //For file name
    strFile = strFile.append(".txt");
    AbstractFile* c_file = new TextFile(strFile);

    vector<char> fileContent;

    for (auto cont = this -> content.begin(); cont != this -> content.end(); ++cont) {
        fileContent.push_back(*cont);
    }
    c_file -> write(fileContent);
    return c_file;
}
