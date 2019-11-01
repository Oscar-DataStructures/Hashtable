/*
Oscar Martinez
CS 271
Dr. Lall
Project 6
*/


#ifndef _hashtable_h
#define _hashtable_h

#include "List.h"
#include <string>

template <class KeyType>
class hashtable : public List<KeyType>
{
  public:
    hashtable(int numSlots);
    hashtable(const hashtable<KeyType>& h);
    ~hashtable();

    KeyType* get(const KeyType& k) const;
    void insert(KeyType* k);
    void remove(const KeyType& k);

    hashtable<KeyType>& operator=(const hashtable<KeyType>& h);
    std::string toString(int slot) const;

    int slots;
    List<KeyType>* table; // an array of linked lists. ie slots
};

class KeyError
{
	public:
		std::string message = "KEY ERROR";
};



#include "hashtable.cpp"

#endif
