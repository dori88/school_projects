/*
//------------------------------------------------------------------------------
// bst.cpp
// Author:  Artiom Voronin, Jin Kim
// Last changed: 06/07/2017
// Purpose: A source file for BST class.
//
//          This source file for BST will write all the necessary
//	    function used to create a BST to hold movies declared on a header.
//------------------------------------------------------------------------------
*/

#include "bst.h"

//--------------------------BST Default Constructor-----------------------------
// Description
//
// BST default constructor:
// Precondition:
//		N/A
// Postcondition:
//		A default BST class object is made.
//------------------------------------------------------------------------------
BST::BST() {
	root = NULL; // assigns the root as NULL
}
// end of BST Default Constructor

//-------------------------------BST destructor---------------------------------
// Description
//
// BST destructor:
//		Destructor is called when program is 
//		terminated, to disallocate the memory.
//		
//		This destructor will call a 
//		deleteNode helper method to delete all
//		of the elements inside the object.
//
// Precondition:
//		deleteNode is a valid method.
// Postcondition:
//		BST memory is deallocated.
//------------------------------------------------------------------------------
BST::~BST() {
	delete root;
}

bool BST::isEmpty() const {
	return root == NULL;
}

// end of BST Destructor

//----------------------------BST insert method --------------------------------
// Description
//
// BST insert method:
//		This insert method will set the given Movie *item, and insert them
//      inside the BinaryTree where it is most appropriate.
//      
//      When the tree is empty, the Movie *item will be set as the root of
//      the BinTree. If is not empty, then it will find an appropriate spot
//      inside the BinTree by comparing the data inside the Movie.
// Precondition:
//		Movie *item is a valid Movie with appropriate data
// Postcondition:
//		NodeData is inserted to BinTree after being compared with all
//      available TreeNodes to find the appropriate location.
//------------------------------------------------------------------------------
void BST::insert(Movie *item) {
	// when the root == NULL (Tree is Empty) 
	// the ND*item will be inserted as the root.
	if (root == NULL) {
		root = new Node;
		root->movie = item;
		root->left = NULL;
		root->right = NULL;

		// If the Tree is not empty,
	}
	else {

		// cur traverse in the tree
		// until cur == NULL is found.
		Node *cur = root;

		// prev will take over cur after the loop
		// to help with inserting after cur == NULL
		Node *prev = NULL;

		// cur will travel in the BinTree until NULL
		while (cur != NULL) {
			prev = cur;

			// These three if statements below checks
			// if the item is already inserted to BinTree.
			// When such is the case, it will return the 
			// root and end the insert method.

			// checks if cur->right has the identical data
			if (cur->right) {
				if (*cur->right->movie == *item) {
					return;
				}
			}
			// checks if cur->left has the identical data
			if (cur->left) {
				if (*cur->left->movie == *item) {
					return;
				}
			}
			// checks if cur has the identical data
			if (*cur->movie == *item) {
				return;
			}

			// After checking for duplicate,
			// it will find the correct location to insert
			// by reaching toward the end of the BinTree while
			// finding the appropriate edges.
			// Eventually until cur reaches NULL
			if (*cur->movie < *item) {
				cur = cur->right;
			}
			else {
				cur = cur->left;
			}
		}

		// As cur is NULL, prev will be previous node of cur
		// which is the root node of where the item should be
		// inserted in.

		// if and else statement compares the item with the
		// prev->data to find the correct edge the new item
		// should be inserted to. Either left or right.
		if (*prev->movie < *item) {
			prev->right = new Node;
			prev->right->movie = item;
			prev->right->left = NULL;
			prev->right->right = NULL;
		}
		else {
			prev->left = new Node;
			prev->left->movie = item;
			prev->left->left = NULL;
			prev->left->right = NULL;

		}
	}
}
// end of insert

//-------------------------BST displaySideways method --------------------------
// Description
//
// BST displaySideways method:
//      This is a provided method used to print the store sideways
//      in a shape of a Binary Tree.
//
//      This method calls for sideways helper method
//      to print the tree.
// Precondition:
//		sideways() method is working as intended
//      root is a valid node from BST
// Postcondition:
//		calls sideways() to print the BST
//------------------------------------------------------------------------------
void BST::displaySideways() const {
	sideways(root, 0);
}

// end of displaySideways

