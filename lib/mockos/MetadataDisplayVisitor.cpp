#include "mockos/MetadataDisplayVisitor.h"

void MetadataDisplayVisitor:: visit_TextFile(TextFile* text_file) {
    string fileName = text_file->getName();
    unsigned int size = text_file->getSize();
    string type = "text";
    cout<< fileName << "   " <<  type  << "     " << size << endl;
}

void MetadataDisplayVisitor:: visit_ImageFile(ImageFile* image_file) {
    string fileName = image_file->getName();
    unsigned int size = image_file->getSize();
    string type = "image";
    cout <<  fileName << "  " <<  type  << "        " << size << endl;
}