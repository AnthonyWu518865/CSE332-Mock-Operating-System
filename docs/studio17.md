# Studio 17
1. Jachin, Eunseo, Anthony
2. We ran the test case of a vector {'X', 'X', 'X', ' ', '2'} and the imageFile named "test.img", and the output is 
   test.img
   X X
   X   
   4
    We ran another test case of {'X', ' ', 'X', ' ', '2'}.
output:
   test.img
   X   
   X   
   4
3. Programming a client to use an interface gives more flexibility, and it is easier to make extensions if new classes are introduced, as software should be open for extensions but not modifications. 
The biggest takeaway is that in this case, code is easier to update or extend. 
4. To create an object of a new concrete file type, we should add codes in the createFile method, checking if the type of the file is music file for example, and then create a new file with it. 