# Lab 5
Lab 5: Eun Seo Lee, Anthony Wu, Jachin Choi

Anthony and Jachin began working on the lab (steps 1-5). Eunseo worked on steps 6-8. We all collectively worked on the rest of the steps and debugged everything together. 
There were several issues we ran into while doing the work, so each time we would discuss it in our group chat and commit and push our work, giving everyone a chance to look at the code and attempt to fix the issues.
By the end of the lab, we had all worked on each of the implementations in our own way, all while communicating with each other the errors we were encountering.


Dynamically allocated objects:
File system and file factory are both dynamically allocated in the file factory. The creation and storage of files was also dynamically allocated to MacroCommand (seen a lot in the main).
Here, we see the rename function as well as the addition macro function derived from the others.
Dynamically allocated objects were determined to be deallocated when the delete command was called. In doing so, we deleted the previous files and memory that had been created via the previous code.
We ensured this deletion was done before the final return statement, to fully deallocate objects without taking up more memory (from the return statement).

Errors:
Throughout the lab, we ran into a lot of errors. To name a few, we had issues with some formatting with the metadata display visitor, as the test cases expected it in a certain format, and we did not have that. Also, a big 
issue that we faced was figuring out the macrocommand parsing for the one we were adding which was touchls. We were having errors with parsing the correct thing into the vector<std::string> for it to run properly. We fixed this by 
running through the debugger and seeing what was wrong, which allowed us to change our code accordingly. Another issue we making the password proxy files work with the touch command. At first, we weren't sure how to parse the input, 
but after some thought, we were able to think about how to parse it properly for it to work. 

Test cases:

We ran testcases thoroughly for all files.

LS Command: For the LS command, we tried it with just ls and ls -m. With ls we can expect the names of the file names. 
We expected two of them in a row and evenly spaced, and we were able to get that output. With the ls -m, we expected the name, size, 
and type of the file. We were able to get this output with 1 file for each row. 

Remove Command: For the remove command, we just have to remove the file from the file system. We tested this by adding a file to the simple fiel system 
using the touch command, and then used the remove command after. We then used ls to see if it was able to work and were able to get the expected output. 

Touch Command: For the touch command, we were expected to use touch or touch -p. We tested this by making new files and password protected files. We were
expecting these files to be created and added to the file system. For the password Protected ones, it asked us for a password, which was expected. 
We also checked right after using the ls command. 

Cat Command: The cat command's role was to append or overwrite things to a file based on if there was a "" or -a after cat.
We expected :wq with -a to have appeneded to it, while :wq without the a to overwrite. We tested this by using the 
ls -m command to check whether it worked. We also checked the :q command, as this would just do nothign to the file. We also 
used ds to look at it. 

Display Command: The display command's role is to just display the file as formatted or unformmated. We just simply used 
the command to see if it worked, as the command showed a picture of the output based on the type of the file, and we were able to 
get the expected output (this is only for image file, as text file makes it the same for both). 

CopyCommand: The copy command's role is to make a copy of the file and adds it into the file system. We simply 
created a file using the touch command. We then appended numbers to the file and then used the cp command to copy it into
the file system. After we used the ls -m and ds to make sure that it retained the same contents as the file it copied. 
We were able to get the expected output. 

Rename Command: This command's rolse uses the macro command. Essentially, it is the combination of the copy command and remove command. 
This uses the composite pattern and we were ablet o test this by creating a file using touch. We then used the renmae and 
used ls -m, and we were only able to see the copied file and not the deleted file. We were ablet o get our expected output 
and used the prototype pattern.


Touchls command: The touchls command is used to make a file and then use ls to make sure the file is added correctly for sure. 
We also added functionality for this to have -p for the touch and -m for the ls to have full functionality. We simply just used it a coupel 
times and it kind of tested itself as ls shows the new files that are added by touch. We had to create a new way of parsing to account 
for this as there might have been -p or -m. touchls <file-name> <-p> <-m> - you dont always need -p or -m as we use string stream 








