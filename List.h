/*
Austin Burgess, Oscar Martinez
CS 271
Dr. Lall
Project 6
*/


#ifndef _List_h
#define _List_h


#include <iostream>
#include <string>

using namespace std;


template <class T>
class Node
{
	public:
		T* data;
		Node<T>* next;

		Node();
		Node(T* d);
		Node(Node* p, T* d);


};


template <class T>
class List : public Node<T>
{
  public:
    List(); // default constructor
    List(const List<T>& src); // copy constructor
    ~List(); // destructor

    void append(T* item); // append a new item to the end of the list
		void headAppend(T* item); //append a new item to the head of the list
    int count(T item) const; // return the number of times a item is in the list
		void remove(const T& item); // delete the first instance of the item
    void insert(int index, T* item); // insert item in position index
		T* find(T item); //returns a pointer to the item
		T* pop(int index); // delete the item in position index
		int length() const; // returns the length of the list
		int index(const T& item) const; // return index of value item, or -1 if not found
    std::string toString(); // return a string representation of the list
		std::string toStringRecursive(Node<T>* front) const;

    T& operator[](int index) const; // indexing operator
    List<T>& operator=(const List& src); // assignment operator


		Node<T>* head;
		Node<T>* tail;
		int size;
		List<T>& deepCopy(const List<T>& otherList);
};

template <class T>
ostream &operator<< (ostream &os, const List<T>& list);


//===============================Error Catches==================================
class IndexError
{
	public:
		std::string message = "INDEX ERROR";
};

class RemoveError
{
	public:
		std::string message = "= REMOVE ERROR";
};

class InsertError
{
	public:
		std::string message = "INSERT ERROR";
};

class KeyError
{
	public:
		std::string message = "KEY ERROR";
};

#include "List.cpp"

#endif
