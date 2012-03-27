// Name: Eric Carr
// HW: HW3P2
// Compiler: g++ --pedantic-error -Werror -Wall -o client llist.cpp slist.cpp client.cpp
// Searchable Linked List Interface
#include "llist.h"

class slist : public llist
{
   public:
      // Purpose: to construct the list; it only needs to call the parent constructor
      // How to call: called implicitly, e.g. slist s;
      slist() : llist() {};
      // Purpose: to deallocate memory allocated by the list. llist.~llist is called implicitly
      // How to call: implicitly called whene an slist falls out of scope, or when using delete on a dynamically allocated slist (i.e. slist *s = new slit; delete s;)
      ~slist() { };
      

      // Purpose: To find an element in the linked list. key is the element to search for
      // How to call: slist s; s.addFront(0); s.addFront(3); s.search(2) // => 0
      // Returns the index of the key, where index (inexplicably) starts at 1
      int search(el_t key) const;
      // Purpose: replace the node at index I (where I is in range 1..ListLength) with the value of Elem
      // How to call: s.replace(10, 1); replaces the first node's value with 10, assuming there is a first node.
      // Returns: void
      void replace(el_t Elem, int I);
};
