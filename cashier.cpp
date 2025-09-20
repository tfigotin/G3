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

    // --- Input prompts ---
    cout << "Enter Date (MM/DD/YY): ";
    getline(cin, date);

    cout << "Enter Quantity of Book: ";
    cin >> quantity;
    cin.ignore();

    cout << "Enter ISBN: ";
    getline(cin, isbn);

    cout << "Enter Title: ";
    getline(cin, title);

    cout << "Enter Price: ";
    cin >> price;

    // --- Calculations ---
    subtotal = quantity * price;
    tax = subtotal * 0.06;
    total = subtotal + tax;

    cout << fixed << showpoint << setprecision(2);

    // --- Redraw box with inputs inside ---
    cout << "\n+--------------------------------------------------+\n";
    cout << "|  Serendipity Booksellers                         |\n";
    cout << "|    Cashier Module                                |\n";
    cout << "|                                                  |\n";

    // Values filled in here
    cout << "|  Date: " << date;
    cout << string(46 - date.size(), ' ') << "|\n";

    cout << "|  Quantity of Book: " << quantity;
    cout << string(33 - to_string(quantity).size(), ' ') << "|\n";

    cout << "|  ISBN: " << isbn;
    cout << string(43 - isbn.size(), ' ') << "|\n";

    cout << "|  Title: " << title;
    cout << string(42 - title.size(), ' ') << "|\n";

    cout << "|  Price: " << price;
    string priceStr = to_string(price);
    cout << string(42 - priceStr.size(), ' ') << "|\n";

    cout << "+--------------------------------------------------+\n";

	// --- Boxed Receipt ---
    cout << "+--------------------------------------------------------------+\n";
    cout << "|  Serendipity Book Sellers                                    |\n";
    cout << "|  Date: " << date
         << string(56 - date.size(), ' ') << "|\n";
    cout << "|                                                              |\n";

    cout << "|  " << left << setw(4) << "Qty"
         << setw(15) << "ISBN"
         << setw(25) << "Title"
         << right << setw(8) << "Price"
         << setw(10) << "Total"
         << " |\n";

    cout << "|  " << string(60, '-') << "  |\n";

    ostringstream subtotalStr;
    subtotalStr << fixed << setprecision(2) << subtotal;

    cout << "|  " << left << setw(4) << quantity
         << setw(15) << isbn
         << setw(25) << title
         << " $" << setw(7) << price
         << " $" << setw(9) << subtotal << " |\n";

    cout << "|                                                              |\n";
    cout << "|                                    Subtotal $" << setw(7) << subtotal << " |\n";
    cout << "|                                         Tax $" << setw(7) << tax << " |\n";
    cout << "|                                       Total $" << setw(7) << total << " |\n";
    cout << "|                                                              |\n";
    cout << "|  Thank You for Shopping at Serendipity!                      |\n";
    cout << "+--------------------------------------------------------------+\n";

    return 0;
}




