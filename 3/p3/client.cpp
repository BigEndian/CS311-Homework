// Name: Eric Carr
// HW: HW2P3
// Compiled with g++ -Wall -Werror --pedantic-error -o client llist.cpp slist.cpp client.cpp
// Purpose: to test copying with the searchable linked list class
#include <iostream>
#include "slist.h"

using namespace std;

// Purpose: to test the copy constructor
// Invoked as: CopyTist(some_slist);
void CopyTest(slist to_mod)
{
   // Add 6 to the end of the linked list
   to_mod.addRear(6);

   // Print its contents
   cout << "CopyTest display: ";
   to_mod.displayAll();
}

int main(int argc, char *argv[])
{
   // Initialize the first list
   slist L1;
   cout << "Creating a list L1 with the elements of 1 2 3 4 5" << endl;
   L1.addRear(1);
   L1.addRear(2);
   L1.addRear(3);
   L1.addRear(4);
   L1.addRear(5);

   // Pass it to CopyTest in order to test the copy constructor
   cout << "Passing L1 to CopyTest" << endl;
   CopyTest(L1);

   // Print it out, after it being passed.
   cout << "Displaying L1 after passing it to CopyTest" << endl;
   cout << "L1: ";
   L1.displayAll();

   // Initialize the second list
   slist L2;
   cout << "Creating a list L2 with the elements of 4 3 2 1" << endl;
   L2.addRear(4);
   L2.addRear(3);
   L2.addRear(2);
   L2.addRear(1);
   cout << "Displaying L2: ";
   L2.displayAll();
   
   // Check copying again
   cout << "Setting L2 to L1" << endl;
   L2 = L1;
   cout << "Displaying L2: ";
   L2.displayAll();
  
   
   cout << "Removing the first element of L1" << endl;
   {
      // I don't want foo in my scope, it's gross
      int foo;
      L1.deleteFront(foo);
   }
   // Print L1 then L2
   cout << "Displaying L1: ";
   L1.displayAll();

   cout << "Displaying L2: ";
   L2.displayAll();

   return 0;
}

