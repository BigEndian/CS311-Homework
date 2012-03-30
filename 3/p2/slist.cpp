// Name: Eric Carr
// HW: HW3P2 (As well as Part 3 now)
// Compiler: g++ --pedantic-error -W{error,all} -o client llist.cpp slist.cpp client.cpp
// Searchable Linked List Implementation with a copy constructor and equality testing
#include "slist.h"

// non-member functions
bool operator==(const slist& left, const slist& right)
{
   if (left.Count != right.Count) // They're of inequal length, can't be the same
   {
      return false;
   }

   Node *lCurr = left.Front;
   Node *rCurr = right.Front;
   
   while (lCurr) // Could also be written as lCurr && rCurr, but shouldn't differ because they're of the same length, assuming I use Next correctly
   {
      if (lCurr->Elem != rCurr->Elem)
      {
         return false;
      }
      else
      {
         lCurr = lCurr->Next;
         rCurr = rCurr->Next;
      }
   }
   return true;
}

bool operator!=(const slist& left, const slist& right)
{
   return !(left == right);
}



// Member functions, operators, and constructors
slist::slist(const slist& other)
{
   Front = Rear = NULL;
   Count = 0;
   this->operator=(other);
}
slist& slist::operator =(const slist& other)
{
   if (&other != this) // No self duplicates
   {
      int foo = 0;
      while (!this->isEmpty())
      {
         this->deleteRear(foo);
      }
      Node *lCurr = NULL, *lPrior = NULL;
      Node *rCurr = other.Front;

      Front = NULL; // In case it's empty
      while (rCurr)
      {
         lCurr = new Node; 
         lCurr->Elem = rCurr->Elem;
         lCurr->Next = NULL;

         if (lPrior)
         {
            lPrior->Next = lCurr;
         }
         else // First node
         {
            Front = lCurr;
         }

         Count++;
         lPrior = lCurr;
         rCurr = rCurr->Next;
      }
      Rear = lCurr;

   }
   return *this;
}
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
