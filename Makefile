
CPPOPTIONS = -c -g -Wall -std=c++0x

all: test_list test_dict test_hashtable imdb2 scrabble

//==============================================================================
test_list.o: test_list.cpp List.h List.cpp
	g++ $(CPPOPTIONSS) -c test_list.cpp

test_list: test_list.o
	g++ -o test_list test_list.o

test_dict.o: test_dict.cpp dict.h dict.cpp
	g++ $(CPPOPTIONSS) -c test_dict.cpp

test_dict: test_dict.o
	g++ -o test_dict test_dict.o

test_hashtable.o: test_hashtable.cpp hashtable.h hashtable.cpp
	g++ $(CPPOPTIONSS) -c test_hashtable.cpp

test_hashtable: test_hashtable.o
	g++ -o test_hashtable test_hashtable.o

imdb2.o: imdb2.cpp hashtable.h hashtable.cpp
	g++ $(CPPOPTIONSS) -c imdb2.cpp

imdb2: imdb2.o
	g++ -o imdb2 imdb2.o

scrabble.o: scrabble.cpp hashtable.h hashtable.cpp
	g++ $(CPPOPTIONSS) -c scrabble.cpp

scrabble: scrabble.o
	g++ -o scrabble scrabble.o

//==============================================================================
//==============================================================================
tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a all
