/****************************************************************
 * CS1B - G3 : Inventory Submenus                               *
 * Partner A : Tamar Figotin (A00328312) - role: driver         *
 * Partner B : Luke Leibee   (1248406) - role: function         *
 * Due Date  : 2025-09-07                                       *
 * Purpose   : Practice making a multi-file C++ program with    *
 *             menus, input checks, and a simple cashier slip. *
 ****************************************************************/
#include "menuhelpers.h"
#include "reports.h"
#include "bookinfo.h"
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

/***************************************************************
 * Helper: draw a section header
 ***************************************************************/
static void drawHeader(const string &title)
{
    printBorder();
    printEmptyLine();
    printCenteredLine(title);
    printEmptyLine();
    printBorder();
}

/***************************************************************
 * Print Reports Menu
 ***************************************************************/
void printRepMenu(string &repChoice)
{
    printBorder();
    printEmptyLine();
    printCenteredLine("Serendipity Booksellers");
    printCenteredLine("Reports");
    printEmptyLine();

    printLeftLine(PROMPT_START_LENGTH, "1. Inventory Listing");
    printLeftLine(PROMPT_START_LENGTH, "2. Inventory Wholesale Value");
    printLeftLine(PROMPT_START_LENGTH, "3. Inventory Retail Value");
    printLeftLine(PROMPT_START_LENGTH, "4. Listing by Quantity");
    printLeftLine(PROMPT_START_LENGTH, "5. Listing by Cost");
    printLeftLine(PROMPT_START_LENGTH, "6. Listing by Age");
    printLeftLine(PROMPT_START_LENGTH, "7. Return to Main Menu");
    printEmptyLine();

    string prompt = "Enter Your Choice: ";
    string leftPart = string(PROMPT_START_LENGTH, ' ') + prompt;

    cout << "*" << leftPart << flush;

    getline(cin >> ws, repChoice);

    cout << "\033[A\r";

    int maxInputLen = INNER_WIDTH - (int)leftPart.length();
    if (maxInputLen < 0) maxInputLen = 0;

    string displayChoice = repChoice.substr(0, maxInputLen);

    int used = leftPart.length() + displayChoice.length();
    int spaces = INNER_WIDTH - used;
    if (spaces < 0) spaces = 0;

    cout << "*" << leftPart << displayChoice << string(spaces, ' ') << "*" << '\n';

    string selectedLine = "You selected: " + repChoice;
    string leftSel = string(PROMPT_START_LENGTH, ' ') + selectedLine;

    int usedSel = leftSel.length();
    int spacesSel = INNER_WIDTH - usedSel;

    if (spacesSel < 0) {
        int allowed = INNER_WIDTH - PROMPT_START_LENGTH;
        leftSel = string(PROMPT_START_LENGTH, ' ') + selectedLine.substr(0, allowed);
        spacesSel = INNER_WIDTH - leftSel.length();
    }

    cout << "*" << leftSel << string(spacesSel, ' ') << "*" << '\n';
    printBorder();
}

/***************************************************************
 * Main Reports Menu
 ***************************************************************/
void repMenu(vector<bookInfo>& inventory)
{
    string repChoice;

    do {
        clearScreen();
        printRepMenu(repChoice);

        if (repChoice == "1")          invListing(inventory);
        else if (repChoice == "2")     invWholesale(inventory);
        else if (repChoice == "3")     invRetail(inventory);
        else if (repChoice == "4")     quantList(inventory);
        else if (repChoice == "5")     costList(inventory);
        else if (repChoice == "6")     ageList(inventory);
        else if (repChoice == "7")     cout << "Returning...";
        else                           cout << "Invalid choice, select 1–7.\n";

        if (repChoice != "7") {
            cout << "\nPress Enter to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (repChoice != "7");
}

/***************************************************************
 * 1. Inventory Listing
 ***************************************************************/
void invListing(const vector<bookInfo>& inventory)
{
    drawHeader("Inventory Listing");

    vector<bookInfo> temp = inventory;

    sort(temp.begin(), temp.end(),
         [](const bookInfo& a, const bookInfo& b) {
             return a.getBookTitle() < b.getBookTitle();
         });

    for (const auto &book : temp)
        displayBookInfo(book);

    cout << "\nPress Enter to return...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/***************************************************************
 * 2. Wholesale Value
 ***************************************************************/
void invWholesale(const vector<bookInfo>& inventory)
{
    drawHeader("Inventory Wholesale Value");

    double total = 0.0;

    for (const auto &book : inventory)
    {
        total += book.getWholeValue() * book.getQtyOnHand();
        displayBookInfo(book);
    }

    cout << "\nTotal Wholesale Value: $" << fixed << setprecision(2) << total;
    cout << "\n\nPress Enter to return...";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/***************************************************************
 * 3. Retail Value
 ***************************************************************/
void invRetail(const vector<bookInfo>& inventory)
{
    drawHeader("Inventory Retail Value");

    double total = 0.0;

    for (const auto &book : inventory)
    {
        total += book.getRetailValue() * book.getQtyOnHand();
        displayBookInfo(book);
    }

    cout << "\nTotal Retail Value: $" << fixed << setprecision(2) << total;
    cout << "\n\nPress Enter to return...";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/***************************************************************
 * 4. Quantity Listing
 ***************************************************************/
void quantList(const vector<bookInfo>& inventory)
{
    drawHeader("Listing by Quantity");

    vector<bookInfo> temp = inventory;

    sort(temp.begin(), temp.end(),
         [](const bookInfo &a, const bookInfo &b) {
             return a.getQtyOnHand() > b.getQtyOnHand();
         });

    for (const auto &book : temp)
        displayBookInfo(book);

    cout << "\nPress Enter to return...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/***************************************************************
 * 5. Cost Listing
 ***************************************************************/
void costList(const vector<bookInfo>& inventory)
{
    drawHeader("Listing by Wholesale Cost");

    vector<bookInfo> temp = inventory;

    sort(temp.begin(), temp.end(),
         [](const bookInfo &a, const bookInfo &b) {
             return a.getWholeValue() > b.getWholeValue();
         });

    for (const auto &book : temp)
        displayBookInfo(book);

    cout << "\nPress Enter to return...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/***************************************************************
 * 6. Age Listing
 ***************************************************************/
void ageList(const vector<bookInfo>& inventory)
{
    drawHeader("Listing by Age (Oldest → Newest)");

    vector<bookInfo> temp = inventory;

    sort(temp.begin(), temp.end(),
         [](const bookInfo &a, const bookInfo &b) {
             return a.getDateAdded() < b.getDateAdded();
         });

    for (const auto &book : temp)
        displayBookInfo(book);

    cout << "\nPress Enter to return...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
