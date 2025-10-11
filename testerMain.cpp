#include <vector>
#include <iostream>
#include "bookinfo.h"
#include "invmenu.h"
using namespace std;

int main()
{
    vector<bookInfo> inventory;

    inventory.push_back(bookInfo("The Great Gatsby", "9780743273565", "F. Scott Fitzgerald", "2025-01-10", 5, 8.50, 15.99));
    inventory.push_back(bookInfo("Dune", "9780441172719", "Frank Herbert", "2025-03-14", 3, 9.75, 19.99));
    inventory.push_back(bookInfo("1984", "9780451524935", "George Orwell", "2025-04-22", 7, 6.25, 12.99));

    lookUpBook(inventory);
}
