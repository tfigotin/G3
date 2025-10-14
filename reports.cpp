/****************************************************************
 * CS1B - G3 : Inventory Submenus                               *
 * Partner A : Tamar Figotin (A00328312) - role: driver         *
 * Partner B : Luke Leibee   (1248406) - role: function         *
 * Due Date  : 2025-09-07                                       *
 * Purpose   : Practice making a multi-file C++ program with    *
 *             menus, input checks, and a simple cashier slip.  *
 * Build     : g++ -std=c++17 -Wall -Wextra -o main mainmenu.cpp*
 *             bookinfo.cpp cashier.cpp invmenu.cpp             *
 *             lookUpBook.cpp menuhelpers.cpp reports.cpp       *
 ****************************************************************/
#include "menuhelpers.h"
#include "reports.h"
#include <iostream>
#include <string>
#include <limits>
using namespace std;


// Print menu, read input (user types), then overwrite the prompt line so right '*' aligns.
// Resulting choice returned in 'choice'.
void printRepMenu(string &repChoice)
{
    printBorder();
    printEmptyLine();
    printCenteredLine("Serendipity Booksellers");
    printCenteredLine("Reports");
    printEmptyLine();

    // options
    printLeftLine(PROMPT_START_LENGTH, "1. Inventory Listing");
    printLeftLine(PROMPT_START_LENGTH, "2. Inventory Wholesale Value");
    printLeftLine(PROMPT_START_LENGTH, "3. Inventory Retail Value");
    printLeftLine(PROMPT_START_LENGTH, "4. Listing by Quantity");
 	 printLeftLine(PROMPT_START_LENGTH, "5. Listing by Cost");
	 printLeftLine(PROMPT_START_LENGTH, "6. Listing by Age");
	 printLeftLine(PROMPT_START_LENGTH, "7. Return to Main Menu");
    printEmptyLine();

    // build left portion of the prompt (indent + text)
    string prompt = "Enter Your Choice: ";
    string leftPart = string(PROMPT_START_LENGTH, ' ') + prompt;

    // Print the prompt (no newline) and flush so the user types on the same line.
    cout << "*" << leftPart << flush;

    // Read the user's line (skip leading whitespace/newline)
    getline(cin >> ws, repChoice);

    // Move the cursor up one line and to the start of that line, then rewrite the entire prompt line
    // This overwrites the previously-echoed input line so the right '*' can be placed in the correct column.
    cout << "\033[A\r";

    // Make sure the displayed input doesn't overflow the inner width
    int maxInputLen = INNER_WIDTH - (int)leftPart.length();
    if (maxInputLen < 0) maxInputLen = 0;
    string displayChoice = repChoice.substr(0, maxInputLen);

    int used = (int)leftPart.length() + (int)displayChoice.length();
    int spaces = INNER_WIDTH - used;
    if (spaces < 0) spaces = 0;

    cout << "*" << leftPart << displayChoice << string(spaces, ' ') << "*" << '\n';

    // "You selected" line inside the same box
    string selectedLine = "You selected: " + repChoice;
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

void repMenu()
{
    string repChoice;
    do {
        clearScreen();
        printRepMenu(repChoice);

        if (repChoice == "1")
            invListing();
        else if (repChoice == "2")
            invWholesale();
        else if (repChoice == "3")
            invRetail();
        else if (repChoice == "4")
            quantList();
		  else if (repChoice == "5")
            costList();
		  else if (repChoice == "6")
            ageList();
        else if (repChoice == "7")
				cout << "Returning...";
		  else
            cout << "Invalid choice, please select 1–7.\n";

        if (repChoice != "7") {
            cout << "\nPress Enter to continue...";
            // wait for Enter
            cin.get();
        }

    } while (repChoice != "7");

}

// Stub function definitions
void invListing()
{
	cout << "Inventory Listing goes here..." << endl;
}

void invWholesale()
{
	cout << "Inventory Wholesale goes here..." << endl;
}

void invRetail()
{
    cout << "Inventory Retail goes here..." << endl;
}

void quantList()
{
    cout << "Listing by Quantity goes here..." << endl;
}

void costList()
{
    cout << "Listing by Cost goes here..." << endl;
}

void ageList()
{
    cout << "Listing by Age goes here..." << endl;
}
