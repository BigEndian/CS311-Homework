//****************************************************************************
//  CS311 Linked Queue ADT - by Rika Notes-6A
//  Header File  llist.h

// ** Complete this file by adding good comments and write llist.C
//****************************************************************************

// Your name: Eric Carr
// HW: HW3P1
// Compiler: g++ --pedantic-error -Wall -Werror llist.cpp client.cpp -o client
// Linked List Interface

#ifndef NULL
#define NULL 0
#endif

typedef int el_t;

// list node is defined here as a struct Node
struct Node
{
  el_t Elem;   // elem is the element stored
  Node   *Next;  // next is the pointer to the next node
};

// I could have done class Node and add the data members under public
// but it will use too much space


class llist
{
 private:
  
  Node *Front;       // front  pointer 
  Node *Rear;        // rear   pointer
  int  Count;        // counter for the number of elements
  
 public:
  class Underflow {};
  class IndexOutOfRange {};

  //** need exception classes here
    
  llist ();            // constructor
  llist(const llist&); // Copy Constructor
  ~llist();            // destructor
  
  // Purpose: Return true if the list is empty, false otherwise
  // How to call: if (list.isEmpty()) { /* ... */ }
  bool isEmpty() const;
  
  // Purpose: Print all of the elements in the linked list, [ empty ] otherwise
  // How to call: list.displayAll();
  void displayAll() const;
    
  // Purpose: Add an element at the end of the linked list
  // How to call: list.addRear(30);
  void addRear(el_t NewNum);
    
  // Purpose: Remove an element from the front of the linked list, and store it in OldNum
  // How to call: el_t temp; list.deleteFront(temp); // do something with temp...
  void deleteFront(el_t& OldNum);
    
  // Purpose: Add an element to the front of the linked list
  // How to call: list.addFront(50);
  void addFront(el_t NewNum);
    
  // Purpose: Remove an element from the rear of the list, and store it in OldNum
  // How to call: el_t temp; list.deleteRear(temp); // do something with temp...
  void deleteRear(el_t& OldNum);
    
  // Purpose: Remove the element at index I and store its value in OldNum, where I starts at 1, NOT 0
  // How to call: el_t temp; list.deleteIth(1, temp); // do something with temp
  void deleteIth(int I, el_t& OldNum);
    
  // Insert an element before element I in the list. The inserted element's value will be newNum
  // How to call: list.addbeforeIth(1, 60);
  void addbeforeIth(int I, el_t newNum);

};
