# Studio 16
1. Jachin, Eunseo, Anthony
2. Declaring an interface is making a base class that only has the declaration of pure virtual function. By setting it equal to 0, all future derived classes are forced to use them.
3. Interface inheritance - TextFile only inherits the method signatures from AbstractFile.
4. Private variable - we don't want the contents to be manipulated.
5. We made a vector called newContent, where we pushed back 'a' and 'b'.
   For read and append, we were able to successfully read the characters and append the two in the output.
   For getSize and getName, the correct size of the file was outputted as well as the correct name, ending in .txt.
6. We accomplished by statically pointing to the base class and dynamically pointing to the TextFile. We also had to modify the operators, as we were using pointers to objects to call functions.


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