#include "../include/mockos/ImageFile.h"
#include "../include/mockos/TextFile.h"
#include "../include/mockos/BasicDisplayVisitor.h"
#include <vector>
#include "mockos/MetadataDisplayVisitor.h"


int main() {
    ImageFile imageFile("test.img");
    vector<char> validData = {'X', ' ', 'X', ' ', '2'};
    imageFile.write(validData);
    // vector<char> currData = imageFile.read();
    // cout << currData.size() << endl;

    vector<char> testData;
    testData.push_back('a');
    TextFile textFile("text.img");
    textFile.append(testData);
    AbstractFile* file = &imageFile;
    file = &textFile;
    //
    // BasicDisplayVisitor display;
    // file->accept(&display);
    MetadataFileVisitor display;
    file->accept(&display);

    // display.visit_TextFile(&textFile);
    //imageFile.accept();


    return 0;

}
