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

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    string date, isbn, title;
    int quantity;
    double price, subtotal, tax, total;

    // --- Box with Prompts (input inside the box) ---
    cout << "+--------------------------------------------------+" << endl;
    cout << "|  Serendipity Booksellers                         |" << endl;
    cout << "|    Cashier Module                                |" << endl;
    cout << "|                                                  |" << endl;

    cout << "|  Date: ";
    getline(cin, date);
    cout << "|  Quantity of Book: ";
    cin >> quantity;
    cin.ignore();

    cout << "|  ISBN: ";
    getline(cin, isbn);
    cout << "|  Title: ";
    getline(cin, title);
    cout << "|  Price: ";
    cin >> price;

    cout << "+--------------------------------------------------+" << endl;

    // --- Calculations ---
    subtotal = quantity * price;
    tax = subtotal * 0.06;
    total = subtotal + tax;

    cout << fixed << showpoint << setprecision(2);

    // --- Receipt ---
    cout << "\nSerendipity Book Sellers\n";
    cout << "Date: " << date << endl;

    cout << left << setw(5) << "Qty"
         << setw(15) << "ISBN"
         << setw(25) << "Title"
         << right << setw(8) << "Price"
         << setw(10) << "Total" << endl;

    cout << "--------------------------------------------------------------" << endl;

    cout << left << setw(5) << quantity
         << setw(15) << isbn
         << setw(25) << title
         << right << "$" << setw(7) << price
         << "$" << setw(9) << subtotal << endl;

    cout << endl;
    cout << right << setw(40) << "Subtotal" << " $" << setw(7) << subtotal << endl;
    cout << right << setw(40) << "Tax" << " $" << setw(7) << tax << endl;
    cout << right << setw(40) << "Total" << " $" << setw(7) << total << endl;

    cout << "\nThank You for Shopping at Serendipity!" << endl;

    return 0;
}




