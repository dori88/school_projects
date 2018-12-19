/*
//------------------------------------------------------------------------------
// store.cpp
// Authors: Jin Kim , Artiom Voronin
// Last modified: 6/7/17
// Purpose: Contains the implementation for store.h
//------------------------------------------------------------------------------
*/
#include "store.h"

//--------------------------------Store()--------------------------------------
// Store() :	   default constructor for Store class
// precondition :  NONE
// postcondition : creates a store object
//------------------------------------------------------------------------------
Store::Store() {};

//-------------------------------~Store()--------------------------------------
// ~Store() : 	   destructor for store class
// precondition :  NONE
// postcondition : deallocates the store object 
//------------------------------------------------------------------------------
Store::~Store()
{
	// Deallocate movie inventory by calling
	// a destructor on three BST pointers

	// Deallocate the customerBase by calling
	// a destructor on the hashtable
}

//-------------------------------proceed----------------------------------------
// proceed() : 	   reads in the file with commands and executes them
// precondition :  commands is a txt file 
// postcondition : executes the commands necessary to run the overall program
//------------------------------------------------------------------------------
void Store::proceed(ifstream & commands)
{
	string line;

	while (!commands.eof())
	{
		getline(commands, line);
		// Calls the factory method class
		if (line[0] == 'I')
		{
			cout << moviesF << endl;
			cout << moviesD << endl;
			cout << moviesC << endl;
		}
		else if (line[0] == 'H')
		{
			//cout << "Calling HIstory" << endl;

			string type;
			string ID;
			stringstream s;
			s << line;
			s >> type;
			s >> ID;
			//customer's id
			int id = atoi(ID.c_str());
			Customer *tmp;
			tmp = customerBase.find(id);
			if (tmp->getLogCount() == 0)
			{
				cout << "No rental history for : " << tmp->getFirstName() << " " 
				<< tmp->getLastName() << endl;
			}
			else
			{
				tmp->getCustLog();
			}


		}
		else if (line[0] == 'B')
		{
			char action;
			string ID; // will get converted to int
			char media; // must be DVD
			char genre; // must be D || F || C
			string title; // movie title

			stringstream s;
			s << line;

			s >> action;
			s >> ID;
			int id = atoi(ID.c_str()); // convert to int

			Customer *tmpC = NULL;
			tmpC= customerBase.find(id);

			if (tmpC == NULL) {
				cout << "Customer with id: " << id << " doesn't exist" << endl;
				continue;
			}
			s >> media;
			//cout << media << endl;
			if (media != 'D')
				cout << "Invalid media type : " << media << endl;

			if (media == 'D')
			{
				s >> genre;
				//  comedy
				if (genre == 'F')
				{
					// obtain title
					getline(s, title, ',');
					//delete extra space at the beginnig
					title.erase(title.begin());
					// obtain release year
					string year;
					getline(s, year, ',');
					year.erase(year.begin());
					int releaseYear;
					releaseYear = atoi(year.c_str());
					
					Movie temp;
					temp.setTitle(title);
					temp.setReleaseYear(releaseYear);

					// check if the movie exists
					Movie *found = new Movie;
					bool flag = moviesF.find(temp, found);

					if (!flag)
					{
						cout << "We don't carry " << title << endl;
					}
					else
					{
						Borrow *b = new Borrow(found);
						tmpC->setCustLog(b);
					}
					
				}
				// drama
				else if (genre == 'D')
				{
					string director;
					// obtain director
					getline(s, director, ',');
					// delete extra space at the beginnig
					director.erase(director.begin());
					// obtain title
					getline(s, title, ',');
					// delete extra space at the beginnig
					title.erase(title.begin());

					Movie temp;
					temp.setTitle(title);
					temp.setDirName(director);

					// check if the movie exists
					Movie *found = new Movie;
					bool flag = moviesD.find(temp, found);

					if (!flag)
					{
						cout << "We don't carry " << title << endl;
					}
					else
					{
						Borrow *b = new Borrow(found);
						tmpC->setCustLog(b);
					}
				}
				// classic
				else if (genre == 'C')
				{
					string space;
					string monthS;
					string yearS;
					string actorF;
					string actorL;
					string actorAndRelease;
					
					getline(s, space, ' ');
					getline(s, monthS, ' ');
					getline(s, yearS, ' ');
					getline(s, actorF, ' ');
					getline(s, actorL, ' ');

					actorAndRelease = actorF + " " + actorL + " " 
						+ monthS + " " + yearS;

					Classic temp;
					temp.setActorAndRelease(actorAndRelease);

					// check if the movie exists
					Movie *found = new Movie;
					bool flag = moviesC.find(temp, found);

					if (!flag)
					{
						cout << "We don't carry " 
							<< actorAndRelease << endl;
					}
					else
					{
						Borrow *b = new Borrow(found);
						tmpC->setCustLog(b);
					}
				}
				else
				{
					cout << "Invalid movie genre: " 
						<< genre << endl;
				}
			}
		}
		else if (line[0] == 'R')
		{
			char action;
			string ID; // will get converted to int
			char media; // must be DVD
			char genre; // must be D || F || C
			string title; // movie title

			stringstream s;
			s << line;
			s >> action;
			s >> ID;
			int id = atoi(ID.c_str()); // convert to int

			Customer *tmpC = NULL;
			tmpC = customerBase.find(id);

			if (tmpC == NULL)
				cout << "Customer with id: " << id 
				<< " doesn't exist" << endl;

			s >> media;
			if (media != 'D')
				cout << "Invalid media type : " << media << endl;

			if (media == 'D')
			{
				s >> genre;
				//  comedy
				if (genre == 'F')
				{
					// obtain title
					getline(s, title, ',');
					// delete extra space at the beginnig
					title.erase(title.begin());
											   // obtain release year
					string year;
					getline(s, year, ',');
					year.erase(year.begin());
					int releaseYear;
					releaseYear = atoi(year.c_str());

					Movie temp;
					temp.setTitle(title);
					temp.setReleaseYear(releaseYear);

					// check if the movie exists
					Movie *found = new Movie;
					bool flag = moviesF.find(temp, found);

					if (!flag)
					{
						cout << "We don't carry " << title << endl;
					}
					else
					{
						Return *r = new Return(found);
						tmpC->setCustLog(r);
					}

				}
				// drama
				else if (genre == 'D')
				{
					string director;
					// obtain director
					getline(s, director, ',');
					// delete extra space at the beginnig
					director.erase(director.begin());
													 // obtain title
					getline(s, title, ',');
					// delete extra space at the beginnig
					title.erase(title.begin());

					cout << director << " " << title << endl;
					Movie temp;
					temp.setTitle(title);
					temp.setDirName(director);

					// check if the movie exists
					Movie *found = new Movie;
					bool flag = moviesD.find(temp, found);

					if (!flag)
					{
						cout << "We don't carry " << title << endl;
					}
					else
					{
						Return *r = new Return(found);
						tmpC->setCustLog(r);
					}
				}
				// classic
				else if (genre == 'C')
				{
					string space;
					string monthS;
					string yearS;
					string actorF;
					string actorL;
					string actorAndRelease;

					getline(s, space, ' ');
					getline(s, monthS, ' ');
					getline(s, yearS, ' ');
					getline(s, actorF, ' ');
					getline(s, actorL, ' ');

					actorAndRelease = actorF + " " + actorL + " " 
						+ monthS + " " + yearS;

					Classic temp;
					temp.setActorAndRelease(actorAndRelease);

					// check if the movie exists
					Movie *found = new Movie;
					bool flag = moviesC.find(temp, found);

					if (!flag)
					{
						cout << "We don't carry " << actorAndRelease << endl;
					}
					else
					{
						Return *r = new Return(found);
						tmpC->setCustLog(r);
					}
				}
				else
				{
					cout << "Invalid movie genre: " << genre << endl;
				}
			}
		}
		else
		{
			cout << "Invalid command type: " << line[0] << endl;
		}

	}
}

