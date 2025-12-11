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

#ifndef REPORTS_H
#define REPORTS_H

#pragma once

#include "bookinfo.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

// Reports Menu
void printRepMenu(string &repChoice);

// Main Reports Menu
void repMenu(vector<bookInfo>& inventory);

// 1. Inventory Listing
void invListing(const vector<bookInfo>& inventory);

// 2. Inventory Wholesale Value
void invWholesale(const vector<bookInfo>& inventory);

// 3. Inventory Retail Value
void invRetail(const vector<bookInfo>& inventory);

// 4. Listing by Quantity
void quantList(const vector<bookInfo>& inventory);

// 5. Listing by Cost
void costList(const vector<bookInfo>& inventory);

// 6. Listing by Age
void ageList(const vector<bookInfo>& inventory);

#endif
