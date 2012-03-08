// Name: Eric Carr
// HW: HW3P1
// Compiler: g++ --pedantic-error -Wall -Werror llist.cpp client.cpp -o client
// Linked List Implementation

#include "llist.h"
#include <iostream>
using namespace std;

// Purpose: Instantiate the linked list
llist::llist()
{
   this->Front = NULL;
   this->Rear = NULL;
   this->Count = 0;
}
// Purpose: Destroy the Linked List by deallocated its dynamically allocated memory
// Algorithm: Start from the front, store its value in a temp, move forward one, then free the memory pointed to by temp
llist::~llist()
{
   Node *temp;
   while (this->Front) // While we still have an element
   {
      temp = this->Front; // Store the current front in temp
      this->Front = this->Front->Next; // Move forward once
      delete temp; // Delete the prior front
   }
}
// Purpose: Create a new linked list from another
// Works by copying the nodes from the other list and using Node *prior to set the Next pointer of each new node created
llist::llist(const llist& list)
{
   Front = Rear = NULL;
   Count = 0;
   Node *listCurrent = list.Front;
   Node *current, *prior = NULL;

   while (listCurrent)
   {
      if (prior)
      {
         prior->Next = current;
      }
      current = new Node;
      current->Elem = listCurrent->Elem;
      current->Next = NULL;
      Count++;

      listCurrent = listCurrent->Next;
      prior = current;

      if (Count == 1) // Adding the first node
      {
         Front = current;
      }
      else if (Count == list.Count) // Adding the last Node
      {
         Rear = current;
      }
   }
}
// Purpose: Check if the linked list is empty
bool llist::isEmpty() const
{
   return (Count == 0);
}
// Purpose: Display all of the elements in the list
// Algorithm: Start at front, print, move to the next element, repeat
void llist::displayAll() const
{
   if (Front == NULL) // If the list is empty
   {
      cout << "[ empty ]" << endl;
      return;
   }
   // Start at front
   Node *current = Front;
   // When current becomes NULL it will evaluate to false
   while (current)
   {
      // Print, then move to next
      cout << current->Elem << " ";
      current = current->Next;
   }
   cout << endl;
}
// Purpose: Add an element at the rear of the linked list 
// Parameters: NewNum will be stored in the new node's Elem field
// Algorithm: Create a new node, make Rear->Next equal to the new node, set rear to the new node.
void llist::addRear(el_t NewNum)
{
   // Create the new node
   Node *addition = new Node;
   addition->Elem = NewNum;
   addition->Next = NULL;
   // If the list is empty..
   if (Count == 0)
   {
      // Set Front AND Rear to the address of the newly created node
      Front = Rear = addition;
   }
   else
   {
      // Otherwise, just set Rear's next to the new node, and set Rear to addition, as it becomes the new Rear
      Rear->Next = addition;
      Rear = addition;
   }
   Count++;
}
// Purpose: Delete the front element
// Parameters: OldNum will receive the value of the deleted element
void llist::deleteFront(el_t& OldNum)
{
   if (Count == 0) // Empty linked list
   {
      throw Underflow();
   }
   // Store the old Front and move one forward
   Node *oldFront = Front;
   Front = Front->Next;

   if (Count == 1) // If the list length is 1, then set Rear to Front, which is NULL, so the list is empty
   {
      Rear = Front; // aka NULL
   }

   Count--;
   // Store the oldFront's value in OldNum, then delete the old front
   OldNum = oldFront->Elem;
   delete oldFront;
}
// Purpose: Add an element at the front of the linked list
// Parameters: NewNum's value will be stored in the new Front node
void llist::addFront(el_t NewNum)
{
   // Create the New Node
   Node *newNode = new Node;
   newNode->Next = Front;
   newNode->Elem = NewNum;
   if (Count == 1) // Already has one element
   {
      Rear = Front;
   }
   else if (Count == 0) // Empty
   {
      Rear = newNode;
   }
   Front = newNode;
   Count++;
}
// Purpose: Delete an element from the end of the linked list
// Parameters: OldNum will receive the value from the old Rear
void llist::deleteRear(el_t& OldNum)
{
   if (Count == 0) // Throw underflow if the list is empty
   {
      throw Underflow();
   }
   else if (Count == 1) // Aka Front == Rear
   {
      OldNum = Rear->Elem;
      Front = Rear = NULL;
      Count--;
   }
   else
   {
      // Iterate to the node just prior to Rear
      Node *current = Front;
      while (current && current->Next != Rear) // Iterate to the Node prior to Rear
      {
         current = current->Next;
      }
      current->Next = NULL;
      OldNum = Rear->Elem;
      delete Rear;
      Rear = current;
      Count--;
   }
}
// Purpose: Delete an element at index I where I starts at 1
// Parameters: I used to determine the index, OldNum will recieve the value of the element at I
void llist::deleteIth(int I, el_t& OldNum)
{
   if (I < 1 || I > Count)
   {
      throw IndexOutOfRange();
   }
   else if (isEmpty())
   {
      throw Underflow();
   }
   else if (I == 1)
   {
      deleteFront(OldNum);
   }
   else if (I == Count)
   {
      deleteRear(OldNum);
   }
   else
   {
      // Iterate to the node prior to the index, delete the node at the index and bridge the gap
      Node *antecedent = Front;
      int counter = 1;
      while (antecedent && ++counter != I)
      {
         antecedent = antecedent->Next;
      }
      Node *ith = antecedent->Next;
      OldNum = ith->Elem;
      antecedent->Next = ith->Next;
      delete ith;
      Count--;
   }
}
// Purpose: Insert a new node prior to the element at index I, where I starts at 1
// Parameters: I to determine the index, newNum will be the value used to instantiate the new Node
void llist::addbeforeIth(int I, el_t newNum)
{
   if (I < 1 || I > Count + 1)
   {
      throw IndexOutOfRange();
   }
   else if (isEmpty())
   {
      throw Underflow();
   }
   else if (I == 1)
   {
      addFront(newNum);
   }
   else if (I == Count+1) // Insert before the element after Rear, at the end
   {
      addRear(newNum);
   }
   else
   {
      // Iterate to the node prior to the index, set that node's next to the new node, and set the new node's next to the antecedent's next, for the purpose of proper insertion
      Node *antecedent = Front;
      int counter = 1;
      while (antecedent && ++counter != I)
      {
         antecedent = antecedent->Next;
      }
      Node *newNode = new Node;
      newNode->Elem = newNum;
      newNode->Next = antecedent->Next;
      antecedent->Next = newNode;
      Count++;
   }
}
