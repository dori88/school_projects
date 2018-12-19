/*
//------------------------------------------------------------------------------
// customer.cpp
// Authors:       Jin Kim , Artiom Voronin
// Last modified: 6/7/17
// Purpose:       Defines the customer object that hold information about
//		  a person who interacts with the store object
//------------------------------------------------------------------------------
*/
#include<iostream>
#include<string>
#include"transaction.h" 
#include"movie.h"
#pragma once
using namespace std;
#define MAXSIZE 100

//------------------------------customer.h--------------------------------------
// Purpose: This file contains customer Class function declaration.
//------------------------------------------------------------------------------
class Customer {

private:

	int logCount = 0; // count the number of history
					  // transaction the user has Used as
					  // index.
	int uniqueID; // customer's unique identification
	Transaction *log[MAXSIZE]; // user's log
	string firstName; // customer's first name
	string lastName; // customer's last name

public:

	//--------------------------------------------------------------------------
	// Customer() : default constructor for Customer class
	// precondition : NONE
	// postcondition : initialize the private value to NULL
	//--------------------------------------------------------------------------
	Customer();

	//--------------------------------------------------------------------------
	// ~Customer() : destructor for Customer class
	// precondition : NONE
	// postcondition : delete the array of Transaction
	//--------------------------------------------------------------------------
	~Customer();

	//--------------------------------------------------------------------------
	// Customer() : constructor that set uniqueID and customer's name
	// for customer
	// precondition : uniqueID is four digit number, firstName and lastName
	// should be a valid string
	// postcondition : initialize the private values with the passed in values
	//--------------------------------------------------------------------------
	Customer(int uniqueID, string firstName, string lastName);

	//--------------------------------------------------------------------------
	// getCustLog() : accessor to access customer's history by calling
	// hash table class
	// precondition : NONE
	// postcondition : print the customer¡¯s history
	//--------------------------------------------------------------------------
	void getCustLog();

	//--------------------------------------------------------------------------
	// setCustLog() : mutator to set customer's history
	// precondition : t is a valid Transaction type
	// postcondition : customer's history is set
	//--------------------------------------------------------------------------
	void setCustLog(Transaction *t);

	//--------------------------------------------------------------------------
	// getLogCount() : accessor to access the number of borrow/ return
	// transactions
	// history the customer has
	// precondition : NONE
	// postcondition : return customer's history count
	//--------------------------------------------------------------------------
	int getLogCount() const;

	//--------------------------------------------------------------------------
	// getUniqueID() : accessor to access customer's unique ID
	// precondition : NONE
	// postcondition : return customer's unique ID
	//--------------------------------------------------------------------------
	int getUniqueID() const;

	//--------------------------------------------------------------------------
	// setCustLog() : mutator to set customer's first name
	// precondition : fn is a valid string
	// postcondition : customer's firstname is set
	//--------------------------------------------------------------------------
	void setFirstName(string fn);

	//--------------------------------------------------------------------------
	// getUniqueID() : accessor to access customer's firstname
	// precondition : NONE
	// postcondition : returns custoemr's firstname
	//--------------------------------------------------------------------------
	string getFirstName()const;

	//--------------------------------------------------------------------------
	// setCustLog() : mutator to set customer's last name
	// precondition : fn is a valid string
	// postcondition : customer's lastname is set
	//--------------------------------------------------------------------------
	void setLastName(string ln);

	//--------------------------------------------------------------------------
	// getUniqueID() : accessor to access customer's lastname
	// precondition : NONE
	// postcondition : returns custoemr's lastname
	//--------------------------------------------------------------------------
	string getLastName()const;

}; // end of class Customer