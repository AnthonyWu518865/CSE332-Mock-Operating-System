#include <iostream>

#include <mockos/SimpleFileFactory.h>
#include "mockos/SimpleFileSystem.h"
using namespace std;

int main() {
    SimpleFileSystem* simpFileSystem = new SimpleFileSystem();
    SimpleFileFactory* simpFileFactory = new SimpleFileFactory();

    AbstractFile * textFile1 = simpFileFactory -> createFile("file1.txt"); //generic test cases
    AbstractFile * imageFile1 = simpFileFactory -> createFile("image1.img");

    //adding the text files to the file system
    if (textFile1) {
        if (simpFileSystem -> addFile ("file1.txt", textFile1) != 0) {
            cout << "Text files can't be added to the system." << endl;
            delete textFile1;
        }
        else {
            vector <char> writeIn = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};
            if (textFile1 -> write(writeIn) == 0) {
                cout << "Text has been added and written: " << endl;
                //reads the text file
                textFile1 -> read();
            }
            else {
                cout<< "Failed to create and write text file." << endl;
            }
        }
    }

    //similar concept for image file
    if (imageFile1) {
        if (simpFileSystem -> addFile("image1.img", imageFile1) != 0) {
            cout << "Image files can't be added to the system." << endl;
            delete imageFile1;
        }
        else {
            vector <char> imageIn = {'X', 'X', 'X', 'X', ' ', 'O', 'O', 'O', 'O'};
            int writeSuccess = imageFile1 -> write(imageIn);
            if (writeSuccess == 0) {
                cout << "Image has been added and written successfully: " << endl;
                //reads the image file
                imageFile1 -> read();
            }
            else if (writeSuccess == -10) {
                //I need to assign an error code, but I lowkey forgot how
                cout << "There is an error in the size of the image." << endl;
                //Are there any other errors you can think of?
                }
            else {
                cout << "Failed to create and write image file. Could be a result of the input." << endl;
            }
        }
    }
    return 0;
}
