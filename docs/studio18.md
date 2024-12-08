# Studio 18
1. Eun Seo, Jachin, Anthony
2. The factory method allows for each item that is created to be put into individual subclasses. A concrete method is called directly upon objects, and differs from factory methods because factory methods allow for change.
   Factory methods allow for flexibility, but can also as a result, result in increased complexity and difficulty in tracking and following code due to the possibility of adding duplicate code.
3. Abstract factory patterns allow for the ability to allocate new file types without changing the basis of the code, which allows for easier implementation and transfer. In doing so, the code remains cleaner, as new object creation doesn't require an entirely new set of code. However,
   similar to the previous question, it adds to the code's complexity, once again making it difficult to follow when attempting to edit or understand it. To introduce a new file type, the code for the factories must be updated to implement the new file - but only if the files types are different.
   If they are the same, on factory's code can do the work for the other.
4. I ran the text: "Hello world", which printed correctly with an exit code of 0. It also displayed the message that it has been added and written.
5. Changes to the SimpleFileSystem were reflected - the specific type of file in which it needs to handle is not considered, and uses the general file code to manage the more complex ones.
   