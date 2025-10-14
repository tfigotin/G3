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
#ifndef CASHIER_H
#define CASHIER_H

#include <string>
using namespace std;

// function prototype for cashier module
void cashier();

// prototypes for helpers (if you need them outside cashier.cpp)
void printTopBorder();
void printBottomBorder();
void printLine(const string &text);

void printReceiptTop();
void printReceiptBottom();
void printReceiptLine(const string &text);

string truncate(const string &s, size_t width);

#endif
