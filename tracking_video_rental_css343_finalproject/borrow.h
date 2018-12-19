/*
//------------------------------------------------------------------------------
// borrow.h
// Authors: Jin Kim , Artiom Voronin
// Last modified: 6/7/17
// Purpose: Contains the class definition for borrow.h
//------------------------------------------------------------------------------
*/
#pragma once
#include <iostream>
#include "transaction.h"
#include "store.h"

class Borrow : public Transaction {

	// overloading operator
	friend ostream& operator<<(ostream &, const Borrow &);

private:

	string movieTitle;

public:

	//--------------------------------------------------------------------------
	// Borrow(): creates default borrow constructor
	// Precondition: N/A
	// Postcondition: A borrow transaction is created
	//--------------------------------------------------------------------------
	Borrow();

	//--------------------------------------------------------------------------
	// Borrow(movie);
	// Precodition: A Movie object is passed in
	// Postcondition: A borrow transaction is created
	// Movie is movie from parameter
	//--------------------------------------------------------------------------
	Borrow(Movie* m);

	//--------------------------------------------------------------------------
	// ~Borrow(); Borrow destructor
	// Precondition: N/A
	// Postcondition: Borrow object is destroyed
	//--------------------------------------------------------------------------
	virtual ~Borrow();

	//--------------------------------------------------------------------------
	// Description: execute borrow function
	// Precondition: Movie is a valid movie file
	// Postcondition: stock in store -1, a new transaction
	// is added in corresponding customer¡¯s history
	//--------------------------------------------------------------------------
	virtual void processTransaction(Movie *);

	//--------------------------------------------------------------------------
	// Description: prints borrow transaction
	// Precondition: <iostream> included
	// Postcondition: prints borrow transaction to console
	// is added in corresponding customer¡¯s history
	//--------------------------------------------------------------------------
	virtual void print(ostream& o) const;

};//End Borrow class
