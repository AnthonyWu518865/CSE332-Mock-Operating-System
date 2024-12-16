#include "mockos/TextFile.h"
#include "mockos/AbstractFile.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main () {
    AbstractFile* input = new TextFile("example.txt");
    //TextFile input("input.txt");
    vector<char> newText;
    newText.push_back('a');
    newText.push_back('b');

    input -> write(newText);

    input -> read();

    vector<char> newText2;
    newText2.push_back('c');
    newText2.push_back('d');

    input -> append(newText2);

    input -> read();

    cout << "File name: " << input -> getName() << endl;
    cout << "Number of characters: " << input -> getSize() << endl;

    return 0;
}