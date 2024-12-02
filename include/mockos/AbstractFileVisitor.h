# pragma once
#include "mockos/ImageFile.h"
#include "mockos/TextFile.h"

class AbstractFileVisitor {
public:
    virtual void visit_TextFile(TextFile* text_file) = 0;
    virtual void visit_ImageFile(ImageFile* image_file) = 0;
};

