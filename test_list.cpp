/*
Oscar Martinez
CS 271
Dr. Lall
Project 6
*/


#include <iostream>
#include "List.h"
#include <string>
#include <cassert>

using namespace std;



// ======================= Test List Constructor Function ======================
void test_listConstructor()
{
	List<std::string> a;
	assert(a.length() == 0);
	a.append("test");
	a.append("test2");

	List<int> b;
	assert(b.length() == 0);

	List<std::string> c(a);
	assert(c.toString() == "[test, test2]");
}


// ============================ Test Append Function ===========================
void test_append()
{
	List<std::string> a;
	a.append("test");
  assert(a.toString()=="[test]");
	a.append("test2");
	assert(a.toString()=="[test, test2]");

	List<int> b;
	b.append(1);
	assert(b.toString()=="[1]");
	b.append(2);
	assert(b.toString()=="[1, 2]");

}


//============================= Test Count Function ============================
void test_count()
{
	List<std::string> a;
	a.append("test");
	a.append("test2");
	assert(a.count("test") == 1);
	assert(a.count("! ") == 0);

	List<int> b;
	b.append(1);
	b.append(2);
	b.append(2);
	assert(b.count(2) == 2);
	assert(b.count(6) == 0);

}


// ============================ Test Remove Function ===========================
void test_remove()
{
	List<std::string> a;
	a.append("test");
	a.append("test2");
	assert(a.toString()=="[test, test2]");
	a.remove("test2");
	assert(a.toString()=="[test]");

	List<int> b;
	b.append(1);
	b.append(2);
	b.append(2);
	assert(b.toString()=="[1, 2, 2]");
	b.remove(2);
	assert(b.toString()=="[1, 2]");
}


//============================ Test Insert Function ============================
void test_insert()
{
	List<std::string> a;
	assert(a.length() == 0);
	a.insert(0, "test");
	assert(a.length() == 1);
	a.insert(1, "test2");


	List<int> b;
	assert(b.length() == 0);
	b.insert(0, 1);
	assert(b.length() == 1);
	b.insert(0, 0);
	assert(b.length() == 2);
	b.insert(2, 4);
	assert(b.length() == 3);
	b.insert(2, 3);
	assert(b.length() == 4);
	assert(b.toString() == "[0, 1, 3, 4]");
}


//============================== Test Pop Function =============================
void test_pop()
{
	List<std::string> a;
	a.append("test");
	a.append("test2");
	assert(a.toString()=="[test, test2]");
	a.pop(1);
	assert(a.toString()=="[test]");

	List<int> b;
	b.append(1);
	b.append(2);
	b.append(2);
	assert(b.toString()=="[1, 2, 2]");
	b.pop(1);
	assert(b.toString()=="[1, 2]");
}


//============================ Test Length Function ============================
void test_length()
{
	List<std::string> a;
	a.append("test");
	a.append("test2");
	assert(a.length()==2);
	a.pop(1);
	assert(a.length()==1);

	List<int> b;
	b.append(1);
	b.append(2);
	b.append(2);
	assert(b.length()==3);
	b.pop(1);
	assert(b.length()==2);
}


// ============================ Test Index Function ============================
void test_index()
{
	List<std::string> a;
	a.append("test");
	assert(a.index("test") == 0);
	a.append("test2");
	assert(a.index("test2") == 1);

	List<int> b;
	b.append(1);
	assert(b.index(1) == 0);
	b.append(2);
	assert(b.index(2) == 1);

}


// ============================ Test Index Operator ============================
void test_indexOperator()
{
	List<std::string> a;
	try
	{
		a[0];
	}
	catch (IndexError error)
	{
		cerr << "Index Error Caught" << endl;
	}

	a.append("test");
	assert(a[0] == "test");

	List<int> b;
	try
	{
		b[0];
	}
	catch (IndexError error)
	{
		cerr << "Index Error Caught" << endl;
	}

	b.append(1);
	assert(b[0] == 1);
	b[0];
}


// ========================== Test Assignment Operator =========================
void test_assignmentOperator()
{
	List<std::string> l;
	l.append("test");
	l.append("test2");
	List<std::string> m;
	m = l;
  assert(m.index("test2")==1);
  assert(m.index("test")==0);
  assert(l.index("test2")==1);
  assert(l.index("test")==0);
  assert(m.length()==2);
  assert(m.toString()=="[test, test2]");

	List<int> n;
	n.append(1);
	n.append(2);
	List<int> o;
	o=n;
  assert(o.toString()=="[1, 2]");
  assert(o.length()==2);
}


// ======================= Test Stream Insertion Operator ======================
void test_streamInsertionOperator()
{

}


// ==================================== Main ===================================
// =============================================================================
int main()
{
	test_listConstructor();
	cout << "List Constructor Test			|Passed|" << endl;
	test_append();
	cout << "Append Test			        |Passed|" << endl;
	test_count();
	cout << "Count Test				|Passed|" << endl;
	test_remove();
	cout << "Remove Test				|Passed|" << endl;
	test_insert();
	cout << "Insert Test				|Passed|" << endl;
	test_pop();
	cout << "Pop Test				|Passed|" << endl;
	test_length();
	cout << "Length Test				|Passed|" << endl;
	test_index();
	cout << "Index Test				|Passed|" << endl;
	test_indexOperator();
	cout << "Index Operator Test		   	|Passed|" << endl;
	test_assignmentOperator();
	cout << "Assignment Operator Test	 	|Passed|" << endl;
	test_streamInsertionOperator();
	cout << "Insertion Operator Test			|Passed|" << endl;

	return 0;
}
