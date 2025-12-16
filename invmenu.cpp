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
#include "inventoryList.h"
#include "invmenu.h"
#include "bookinfo.h"
#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

//const int MAX_BOOKS = 20;

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
void printAddBookMenu(InventoryList& inventory, string &addBookChoice, bookInfo &newBook)
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
	 		<< setw(40) << "DATABASE SIZE: " << setw(3) << inventory.size() << " CURRENT BOOK COUNT: " << setw(3) << inventory.size() << " *" << endl
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
void printEditBookMenu(InventoryList& inventory, string &editBookChoice, bookInfo &editBook)
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

void invMenu(InventoryList& inventory)
{
    string invChoice;
    do {
        clearScreen();
        printInvMenu(invChoice);

        if (invChoice == "1") {
				bookNode* node = lookUpBook(inventory);
				if (node != NULL)
        		cout << "\n(Book index " << node << " selected.)\n";
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


bookNode* lookUpBook(InventoryList& inventory)
{
    cout << "\n==================== Look Up Book ====================\n";

    if (!inventory.getHead())
    {
        cout << "Inventory is empty. Nothing to look up.\n";
        return NULL;
    }

    // Prompt user for search term
    cout << "Enter book title or ISBN (partial, case-insensitive)\n";
    cout << "Or press ENTER to cancel.\n> ";

    string key;
    getline(cin, key);

    if (key.empty())
    {
        cout << "Returning to Inventory Menu...\n";
  		  return NULL;
    }

	 transform(key.begin(), key.end(), key.begin(), ::tolower);

	 vector<bookNode*> matches;

    // Traverse linked list
    for (bookNode* curr = inventory.getHead(); curr; curr = curr->next)
    {
        string title = curr->book.getBookTitle();
        string isbn  = curr->book.getISBN();

        transform(title.begin(), title.end(),
                  title.begin(), ::tolower);
        transform(isbn.begin(), isbn.end(),
                  isbn.begin(), ::tolower);

        if (title.find(key) != string::npos ||
            isbn.find(key)  != string::npos)
        {
            matches.push_back(curr);
        }
    }

    /* Search through all books
    for (size_t i = 0; i < inventory.size(); ++i)
    {
        string title = toLower(inventory[i].getBookTitle());
        string isbn  = toLower(inventory[i].getISBN());

        if (title.find(key) != string::npos || isbn.find(key) != string::npos)
        {
            matches.push_back(i);
        }
    }
	 */

    // Handle no matches
    if (matches.empty())
    {
        cout << "\nNo matches found for \"" << key << "\".\n";
        return NULL;
    }

    // Display results
    cout << "\nMatches found:\n";
    cout << "------------------------------------------------------\n";
    for (size_t i = 0; i < matches.size(); i++) //compare unsigned to unsigned
    {
        //const bookInfo& b = inventory[matches[i]];
        cout << setw(2) << (i + 1) << ") "
             << matches[i]->book.getBookTitle() << " — "
             << matches[i]->book.getAuthor() << " — "
             << matches[i]->book.getISBN()
             << " — Qty: " << matches[i]->book.getQtyOnHand()
             << " — $" << fixed << setprecision(2) << matches[i]->book.getRetailValue() << '\n';
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
            cout << "Canceled.\n";
            return NULL;
        }
                  //compare unsigned ints
        else if (choice >= 1 && choice <= (int)matches.size())
        {
				//int selectedIndex = matches[choice - 1];
            cout << "\n";
            //displayBookInfo(node->book);
            return matches[choice-1];
		  }
        else
        {
            cout << "Invalid selection. Try again.\n";
        }
    }
}

//Overload lookUpBook for userCanceled input
bookNode* lookUpBook(InventoryList& inventory, bool& userCanceled)
{
    userCanceled = false;  // default

    cout << "\n==================== Look Up Book ====================\n";

    if (!inventory.getHead())
    {
        cout << "Inventory is empty. Nothing to look up.\n";
        return NULL;
    }

    // Prompt the user
    cout << "Enter book title or ISBN (partial, case-insensitive)\n";
    cout << "Or press ENTER to cancel.\n> ";

    string key;
    getline(cin, key);

    if (key.empty())
    {
        userCanceled = true;  // user pressed ENTER
        return NULL;
    }

    vector<bookNode*> matches;

    for (bookNode* curr = inventory.getHead(); curr; curr = curr->next)
    {
        string title = curr->book.getBookTitle();
        string isbn  = curr->book.getISBN();

        transform(title.begin(), title.end(), title.begin(), ::tolower);
        transform(isbn.begin(), isbn.end(), isbn.begin(), ::tolower);

        string lowerKey = key;
        transform(lowerKey.begin(), lowerKey.end(), lowerKey.begin(), ::tolower);

        if (title.find(lowerKey) != string::npos || isbn.find(lowerKey) != string::npos)
        {
            matches.push_back(curr);
        }
    }

    if (matches.empty())
    {
        cout << "\nNo matches found for \"" << key << "\".\n";
        return NULL;
    }

    cout << "\nMatches found:\n";
    cout << "------------------------------------------------------\n";
    for (size_t i = 0; i < matches.size(); i++)
    {
        cout << setw(2) << (i + 1) << ") "
             << matches[i]->book.getBookTitle() << " — "
             << matches[i]->book.getAuthor() << " — "
             << matches[i]->book.getISBN()
             << " — Qty: " << matches[i]->book.getQtyOnHand()
             << " — $" << fixed << setprecision(2) << matches[i]->book.getRetailValue() << '\n';
    }

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
        cin.ignore(100, '\n');

        if (choice == 0)
        {
            userCanceled = true;
            return NULL;
        }
        else if (choice >= 1 && choice <= (int)matches.size())
        {
            return matches[choice-1];
        }
        else
        {
            cout << "Invalid selection. Try again.\n";
        }
    }
}

void addBook(InventoryList& inventory)
{
	string addBookChoice;
	bookInfo newBook;
	bool unsavedChanges = false;

	/*if (inventory.size() >= MAX_BOOKS)
	{
   	cout << "\n**************************************************\n";
      cout << "*           Inventory Database is FULL!          *\n";
      cout << "*    You cannot add any more books to the store. *\n";
      cout << "**************************************************\n\n";
   	return;
	}
	*/

	do {
		clearScreen();
      printAddBookMenu(inventory, addBookChoice, newBook);

      if (addBookChoice == "1")
		{
    		string title;
   		cout << "Enter book title: ";
   		getline(cin >> ws, title);
    		newBook.setBookTitle(title);
			unsavedChanges = true;
		}
      else if (addBookChoice == "2")
		{
      	string isbn;
         cout << "Enter ISBN: ";
         getline(cin >> ws, isbn);
         newBook.setISBN(isbn);
			unsavedChanges = true;
		}
      else if (addBookChoice == "3")
		{
      	string author;
         cout << "Enter Author: ";
         getline(cin >> ws, author);
         newBook.setAuthor(author);
			unsavedChanges = true;
		}
      else if (addBookChoice == "4")
		{
      	string publisher;
         cout << "Enter Publisher: ";
         getline(cin >> ws, publisher);
         newBook.setPublisher(publisher);
			unsavedChanges = true;
		}
      else if (addBookChoice == "5")
		{
			string dateAdded;
			cout << "Enter Date Added (mm/dd/yyyy): ";
			getline(cin >> ws, dateAdded);
			newBook.setDateAdded(dateAdded);
			unsavedChanges = true;
		}
		else if (addBookChoice == "6")
		{
			int qty;

			do {
				cout << "Enter Quantity on Hand: ";
				if (!(cin >> qty) || qty < 0)
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "Invalid input.";
				}
			} while (!cin || qty < 0);

			cin.ignore(10000, '\n');

			newBook.setQtyOnHand(qty);
			unsavedChanges = true;
		}
		else if (addBookChoice == "7")
		{
			double wholeValue;

			do{
				cout << "Enter Wholesale Cost: ";
				if (!(cin >> wholeValue) || wholeValue < 0)
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "Invalid input.";
				}
			} while (!cin || wholeValue < 0);

			cin.ignore(10000, '\n');
			newBook.setWholeValue(wholeValue);
			unsavedChanges = true;
		}
		else if (addBookChoice == "8")
		{
			double retail;

			do{
				cout << "Enter Retail Price: ";
				if (!(cin >> retail) || retail < 0)
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "Invalid input.";
				}
			} while (!cin || retail < 0);

			cin.ignore(10000, '\n');
			newBook.setRetailValue(retail);
			unsavedChanges = true;
		}
		else if (addBookChoice == "9")
		{
			cout << "Saving...\n";
			inventory.insert(newBook);
			cout << "Book successfully added to inventory!\n";
			unsavedChanges = false;
			newBook = bookInfo(); // go back to default values
			addBookChoice = "";
			//cin.get();

			/* Check if inventory just reached MAX_BOOKS
            if (inventory.size() >= MAX_BOOKS) {
                cout << "\n**************************************************\n";
                cout << "*           Inventory Database is FULL!          *\n";
                cout << "*    You cannot add any more books to the store. *\n";
                cout << "**************************************************\n\n";
                break; // exit addBook() and go back to invMenu()
            }
			*/

		}
		else if (addBookChoice == "0")
		{
			if(unsavedChanges)
			{
				char confirm;
				cout << "You have unsaved changes. Do you wish to proceed? (Y/N)";
				cin >> confirm;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

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

    } while (addBookChoice != "0");

}