//----------------------------BST retrieve method ------------------------------
// Description
//
// BST retrieve method:
//      Checks the BST for movie &findingNode using a retrieveHelper method
//      When the right movie is found, it uses a Movie *&foundMovie to record
//      the location of the movie found.
// Precondition:
//		N/A
// Postcondition:
//		N/A
//------------------------------------------------------------------------------
bool BST::find(const Movie &findingMovie, Movie *&foundMovie) {
	// checks if the BinTree is empty, in such case 
	// this method returns false as there are no Node to find
	if (root == NULL) return false;

	bool found = false;

	// calls retrieveHelper to help with finding the ND &findingNode.
	retrieveHelper(root, findingMovie, foundMovie, found);

	return found;
}
// end of find

//-----------------------------BST sideways method -----------------------------
// Description
//
// BST sideways method:
//      A recursive method that will record the depth of the
//      tree Node, then indent by however many spaces are there by their level.
// Precondition:
//		Node current is a valid Node
// Postcondition:
//		N/A
//------------------------------------------------------------------------------
void BST::sideways(Node* current, int level) const {
	if (current != NULL) {
		level++;
		sideways(current->right, level);

		// indent for readability, 4 spaces per depth level
		for (int i = level; i >= 0; i--) {
			cout << "    ";
		}

		cout << *current->movie << endl;        // display information of object
		sideways(current->left, level);
	}
}
// end of sideways

//---------------------------BST printHelper method ----------------------------
// Description
//
// BST printHelper method:
//      helper method for printing the BST to an ostream.
//      simply, as ostream &o is passed by reference,
//      this method will traverse the BST in a recursion manner,
//      and insert the data to the ostream &o.
// Precondition:
//		<ostream> is included.
//      Node *cur is a valid Node object
// Postcondition:
//		all BST elements are inserted to ostream o for printing.
//------------------------------------------------------------------------------
void BST::printHelper(ostream &o, Node *cur) const {
	if (cur == NULL) return;
	printHelper(o, cur->left);
	// case for classical 
	if (cur->movie->getType() == 'C')
	{
		o << cur->movie->getType() << ",   " << 
			cur->movie->getStock() << ",   " << cur->movie->getDirName()
			<< ",   " << cur->movie->getTitle() << ",   " 
			<< cur->movie->getActorAndRelease()<< endl;

	}
	else
	{
		o << cur->movie->getType() << ",   " << cur->movie->getStock() 
			<< ",   " << cur->movie->getDirName()
			<< ",   " << cur->movie->getTitle() << ",   " 
			<< cur->movie->getReleaseYear() << endl;
	}

	
	printHelper(o, cur->right);
}
// end of printHelper

//--------------------------BST retrieveHelper method --------------------------
// Description
//
// BST retrieveHelper method:
//      Helper method for retrieve method. 
//
//      This method will run a recursive, with constantly moving the
//      NodeData findingMovie and foundMovie, until foundMovie is found in 
//      the BST.
//
//      Once found, foundMovie will record the addres where findingMovie was
//      found in the BST before ending the recursion.
// Precondition:
//		findingMovie is set as an empty, garbage Movie
// Postcondition:
//		if foundMovie is found, foundMovie records the address of where
//      the Movie was found.
//------------------------------------------------------------------------------
void BST::retrieveHelper(Node *cur, const Movie &findingMovie,
	Movie*& foundMovie, bool& found) const {
	if (cur == NULL) return;
	if (*cur->movie == findingMovie || cur->movie->getActorAndRelease() 
		== findingMovie.getActorAndRelease()) {
		foundMovie = cur->movie;
		found = true;
		return;
	}
	else {
		retrieveHelper(cur->left, findingMovie, foundMovie, found);
		retrieveHelper(cur->right, findingMovie, foundMovie, found);
	}
}
// end of retrieveHelper

//---------------------------BST operator<< method -----------------------------
// Description
//
// BST operator<< method:
//      operator<< method that overloads the existing operator<<.
//      When << is used, this method is called.
//
//      Because it will print the BST object, it will always
//      start at the root, and with the root and ostream output ready, it 
//      uses a helper method printHelper to print the object.
//      ostream output is passed to the method with pass by reference,
//      so after printHelper method is completed, this operator<< will return
//      the output.
// Precondition:
//		s is a valid BST object.
// Postcondition:
//		printHelper is called, and ostream is returned for printing.
//------------------------------------------------------------------------------
ostream & operator<<(ostream &output, const BST &s) {
	s.printHelper(output, s.root);
	output << endl;
	return output;
}
// end of operator<<