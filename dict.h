/*
Austin Burgess, Oscar Martinez
CS 271
Dr. Lall
Project 6
*/

#ifndef _dict_h
#define _dict_h

#include <iostream>
#include <string>
#include "hashtable.h"

template <class KeyType1, class KeyType2>
class Pair
{
public:
  Pair();
  Pair(Pair<KeyType1, KeyType2>& p);
  Pair(KeyType1 k, KeyType2 v);
  ~Pair();

  KeyType1 key;
  KeyType2 value;


}

template <class KeyType1, class KeyType2>
class Dictionary : public hashtable<Pair<KeyType1, KeyType2>>
{
  public:
    Dictionary(); //constructor
    Dictionary(const Dictionary<KeyType1, KeyType2>& dict); //copy constructor


    bool empty() const; // return true if empty; false o/w

    KeyType get(const KeyType1& k) const; // return first item with key equal to k

    void insert(KeyType1 k, KeyType2 v); // insert k into the tree, add unique key error
    void remove(const KeyType1& k); // delete first item with key equal to k

    using hashtable<Pair<KeyType1, KeyType2>>::table;
};

#include "dict.cpp"

#endif