void editBook(InventoryList& inventory)
{

	string editBookChoice;
	bool unsavedChanges = false;
	bool editing = true;

	clearScreen();

	while(editing)
	{
		bool userCanceled = false;
		bookNode* node = lookUpBook(inventory, userCanceled);

		if(userCanceled)
			break;

		else if (node == NULL)
		{
			cout << "Book not found.\n";
			char again;
			cout << "Edit another? (Y/N): ";
			cin >> again;
			cin.ignore(10000, '\n');

			if (toupper(again) != 'Y'){
				break;
			}
			clearScreen();
			continue;
		}

		bookInfo &book = node->book;     // Real book
		bookInfo editBook = book;        // Copy of Book for unsaved changes

		do
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

				bookNode* found = inventory.findISBN(isbn);

				if(found != NULL && found != node) {
					cout << "ISBN already exists. Overwrite? (Y/N): ";
					char ans;
					cin >> ans;
					cin.ignore(10000, '\n');

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

				do
				{
					cout << "Edit Quantity on Hand: ";
					cin >> qty;

					if(!cin || qty < 0)
					{
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Invalid input. Please enter a non-negative integer.\n";
					}
				}while(!cin || qty < 0);

				cin.ignore(10000, '\n');
				editBook.setQtyOnHand(qty);
				unsavedChanges = true;
			}
			else if (editBookChoice == "7")
			{
				double wholeValue;

				do {
					cout << "Edit Wholesale Cost: ";
					cin >> wholeValue;

					if(!cin || wholeValue < 0.0)
					{
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Invalid input. Please enter a value greater than 0.\n";
					}

				}while(!cin || wholeValue < 0.0);

				cin.ignore(10000, '\n');
				editBook.setWholeValue(wholeValue);
				unsavedChanges = true;
			}
			else if (editBookChoice == "8")
			{
				double retail;

				do {
					cout << "Edit Retail Price: ";
					cin >> retail;

					if(!cin || retail < 0.0)
					{
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "Invalid input. Please enter a value greater than 0.\n";
					}
				}while (!cin || retail < 0.0);

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
					cin.ignore(10000, '\n');

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
					}
				}
				else
				{
					break;
				}
			} //end of else if 0

			else
			{
      		cout << "Invalid choice, please select 0–9.\n";
				cin.get();
			}

		}while(editBookChoice != "0");

		char again;
		cout << "Edit another? (Y/N): ";
		cin >> again;
		cin.ignore(10000, '\n');

		if (toupper(again) != 'Y'){
			break;
		}
		clearScreen();
	}
}

void deleteBook(InventoryList& inventory)
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

		  bool userCanceled = false;
        bookNode* node = lookUpBook(inventory, userCanceled);

		  if(userCanceled)
		  {
		  	  cout << "Deletion canceled.\n";
			  break;
		  }

        if (node == NULL)
        {
            cout << "No book selected.\n";
        }
        else
        {

            // Confirm delete
            char confirm;
            cout << "\nDelete \"" << node->book.getBookTitle() << "\"? (y/n): ";
            cin >> confirm;
            cin.ignore(10000, '\n');

            if (tolower(confirm) == 'y')
            {
                // erase element
                inventory.remove(node);

                cout << "\nBook deleted successfully!\n";
            }
            else
            {
                cout << "\nDeletion canceled.\n";
            }
        }

        // Ask if user wants to delete another
		  if(!inventory.empty()) {
		  	  cout << "\nDelete another? (y/n): ";
			  cin >> again;
			  cin.ignore(10000, '\n');
		  }
	     else {
           cout << "\nInventory is now empty.\n";
           break;
    	  }

	 }
    cout << "\nReturning to Inventory Menu...\n";
}
