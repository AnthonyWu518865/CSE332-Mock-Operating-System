# Studio 16
# add detil later ****
1. Jachin, Eunseo, Anthony
2. Declaring an interface is making a base class that only has the declaration of pure virtual function. 
3. Interface inheritance
4. Private Variable
5. We made a vector called newContent, where we pushed back 'a' and 'b'. We tested all the functions using the vector for the ones that needed it and then the oens without lke getName, getSize, and read, we ran without it. We got all the expected output. 
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