/*
//------------------------------------------------------------------------------
// store.cpp
// Authors: Jin Kim , Artiom Voronin
// Last modified: 6/7/17
// Purpose: Contains the implementation for store.h
//------------------------------------------------------------------------------
*/
#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include "movie.h"
#include "movief.h"
#include "bst.h"
#include "hashtable.h"
#include "transaction.h"
#include "borrow.h"
#include "return.h"
#include "hashtable.h"

using namespace std;
class Store {

public:
//--------------------------------Store()--------------------------------------
// Store() :	   default constructor for Store class
// precondition :  NONE
// postcondition : creates a store object
//------------------------------------------------------------------------------
	Store(); 
//-------------------------------~Store()--------------------------------------
// ~Store() : 	   destructor for store class
// precondition :  NONE
// postcondition : deallocates the store object 
//------------------------------------------------------------------------------
	~Store();
	
	// reads the commands from the file
//-------------------------------proceed----------------------------------------
// proceed() : 	   reads in the file with commands and executes them
// precondition :  commands is a txt file 
// postcondition : executes the commands necessary to run the overall program
//------------------------------------------------------------------------------
	void proceed(ifstream &commands);

	// reads the movies from the file 
//-------------------------------buildInventory-------------------------------------
// buildInventory : reads in the file with movies and stores them in appropriate BST
// precondition :   movies is a txt file 
// postcondition :  inserts movies into appropriate genre BST
//----------------------------------------------------------------------------------
	void buildInventory(ifstream &movies);
	// reads the customers from the file
//-------------------------------buildCustomerBase--------------------------------------
// buildCustomerBase : reads in the file with customers and stores them into a HashTable
// precondition :      customers is a txt file 
// postcondition :     inserts customers into a hashtable
//--------------------------------------------------------------------------------------
	void buildCustomerBase(ifstream &customers);

private:
	// stores all customers in a hashtable called customerBase
	HashTable customerBase;
	// movies in a form of BST
	BST moviesC; // might be able to group all three
	BST moviesD; // of movies into one single array of pointers
	BST moviesF;

	
};
