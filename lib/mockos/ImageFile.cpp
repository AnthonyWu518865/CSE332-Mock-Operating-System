#include <string>
#include <iostream>
#include <vector>
#include "mockos/ImageFile.h"

using namespace std;

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
    size = data[data.size()-1] - '0';

    if (size < 1 || size * size != (data.size() - 1)) {
        contents.clear();
        size = 0;
        return -2;
    }

    for (int i = 0; i < data.size() - 1; ++i) {
        if (data[i] != 'X' && data[i] != ' ') {
            contents.clear();
            size = 0;
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
    return -1;
}

// int ImageFile::coordinatetoIndex(int x, int y) {
//     if(x < 0 || y < 0 || x > (size - '0') || y > (size - '0')) {
//         return -4;
//     }
//     return y * size + x;
// }

void ImageFile::read() {
    // for (auto c : contents) {
    //     std::cout << c << '\n';
    // }

    for(int height = 0; height < size; height++) {
        for(int width = 0; width < size; width++) {
            int currIndex = width * size + height;
            cout << contents[currIndex] << " ";
        }
        cout << endl;
    }
}


