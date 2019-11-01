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

	int hash(int slots)
	{
		int sum = 0;
		for (int i = 0; i < key.length(); i++)
		{
			sum += int(key[i]);
		}

		return (sum % slots);
	}
	
};

// ================================= Constructor ===============================
void test_defaultConstructor()
{
	hashtable<Pair> t1(10);
	assert(t1.slots == 10);
	hashtable<Pair> t2(20);
	assert(t2.slots == 20);
}


// ============================== Copy Constructor ==============================
void test_copyConstructor()
{
	hashtable<Pair> t1(10);
	hashtable<Pair> t2(t1);
	assert(t2.slots == 10);
}


//========================= Test Insert and Get Methods =======================
void test_insert_and_get()
{
	Pair p;
	p.key = "key";
	p.value = "value";

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
	test_insert_and_get();
	cout << "Insert and Get Test			|Passed|" << endl;
	// test_remove();
	// cout << "Remove Test				|Passed|" << endl;
  // test_operator();
  // cout << "Insert and Get Test			|Passed|" << endl;

	return 0;
}
