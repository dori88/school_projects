/*
//------------------------------------------------------------------------------
// borrow.cpp
// Authors: Jin Kim , Artiom Voronin
// Last modified: 6/7/17
// Purpose: Contains the implementation for borrow.h
//------------------------------------------------------------------------------
*/
#include "borrow.h"

//--------------------------------------------------------------------------
// Borrow(): creates default borrow constructor
// Precondition: N/A
// Postcondition: A borrow transaction is created
//--------------------------------------------------------------------------
Borrow::Borrow() {
}

//--------------------------------------------------------------------------
// Borrow(movie);
// Precodition: A Movie object is passed in
// Postcondition: A borrow transaction is created
// Movie is movie from parameter
//--------------------------------------------------------------------------
Borrow::Borrow(Movie* m) {
	movieTitle = m->getTitle();
	processTransaction(m);
}

//--------------------------------------------------------------------------
// ~Borrow(); Borrow destructor
// Precondition: N/A
// Postcondition: Borrow object is destroyed
//--------------------------------------------------------------------------
Borrow::~Borrow() {
}

//--------------------------------------------------------------------------
// Description: execute borrow function
// Precondition: Movie is a valid movie file
// Postcondition: stock in store -1, a new transaction
// is added in corresponding customer¡¯s history
//--------------------------------------------------------------------------
void Borrow::processTransaction(Movie *m) {
	if (m->getReleaseYear() != 0) {
		int stockTmp = m->getStock();
		if (stockTmp > 0) {
			m->setStock(stockTmp - 1);

		}
		else cout << m->getTitle() << " is out of stock!";
	}
}
//--------------------------------------------------------------------------
// Description: prints borrow transaction
// Precondition: <iostream> included
// Postcondition: prints borrow transaction to console
// is added in corresponding customer¡¯s history
//--------------------------------------------------------------------------
void Borrow::print(ostream & o) const {
	o << "Borrowed: " << movieTitle;
}

// overload << operator
ostream & operator<<(ostream &o, const Borrow &t) {
	t.print(o);
	return o;
}
