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
using namespace std;

#include "bookinfo.h"
#include "inventoryList.h"


/******************** Default Constructor ********************/
bookInfo::bookInfo() {
    bookTitle = "EMPTY";
    isbn = "EMPTY";
    author = "EMPTY";
	 publisher = "EMPTY";
    dateAdded = "EMPTY";
    qtyOnHand = 0;
    wholeValue = 0.00;
    retailValue = 0.00;
}

/******************** Full Constructor ********************/
bookInfo::bookInfo(string t, string i, string a, string p,  string d,
                   int q, double w, double r) {
    bookTitle = t;
    isbn = i;
    author = a;
	 publisher = p;
    dateAdded = d;
    qtyOnHand = q;
    wholeValue = w;
    retailValue = r;
}

/******************** Operator Overload ********************/
bool bookInfo::operator<(const bookInfo& rhs) const
{
    switch (InventoryList::sortCode)
    {
        case 0: return bookTitle < rhs.bookTitle;
        case 1: return isbn < rhs.isbn;
        default: return bookTitle < rhs.bookTitle;
    }
}

void displayBookInfo(const bookInfo &book)
{
    cout << "\n================= Book Information =================\n";

	 // Truncate long titles
    string title = book.getBookTitle();
    const int maxTitleLength = 34;
    if (title.length() > maxTitleLength)
        title = title.substr(0, maxTitleLength - 3) + "...";

    cout << left << setw(18) << "Title:"       << title                << '\n';
    cout << setw(18) << "ISBN:"                << book.getISBN()       << '\n';
    cout << setw(18) << "Author:"              << book.getAuthor()     << '\n';
	 cout << setw(18) << "Publisher:"			  << book.getPublisher()  << '\n';
    cout << setw(18) << "Date Added:"          << book.getDateAdded()  << '\n';
    cout << setw(18) << "Quantity on Hand:"    << book.getQtyOnHand()  << '\n';
    cout << setw(18) << "Wholesale Cost:"      << "$" << fixed << setprecision(2)
         << book.getWholeValue() << '\n';
    cout << setw(18) << "Retail Price:"        << "$" << fixed << setprecision(2)
         << book.getRetailValue() << '\n';
    cout << "=====================================================\n";
}


