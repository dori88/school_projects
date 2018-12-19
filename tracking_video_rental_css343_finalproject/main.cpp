/*
//------------------------------------------------------------------------------
// main.cpp
// Authors: Jin Kim , Artiom Voronin
// Last modified: 6/7/17
// Purpose: This file serves as a main driver for the program that manages
// 	    a movie rental store interating with customers through a series
//          of commands.
//------------------------------------------------------------------------------
*/
#include <iostream>
#include <fstream>
#include <string>

#include "movie.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"

#include "store.h"
using namespace std;

int main() {

	// reading the movies data
	ifstream movies("data4movies.txt");
	if (!movies) {
		cout << "File could not be opened." << endl;
		return 1;
	}
	// reading customers
	ifstream customers("data4customers.txt");
	if (!customers) {
		cout << "File could not be opened." << endl;
		return 1;
	}
	// reading the commands 
	ifstream commands("data4commands.txt");
	if (!commands) {
		cout << "File could not be opened." << endl;
		return 1;
	}


	// creating a store 
	Store movieRentalStore;

	// build inventory and customer base for the store
	// movies will be stored in separate BST Trees depending on their genre
	// customers are stored as hash table
	movieRentalStore.buildInventory(movies);
	movieRentalStore.buildCustomerBase(customers);

	// execute the program by calling the commands
	movieRentalStore.proceed(commands);
	system("pause");
	return 0;
}