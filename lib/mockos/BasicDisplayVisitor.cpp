#include "mockos/BasicDisplayVisitor.h"

void BasicDisplayVisitor::visit_TextFile(TextFile* text_file) {
    for (const char& c : text_file->read()) {
        std::cout << c;
    }
    std::cout << std::endl;
}

void BasicDisplayVisitor::visit_ImageFile(ImageFile* image_file) {
    unsigned int currSize = image_file->getDimensions();
    for(int height = 0; height < currSize; height++) {
        for(int width = 0; width < currSize; width++) {
            int currIndex = width * currSize + height;
            cout << image_file->read()[currIndex] << " ";
        }
        cout << endl;
    }
}