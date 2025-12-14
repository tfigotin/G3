#ifndef INVENTORYLIST_H
#define INVENTORYLIST_H

#include "bookinfo.h"

struct bookNode
{
    bookInfo book;
    bookNode* next;

    bookNode(const bookInfo& b)
        : book(b), next(NULL) {}
};

class InventoryList
{
private:
    bookNode* head;
    size_t count;

public:
    static int sortCode;

    InventoryList();
    ~InventoryList();

    // Core list operations
    void insert(const bookInfo& book);
    void remove(bookNode* node);

    // Lookup
    bookNode* findISBN(const std::string& isbn) const;

    // Utilities
    bookNode* getHead() const;
    int size() const;
    bool empty() const;
};

#endif

