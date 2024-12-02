#include "mockos/SimpleFileSystem.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"


int main() {
    std::vector<char> validData = {'X', ' ', 'X', ' ', '2'};
    ImageFile imageFile("test.img");
    std::cout<<imageFile.getName() << endl;
    imageFile.write(validData);
    imageFile.read();
    std::cout<<imageFile.getSize()<< endl;

    SimpleFileSystem fs;

    AbstractFile* file1 = new TextFile("file1.txt");
    fs.addFile("file1.txt", file1);

    int deleteResult = fs.deleteFile("file1.txt");
    if (deleteResult == 0) {
        std::cout << "File deleted successfully!" << std::endl;
    } else {
        std::cout << "Failed to delete file. Error code: " << deleteResult << std::endl;
    }

    AbstractFile* file2 = new TextFile("file2.txt");
    fs.addFile("file2.txt", file2);
    fs.openFile("file2.txt");
    deleteResult = fs.deleteFile("file2.txt");
    if (deleteResult == -2) {
        std::cout << "File is open and cannot be deleted." << std::endl;
    }
    fs.closeFile(file2);
    deleteResult = fs.deleteFile("file2.txt");
    if (deleteResult == 0) {
        std::cout << "File deleted successfully!" << std::endl;
    }
    return 0;
}