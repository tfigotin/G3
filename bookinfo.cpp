/****************************************************************
 * CS1B - G3 :             *
 * Partner A : Tamar Figotin (A00328312) - role: driver         *
 * Partner B : Luke Leibee   (1248406) - role: function         *
 * Due Date  : 2025-                                      *
 * Purpose   : .  *
 * Build     :                                     *
 ****************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

#include "bookinfo.h"


/******************** Default Constructor ********************/
bookInfo::bookInfo() {
    bookTitle = "EMPTY";
    isbn = "EMPTY";
    author = "EMPTY";
    dateAdded = "EMPTY";
    qtyOnHand = 0;
    wholeValue = 0.00;
    retailValue = 0.00;
}

/******************** Full Constructor ********************/
bookInfo::bookInfo(string t, string i, string a, string d,
                   int q, double w, double r) {
    bookTitle = t;
    isbn = i;
    author = a;
    dateAdded = d;
    qtyOnHand = q;
    wholeValue = w;
    retailValue = r;
}

void displayBookInfo(const bookInfo &book)
{
    cout << "\n================= Book Information =================\n";
    cout << left << setw(18) << "Title:"        << book.getBookTitle()      << '\n';
    cout << setw(18) << "ISBN:"                << book.getISBN()       << '\n';
    cout << setw(18) << "Author:"              << book.getAuthor()     << '\n';
    cout << setw(18) << "Date Added:"          << book.getDateAdded()  << '\n';
    cout << setw(18) << "Quantity on Hand:"    << book.getQtyOnHand()  << '\n';
    cout << setw(18) << "Wholesale Cost:"      << "$" << fixed << setprecision(2)
         << book.getWholeValue() << '\n';
    cout << setw(18) << "Retail Price:"        << "$" << fixed << setprecision(2)
         << book.getRetailValue() << '\n';
    cout << "=====================================================\n";
}
