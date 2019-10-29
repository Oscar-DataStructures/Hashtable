/*
Oscar Martinez
CS 271
Dr. Lall
Project 6
*/
#ifndef _List_h
#define _List_h


#include <iostream>
#include <string>

template <class T>
class Node
{
	public:
		Node();
		Node(T d);
		Node(Node* p, T d);

	private:
		T data;
		Node* next;

	template <class U>
	friend class List;
};


template <class T>
class List
{
  public:
    List(); // default constructor
    List(const List<T>& src); // copy constructor
    ~List(); // destructor

    void append(T item); // append a new item to the end of the list
    int count(T item) const; // return the number of times a item is in the list
		void remove(T item); // delete the first instance of the item
    void insert(int index, T item); // insert item in position index
		void pop(int index); // delete the item in position index
		int length() const; // returns the length of the list
		int index(T item) const; // return index of value item, or -1 if not found
    std::string toString() const; // return a string representation of the list

    T& operator[](int index) const; // indexing operator
    List<T>& operator=(const List& src); // assignment operator
		//friend class ostream &operator<< (ostream &out, const List<T> &list); // not sure, right track i think?

	private:
		Node<T>* head;
		Node<T>* tail;
		int size;
		List<T>& deepCopy(const List<T>& src);
};

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

#include "List.cpp"

#endif
