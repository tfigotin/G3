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

#ifndef INVMENU_H
#define INVMENU_H

#include <vector>
#include "bookinfo.h"

// Inventory menu function
void invMenu(std::vector<bookInfo>& inventory);

// Stub functions
//void lookUpBook();
void addBook(std::vector<bookInfo>& inventory);
void editBook(std::vector<bookInfo>& inventory);
void deleteBook(std::vector<bookInfo>& inventory);

// Look Up Book
void lookUpBook(std::vector<bookInfo> &inventory);

#endif




