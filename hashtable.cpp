/*
Oscar Martinez
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
//Postcondition:  N/A
{
  slots = numSlots;
  table = new List<KeyType>[numSlots];
  for(int i = 0; i < table->size; i++)
  {
    table[i].head = NULL;
  }
}


// ============================== Copy Constructor ==============================
template <class KeyType>
hashtable<KeyType>::hashtable(const hashtable<KeyType>& h)
//Preconditions:  N/A
//Postcondition:  N/A
{
  slots = h.slots;
  table = new List<KeyType>[slots];
  table->size = h.table->size;
  for(int i = 0; i < table->size; i++)
  {
    table[i] = List<KeyType>::deepCopy(h.table[i]);
  }
}


// ================================= DeConstructor =============================
template <class KeyType>
hashtable<KeyType>::~hashtable()
//Preconditions:  N/A
//Postcondition:  N/A
{
  for(int i = 0; i < table->size; i++)
  {
    List<KeyType>::~List();
  }
}


// ================================= Get Method ================================
template <class KeyType>
KeyType* hashtable<KeyType>::get(const KeyType& k) const
//Preconditions:  N/A
//Postcondition:  N/A
{
  int hSlots = k->hash(slots);
  int result = table[hSlots].index();
  if (result == -1)
  {
    throw KeyError();
  }

  else
  {
    return *k;
  }

  //if collision then search in list T[h(k)] for key k
}


// ================================ Insert Method ==============================
template <class KeyType>
void hashtable<KeyType>::insert(KeyType* k)
//Preconditions:  N/A
//Postcondition:  N/A
{
  int hSlots = k->hash(slots);
  Node<KeyType>* current = table[hSlots].head;
  if (table[hSlots].head == NULL)
  {
    table[hSlots].head = k;
    return;
  }
  current->next = k;
  table[hSlots].head = k;

  //if collisino insert x at the head of list T[h(x.key)]
}


// ================================ Remove Method ==============================
template <class KeyType>
void hashtable<KeyType>::remove(const KeyType& k)
//Preconditions:  N/A
//Postcondition:  N/A
{
  int hSlots = k->hash(slots);
  table[hSlots].remove(k);

  //if collision then delete x from list T[h(x.key)]
}


// ============================= Assignment Operator ===========================
template <class KeyType>
hashtable<KeyType>& hashtable<KeyType>::operator=(const hashtable<KeyType>& h)
//Preconditions:  N/A
//Postcondition:  N/A
{
  for (int i = 0; i < table->size; i++)
  {
    table[i] = h.table[i];
  }

  return *this;
}


// =============================== toString Method ==============================
template <class KeyType>
string hashtable<KeyType>::toString(int slot) const
//Preconditions:  N/A
//Postcondition:  N/A
{
  string result = table[slot].toString();

  return result;

}
