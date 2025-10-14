/****************************************************************
 * CS1B - G3 : Inventory Submenus                               *
 * Partner A : Tamar Figotin (A00328312) - role: driver         *
 * Partner B : Luke Leibee   (1248406) - role: function         *
 * Due Date  : 2025-09-07                                       *
 * Purpose   : Practice making a multi-file C++ program with    *
 *					menus, input checks, and a simple cashier slip.  *
 * Build     : g++ -std=c++17 -Wall -Wextra -o main mainmenu.cpp*
 *					bookinfo.cpp cashier.cpp invmenu.cpp             *
 *					lookUpBook.cpp menuhelpers.cpp reports.cpp       *
 ****************************************************************/

#include "menuhelpers.h"
#include "invmenu.h"
#include "bookinfo.h"
#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <iomanip>
using namespace std;

const int MAX_BOOKS = 20;

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
    printLeftLine(PROMPT_START_LENGTH, "2. Add a Book");    printLeftLine(PROMPT_START_LENGTH, "3. Edit a Book's Record");
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

void printAddBookMenu(vector<bookInfo> &inventory, string &addBookChoice, bookInfo &newBook)
	{
	 const int MENU_SIZE = 10;
    string addBookArr[MENU_SIZE] = {"Return to Inventory Menu", "Enter Book Title", "Enter ISBN", "Enter Author", "Enter Publisher", "Enter Date Added (mm/dd/yyyy)",
										    "Enter Quantity on Hand", "Enter Wholesale Cost", "Enter Retail Price", "Save Book to Database"};

    printBorder();
    printEmptyLine();
    printCenteredLine("Serendipity Booksellers");
    printCenteredLine("Add Book");
	 printEmptyLine();

	 cout << "*";

	 cout << right
	 		<< setw(42) << "DATABASE SIZE: " << setw(2) << MAX_BOOKS - inventory.size() << " CURRENT BOOK COUNT: " << setw(2) << inventory.size() << " *" << endl
	 		<< left;

    printEmptyLine();
	 cout << "*";

	 cout << right
			<< setw(69) << "--PENDING VALUES *" << endl
	 		<< left;

	 string value;
	 int valueInt;
	 double valueDouble;

	 for (int i = 1; i < 6; i++) //loop through default constructor, assign value to members
	 {
	 	switch (i)
    	{
    		case 1: value = newBook.getBookTitle(); break;
      	case 2: value = newBook.getISBN(); break;
      	case 3: value = newBook.getAuthor(); break;
			case 4: value = newBook.getPublisher(); break;
      	case 5: value = newBook.getDateAdded(); break;
    	}
		printAddBookArray(addBookArr[i], i, value);
	 }

	 valueInt = newBook.getQtyOnHand();
	 printAddBookArray(addBookArr[6], 6, valueInt);

	 valueDouble = newBook.getWholeValue();
	 printAddBookArray(addBookArr[7], 7, valueDouble);

	 valueDouble = newBook.getRetailValue();
	 printAddBookArray(addBookArr[8], 8, valueDouble);

	 value = "";
	 printAddBookArray(addBookArr[9], 9, value);
	 printAddBookArray(addBookArr[0], 0, value);
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

void invMenu(std::vector<bookInfo>& inventory)
{
    string invChoice;
    do {
        clearScreen();
        printInvMenu(invChoice);

        if (invChoice == "1")
            lookUpBook(inventory);
        else if (invChoice == "2")
     	      addBook(inventory);
        else if (invChoice == "3")
            editBook(inventory);
        else if (invChoice == "4")
            deleteBook(inventory);
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

// Function definitions
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

void addBook(std::vector<bookInfo>& inventory)
{
	string addBookChoice;
	bookInfo newBook;
	bool unsavedChanges = false; //tracks for entered data

	if (inventory.size() >= MAX_BOOKS)
	{
   	cout << "\n**************************************************\n";
      cout << "*           Inventory Database is FULL!          *\n";
      cout << "*    You cannot add any more books to the store. *\n";
      cout << "**************************************************\n\n";
   	return;
	}

	do {
		clearScreen();
      printAddBookMenu(inventory, addBookChoice, newBook);

      if (addBookChoice == "1")
		{
    		string title;
   		cout << "Enter book title: ";
   		getline(cin, title);
    		newBook.setBookTitle(title);
			unsavedChanges = true;
		}
      else if (addBookChoice == "2")
		{
      	string isbn;
         cout << "Enter ISBN: ";
         getline(cin, isbn);
         newBook.setISBN(isbn);
			unsavedChanges = true;
		}
      else if (addBookChoice == "3")
		{
      	string author;
         cout << "Enter Author: ";
         getline(cin, author);
         newBook.setAuthor(author);
			unsavedChanges = true;
		}
      else if (addBookChoice == "4")
		{
      	string publisher;
         cout << "Enter Publisher: ";
         getline(cin, publisher);
         newBook.setPublisher(publisher);
			unsavedChanges = true;
		}
      else if (addBookChoice == "5")
		{
			string dateAdded;
			cout << "Enter Date Added (mm/dd/yyyy): ";
			getline(cin, dateAdded);
			newBook.setDateAdded(dateAdded);
			unsavedChanges = true;
		}
		else if (addBookChoice == "6")
		{
			int qty;
			cout << "Enter Quantity on Hand: ";
			cin >> qty;
			cin.ignore(10000, '\n');
			newBook.setQtyOnHand(qty);
			unsavedChanges = true;
		}
		else if (addBookChoice == "7")
		{
			double wholeValue;
			cout << "Enter Wholesale Cost: ";
			cin >> wholeValue;
			cin.ignore(10000, '\n');
			newBook.setWholeValue(wholeValue);
			unsavedChanges = true;
		}
		else if (addBookChoice == "8")
		{
			double retail;
			cout << "Enter Retail Price: ";
			cin >> retail;
			cin.ignore(10000, '\n');
			newBook.setRetailValue(retail);
			unsavedChanges = true;
		}
		else if (addBookChoice == "9")
		{
			cout << "Saving...\n";
			inventory.push_back(newBook);
			cout << "Book successfully added to inventory!\n";
			unsavedChanges = false;
			newBook = bookInfo(); // go back to default values

			// Check if inventory just reached MAX_BOOKS
            if (inventory.size() >= MAX_BOOKS) {
                cout << "\n**************************************************\n";
                cout << "*           Inventory Database is FULL!          *\n";
                cout << "*    You cannot add any more books to the store. *\n";
                cout << "**************************************************\n\n";
                break; // exit addBook() and go back to invMenu()
            }

		}
		else if (addBookChoice == "0")
		{
			if(unsavedChanges)
			{
				char confirm;
				cout << "You have unsaved changes. Do you wish to proceed? (Y/N)";
				cin >> confirm;
				cin.ignore();

				if(toupper(confirm) == 'Y')
				{
					cout << "Continuing...\n";
					newBook = bookInfo();
					break;
				}
				else
				{
					cout << "Returning...";
					addBookChoice = ""; //reset user's input so we don't exit loop
					continue;
				}
			}
			else
			{
				cout << "Returning To Inventory Menu...";
				break;
			}
		} //end of else if

		else
		{
      	cout << "Invalid choice, please select 0–9.\n";
			cin.get();
		}

    } while (addBookChoice != "0" && inventory.size() < MAX_BOOKS);

	do
	{
		clearScreen();
      printAddBookMenu(inventory, addBookChoice, newBook);

		if(addBookChoice == "0")
		{
			cout << "Returning To Inventory Menu...";
			break;
		}
		else
		{
		cout << "\n**************************************************\n";
      cout << "*           Inventory Database is FULL!          *\n";
      cout << "*    You cannot add any more books to the store. *\n";
      cout << "**************************************************\n\n";
		cin.get();
		}
	}while (inventory.size() >= MAX_BOOKS);
}

void editBook(std::vector<bookInfo>& inventory)
{
    cout << "Edit Book goes here..." << endl;
}

void deleteBook(std::vector<bookInfo>& inventory)
{
    cout << "Delete Book goes here..." << endl;
}
