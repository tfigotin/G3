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

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include "bookinfo.h"

using namespace std;

/****************************************************************
 * FUNCTION : lookUpBook
 * PURPOSE  : Search for books by title or ISBN (case-insensitive)
 *             and display full info for a selected match.
 ****************************************************************/
void lookUpBook(vector<bookInfo>& inventory)
{
    cout << "\n==================== Look Up Book ====================\n";

    if (inventory.empty())
    {
        cout << "Inventory is empty. Nothing to look up.\n";
        return;
    }

    // Prompt user for search term
    cout << "Enter book title or ISBN (partial, case-insensitive)\n";
    cout << "Or press ENTER to cancel.\n> ";

    string search;
    getline(cin, search);

    if (search.empty())
    {
        cout << "Returning to Inventory Menu...\n";
        return;
    }

    // Convert input to lowercase for comparison
    auto toLower = [](string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        return s;
    };

    string key = toLower(search);
    vector<int> matches;

    // Search through all books
    for (size_t i = 0; i < inventory.size(); ++i)
    {
        string title = toLower(inventory[i].getBookTitle());
        string isbn  = toLower(inventory[i].getISBN());

        if (title.find(key) != string::npos || isbn.find(key) != string::npos)
        {
            matches.push_back(i);
        }
    }

    // Handle no matches
    if (matches.empty())
    {
        cout << "\nNo matches found for \"" << search << "\".\n";
        return;
    }

    // Display results
    cout << "\nMatches found:\n";
    cout << "------------------------------------------------------\n";
    for (size_t i = 0; i < matches.size(); ++i) //compare unsigned to unsigned
    {
        const bookInfo& b = inventory[matches[i]];
        cout << setw(2) << (i + 1) << ") "
             << b.getBookTitle() << " — "
             << b.getAuthor() << " — "
             << b.getISBN()
             << " — Qty: " << b.getQtyOnHand()
             << " — $" << fixed << setprecision(2) << b.getRetailValue() << '\n';
    }

    // Let user choose one
    int choice;
    while (true)
    {
        cout << "\nSelect # to view details, or 0 to cancel: ";
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid input. Enter a number.\n";
            continue;
        }
        cin.ignore(100, '\n'); // clear leftover input

        if (choice == 0)
        {
            cout << "Canceled. Returning to Inventory Menu...\n";
            return;
        }
		  //compare unsigned ints
        else if (choice > 0 && static_cast<size_t>(choice) <= matches.size())
        {
            cout << "\n";
            displayBookInfo(inventory[matches[choice - 1]]);
            return;
        }
        else
        {
            cout << "Invalid selection. Try again.\n";
        }
    }
}
