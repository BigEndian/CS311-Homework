// Name: Eric Carr
// HW: HW3P2
// Compiler: g++ --pedantic-error -W{all,error} -o client slist.cpp llist.cpp client.cpp
// Client file

#include <iostream>
#include "slist.h"

using namespace std;


// Purpose: To test the searchable linked list class
int main(int argc, char *argv[]) {
   int position = 0;
   slist list;
   list.addFront(4);
   list.addRear(6);
   list.addRear(7);
   list.addRear(8);
   list.displayAll();

   position = list.search(6); // Search for a value
   if (position != 0) // Found the position, print and replace
   {
      cout << "6 found in the list at position " << position << endl;
      list.replace(0, position);
   }
   else
   {
      cout << "6 was not found in the list" << endl;
   }
   position = list.search(8); // Search for a value
   if (position != 0) // Found the position, print and replace
   {
      cout << "8 found in the list at position " << position << endl;
      list.replace(2, position);
   }
   else
   {
      cout << "8 was not found in the list" << endl;
   }
   list.displayAll();
   position = list.search(5); // Search for a value
   if (position != 0) // Found the position, print
   {
      cout << "5 found in the list at position " << position << endl;
   }
   else
   {
      cout << "5 was not found in the list" << endl;
   }

   return 0;
}
