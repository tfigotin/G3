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

#include "cashier.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <limits>
#include <algorithm>

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

	string toLower(const std::string& s) {
   	string result = s;
   	transform(result.begin(), result.end(), result.begin(),
      				[](unsigned char c){ return std::tolower(c); });
   	return result;
	}

	// Cashier function
void cashier(InventoryList& inventory) {

	const int MAX_CART = 20;
	bookNode** cartNodes = new bookNode*[MAX_CART];
	int* cartQty     = new int[MAX_CART];
	int cartCount = 0;

	//Clear Screen from main menu
	cout << "\033[2J\033[1;1H";

	string date;
   cout << "Date (MM/DD/YY): ";
   cin.ignore();
   getline(cin, date);

	char more = 'Y';
   while (toupper(more) == 'Y' && cartCount < MAX_CART) {
   	// Display inventory
   	cout << "\nAvailable Books:\n";
   	bookNode* curr = inventory.getHead();
   	int idx = 0;
   	while (curr) {
     		cout << idx << ". " << curr->book.getBookTitle()
      		  << " | ISBN: " << curr->book.getISBN()
              << " | Price: $" << fixed << setprecision(2) << curr->book.getRetailValue()
              << " | Qty: " << curr->book.getQtyOnHand() << endl;
      	curr = curr->next;
      	idx++;
      }

      string input;
		cout << "Enter Index, ISBN, or Title to add to cart (-1 to checkout): ";
		getline(cin, input);

		if (input == "-1")
			break;

		bookNode* node = nullptr;
		curr = inventory.getHead();
      idx = 0;

		//Index match
		while (curr) {
      	if (input == to_string(idx)) {
         	node = curr;
            break;
      	}
         curr = curr->next;
         idx++;
      }

		//ISBN match
		if (!node) node = inventory.findISBN(input);

		if (!node) {
      	curr = inventory.getHead();
         	string inputLower = toLower(input);
            while (curr) {
            	if (toLower(curr->book.getBookTitle()) == inputLower) {
               	node = curr;
                  break;
               }
               curr = curr->next;
      	}
		}

		if (!node) {
      	cout << "Book not found. Try again.\n";
      	continue;
		}


		int qty;
      cout << "Enter quantity (available: " << node->book.getQtyOnHand() << "): ";
      while (!(cin >> qty) || qty <= 0 || qty > node->book.getQtyOnHand()) {
      	cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         cout << "Invalid quantity. Enter again (max " << node->book.getQtyOnHand() << "): ";
      }
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		/*
		cout << "Title: ";
		getline(cin, title);

		cout << "Price: $";
		while (!(cin >> price)) {
			cin.clear();
	      cin.ignore(numeric_limits<streamsize>::max(), '\n');
	      cout << "Please enter a valid price (e.g. 12.95): ";
	 	}
	   cin.ignore(numeric_limits<streamsize>::max(), '\n');
		*/

		cartNodes[cartCount] = node;
      cartQty[cartCount] = qty;
      cartCount++;

		if (cartCount >= MAX_CART) {
      	cout << "Cart full.\n";
         break;
      }

      cout << "Add another book? (Y/N): ";
      cin >> more;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	// Handle empty cart
   if (cartCount == 0) {
   	cout << "No items in cart.\n";
      delete[] cartNodes;
      delete[] cartQty;
      return;
   }

   // --- Confirm purchase ---
   char confirm;
   cout << "\nProceed with purchase? (Y/N): ";
   cin >> confirm;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   if (toupper(confirm) != 'Y') {
   	cout << "Purchase canceled.\n";
      delete[] cartNodes;
      delete[] cartQty;
      return;
   }
	// Receipt header
   ostringstream header;
   header << left << setw(5) << "Qty"
          << setw(15) << "ISBN"
          << setw(25) << "Title"
          << right << setw(8) << "Price"
          << setw(10) << "Total";
   printReceiptLine(header.str());
   printReceiptLine(string(RECEIPT_CONTENT, '_'));

   // Line items
   float subtotal = 0.0f;
   for (int i = 0; i < cartCount; i++) {
   	float lineTotal = cartQty[i] * cartNodes[i]->book.getRetailValue();
      subtotal += lineTotal;

      ostringstream line;
      line << left << setw(5) << cartQty[i]
           << setw(15) << cartNodes[i]->book.getISBN()
           << setw(25) << truncate(cartNodes[i]->book.getBookTitle(), 25)
           << right << setw(8) << fixed << setprecision(2) << cartNodes[i]->book.getRetailValue()
           << setw(10) << fixed << setprecision(2) << lineTotal;
      printReceiptLine(line.str());
	}

	printReceiptLine(""); // blank line before totals

   // Totals
   float tax = subtotal * 0.06f;
   float total = subtotal + tax;

   ostringstream sub, taxline, tot;
   sub     << right << setw(56) << "Subtotal" << setw(7) << "$" << fixed << setprecision(2) << subtotal;
   taxline << right << setw(56) << "Tax"      << setw(7) << "$" << fixed << setprecision(2) << tax;
   tot     << right << setw(56) << "Total"    << setw(7) << "$" << fixed << setprecision(2) << total;

   printReceiptLine(sub.str());
   printReceiptLine(taxline.str());
   printReceiptLine(tot.str());
   printReceiptLine("");
   printReceiptLine("Thank You for Shopping at Serendipity!");
   printReceiptBottom();

   // --- Adjust inventory quantities ---
   for (int i = 0; i < cartCount; i++) {
   	cartNodes[i]->book.setQtyOnHand(cartNodes[i]->book.getQtyOnHand() - cartQty[i]);
   }

   // --- Cleanup ---
   delete[] cartNodes;
   delete[] cartQty;
}
































	/*
	// Now print the nicely formatted box with all values
	cout << "\033[2J\033[1;1H"; // clear the screen
	printTopBorder();
	printLine("Serendipity Booksellers");
	printLine("Cashier Module");
	printLine(""); // blank line
	printLine("Date: " + date);

	// convert quantity to string
	printLine("Quantity of Book: " + to_string(qty));

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
        	  << setw(7) << ("$" + (ostringstream() << fixed << setprecision(2) << subtotal).str());

	taxline << right << setw(56) << "Tax"
           << setw(7) << ("$" + (ostringstream() << fixed << setprecision(2) << tax).str());

	tot     << right << setw(56) << "Total"
           << setw(7) << ("$" + (ostringstream() << fixed << setprecision(2) << total).str());

	printReceiptLine(sub.str());
	printReceiptLine(taxline.str());
	printReceiptLine(tot.str());
	printReceiptLine("");

	// Closing message
	printReceiptLine("Thank You for Shopping at Serendipity!");
	printReceiptBottom();


	for (int i = 0; i < cartCount; i++) {
		bookNode* node = inventory.getHead();
   	for (int j = 0; j < cartIndices[i]; j++)
   		node = node->next;

   	node->book.setQtyOnHand(node->book.getQtyOnHand() - cartQty[i]);
	}

	delete[] cartIndices;
	delete[] cartQty;

}


*/



