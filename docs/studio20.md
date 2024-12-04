# Studio 20
1. Jachin, Eunseo, Anthony 
2. The reason why we have to delete the pointer to the file is because if we don't explicitly add this function, it will only delete the PasswordProxy object and leaving the pointer to the AbstractFile on the heap, leading to a memory leak. 
3. We tested the read, write and accept functions and were able to get the desired output
   
Testcase for accept: We created a BasicDisplayVisitor object and passed in the address to the PasswordProxy object
Password prompt: eunseoanthony
   a

Process finished with exit code 0

Testcase for read: We created a TextFile object and pushed back a vector of one char. We used read and output the size of it, where we were able to recieve the expected result

Password prompt: eunseoanthony
1
Process finished with exit code 0

Testcase for write: We wrote in a vector of chars of size 2 to see if it worked and read after and got the size

/Users/jachinchoi/CLionProjects/oop-work-jachinanthonyeunseo16-21/cmake-build-debug/src/studio20
Password prompt: eunseoanthony
Password prompt: eunseoanthony
2
Process finished with exit code 0

We also tested for 