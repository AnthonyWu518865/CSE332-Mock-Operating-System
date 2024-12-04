#include "../include/mockos/PasswordProxy.h"
#include <iostream>
#include "../include/mockos/TextFile.h"
#include "../include/mockos/BasicDisplayVisitor.h"
int main() {
    AbstractFile* a = new TextFile("example.txt");
    vector<char> hello;
    hello.push_back('a');
    a->write(hello);
    PasswordProxy curr(a, "eunseoanthony");
    // BasicDisplayVisitor thing;
    // curr.accept(&thing);
    vector<char> writeTest;
    writeTest.push_back('p');
    writeTest.push_back('a');
    int tes = curr.write(writeTest);
    if (tes == -8) {
        return 6;
    }
    vector<char> something = curr.read();
    cout << something.size();
}