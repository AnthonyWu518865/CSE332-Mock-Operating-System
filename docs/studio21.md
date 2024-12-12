# Studio 21
1. Anthony, Jachin, Eunseo
2. It is important to declare a virtual destructor for the base class because it ensures that when an object from the derived class is deleted, the destructor of the derived class is called first, and then the base class destructor. This is a proper cleanup for classes that have inheritance, otherwise, problems like memory leak may happen
3.   