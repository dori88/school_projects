/*
//------------------------------------------------------------------------------
// bst.h
// Author:  Artiom Voronin, Jin Kim
// Last changed: 06/07/2017
// Purpose: A header file for BST class.
//
//          This header file for BST will declare all the necessary
//	    function used to create a BST to hold movies.
//------------------------------------------------------------------------------
*/

#include <string>
#include <iostream>
#include <fstream>
#include "movie.h"
#include "classic.h"
using namespace std;

//----------------------------------BST Class-----------------------------------
// Description
//
// BST :
//
// Precondition : movie.h is included
//		  <iostream>, <fstream>, and <string> is included
// Post-condition : Creates BST class object,
//		    and declares all the necessary methods.
//------------------------------------------------------------------------------

class BST {

	// operator<< to be used specifically for BinTree class object
	friend ostream& operator<<(ostream &output, const BST& s);

public:

	//--------------------------------------------------------------------------
	BST();	  // default constructor
	~BST();	  // destructor
	bool isEmpty() const;	    // true if tree is empty, otherwise false
	void insert(Movie *);	    // inserts a new F movie into a tree
	void displaySideways() const;	// displays the tree sideways
							// retrieve checks if the movie is inside the BST.
	bool find(const Movie &, Movie *&);

private:
	struct Node {
		Movie* movie;			// pointer to Movie object
		Node* left;				// left subtree pointer
		Node* right;			// right subtree pointer
	};
	Node* root;

	//--------------------------------------------------------------------------
	// provided, helper for displaySideways()
	void sideways(Node*, int) const;
	// helper method for operator <<
	void printHelper(ostream&, Node*) const;
	// helper method for retrieve
	void retrieveHelper(Node*, const Movie&, Movie *&, bool&) const;


};
// end of BST class