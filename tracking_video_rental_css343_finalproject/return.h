/*
//------------------------------------------------------------------------------
// return.h
// Authors: Jin Kim , Artiom Voronin
// Last modified: 6/7/17
// Purpose: Contains the class definition for return.h
//------------------------------------------------------------------------------
*/
#pragma once
#include <iostream>
#include "transaction.h"
#include "store.h"

class Return : public Transaction {

	// overloading operator
	friend ostream& operator<<(ostream &, const Return &);

private:

	string movieTitle;

public:

	//--------------------------------------------------------------------------
	// Borrow(): creates default Return constructor
	// Precondition: N/A
	// Postcondition: A Return transaction is created
	//--------------------------------------------------------------------------
	Return();

	//--------------------------------------------------------------------------
	// Return(movie);
	// Precodition: A Movie object is passed in
	// Postcondition: A Return transaction is created
	// Movie is movie from parameter
	//--------------------------------------------------------------------------
	Return(Movie* m);

	//--------------------------------------------------------------------------
	// ~Borrow(); Return destructor
	// Precondition: N/A
	// Postcondition: Return object is destroyed
	//--------------------------------------------------------------------------
	virtual ~Return();

	//--------------------------------------------------------------------------
	// Description: execute Return function
	// Precondition: Movie is a valid movie file
	// Postcondition: stock in store +1, a new transaction
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

};//End Return class
