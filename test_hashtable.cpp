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

	int hash(int slots) const
	{
		int sum = 0;
		for (int i = 0; i < key.length(); i++)
		{
			sum += int(key[i]);
		}

		return (sum % slots);
	}

	bool operator==(const Pair p)
	{
		return key == p.key;
	}

	bool operator!=(const Pair p)
	{
		return key != p.key;
	}

	bool operator<(const Pair p)
	{
		return key < p.key;
	}

	bool operator>(const Pair p)
	{
		return key > p.key;
	}

	bool operator>=(const Pair p)
	{
		return key >= p.key;
	}

	bool operator<=(const Pair p)
	{
		return key <= p.key;
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

	Pair pCopy;						//collision test
	pCopy.key = "key";
	pCopy.value = "value";

	Pair p1;
	p1.key = "dog";
	p1.value = "cat";

	Pair p2;
	p2.key = "rain";
	p2.value = "snow";
	hashtable<Pair> t1(10);			//table1


	int result = p.hash(t1.slots);
	int result1 = p1.hash(t1.slots);
	int result2 = p2.hash(t1.slots);


	Pair* pPoint = &p;
	t1.insert(pPoint);

	Pair* pCopyPoint = &pCopy;		//used to test collision
	t1.insert(pCopyPoint);


	Pair* pPoint1 = &p1;
	t1.insert(pPoint1);

	Pair* pPoint2 = &p2;
	t1.insert(pPoint2);


	//cout << t1.get(p) << endl;


	//cout << t1.toString(result) << endl;
}


// ============================= Test Remove Method ============================
void test_remove()
{
	Pair p;
	p.key = "key";
	p.value = "value";

	Pair pCopy;						//collision test
	pCopy.key = "key";
	pCopy.value = "value";

	Pair p1;
	p1.key = "dog";
	p1.value = "cat";

	Pair p2;
	p2.key = "rain";
	p2.value = "snow";
	hashtable<Pair> t1(10);		//table1


	int result = p.hash(t1.slots);
	int result1 = p1.hash(t1.slots);
	int result2 = p2.hash(t1.slots);



	Pair* pPoint = &p;
	t1.insert(pPoint);

	Pair* pCopyPoint = &pCopy;		//used to test collision
	t1.insert(pCopyPoint);

	Pair* pPoint1 = &p1;
	t1.insert(pPoint1);

	Pair* pPoint2 = &p2;
	t1.insert(pPoint2);


	t1.remove(p);
	t1.remove(p);
	t1.remove(p1);
	t1.remove(p2);
}


// =============================== Test Operator ===============================
void test_operator()
{
	Pair p;
	p.key = "key";
	p.value = "value";

	Pair pCopy;						//collision test
	pCopy.key = "key";
	pCopy.value = "value";

	Pair p1;
	p1.key = "dog";
	p1.value = "cat";

	Pair p2;
	p2.key = "rain";
	p2.value = "snow";
	hashtable<Pair> t1(10);			//table1


	int result = p.hash(t1.slots);
	int result1 = p1.hash(t1.slots);
	int result2 = p2.hash(t1.slots);



	Pair* pPoint = &p;
	t1.insert(pPoint);

	Pair* pCopyPoint = &pCopy;		//used to test collision
	t1.insert(pCopyPoint);

	Pair* pPoint1 = &p1;
	t1.insert(pPoint1);

	Pair* pPoint2 = &p2;
	t1.insert(pPoint2);

	hashtable<Pair> t2(10);					//table2
	t2 = t1;

	t1.remove(p);
	t1.remove(p1);
	t1.remove(p2);

	t2 = t1;
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
	test_remove();
	cout << "Remove Test				|Passed|" << endl;
  test_operator();
  cout << "Operator Test				|Passed|" << endl;

	return 0;
}
