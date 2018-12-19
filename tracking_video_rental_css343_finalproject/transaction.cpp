/*
//------------------------------------------------------------------------------
// transaction.cpp
// Author:  Artiom Voronin, Jin Kim
// Last changed: 06/07/2017
// Purpose: An implementation file for transaction class.
//------------------------------------------------------------------------------
*/
#include "transaction.h"

//------------------------------------------------------------------------------
// Transaction() : constructor that sets default value for Transaction
// precondition : NONE
// postcondition : creates default Transaction class
//------------------------------------------------------------------------------
Transaction::Transaction() {

}

//------------------------------------------------------------------------------
// ~Transaction() : destruction for Transaction class
// precondition : NONE
// postcondition : Transaction class is destructed
//------------------------------------------------------------------------------
Transaction::~Transaction() {

}

//--------------------------------------------------------------------------
// processTransaction() : process the desired transaction. 
//						  This method is merely a placeholder for the 
//						  inheriting classes.
// precondition : NONE
// postcondition : Process the desired transaction.
//--------------------------------------------------------------------------
void Transaction::processTransaction(char action, int id) {

}

//--------------------------------------------------------------------------
// Description: prints transaction
// Precondition: <iostream> included
// Postcondition: prints transaction to console
// is added in corresponding customer¡¯s history
//--------------------------------------------------------------------------
void Transaction::print(ostream & o) const {
}

ostream & operator<<(ostream &o, const Transaction &t) {
	t.print(o);
	return o;

}
