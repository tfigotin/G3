/****************************************************************
 * CS1B - G2 : Serendipity Menus (Navigatin & Stubs)            *
 * Partner A : Tamar Figotin (A00328312) - role: driver         *
 * Partner B : Luke Leibee   (1248406) - role: function         *
 * Due Date  : 2025-09-07                                       *
 * Purpose   : Practice making a multi-file C++ program with    *
 *					menus, input checks, and a simple cashier slip.  *
 * Build     : g++ -std=c++20 mainmenu.cpp cashier.cpp          *
					invmenu.cpp reports.cpp -o serendipity &&        *
					./serendipity                                    *
 ****************************************************************/

#include "serendipity.h"

int main()
{
	char choice {};
	string discard;

	do
	{
		cout << "\033[H\033[2J" << endl; //Clear the screen

		printMainMenu();

		cin.get(choice);

		switch(choice)
		{
			case '1':
				cashier();
				break;
			case '2':
				invmenu();
				break;
			case '3':
				reports();
				break;
			case '4':
				cout << "You chose option 4" << endl;
				break;
			default:
				cout << "*** ->" << choice << "<- *** is Invalid" << endl;
				cout << "Please enter a valid choice 1-4" << endl;
				break;
			cin.clear();

			cin.ignore();
			cin.ignore();
	}while(choice != 4);


}


