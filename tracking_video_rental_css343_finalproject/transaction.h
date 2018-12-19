/*
//------------------------------------------------------------------------------
// transaction.h
// Author:  Artiom Voronin, Jin Kim
// Last changed: 06/07/2017
// Purpose: An header file for transaction class.
//------------------------------------------------------------------------------
*/
#pragma once

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Transaction {

	friend ostream& operator<<(ostream &, const Transaction &);

public:

	//--------------------------------------------------------------------------
	// Transaction() : constructor that sets default value for Transaction
	// precondition : NONE
	// postcondition : creates default Transaction class
	//--------------------------------------------------------------------------
	Transaction();

	//--------------------------------------------------------------------------
	// ~Transaction() : destruction for Transaction class
	// precondition : NONE
	// postcondition : Transaction class is destructed
	//--------------------------------------------------------------------------
	virtual ~Transaction();

	//--------------------------------------------------------------------------
	// processTransaction() : process the desired transaction. 
	//						  This method is merely a placeholder for the 
	//						  inheriting classes.
	// precondition : NONE
	// postcondition : Process the desired transaction.
	//--------------------------------------------------------------------------
	virtual void processTransaction(char action, int id);

	//--------------------------------------------------------------------------
	// Description: prints transaction
	// Precondition: <iostream> included
	// Postcondition: prints transaction to console
	// is added in corresponding customer¡¯s history
	//--------------------------------------------------------------------------
	virtual void print(ostream& o) const;

protected:

	char action;

};
