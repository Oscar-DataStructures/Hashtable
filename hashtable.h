/*
Austin Burgess, Oscar Martinez
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
    hashtable(int numSlots);    //default Constructor with a slot number to make table size of numSlots
    hashtable(const hashtable<KeyType>& h);   //copy Constructor
    ~hashtable();   //DeConstructor

    KeyType* get(const KeyType& k) const;   //checks to see if k is in table and returns a pointer to k
    void insert(KeyType* k);    //inserts k into the apriopiate slot in the table
    void remove(const KeyType& k);    //removes k from the apriopiate slot in the table

    hashtable<KeyType>& operator=(const hashtable<KeyType>& h);   //sets this table equal to the assigned h's table
    std::string toString(int slot) const;   //provides a string representation of a slot in the table

    int slots;    //how many slots are in the table
    List<KeyType>* table; // an array of linked lists. ie slots
};

class KeyError
{
	public:
		std::string message = "KEY ERROR";
};


#include "hashtable.cpp"

#endif
