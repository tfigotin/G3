/****************************************************************
 * CS1B - G2 : Serendipity Menus (Navigatin & Stubs)            *
 * Partner A : Tamar Figotin (A00328312) - role: driver         *
 * Partner B : Luke Leibee   (1248406) - role: function         *
 * Due Date  : 2025-09-07                                       *
 * Purpose   : Practice making a multi-file C++ program with    *
 *					menus, input checks, and a simple cashier slip.  *
 * Build     : g++ -std=c++20 mainmenu.cpp cashier.cpp          *
 *					invmenu.cpp reports.cpp -o serendipity &&        *
 *					./serendipity                                    *
 ****************************************************************/

//#include "serendipity.h"  ?
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

//clear screen function
void clearScreen()
{
	cout << "\033[H\033[2J" << endl;
}

void printMainMenu()
{
	const int COLUMN_WIDTH 	  		 = 50;
	const int PROMPT_START_LENGTH  = 9;
	const int COLUMN_SUBTRACT 		 = 3;
	const string PROMPT_START 		 = "*       ";

	cout << string(COLUMN_WIDTH, '*') << endl; //Print top border
	cout << "* " << string(COLUMN_WIDTH - COLUMN_SUBTRACT, ' ') << "*" <<  endl; //Print empty line

	//Print Serendipity Booksellers and Main Menu
	cout << "* " << setw(COLUMN_WIDTH/2 + 6) << "Serendipity Booksellers"   << setw(COLUMN_WIDTH/2 - 8) << "*" << endl;
	cout << "* " << setw(COLUMN_WIDTH/2 - 3) << "Main Menu" 	<< setw(COLUMN_WIDTH/2 + 1) << "*" << endl;

	cout << "* " << string(COLUMN_WIDTH - COLUMN_SUBTRACT, ' ') << "*" <<  endl; //Print empty line

	//Print Prompts
	cout << left;
	cout << PROMPT_START << setw(COLUMN_WIDTH - PROMPT_START_LENGTH) << "1. Cashier Module" 			    << "*" << endl;
	cout << PROMPT_START << setw(COLUMN_WIDTH - PROMPT_START_LENGTH) << "2. Inventory Database Module"  << "*" << endl;
	cout << PROMPT_START << setw(COLUMN_WIDTH - PROMPT_START_LENGTH) << "3. Report Module" 			    << "*" << endl;
	cout << PROMPT_START << setw(COLUMN_WIDTH - PROMPT_START_LENGTH) << "4. Exit" 						    << "*" << endl;

	cout << "* " <<  string(COLUMN_WIDTH - COLUMN_SUBTRACT, ' ') << "*" << endl; //Print empty line
//	cout << PROMPT_START << setw(COLUMN_WIDTH - PROMPT_START_LENGTH) << "Enter Your Choice: " << setw(COLUMN_WIDTH) << "*" << endl;

	cout << "* " <<  string(COLUMN_WIDTH - COLUMN_SUBTRACT, ' ') << "*" << endl; //Print empty line
	cout << string(COLUMN_WIDTH, '*') << endl; //Print bottom border
	cout << right;
}

int main()
{
	char choice {};

	do
	{
		clearScreen();
		printMainMenu();

		//Input
	//		cout << "\033[3A";  //moves cursor up X amount of rows
	//	cout << "\033[26C"; //moves cursor to the right X amount of columns
	//	cin.get(choice);
	//	cin.ignore(numeric_limits<streamsize>::max(), '\n');  // flush leftover '\n'
		cout << "Enter Your Choice: ";
		cin >> choice;

      switch(choice)
      {
			case '1':
				//cashier();
				break;
			case '2':
				//invmenu();
				break;
			case '3':
				//reports();
				break;
			case '4':
				cout << endl << "You chose option 4" << endl;
				break;
			default:
				cout << "*** ->" << choice << "<- *** is Invalid!" << endl;
				cout << "Please enter a valid choice 1-4" << endl;
				break;
			cin.clear();

	//		cin.ignore();
	//		cin.ignore();
		}

	}while(choice != '4');

	return 0;
}


