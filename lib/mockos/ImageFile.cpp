#include <string>
#include <iostream>
#include <vector>
#include "mockos/ImageFile.h"
#include "mockos/AbstractFileVisitor.h"

using namespace std;

ImageFile::ImageFile(const std::string& fileName)
    : filename(fileName), size(0) {}

unsigned int ImageFile::getSize() const {
    return contents.size();
}

unsigned int ImageFile::getDimensions() {
    return size;
}


string ImageFile::getName() const {
    return this->filename;
}

int ImageFile::write(const vector<char>& data) {
    if (data.empty()) {
        size = 0;
        contents.clear();
        cout<< "Error: empty contents" << endl;
        return -1;
    }
    size = data[data.size()-1] - '0';

    if (size < 1 || size * size != (data.size() - 1)) {
        contents.clear();
        size = 0;
        cout<< "Error: wrong size" << endl;
        return -2;
    }

    for (int i = 0; i < data.size() - 1; ++i) {
        if (data[i] != 'X' && data[i] != ' ') {
            contents.clear();
            size = 0;
            cout<< "Error: wrong contents" << endl;
            return -3;
        }
    }
    contents.clear();

    for(int height = 0; height < size; height++) {
        for(int width = 0; width < size; width++) {
            int currIndex = width * size + height;
            contents.push_back(data[currIndex]);
        }
    }
    return 0;
}

int ImageFile :: append(vector<char> & extra) {
    return -4;
}


vector<char> ImageFile::read() {

    // for(int height = 0; height < size; height++) {
    //     for(int width = 0; width < size; width++) {
    //         int currIndex = width * size + height;
    //         cout << contents[currIndex] << " ";
    //     }
    //     cout << endl;
    // }
    return contents;
}
void ImageFile::accept(AbstractFileVisitor* abstract_file_visitor) {
    abstract_file_visitor->visit_ImageFile(this);
}
