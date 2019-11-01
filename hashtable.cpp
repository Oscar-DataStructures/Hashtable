/*
Austin Burgess, Oscar Martinez
CS 271
Dr. Lall
Project 6
*/


#include <sstream>
#include <string>
#include <iostream>
#include <typeinfo>


using namespace std;



// ================================= Constructor ===============================
template <class KeyType>
hashtable<KeyType>::hashtable(int numSlots)
//Preconditions:  N/A
//Postcondition:  dynamically allocated table with size numSlots where each list in array is null
{
  slots = numSlots;
  table = new List<KeyType>[numSlots];    //dynamically allocated table
  for(int i = 0; i < table->size; i++)    //iterates throughout the table
  {
    table[i].head = NULL;   //sets each list's head to NULL
  }
}


// ============================== Copy Constructor ==============================
template <class KeyType>
hashtable<KeyType>::hashtable(const hashtable<KeyType>& h)
//Preconditions:  Can only be used for construction
//Postcondition:  Current hashtable will be a copy of h hashtable
{
  slots = h.slots;
  table = new List<KeyType>[slots];   //dynamically allocated table
  table->size = h.table->size;
  for(int i = 0; i < table->size; i++)    //iterates throughout the table
  {
    table[i] = List<KeyType>::deepCopy(h.table[i]);   //inherits Lists deep copy method and ultizes it
  }
}


// ================================= DeConstructor =============================
template <class KeyType>
hashtable<KeyType>::~hashtable()
//Preconditions:  Hashtable must exist to be deallocated
//Postcondition:  Deallocates memory and destroys existing bst
{
  for(int i = 0; i < table->size; i++)
  {
    List<KeyType>::~List();   //inherits Lists DeConstructor and ultizes it
  }
}


// ================================= Get Method ================================
template <class KeyType>
KeyType* hashtable<KeyType>::get(const KeyType& k) const  //TODO [ASK]: why const and what does that do
//Preconditions:  K must be a pair that exists in hashtable
//Postcondition:  Throws a key error if not found and returns pointer if found
{
  int hSlots = k.hash(slots);   //can only call const functions on k bc k is const
  int result = table[hSlots].index(k);    //index method returns -1 if not found and index if found
  if (result == -1)   //not found
  {
    throw KeyError();
  }

  else    //found so return pointer
  {
    KeyType* kFound = &k;
    return kFound;
  }
}


// ================================ Insert Method ==============================
template <class KeyType>
void hashtable<KeyType>::insert(KeyType* k) //TODO [CHECK]: might need to change list insert to insert node at head of list
//Preconditions:  N/A
//Postcondition:  k will be inserted into the hashtable at the apriopiate slot
{
  int hSlots = k->hash(slots);
  Node<KeyType>* insNode = new Node<KeyType>(k);
  Node<KeyType>* current = table[hSlots].head;
  if (table[hSlots].head == NULL)
  {
    table[hSlots].head = insNode;
    return;
  }
  insNode->next = table[hSlots].head;
  table[hSlots].head = insNode;
}


// ================================ Remove Method ==============================
template <class KeyType>
void hashtable<KeyType>::remove(const KeyType& k)   //TODO[ASK]: how const changes this
//Preconditions:  k must be in the hashtable
//Postcondition:  k will be removed from the hashtable if it exists, if it doesnt then KeyError
{
  int hSlots = k.hash(slots);
  int result = table[hSlots].index(k);    //index method returns -1 if not found and index if found
  if (result == -1)   //not found
  {
    throw KeyError();
  }
  else
    table[hSlots].remove(k);    //calls the list remove

}


// ============================= Assignment Operator ===========================
template <class KeyType>
hashtable<KeyType>& hashtable<KeyType>::operator=(const hashtable<KeyType>& h)
//Preconditions:  N/A
//Postcondition:  Returns hashtable that is the same as the parameter hashtable h
{
  for (int i = 0; i < table->size; i++)   //iterates through the hashtable
  {
    table[i] = h.table[i];    //Assignment using the list assignment method
  }

  return *this;
}


// =============================== toString Method =============================
template <class KeyType>
string hashtable<KeyType>::toString(int slot) const
//Preconditions:  N/A
//Postcondition:  Return string representation of linked list at slot
{
  string result = table[slot].toString();   //uses the list toString method

  return result;

}
