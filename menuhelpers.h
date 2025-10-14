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

#ifndef MENUHELPERS_H
#define MENUHELPERS_H

#include <iostream>
#include <string>

using namespace std;

// layout constants
const int COLUMN_WIDTH = 70;
const int INNER_WIDTH  = COLUMN_WIDTH - 2;
const int PROMPT_START_LENGTH = 5;

// clear screen
void clearScreen();

// helpers
void printBorder();
void printEmptyLine();
void printCenteredLine(const string &s);
void printLeftLine(int indent, const string &s);
void printAddBookArray(const string &s, int i, const string &value);
void printAddBookArray(const string &s, int i, double &valueDouble);
void printAddBookArray(const string&s, int i, int &valueInt);

#endif
