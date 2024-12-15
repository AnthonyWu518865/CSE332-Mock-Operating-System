# Lab 5
Lab 5: Eun Seo Lee, Anthony Wu, Jachin Choi

Anthony and Jachin began working on the lab (steps 1-5). Eunseo worked on steps 6-8.
There were several issues we ran into while doing the work, so each time we would discuss it in our group chat and commit and push our work, giving everyone a chance to look at the code and attempt to fix the issues.
By the end of the lab, we had all worked on each of the implementations in our own way, all while communicating with each other the errors we were encountering.

Dynamically allocated objects:
File system and file factory are both dynamically allocated in the file factory. The creation and storage of files was also dynamically allocated to MacroCommand (seen a lot in the main).
Here, we see the rename function as well as the addition macro function derived from the others.
Dynamically allocated objects were determined to be deallocated when the delete command was called. In doing so, we deleted the previous files and memory that had been created via the previous code.
We ensured this deletion was done before the final return statement, to fully deallocate objects without taking up more memory (from the return statement).

Errors:

Test cases: