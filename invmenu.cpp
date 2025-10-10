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

#include "menuhelpers.h"
#include "invmenu.h"
#include "bookinfo.h"
#include <iostream>
#include <string>
#include <limits>
using namespace std;


// Print menu, read input (user types), then overwrite the prompt line so right '*' aligns.
// Resulting choice returned in 'choice'.
void printInvMenu(string &invChoice)
{
    printBorder();
    printEmptyLine();
    printCenteredLine("Serendipity Booksellers");
    printCenteredLine("Inventory Database");
    printEmptyLine();

    // options
    printLeftLine(PROMPT_START_LENGTH, "1. Look Up a Book");
    printLeftLine(PROMPT_START_LENGTH, "2. Add a Book");
    printLeftLine(PROMPT_START_LENGTH, "3. Edit a Book's Record");
    printLeftLine(PROMPT_START_LENGTH, "4. Delete a Book");
 	 printLeftLine(PROMPT_START_LENGTH, "5. Return to the Main Menu");
    printEmptyLine();

    // build left portion of the prompt (indent + text)
    string prompt = "Enter Your Choice: ";
    string leftPart = string(PROMPT_START_LENGTH, ' ') + prompt;

    // Print the prompt (no newline) and flush so the user types on the same line.
    cout << "*" << leftPart << flush;

    // Read the user's line (skip leading whitespace/newline)
    getline(cin >> ws, invChoice);

    // Move the cursor up one line and to the start of that line, then rewrite the entire prompt line
    // This overwrites the previously-echoed input line so the right '*' can be placed in the correct column.
    cout << "\033[A\r";

    // Make sure the displayed input doesn't overflow the inner width
    int maxInputLen = INNER_WIDTH - (int)leftPart.length();
    if (maxInputLen < 0) maxInputLen = 0;
    string displayChoice = invChoice.substr(0, maxInputLen);

    int used = (int)leftPart.length() + (int)displayChoice.length();
    int spaces = INNER_WIDTH - used;
    if (spaces < 0) spaces = 0;

    cout << "*" << leftPart << displayChoice << string(spaces, ' ') << "*" << '\n';

    // "You selected" line inside the same box
    string selectedLine = "You selected: " + invChoice;
    string leftSel = string(PROMPT_START_LENGTH, ' ') + selectedLine;
    int usedSel = (int)leftSel.length();
    int spacesSel = INNER_WIDTH - usedSel;
    if (spacesSel < 0) {
        // truncate if too long
        int allowed = INNER_WIDTH - PROMPT_START_LENGTH;
        if (allowed < 0) allowed = 0;
        leftSel = string(PROMPT_START_LENGTH, ' ') + selectedLine.substr(0, allowed);
        spacesSel = INNER_WIDTH - (int)leftSel.length();
    }
    cout << "*" << leftSel << string(spacesSel, ' ') << "*" << '\n';

    printBorder();
}

