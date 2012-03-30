// Name: Eric Carr
// HW: HW3P3
// Compiled with g++ -Wall -Werror --pedantic-error -o client_equality llist.cpp slist.cpp client_equality.cpp
// File: client_equality.cpp, used to test the equality operator for the slist class.

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "slist.h"

using namespace std;

void populate_list(slist& s, unsigned int max_length, unsigned int max_value);

// Purpose: to test slist's == operator by generating pseudo-random searchable linked lists and comparing them.
// Compile with g++ -Wall -Werror --pedantic-error llist.cpp slist.cpp client_equality.cpp
int main(int argc, char *argv[])
{
   srand(time(NULL));
   const unsigned int lists_count    = 8;
   const unsigned int max_list_size  = 10;
   const unsigned int max_list_value = 100;

   vector<slist> lists;
   lists.reserve(lists_count);

   // Fill all lists except the last two
   for (unsigned int i = 0; i < lists_count - 2; i++)
   {
      // Populate the list
      populate_list(lists[i], (((unsigned int)rand()) % max_list_size), max_list_value);

      // Print the generated list
      cout << "Generated List #" << (i+1) << ": ";
      lists[i].displayAll();
   }
   lists[lists_count-2] = lists[((unsigned int)rand() % (lists_count - 1))];
   cout << "Generated List #" << lists_count-1 << ": ";
   lists[lists_count-2].displayAll();

   // Leave the last as empty
   cout << "Generated List #" << lists_count << ": ";
   lists[lists_count-1].displayAll();


   // Compare the lists
   for (unsigned int i = 0; i < lists_count-1; i++)
   {
      for (unsigned int j = i + 1; j < lists_count; j++)
      {
         if (lists[i] == lists[j])
         {
            cout << "List #" << (i+1) << " is equal to List #" << (j+1) << endl;
         }
         else
         {
            cout << "List #" << (i+1) << " is not equal List #" << (j+1) << endl;
         }
      }
   }
   return 0;
}

// Purpose: To fill a list with pseudo random values
// Invocation: poulate_list(some_slist, 10, 500);
void populate_list(slist& s, unsigned int max_length, unsigned int max_value)
{
   for (unsigned int i = 0; i < max_length; i++)
   {
      int method = (i != 0) ? rand() % 3 : rand() % 2; // Don't use the third method when the list is empty as it will cause an overflow
      unsigned int value = ((unsigned int)rand()) % max_value;
      if (method == 0) // add at the end
      {
         s.addRear(value);
      }
      else if (method == 1) // the beginning
      {
         s.addFront(value);
      }
      else // add at a random index
      {
         // Generates a random, min of 1, maximum of current list length + 1
         int index = rand() % (i + 1);
         index += 1;
         s.addbeforeIth(index, value);
      }
   }
}
