#include "../include/mockos/TextFile.h"
#include <iostream>
#include <string>


using namespace std;
int main () {
    abstract_file* input = new TextFile("example.txt");
    //TextFile input("input.txt");
    vector<char> newText;
    newText.push_back('a');
    newText.push_back('b');
    input->write(newText);
    // cout << input.getName() << endl;
    // cout << input.getSize() << endl;
    // input.append(newText);
    input->read();
    return 0;
}