void printAddBookMenu(string &addBookChoice)
	{
	 const int menuSize = 10;
    string addBookArr[menuSize] = {"Return to Inventory Menu", "Enter Book Title", "Enter ISBN", "Enter Author", "Enter Publisher", "Enter Date Added (mm/dd/yyyy)",
										    "Enter Quantity on Hand", "Enter Wholesale Cost", "Enter Retail Price", "Save Book to Database"};
    printBorder();
    printEmptyLine();
    printCenteredLine("Serendipity Booksellers");
    printCenteredLine("Add Book");
    printEmptyLine();

    for(int i = 1; i < menuSize; i++) //loop through index 1-9
		{
			printLeftLineArray(PROMPT_START_LENGTH, addBookArr[i], i);
		}
	 printLeftLineArray(PROMPT_START_LENGTH, addBookArr[0], 0);
    printEmptyLine();

    // build left portion of the prompt (indent + text)
    string prompt = "Enter Your Choice: ";
    string leftPart = string(PROMPT_START_LENGTH, ' ') + prompt;

    // Print the prompt (no newline) and flush so the user types on the same line.
    cout << "*" << leftPart << flush;

    // Read the user's line (skip leading whitespace/newline)
    getline(cin >> ws, addBookChoice);

    // Move the cursor up one line and to the start of that line, then rewrite the entire prompt line
    // This overwrites the previously-echoed input line so the right '*' can be placed in the correct column.
    cout << "\033[A\r";

    // Make sure the displayed input doesn't overflow the inner width
    int maxInputLen = INNER_WIDTH - (int)leftPart.length();
    if (maxInputLen < 0) maxInputLen = 0;
    string displayChoice = addBookChoice.substr(0, maxInputLen);

    int used = (int)leftPart.length() + (int)displayChoice.length();
    int spaces = INNER_WIDTH - used;
    if (spaces < 0) spaces = 0;

    cout << "*" << leftPart << displayChoice << string(spaces, ' ') << "*" << '\n';

    // "You selected" line inside the same box
    string selectedLine = "You selected: " + addBookChoice;
    string leftSel = string(PROMPT_START_LENGTH, ' ') + selectedLine;
    int usedSel = (int)leftSel.length();
    int spacesSel = INNER_WIDTH - usedSel;
    if (spacesSel < 0) {
        // truncate if too long
        int allowed = INNER_WIDTH - PROMPT_START_LENGTH;
        if (allowed < 0) allowed = 0;
        leftSel = string(PROMPT_START_LENGTH, ' ') + selectedLine.substr(0, allowed);
        spacesSel = INNER_WIDTH - (int)leftSel.length();
    }
    cout << "*" << leftSel << string(spacesSel, ' ') << "*" << '\n';

    printBorder();
}

void invMenu()
{
    string invChoice;
    do {
        clearScreen();
        printInvMenu(invChoice);

        if (invChoice == "1")
            lookUpBook();
        else if (invChoice == "2")
            addBook();
        else if (invChoice == "3")
            editBook();
        else if (invChoice == "4")
            deleteBook();
        else if (invChoice == "5")
				cout << "Returning...";
		  else
            cout << "Invalid choice, please select 1–5.\n";

        if (invChoice != "5") {
            cout << "\nPress Enter to continue...";
            // wait for Enter
            cin.get();
        }

    } while (invChoice != "5");

}

// Stub function definitions
void lookUpBook()
{
	cout << "Look Up Book gooes here..." << endl;
}

void addBook()
{
	string addBookChoice;
	bookInfo newBook;

	do {
        clearScreen();
        printAddBookMenu(addBookChoice);

        if (addBookChoice == "1"){

    			string title;
   			cout << "Enter book title: ";
    			cin >> title;

    			newBook.setBookTitle(title);
		  }
        else if (addBookChoice == "2")
            cout << "Enter ISBN: ";
        else if (addBookChoice == "3")
            cout << "Enter Author: ";
        else if (addBookChoice == "4")
            cout << "Enter Publisher: ";
        else if (addBookChoice == "5")
				cout << "Enter Date Added (mm/dd/yyyy): ";
		  else if (addBookChoice == "6")
				cout << "Enter Quantity on Hand: ";
		  else if (addBookChoice == "7")
				cout << "Enter Wholesale Cost: ";
		  else if (addBookChoice == "8")
				cout << "Enter Retail Price: ";
		  else if (addBookChoice == "9")
				cout << "Saving...";
		  else if (addBookChoice == "0")
				cout << "Returning...";
		  else
            cout << "Invalid choice, please select 0–9.\n";

        if (addBookChoice != "0") {
            cout << "\nPress Enter to continue...";
            // wait for Enter
            cin.get();
        }
    } while (addBookChoice != "0");
}

void editBook()
{
    cout << "Edit Book goes here..." << endl;
}

void deleteBook()
{
    cout << "Delete Book goes here..." << endl;
}
