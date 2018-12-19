/*
//------------------------------------------------------------------------------
// movief.cpp
// Authors:       Jin Kim , Artiom Voronin
// Last modified: 6/7/17
// Purpose:       Implementation file for MovieF class
//------------------------------------------------------------------------------
*/
#include "movief.h"

//--------------------------------MovieF----------------------------------------
// MovieF :	   default constructor for MovieF class
// precondition :  NONE
// postcondition : creates a movief object
//------------------------------------------------------------------------------
MovieF::MovieF() {}

//--------------------------------~MovieF--------------------------------------
// ~MovieF :	   destructor for MovieF class
// precondition :  NONE
// postcondition : deallocates the movief object
//------------------------------------------------------------------------------
MovieF::~MovieF() {}

//--------------------------------makeMovie--------------------------------------
// makeMovie :	   reads in a string and calls the appropriate constructors
// precondition :  line contains > 0 number of characters
// postcondition : returns a movie pointer
//------------------------------------------------------------------------------
Movie * MovieF::makeMovie(const string &line)
{
	Movie *temp = NULL;
	// depending on the first character of the string
	// determine which constructor to call
	switch (line[0])
	{
	case 'F':
		temp = (Movie*) new Comedy(line);
		break;
	case 'D':
		temp = (Movie*) new Drama(line);
		break;
	case 'C':
		temp = (Movie*) new Classic(line);
		break;
	default:
		break;
	}

	return temp;
}