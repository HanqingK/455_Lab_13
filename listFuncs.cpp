// Name:
// USC NetID:
// CSCI 455 PA5
// Spring 2019


#include <iostream>

#include <cstdlib>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
	key = theKey;
	value = theValue;
	next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
	key = theKey;
	value = theValue;
	next = n;
}


//*************************************************************************
// put the function definitions for your list functions below
bool addFront(const string &target, int addData, ListType &list) {

	if (contains(target, list)) {
       cout << "The element " << target << " has already exist in the list" << endl;
		return false;
	}

	Node * curr = new Node(target, addData);
	curr->next = list;
	list = curr;
	return true;
}

bool addLast(const string &target, int addData, ListType &list) {
	if (contains(target, list)) {
       cout << "The element " << target << " has already exist in the list" << endl;
		return false;
	}
	Node * curr = list;
	Node * newNode = new Node(target, addData);

	if (curr == NULL) {
		list = newNode;
		return true;
	}
	else {
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = newNode;
		return true;
	}
}


bool deleteNode(const string &target, ListType &list) {
	if (!contains(target, list)) {
       cout << "The element " << target << " does not exist in the list" << endl;
		return false;
	}
	Node * delPtr = NULL;
	Node * curr = list;
	Node * temp = curr;
	while (curr != NULL && curr->key != target) {
		temp = curr;
		curr = curr->next;
	}

	if (curr == NULL) {
		cout <<"The element "<< target << " was not in the list" << endl;
		delete delPtr;
		return false;
	}
	else {
		delPtr = curr;
		curr = curr->next;
		temp->next = curr;
       if (delPtr == list) {
			list = list->next;
			temp = NULL;
		}
		delete delPtr;
		cout << "The element " << target << " was deleted" << endl;
		return true;
	}
}

bool contains(const string &target, ListType &list) {
	Node * curr = list;
	while (curr != NULL && curr->key != target) {
		curr = curr->next;
	}
	if (curr == NULL) {
       //cout << "The element " << target << " does not exist in the list" << endl;
		return false;
	}
	else {
        // cout << "The element " << target << " has already exist in the list" << endl;
		return true;
	}

}

ListType target(ListType &list, const string &target) {
	if (list == NULL) {
		return NULL;
	}
	Node * curr = list;
	while (curr != NULL && curr->key != target) {
		curr = curr->next;
	}
	if (curr == NULL) {
		return NULL;
	}
	else {
		return curr;
	}

}

int size(ListType &list) {
	int size = 0;
	Node * curr = list;
	while (curr != NULL) {
		size++;
		curr = curr->next;
	}
	return size;
}

void printList(ListType &list) {
	Node * curr = list;
	while (curr != NULL) {
		cout << curr->key << ": " << curr->value << ", ";
		curr = curr->next;
	}
   cout << endl;
}
