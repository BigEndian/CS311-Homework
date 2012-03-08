// Name: Eric Carr
// HW: HW3P1
// Compiler: g++ --pedantic-error -Wall -Werror llist.cpp client.cpp -o client
// Client file

#include "llist.h"
#include <iostream>
using namespace std;

void checkIsEmpty(const llist& list);

// Purpose: to test the linked list class
// Compiled with g++ --pedantic-error -Wall -Werror llist.cpp client.cpp -o client
int main(int argc, char *argv[])
{
   llist list;
   int temp; // Used to store the values from deleteFront, deleteIth, etc.
   int case_num;
   // Prompt the user for the case to test
   cout << "Enter which case to use: ";
   cin >> case_num;
   switch (case_num)
   {
      case 1:
         checkIsEmpty(list);
         list.displayAll();
         list.addRear(1);
         list.addRear(2);
         list.addRear(3);
         list.displayAll();
         // Remove and print the removed value
         list.deleteFront(temp);
         cout << "Element (" << temp << ") removed from the front of the list" << endl;
         // Remove and print the removed value
         list.deleteFront(temp);
         cout << "Element (" << temp << ") removed from the front of the list" << endl;
         list.displayAll();
         checkIsEmpty(list);
         // Remove and print the removed value
         list.deleteFront(temp);
         cout << "Element (" << temp << ") removed from the front of the list" << endl;
         checkIsEmpty(list);
         break;
      case 2:
         list.addFront(5);
         list.addFront(4);
         list.deleteFront(temp);
         list.addRear(6);
         list.addRear(8);
         list.addRear(9);
         list.displayAll();
         list.addbeforeIth(1, 4);
         list.addbeforeIth(4, 7);
         list.addbeforeIth(7, 10);
         try
         {
            list.addbeforeIth(9, 12);
         }
         catch (llist::IndexOutOfRange)
         {
            cerr << "Could not insert element 12 before the 9th element: Index out of Range" << endl;
         }
         try
         {
            list.addbeforeIth(0, 0);
         }
         catch (llist::IndexOutOfRange)
         {
            cerr << "Could not insert element 0 before the 0th element: Index out of Range" << endl;
         }
         list.displayAll();
         list.deleteIth(1, temp);
         // Remove and print the removed value
         cout << "Element (" << temp << ") at index 1 removed" << endl;
         list.deleteIth(6, temp);
         // Remove and print the removed value
         cout << "Element (" << temp << ") at index 6 removed" << endl;
         list.deleteIth(3, temp);
         // Remove and print the removed value
         cout << "Element (" << temp << ") at index 3 removed" << endl;
         try
         {
            list.deleteIth(5, temp);
         }
         catch (llist::IndexOutOfRange)
         {
            cerr << "Could not remove element at index 5: Index out of Range" << endl;
         }
         try
         {
            list.deleteIth(0, temp);
         }
         catch (llist::IndexOutOfRange)
         {
            cerr << "Could not remove element at index 0: Index out of Range" << endl;
         }
         list.displayAll();
         while (!list.isEmpty())
         {
            // Remove and print the removed value
            list.deleteRear(temp);
            cout << "Removed element (" << temp << ") from the rear of the list" << endl;
         }
         list.displayAll();
         break;
      case 3:
         try
         {
            list.addbeforeIth(0, 0 | 0x1 | 0x4 | 0x16 | 0x64); /* Might as well have some fun with this project */
         }
         catch (llist::IndexOutOfRange)
         {
            cerr << "Could not add an element before index 0: Index out of Range" << endl;
         }
         try
         {
            list.deleteFront(temp);
         }
         catch (llist::Underflow)
         {
            cerr << "Could not delete the first element: Underflow" << endl;
         }
         break;
      case 4:
         try
         {
            list.addbeforeIth(0, 0 | 0x2 | 0x8 | 0x32 | 0x128); /* Might as well have some fun with this project */
         }
         catch (llist::IndexOutOfRange)
         {
            cerr << "Could not add an element before index 0: Index out of Range" << endl;
         }
         try
         {
            list.deleteRear(temp);
         }
         catch (llist::Underflow)
         {
            cerr << "Could not delete the last element: Underflow" << endl;
         }
         break;
      default:
         cerr << "Invalid case number: " << case_num << endl;
         return 1;
   }
   return 0;
}
void checkIsEmpty(const llist& list)
{
   if (list.isEmpty())
   {
      cout << "List is empty" << endl;
   }
   else
   {
      cout << "List is not empty" << endl;
   }
}
