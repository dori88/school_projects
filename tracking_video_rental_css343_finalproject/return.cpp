/*
//------------------------------------------------------------------------------
// return.cpp
// Authors: Jin Kim , Artiom Voronin
// Last modified: 6/7/17
// Purpose: Contains the implementation for return.h
//------------------------------------------------------------------------------
*/
#include "return.h"

//--------------------------------------------------------------------------
// Borrow(): creates default Return constructor
// Precondition: N/A
// Postcondition: A Return transaction is created
//--------------------------------------------------------------------------
Return::Return() {
}

//--------------------------------------------------------------------------
// Return(movie);
// Precodition: A Movie object is passed in
// Postcondition: A Return transaction is created
// Movie is movie from parameter
//--------------------------------------------------------------------------
Return::Return(Movie* m) {
	movieTitle = m->getTitle();
	processTransaction(m);
}

//--------------------------------------------------------------------------
// ~Borrow(); Return destructor
// Precondition: N/A
// Postcondition: Return object is destroyed
//--------------------------------------------------------------------------
Return::~Return() {
}

//--------------------------------------------------------------------------
// Description: execute Return function
// Precondition: Movie is a valid movie file
// Postcondition: stock in store +1, a new transaction
// is added in corresponding customer¡¯s history
//--------------------------------------------------------------------------
void Return::processTransaction(Movie *m) {
	if (m->getReleaseYear() != 0) {
		int stockTmp = m->getStock();
		m->setStock(stockTmp + 1);
	}
}

//--------------------------------------------------------------------------
// Description: prints borrow transaction
// Precondition: <iostream> included
// Postcondition: prints borrow transaction to console
// is added in corresponding customer¡¯s history
//--------------------------------------------------------------------------
void Return::print(ostream & o) const {
	o << "Returned: " << movieTitle;
}

//operator << overload
ostream & operator<<(ostream &o, const Return &t) {
	t.print(o);
	return o;
}
