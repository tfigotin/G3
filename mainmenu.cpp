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
#include <iostream>
#include <string>
#include <limits>
using namespace std;


// Print menu, read input (user types), then overwrite the prompt line so right '*' aligns.
// Resulting choice returned in 'choice'.
void printMainMenu(string &choice)
{
    printBorder();
    printEmptyLine();
    printCenteredLine("Serendipity Booksellers");
    printCenteredLine("Main Menu");
    printEmptyLine();

    // options
    printLeftLine(PROMPT_START_LENGTH, "1. Cashier Module");
    printLeftLine(PROMPT_START_LENGTH, "2. Inventory Database Module");
    printLeftLine(PROMPT_START_LENGTH, "3. Report Module");
    printLeftLine(PROMPT_START_LENGTH, "4. Exit");
    printEmptyLine();

    // build left portion of the prompt (indent + text)
    string prompt = "Enter Your Choice: ";
    string leftPart = string(PROMPT_START_LENGTH, ' ') + prompt;

    // Print the prompt (no newline) and flush so the user types on the same line.
    cout << "*" << leftPart << flush;

    // Read the user's line (skip leading whitespace/newline)
    getline(cin >> ws, choice);

    // Move the cursor up one line and to the start of that line, then rewrite the entire prompt line
    // This overwrites the previously-echoed input line so the right '*' can be placed in the correct column.
    cout << "\033[A\r";

    // Make sure the displayed input doesn't overflow the inner width
    int maxInputLen = INNER_WIDTH - (int)leftPart.length();
    if (maxInputLen < 0) maxInputLen = 0;
    string displayChoice = choice.substr(0, maxInputLen);

    int used = (int)leftPart.length() + (int)displayChoice.length();
    int spaces = INNER_WIDTH - used;
    if (spaces < 0) spaces = 0;

    cout << "*" << leftPart << displayChoice << string(spaces, ' ') << "*" << '\n';

    // "You selected" line inside the same box
    string selectedLine = "You selected: " + choice;
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

int main()
{
    string choice;
    do {
        clearScreen();
        printMainMenu(choice);

        if (choice == "1")
            cout << "Cashier module goes here...\n";
        else if (choice == "2")
            invMenu();
        else if (choice == "3")
            cout << "Report module goes here...\n";
        else if (choice == "4")
            cout << "Exiting program...\n";
        else
            cout << "Invalid choice, please select 1–4.\n";

        if (choice != "4") {
            cout << "\nPress Enter to continue...";
            // wait for Enter
            cin.get();
        }

    } while (choice != "4");

    return 0;
}
