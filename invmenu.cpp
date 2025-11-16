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

//search inventory for ISBN
int findISBN(const vector<bookInfo>& inventory, const string& isbn) {
	for(size_t i = 0; i < inventory.size(); i++) {
		if (inventory[i].getISBN() == isbn)
			return i;
	}
	return -1;
}

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


//Print AddBookMenu
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


//Print Edit Book Menu
void printEditBookMenu(vector<bookInfo> &inventory, string &editBookChoice, bookInfo &editBook)
	{
	 const int MENU_SIZE = 10;
    string addBookArr[MENU_SIZE] = {"Return to Inventory Menu", "Edit Book Title", "Edit ISBN", "Edit Author", "Edit Publisher", "Edit Date Added (mm/dd/yyyy)",
										    "Edit Quantity on Hand", "Edit Wholesale Cost", "Edit Retail Price", "Save Book to Database"};

    printBorder();
    printEmptyLine();
    printCenteredLine("Serendipity Booksellers");
    printCenteredLine("Edit Book");
	 printEmptyLine();

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
    		case 1: value = editBook.getBookTitle(); break;
      	case 2: value = editBook.getISBN(); break;
      	case 3: value = editBook.getAuthor(); break;
			case 4: value = editBook.getPublisher(); break;
      	case 5: value = editBook.getDateAdded(); break;
    	}
		printAddBookArray(addBookArr[i], i, value);
	 }

	 valueInt = editBook.getQtyOnHand();
	 printAddBookArray(addBookArr[6], 6, valueInt);

	 valueDouble = editBook.getWholeValue();
	 printAddBookArray(addBookArr[7], 7, valueDouble);

	 valueDouble = editBook.getRetailValue();
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
    getline(cin >> ws, editBookChoice);

    // Move the cursor up one line and to the start of that line, then rewrite the entire prompt line
    // This overwrites the previously-echoed input line so the right '*' can be placed in the correct column.
    cout << "\033[A\r";

    // Make sure the displayed input doesn't overflow the inner width
    int maxInputLen = INNER_WIDTH - (int)leftPart.length();
    if (maxInputLen < 0) maxInputLen = 0;
    string displayChoice = editBookChoice.substr(0, maxInputLen);

    int used = (int)leftPart.length() + (int)displayChoice.length();
    int spaces = INNER_WIDTH - used;
    if (spaces < 0) spaces = 0;

    cout << "*" << leftPart << displayChoice << string(spaces, ' ') << "*" << '\n';

    // "You selected" line inside the same box
    string selectedLine = "You selected: " + editBookChoice;
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

        if (invChoice == "1") {
				int index = lookUpBook(inventory);
				if (index != -1)
        		cout << "\n(Book index " << index << " selected.)\n";
		  }
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
int lookUpBook(vector<bookInfo>& inventory)
{
    cout << "\n==================== Look Up Book ====================\n";

    if (inventory.empty())
    {
        cout << "Inventory is empty. Nothing to look up.\n";
        return -1;
    }

    // Prompt user for search term
    cout << "Enter book title or ISBN (partial, case-insensitive)\n";
    cout << "Or press ENTER to cancel.\n> ";

    string search;
    getline(cin, search);

    if (search.empty())
    {
        cout << "Returning to Inventory Menu...\n";
        return -1;
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
        return -1;
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
            return -1;
        }
                  //compare unsigned ints
        else if (choice > 0 && static_cast<size_t>(choice) <= matches.size())
        {
				int selectedIndex = matches[choice - 1];
            cout << "\n";
            displayBookInfo(inventory[selectedIndex]);
            return selectedIndex;
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
	bool unsavedChanges = false;

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

	while(inventory.size() >= MAX_BOOKS && addBookChoice != "0")
	{
		clearScreen();
      printAddBookMenu(inventory, addBookChoice, newBook);

		if(addBookChoice == "0")
		{
			cout << "Returning To Inventory Menu...";
		}
		else
		{
		cout << "\n**************************************************\n";
      cout << "*           Inventory Database is FULL!          *\n";
      cout << "*    You cannot add any more books to the store. *\n";
      cout << "**************************************************\n\n";
		cin.get();
		}
	}
}

void editBook(std::vector<bookInfo>& inventory)
{
	string editBookChoice;
	bool unsavedChanges = false;

	clearScreen();

	bool editing = true;

	while(editing)
	{
		int idx = lookUpBook(inventory);
		if (idx == -1)
		{
			cout << "Book not found.\n";
			char again;
			cout << "Edit another? (Y/N): ";
			cin >> again;
			cin.ignore(10000, '\n');

			if (toupper(again) != 'Y')
				editing = false;

			continue;
		}

		bookInfo &book = inventory[idx]; // Real book
		bookInfo editBook = book;        // Copy of Book for unsaved changes

		while(editBookChoice != "0")
		{
			clearScreen();
			printEditBookMenu(inventory, editBookChoice, editBook);

			if(editBookChoice == "1")
			{
				string title;
   			cout << "Edit book title: ";
   			getline(cin, title);
    			editBook.setBookTitle(title);
				unsavedChanges = true;
			}
			else if (editBookChoice == "2")
			{
      		string isbn;
         	cout << "Enter ISBN: ";
         	getline(cin, isbn);

				int index = findISBN(inventory, isbn);

				if(index != -1 && index != idx) {
					cout << "ISBN already exists. Overwrite? (Y/N): ";
					char ans;
					cin >> ans;
					cin.ignore();

					if(toupper(ans) != 'Y') {
						cout << "Canceled.\n";
					}
					else { //Overwrite ISBN
						editBook.setISBN(isbn);
						unsavedChanges = true;
					}
				}
				else { //Unique ISBN
					editBook.setISBN(isbn);
					unsavedChanges = true;
				}
			}

      	else if (editBookChoice == "3")
			{
      		string author;
         	cout << "Edit Author: ";
         	getline(cin, author);
         	editBook.setAuthor(author);
				unsavedChanges = true;
			}
      	else if (editBookChoice == "4")
			{
      		string publisher;
         	cout << "Edit Publisher: ";
         	getline(cin, publisher);
         	editBook.setPublisher(publisher);
				unsavedChanges = true;
			}
      	else if (editBookChoice == "5")
			{
				string dateAdded;
				cout << "Edit Date Added (mm/dd/yyyy): ";
				getline(cin, dateAdded);
				editBook.setDateAdded(dateAdded);
				unsavedChanges = true;
			}
			else if (editBookChoice == "6")
			{
				int qty;
				cout << "Edit Quantity on Hand: ";
				cin >> qty;
				while(!cin || qty < 0)
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "Invalid input. Please enter a non-negative integer.\n";
					cin >> qty;
				}
				editBook.setQtyOnHand(qty);
				unsavedChanges = true;
			}
			else if (editBookChoice == "7")
			{
				double wholeValue;
				cout << "Edit Wholesale Cost: ";
				cin >> wholeValue;
				while(!cin || wholeValue < 0.0)
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "Invalid input. Please enter a value greater than 0.\n";
					cin >> wholeValue;
				}
				editBook.setWholeValue(wholeValue);
				unsavedChanges = true;
			}
			else if (editBookChoice == "8")
			{
				double retail;
				cout << "Edit Retail Price: ";
				cin >> retail;
				while(!cin || retail < 0)
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "Invalid input. Please enter a value greater than 0.\n";
					cin >> retail;
				}
				cin.ignore(10000, '\n');
				editBook.setRetailValue(retail);
				unsavedChanges = true;
			}
			else if (editBookChoice == "9")
			{
				cout << "Saving...\n";
				book = editBook;
				cout << "Book successfully updated!\n";
				unsavedChanges = false;
				cin.get();
			}

			else if (editBookChoice == "0")
			{
				if(unsavedChanges)
				{
					char confirm;
					cout << "You have unsaved changes. Do you wish to proceed? (Y/N)";
					cin >> confirm;
					cin.ignore(10000, 'n');

					if(toupper(confirm) == 'Y')
					{
						cout << "Continuing...\n";
						editBook = bookInfo();
						break;
					}
					else
					{
						cout << "Returning...";
						editBookChoice = ""; //reset user's input so we don't exit loop
						continue;
					}
				}
				else
				{

				}
			} //end of else if 0

			else
			{
      		cout << "Invalid choice, please select 0–9.\n";
				cin.get();
			}

		}

		char again;
		cout << "Edit another? (Y/N): ";
		cin >> again;
		cin.ignore(10000, '\n');

		if (toupper(again) != 'Y'){
			cout << "Returning to Inventory Menu...";
			break;
		}
	}
}

void deleteBook(std::vector<bookInfo>& inventory)
{
    if (inventory.empty())
    {
        cout << "\nInventory is empty. Nothing to delete.\n";
        return;
    }

    char again = 'y';

    while (tolower(again) == 'y')
    {
        clearScreen();
        cout << "\n==================== Delete Book ====================\n";

        int idx = lookUpBook(inventory);
        if (idx == -1)
        {
            cout << "No book selected.\n";
        }
        else
        {

            // Confirm delete
            char confirm;
            cout << "\nDelete this book? (y/n): ";
            cin >> confirm;
            cin.ignore(10000, '\n');

            if (tolower(confirm) == 'y')
            {
                // ERASE the element → plugs the hole
                inventory.erase(inventory.begin() + idx);

                cout << "\nBook deleted successfully!\n";
                cout << "(Inventory has been compacted — no holes.)\n";
            }
            else
            {
                cout << "\nDeletion canceled.\n";
            }
        }

        // Ask if user wants to delete another
        cout << "\nDelete another? (y/n): ";
        cin >> again;
        cin.ignore(10000, '\n');
    }

    cout << "\nReturning to Inventory Menu...\n";
}
