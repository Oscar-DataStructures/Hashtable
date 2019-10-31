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
  table = new List<int>[numSlots];
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
  table = new List<int>[slots];
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

  //if collision then search in list T[h(k)] for key k
}


// ================================ Insert Method ==============================
template <class KeyType>
void hashtable<KeyType>::insert(KeyType* k)
//Preconditions:  N/A
//Postcondition:  N/A
{

  //if collisino insert x at the head of list T[h(x.key)]
}


// ================================ Remove Method ==============================
template <class KeyType>
void hashtable<KeyType>::remove(const KeyType& k)
//Preconditions:  N/A
//Postcondition:  N/A
{

  //if collision then delete x from list T[h(x.key)]
}


// ================================= Hash Method ===============================
template <class KeyType>
int hashtable<KeyType>::hash(int slots)
//Preconditions:  N/A
//Postcondition:  N/A
{

}


// ============================= Assignment Operator ===========================
template <class KeyType>
hashtable<KeyType>& hashtable<KeyType>::operator=(const hashtable<KeyType>& h)
//Preconditions:  N/A
//Postcondition:  N/A
{

}


// =============================== toString Method ==============================
template <class KeyType>
string hashtable<KeyType>::toString(int slot) const
//Preconditions:  N/A
//Postcondition:  N/A
{
  // table[slot].toString();

}
