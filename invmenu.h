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
#ifndef INVMENU_H
#define INVMENU_H

#include <vector>
#include "bookinfo.h"

/**
 * @brief Displays the inventory menu and handles user selections.
 *
 * This function provides the main interface for managing the inventory of books.
 *
 * @param inventory Reference to a vector of bookInfo objects representing
 *                  the current inventory.
 */
void invMenu(std::vector<bookInfo>& inventory);

/**
 * @brief Adds a new book to the inventory.
 *
 * @param inventory Reference to the vector of bookInfo objects where the
 *                  new book will be added.
 */
void addBook(std::vector<bookInfo>& inventory);

/**
 * @brief Edits the information of an existing book in the inventory.
 *
 * @param inventory Reference to the vector of bookInfo objects containing
 *                  the book to be edited.
 */
void editBook(std::vector<bookInfo>& inventory);

/**
 * @brief Deletes a book from the inventory.
 *
 * @param inventory Reference to the vector of bookInfo objects from which
 *                  a book will be removed.
 */
void deleteBook(std::vector<bookInfo>& inventory);

/**
 * @brief Searches the inventory for a book based on user input.
 *
 * @param inventory Reference to the vector of bookInfo objects to search through.
 * @return The index of the found book, or -1 if not found.
 */
int lookUpBook(std::vector<bookInfo> &inventory);

#endif




