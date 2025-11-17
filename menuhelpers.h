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

/**
 * @file menuhelpers.h
 * @brief Provides helper functions for printing formatted menus and UI layout.
 */

/** @brief Total width of menu display border. */
const int COLUMN_WIDTH = 70;

/** @brief Inner usable width (excluding border characters). */
const int INNER_WIDTH  = COLUMN_WIDTH - 2;

/** @brief Indentation where prompts begin. */
const int PROMPT_START_LENGTH = 5;

/**
 * @brief Clears the console screen.
 *
 * Platform-independent wrapper used throughout menu displays.
 */
void clearScreen();

/**
 * @brief Prints a full horizontal border line.
 */
void printBorder();

/**
 * @brief Prints an empty bordered line (blank inside).
 */
void printEmptyLine();

/**
 * @brief Prints a centered line of text within the menu borders.
 * @param s The string to center and display.
 */
void printCenteredLine(const string &s);

/**
 * @brief Prints a left-aligned line with indentation inside the menu borders.
 * @param indent Number of spaces before the text.
 * @param s The text to print.
 */
void printLeftLine(int indent, const string &s);

/**
 * @brief Prints an indexed "add book" line for string values.
 * @param s Label text.
 * @param i Index number.
 * @param value The string value to display.
 */
void printAddBookArray(const string &s, int i, const string &value);

/**
 * @brief Prints an indexed "add book" line for double values.
 * @param s Label text.
 * @param i Index number.
 * @param valueDouble Reference to the double value to display.
 */
void printAddBookArray(const string &s, int i, double &valueDouble);

/**
 * @brief Prints an indexed "add book" line for integer values.
 * @param s Label text.
 * @param i Index number.
 * @param valueInt Reference to the int value to display.
 */
void printAddBookArray(const string&s, int i, int &valueInt);

#endif
