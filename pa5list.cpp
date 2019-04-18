// Name:
// USC NetID:
// CS 455 PA5
// Spring 2019

// pa5list.cpp
// a program to test the linked list code necessary for a hash table chain

// You are not required to submit this program for pa5.

// We gave you this starter file for it so you don't have to figure
// out the #include stuff.  The code that's being tested will be in
// listFuncs.cpp, which uses the header file listFuncs.h

// The pa5 Makefile includes a rule that compiles these two modules
// into one executable.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "listFuncs.h"


int main() {

	ListType list = NULL;
	addFront( "world", 21, list); // addFront test
	addFront("hello", 5, list);
    cout<< "the result is: ";
    addFront("hello", 5, list); //contains test
    cout << "expected result is: " << "The element hello has already in the list"<< endl << endl;

   cout<< "the result is: ";
   printList(list); //  printList Test
   cout << "expected result is: " << "hello: 5, world: 21"<< endl << endl;

   
 
	addLast("zhong", 11, list); // addLast test
    cout<< "the result is: ";
    addLast("zhong", 11, list); //test contains
    cout << "expected result is: " << "The element zhong has already in the list"<< endl << endl;

   cout<< "the result is: ";
   printList(list); //  printList Test
   cout << "expected result is: " << "hello: 5, world: 21, zhong: 11"<< endl << endl;

   
   deleteNode("hello",list);
   deleteNode("zhong",list);
   cout<< "the result is: ";
   printList(list); //  printList Test
   cout << "expected result is: " << "world: 21"<< endl << endl;
   
   
  // ListType test = target(list, "hello");
    //  cout << endl;
   // printList(test);
   
    cout << size(list) << endl;
   
  
   return 0;
}
