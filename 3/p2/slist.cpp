// Name: Eric Carr
// HW: HW3P2
// Compiler: g++ --pedantic-error -W{error,all} -o client llist.cpp slist.cpp client.cpp
// Searchable Linked List Implementation
#include "slist.h"

int slist::search(el_t key) const
{
   Node *curr = Front;
   int curr_index = 1;
   while (curr)
   {
      if (curr->Elem == key)
      {
         return curr_index;
      }
      curr = curr->Next;
      curr_index++;
   }
   return 0;
}
void slist::replace(el_t Elem, int I)
{
   if (I < 1 || I > Count)
   {
      throw IndexOutOfRange();
   }
   else if (isEmpty())
   {
      throw Underflow();
   }
   else
   {
      int curr_index = 1;
      Node *curr = Front;
      while (curr_index != I)
      {
         curr = curr->Next;
         curr_index++;
      }
      curr->Elem = Elem;
   }
}
