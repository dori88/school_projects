#include "hashtable.h"

//--------------------------Constructor-------------------------------------
// constuctor: initializes a hash table
// precondition: N/A
// postcondition: hash table constructed
//--------------------------------------------------------------------------
HashTable::HashTable() {
	for (int i = 0; i < 31; i++) {
		hashTableArr[i] = NULL;
	}
	//cout << "HashTable made";
}

//--------------------------Constructor-------------------------------------
// constuctor: initializes a hash table
// precondition: N/A
// postcondition: hash table constructed
//--------------------------------------------------------------------------
HashTable::~HashTable() {
}

//--------------------inserts-----------------------------------------------
// insert: inserts a customer in the hashtable
// precondition: c is a valid customer object
// postcondition: a customer is inserted in the hash table
//--------------------------------------------------------------------------
void HashTable::insert(Customer *c) {
	int uniqueID = c->getUniqueID();
	int key = uniqueID % 31;
	if (hashTableArr[key] == NULL) {
		hashTableArr[key] = c;
	}
	else {
		int i = 0;
		while (hashTableArr[(key + (i*i))] != NULL) {
			i++;
			if (hashTableArr[(key + (i*i))] == NULL) {
				hashTableArr[(key + (i*i))] = c;
				break;
			}
		}
	}
}

//--------------------------------find--------------------------------------
// find: find the customer in the hashtable
// precondition: c is a valid customer object
// postcondition: return a pointer to the finding customer
//--------------------------------------------------------------------------
Customer* HashTable::find(const int uID) {
	int key = uID % 31;
	if (hashTableArr[key] != NULL)
	{
		if (hashTableArr[key]->getUniqueID() == uID) {
		return hashTableArr[key];
	}
	else{
		int i = 0;
		while (hashTableArr[(key + (i*i))] != NULL) {
			i++;
			if (hashTableArr[(key + (i*i))]->getUniqueID() == uID) {
				return hashTableArr[(key + (i*i))];
				break;
			}
		}
	}
	}
	
	return NULL;
}