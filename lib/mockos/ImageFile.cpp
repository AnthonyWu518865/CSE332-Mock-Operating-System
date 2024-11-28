#include <string>
#include <iostream>
#include <vector>
#include "../include/mockos/ImageFile.h"

ImageFile::ImageFile(const std::string& fileName)
    : filename(fileName), size(0) {}

unsigned int ImageFile::getSize() const {
    return contents.size();
}

string ImageFile::getName() const {
    return this->filename;
}

int ImageFile::write(const vector<char>& data) {
    if (data.empty()) {
        size = 0;
        contents.clear();
        return -1;
    }
    char sizeChar = data.back();
    int n = sizeChar - '0';

    if (data.size() < 1 || n * n != static_cast<int>(data.size() - 1)) {
        contents.clear();
        size = 0;
        return -2;
    }

    for (size_t i = 0; i < data.size() - 1; ++i) {
        if (data[i] != 'X' && data[i] != ' ') {
            contents.clear();
            size = 0;
            return -3;
        }
    }
    contents.clear();
    contents.insert(contents.begin(), data.begin(), data.end() - 1);
    size = sizeChar-'0';
    return 0;
}

int ImageFile :: append(vector<char> & extra) {
    return -1;
}

int ImageFile::coordinatetoIndex(int x, int y) {
    if(x < 0 || y < 0 || x > (size - '0') || y > (size - '0')) {
        return -4;
    }
    return y * size - '0' + x;
}

void ImageFile::read() {
    for (auto c : contents) {
        std::cout << c << ' ';
    }

    // int n = size - '0';
    // for(int y = 0; y < n; y++) {
    //     for(int x = 0; x < n; x++) {
    //         std::cout << contents[coordinatetoIndex(x,y)];
    //     }
    //     std::cout << std::endl;
    // }
}


