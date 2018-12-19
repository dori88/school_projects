/*
//------------------------------------------------------------------------------
// movief.h
// Authors:       Jin Kim , Artiom Voronin
// Last modified: 6/7/17
// Purpose:       This class acts as a factory method class that helps build
//		  the appropriate constructors for the movie classes
//------------------------------------------------------------------------------
*/
#pragma once
#include "movie.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"
#include <string>
#include <sstream>

//----------------------------------MovieF Class--------------------------------
// Description
// 
//
// Precondition :   bst.h , hashtable.h are included
//		    <fstream> is included
// Post-condition : creates a hashtable for customers, 
//		    three BST trees used to store movies,
//		    executes the program by reading in the files.
//		   
//------------------------------------------------------------------------------
class MovieF {

public:

	//--------------------------------MovieF------------------------------------
	// MovieF :	   default constructor for MovieF class
	// precondition :  NONE
	// postcondition : creates a movief object
	//--------------------------------------------------------------------------
	MovieF();

	//--------------------------------~MovieF-----------------------------------
	// ~MovieF :	   destructor for MovieF class
	// precondition :  NONE
	// postcondition : deallocates the movief object
	//--------------------------------------------------------------------------
	~MovieF();

	//--------------------------------makeMovie---------------------------------
	// makeMovie :	   reads in a string and calls the appropriate constructors
	// precondition :  line contains > 0 number of characters
	// postcondition : returns a movie pointer
	//--------------------------------------------------------------------------
	static Movie* makeMovie(const string &line);

};