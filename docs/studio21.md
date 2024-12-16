# Studio 21
1. Anthony, Jachin, Eunseo
2. It is important to declare a virtual destructor for the base class because it ensures that when an object from the derived class is deleted, the destructor of the derived class is called first, and then the base class destructor. This is a proper cleanup for classes that have inheritance, otherwise, problems like memory leak may happen.
3. The command prompt doesn't know any of the concrete class but it interacts with the abstract file class, this makes it flexible because at run time, it can be changed to interact with different file objects, and we have access to different functions and implementations.
4. By inputting 'q', the program successfully quit the command prompt with the expected exit code.
   We executed "help" and "touch" as well, which had the correct outputs.
   When just "touch" was inputted, an error message appeared because there was no file for it to act upon (expected). When a file was added after "touch", the correct file was created and added to the file system. 
   We did a bunch of commands of gibberish and as expected, we got errors in our output, because that command is not found/doesn't exist (expected).