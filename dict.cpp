/*
Austin Burgess, Oscar Martinez
CS 271
Dr. Lall
Project 6
*/

#include <sstream>
#include <string>
#include <typeinfo>


using namespace std;



// ================================= Constructor ===============================
template <class KeyType1, class KeyType2>
Dictionary<KeyType1, KeyType2>::Dictionary() : hashtable<KeyType>(int numSlots)
//Preconditions:  N/A
//Postcondition:  Inherits hashtable constructor
{

}


// =============================== Copy Constructor ============================
template <class KeyType1, class KeyType2>
Dictionary<KeyType1, KeyType2>::Dictionary(const Dictionary<KeyType1, KeyType2>& dict) : hashtable<Pair<KeyType1, KeyType2>>(dict)
//Preconditions:    N/A
//Postcondition:    Inherits hashtable copy constructor
{

}


// ================================= Empty Method ==============================
template <class KeyType1, class KeyType2>
bool Dictionary<KeyType1, KeyType2>::empty() const
//Preconditions:  Tree must exist
//Postcondition:  Returns whether or not dict is empty
{
  int size = 0;
  for (list : table)
  {
    size += list.length();
  }
  return size == 0;
}


// ================================= Get Method ================================
template <class KeyType1, class KeyType2>
Pair<KeyType1, KeyType2>* Dictionary<KeyType1, KeyType2>::get(const KeyType1& k) const
//Preconditions:    Tree must exist
//Postcondition:    Inherits hashtable helpGet method to return key of dict or null if not found
{
  Pair<KeyType1, KeyType2>* output = hashtable<Pair<KeyType1, KeyType2>>::get(output->key);
  return output;
}


// ================================ Insert Method ==============================
template <class KeyType1, class KeyType2>
void Dictionary<KeyType1, KeyType2>::insert(KeyType1 k, KeyType2 v)
// PreConditions:   N/A
// PostConditions:  Inherits bst insert method to insert into dict value k
{
  try   // if a GetError is received, that means k is not yet in the dict so we can add it
  {
    Pair<KeyType1, KeyType2> exists = get(k);
  }

  catch(GetError)   // add it
  {
    hashtable<KeyType>::insert(k);      //hashtable inheritance
    return;
  }

  // else - it was found so throw KeyError
  {
    throw KeyError();             //KeyError caught
  }

}


// ================================ Remove Method ==============================
template <class KeyType1, class KeyType2>
void Dictionary<KeyType1, KeyType2>::remove(const KeyType1& k)
//Preconditions:  Tree must exist
//Postcondition:  Inherits remove method from hashtable to remove value k from dict
{
  hashtable<KeyType>::remove(k);      //hashtable inheritance
}
