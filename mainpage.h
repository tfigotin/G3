/**
 * \mainpage Serendipity Booksellers – Inventory & POS System
 *
 * \section overview_sec Project Overview
 *
 * Serendipity Booksellers is a small bookstore located in a shopping mall. 
 * The manager requested a point-of-sale (POS) software package that makes
 * the computer function as both a cash register and an inventory database.
 *
 * This project is developed incrementally across multiple chapters, eventually
 * forming a complete, multi-module C++ application.
 *
 * The software performs the following major tasks:
 * - Calculate the total of a sale, including sales tax
 * - Subtract purchased books from the inventory database
 * - Add, change, delete, and look up books in inventory
 * - Display various inventory and sales reports
 *
 * \section modules_sec Program Modules
 *
 * The program is organized into three main modules:
 *
 * - **Cashier Module**  
 *   Acts as a cash register: collects purchases, computes totals and tax,
 *   and deducts quantities from the inventory.
 *
 * - **Inventory Database Module**  
 *   Stores and manages all book records. Supports:
 *   - Lookup (partial title or ISBN)  
 *   - Add new books  
 *   - Edit existing book data  
 *   - Delete books (with compaction)  
 *   - Display individual book information
 *
 * - **Report Module**  
 *   Generates the following reports:
 *   - Complete inventory list  
 *   - Wholesale value report  
 *   - Retail value report  
 *   - Books sorted by quantity  
 *   - Books sorted by wholesale cost  
 *   - Books sorted by date added  
 *
 * \section data_sec Book Record Structure
 *
 * Each book in the inventory stores the following fields:
 * - ISBN (string)  
 * - Title  
 * - Author  
 * - Publisher  
 * - Date Added  
 * - Quantity on Hand  
 * - Wholesale Cost  
 * - Retail Price  
 *
 * \section g4_sec G4 Update — Inventory Edit & Delete (This Lab)
 *
 * In this milestone, you implemented:
 *
 * - **Edit Book**  
 *   Menu-driven modification of any field  
 *   Includes validation and optional duplicate ISBN checks  
 *   Cancel/Save behavior is required  
 *
 * - **Delete Book**  
 *   Uses lookUpBook(...) to find a record  
 *   Confirms deletion  
 *   Removes the book and compacts the inventory  
 *
 * - **Doxygen Documentation**  
 *   Added class/function comments and a main project page  
 *
 * \section behavior_sec Required Behaviors
 *
 * - Search is partial and case-insensitive  
 * - Quantities ≥ 0  
 * - Wholesale/Retail ≥ 0.0  
 * - ISBN stored as string to preserve leading zeros  
 * - Menus must support cancel without corrupting data  
 * - No global inventory; pass containers by reference  
 *
 * \section build_sec Build Instructions
 *
 * Build with:
 * \code
 * g++ -std=c++20 -Wall -Wextra -o main \
 *    mainmenu.cpp bookinfo.cpp cashier.cpp \
 *    invmenu.cpp menuhelpers.cpp reports.cpp
 * \endcode
 *
 * Run:
 * \code
 * ./main
 * \endcode
 *
 * \section team_sec Team
 * - Tamar Figotin  
 * - Luke Leibee  
 *
 */
