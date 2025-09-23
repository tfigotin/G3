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

#include "cashier.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

	// Summary Box Helpers
	const int TOTAL_WIDTH = 59;                // total characters including the two '+' corners
	const int CONTENT_PAD = TOTAL_WIDTH - 4;   // characters available for text between "| " and " |"

	// Print top border
	void printTopBorder() {
	    cout << "+" << string(TOTAL_WIDTH - 2, '-') << "+" << endl;
	}

	// Print bottom border
	void printBottomBorder() {
	    cout << "+" << string(TOTAL_WIDTH - 2, '-') << "+" << endl;
	}

	// Print one content line (text will be left-aligned and padded to fill the box)
	void printLine(const string &text) {
	    cout << "| " << left << setw(CONTENT_PAD) << text << " |" << endl;
	}

	// --- Receipt box helpers (width = 70) ---
	const int RECEIPT_WIDTH = 70;
	const int RECEIPT_CONTENT = RECEIPT_WIDTH - 4;

	void printReceiptTop() {
	    cout << "+" << string(RECEIPT_WIDTH - 2, '-') << "+" << endl;
	}
	void printReceiptBottom() {
	    cout << "+" << string(RECEIPT_WIDTH - 2, '-') << "+" << endl;
	}
	void printReceiptLine(const string &text) {
	    cout << "| " << left << setw(RECEIPT_CONTENT) << text << " |" << endl;
	}

	// --- Helper to truncate text to fit a column ---
	string truncate(const string &s, size_t width) {
    if (s.size() <= width)
        return s;
    else
        return s.substr(0, width - 3) + "..."; // add ellipsis
	}

	// Cashier function
	void cashier() {

	 string date, isbn, title;
	 int quantity;
	 double price;

	 //Clear Screen from main menu
	 cout << "\033[2J\033[1;1H";

	 // Collect input first (prompts are simple console prompts)
	 cout << "Date: ";
	 getline(cin, date);

	 cout << "Quantity of Book: ";
	 while (!(cin >> quantity)) {
	     cin.clear();
	     cin.ignore(numeric_limits<streamsize>::max(), '\n');
	     cout << "Please enter a valid number for quantity: ";
	 	}
	 cin.ignore(numeric_limits<streamsize>::max(), '\n');

	 cout << "ISBN: ";
	 getline(cin, isbn);

	 cout << "Title: ";
	 getline(cin, title);

	 cout << "Price: $";
	 while (!(cin >> price)) {
	     cin.clear();
	     cin.ignore(numeric_limits<streamsize>::max(), '\n');
	     cout << "Please enter a valid price (e.g. 12.95): ";
	 	}
	 cin.ignore(numeric_limits<streamsize>::max(), '\n');

	 // Now print the nicely formatted box with all values
	 cout << "\033[2J\033[1;1H"; // clear the screen
	 printTopBorder();
	 printLine("Serendipity Booksellers");
	 printLine("Cashier Module");
	 printLine(""); // blank line

	 printLine("Date: " + date);

	 // convert quantity to string
	 printLine("Quantity of Book: " + to_string(quantity));

	 printLine("ISBN: " + isbn);
	 printLine("Title: " + truncate(title, CONTENT_PAD - 7));

	 // format price to two decimals
	 ostringstream oss;
	 oss << fixed << setprecision(2) << price;
	 printLine("Price: $" + oss.str());

	 printBottomBorder();

	// Pause before checkout
	cout << "Please press Enter to checkout...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "\033[2J\033[1;1H"; // clear the screen

	// --- Calculations ---
	float subtotal = quantity * price;
	float tax = subtotal * 0.06;
	float total = subtotal + tax;

	cout << fixed << showpoint << setprecision(2);

	// --- Receipt ---
	cout << "\033[2J\033[1;1H"; // clear screen
	printReceiptTop();
	printReceiptLine("Serendipity Book Sellers");
	printReceiptLine("");
	printReceiptLine("Date: " + date);
	printReceiptLine("");

	// Header row
	ostringstream header;
	header << left << setw(5) << "Qty"
	       << setw(15) << "ISBN"
	       << setw(25) << "Title"
	       << right << setw(8) << "Price"
	       << setw(10) << "Total";
	printReceiptLine(header.str());

	// Horizontal separator
	printReceiptLine(string(RECEIPT_CONTENT, '_'));

	// Line item row
	ostringstream item;

	// format price and subtotal with $ prefix
	ostringstream priceStream, subtotalStream;
	priceStream << "$" << fixed << setprecision(2) << price;
	subtotalStream << "$" << fixed << setprecision(2) << subtotal;

	item << left  << setw(5)  << quantity
     << setw(15) << isbn
     << setw(25) << truncate(title, 25)
     << right << setw(8)  << priceStream.str()
     << setw(10) << subtotalStream.str();

	printReceiptLine(item.str());

	printReceiptLine(""); // blank line before totals

	// Totals
	ostringstream sub, taxline, tot;

	// labels on the left, values aligned with Total column
	sub     << right << setw(56) << "Subtotal"
        	  << setw(10) << ("$" + (ostringstream() << fixed << setprecision(2) << subtotal).str());

	taxline << right << setw(56) << "Tax"
           << setw(10) << ("$" + (ostringstream() << fixed << setprecision(2) << tax).str());

	tot     << right << setw(56) << "Total"
           << setw(10) << ("$" + (ostringstream() << fixed << setprecision(2) << total).str());

	printReceiptLine(sub.str());
	printReceiptLine(taxline.str());
	printReceiptLine(tot.str());
	printReceiptLine("");

	// Closing message
	printReceiptLine("Thank You for Shopping at Serendipity!");
	printReceiptBottom();

	}