//-------------------------------buildInventory-------------------------------------
// buildInventory : reads in the file with movies and stores them in appropriate BST
// precondition :   movies is a txt file 
// postcondition :  inserts movies into appropriate genre BST
//----------------------------------------------------------------------------------
void Store::buildInventory(ifstream & movies)
{
	string line;
	while (!movies.eof())
	{
		getline(movies, line);
		// Calls the factory method class
		Movie *tempMovie = MovieF::makeMovie(line);
		// determines what genre
		switch (line[0])
		{
		case 'F':
			moviesF.insert(tempMovie);
			break;
		case 'D':
			moviesD.insert(tempMovie);
			break;
		case 'C':
			moviesC.insert(tempMovie);
			break;
		default:
			break;
		}
	}
}

//-------------------------------buildCustomerBase--------------------------------------
// buildCustomerBase : reads in the file with customers and stores them into a HashTable
// precondition :      customers is a txt file 
// postcondition :     inserts customers into a hashtable
//--------------------------------------------------------------------------------------
void Store::buildCustomerBase(ifstream & customers)
{
	Customer *customer;

	while (!customers.eof())
	{
		string ID, last, first;

		customers >> ID;
		customers >> last;
		customers >> first;

		// convert string to int
		int id = atoi(ID.c_str());
		// create a customer
		customer = new Customer(id, last, first);
		// insert the cusotmer into the hashtable
		customerBase.insert(customer);
	}
}
