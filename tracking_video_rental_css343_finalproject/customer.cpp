/*
//------------------------------------------------------------------------------
// customer.cpp
// Authors:       Jin Kim , Artiom Voronin
// Last modified: 6/7/17
// Purpose:       Contains the implementation for customer.h
//------------------------------------------------------------------------------
*/
#include "customer.h"

//--------------------------------------------------------------------------
// Customer() : default constructor for Customer class
// precondition : NONE
// postcondition : initialize the private value to NULL
//--------------------------------------------------------------------------
Customer::Customer() {
	logCount = 0;
	uniqueID = 0;
	firstName = "";
	lastName = "";

	//cout << "Default Customer constructor made" << endl;
}

//--------------------------------------------------------------------------
// ~Customer() : destructor for Customer class
// precondition : NONE
// postcondition : delete the array of Transaction
//--------------------------------------------------------------------------
Customer::~Customer() {
}

//--------------------------------------------------------------------------
// Customer() : constructor that set uniqueID and customer's name
// for customer
// precondition : uniqueID is four digit number, firstName and lastName
// should be a valid string
// postcondition : initialize the private values with the passed in values
//--------------------------------------------------------------------------
Customer::Customer(int uID, string fn, string ln) {
	logCount = 0;
	uniqueID = uID;
	firstName = fn;
	lastName = ln;

	//cout << fn << " " << ln << " Customer made" << endl;
}

//--------------------------------------------------------------------------
// getCustLog() : accessor to access customer's history by calling
// hash table class
// precondition : NONE
// postcondition : print the customer¡¯s history
//--------------------------------------------------------------------------
void Customer::getCustLog() {
	cout << firstName << " " << lastName << "'s Transaction History:" 
			<< endl;
	for (int i = 0; i < logCount; i++) {
		cout << *log[i] << endl;
	}
	cout << endl;
}

void Customer::setCustLog(Transaction *t) {
	log[logCount] = t;
	logCount++;
}

/*
//--------------------------------------------------------------------------
// setCustLog() : mutator to set customer's history
// precondition : t is a valid Transaction type
// postcondition : customer's history is set
//--------------------------------------------------------------------------
*/

//--------------------------------------------------------------------------
// getLogCount() : accessor to access the number of borrow/ return
// transactions
// history the customer has
// precondition : NONE
// postcondition : return customer's history count
//--------------------------------------------------------------------------
int Customer::getLogCount() const {
	return logCount;
}

//--------------------------------------------------------------------------
// getUniqueID() : accessor to access customer's unique ID
// precondition : NONE
// postcondition : return customer's unique ID
//--------------------------------------------------------------------------
int Customer::getUniqueID() const {
	return uniqueID;
}

//--------------------------------------------------------------------------
// setCustLog() : mutator to set customer's first name
// precondition : fn is a valid string
// postcondition : customer's firstname is set
//--------------------------------------------------------------------------
void Customer::setFirstName(string fn)
{
	firstName = fn;
}

//--------------------------------------------------------------------------
// getUniqueID() : accessor to access customer's firstname
// precondition : NONE
// postcondition : returns custoemr's firstname
//--------------------------------------------------------------------------
string Customer::getFirstName() const
{
	return firstName;
}

//--------------------------------------------------------------------------
// setCustLog() : mutator to set customer's last name
// precondition : fn is a valid string
// postcondition : customer's lastname is set
//--------------------------------------------------------------------------
void Customer::setLastName(string ln)
{
	lastName = ln;
}

//--------------------------------------------------------------------------
// getUniqueID() : accessor to access customer's lastname
// precondition : NONE
// postcondition : returns custoemr's lastname
//--------------------------------------------------------------------------
string Customer::getLastName() const
{
	return lastName;
}
