//------------------------------------------------------------------------------
// hashtable.h
// Authors:       Jin Kim , Artiom Voronin  
// Last modified: 6/7/17
// Purpose:       This is the header file definig hashTable class
//                that holds customer, sort them based on their Account ID
//------------------------------------------------------------------------------
#pragma once
#include "customer.h"
#define HASHTABLESIZE 31

class HashTable {

private:

	Customer *hashTableArr[HASHTABLESIZE];

public:

	//--------------------------Constructor-------------------------------------
	// constuctor: initializes a hash table
	// precondition: N/A
	// postcondition: hash table constructed
	//--------------------------------------------------------------------------
	HashTable();

	//--------------------------------------------------------------------------
	// Destructor: destructor
	// precondition: none
	// postcondition: the hashtable is destructed
	//--------------------------------------------------------------------------
	~HashTable();

	//------------------------------insert--------------------------------------
	// insert: inserts a customer in the hashtable
	// precondition: c is a valid customer object
	// postcondition: a customer is inserted in the hash table
	//--------------------------------------------------------------------------
	void insert(Customer *c);

	//--------------------------------find--------------------------------------
	// find: find the customer in the hashtable
	// precondition: c is a valid customer object
	// postcondition: return a pointer to the finding customer
	//--------------------------------------------------------------------------
	Customer* find(const int uID);
};