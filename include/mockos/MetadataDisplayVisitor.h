#pragma once
#include "mockos/ImageFile.h"
#include "mockos/TextFile.h"
#include "mockos/AbstractFileVisitor.h"

class MetadataDisplayVisitor : public AbstractFileVisitor {
public:
    void visit_TextFile(TextFile* text_file) override;
    void visit_ImageFile(ImageFile* image_file) override;
};