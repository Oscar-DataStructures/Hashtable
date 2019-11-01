/*
Oscar Martinez
CS 271
Dr. Lall
Project 6
*/

#include <iostream>
#include <string>
#include <cassert>
#include "hashtable.h"

using namespace std;

struct Pair
{
	string key;
	string value;

	public:
		int hash(int slots)
};

// ================================= Constructor ===============================
void test_defaultConstructor()
{
	hashtable<int> a(2);

}


// ============================== Copy Constructor ==============================
void test_copyConstructor()
{
	hashtable<int> a(2);
	hashtable<int> b(a);
}


//========================= Test Insert and Get Methods =======================
void test_insert_and_get()
{

}


// ============================= Test Remove Method ============================
void test_remove()
{

}


// =============================== Test Operator ===============================
void test_operator()
{

}



// ==================================== Main ===================================
// =============================================================================
int main()
{
	test_defaultConstructor();
	cout << "Default Constructor Test		|Passed|" << endl;
	test_copyConstructor();
	cout << "Copy Constructor Test			|Passed|" << endl;
	// test_insert_and_get();
	// cout << "Insert and Get Test			|Passed|" << endl;
	// test_remove();
	// cout << "Remove Test				|Passed|" << endl;
  // test_operator();
  // cout << "Insert and Get Test			|Passed|" << endl;

	return 0;
}
