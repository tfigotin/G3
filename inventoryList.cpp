#include "inventoryList.h"
#include <iostream>

int InventoryList::sortCode = 0;

/******************** Constructor ********************/
InventoryList::InventoryList()
{
    head = nullptr;
    count = 0;
}

/******************** Destructor ********************/
InventoryList::~InventoryList()
{
    bookNode* curr = head;
    while (curr)
    {
        bookNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

/******************** Insert (ORDERED) ********************/
void InventoryList::insert(const bookInfo& book)
{
    bookNode* newNode = new bookNode(book);

    // Insert at head
    if (!head ||
        (sortCode == 0 && book.getBookTitle() < head->book.getBookTitle()) ||
        (sortCode == 1 && book.getISBN() < head->book.getISBN()) ||
        (sortCode == 2 && book.getAuthor() < head->book.getAuthor()))
    {
        newNode->next = head;
        head = newNode;
        count++;
        return;
    }

    bookNode* curr = head;

    while (curr->next &&
          !(
            (sortCode == 0 && book.getBookTitle() < curr->next->book.getBookTitle()) ||
            (sortCode == 1 && book.getISBN() < curr->next->book.getISBN()) ||
            (sortCode == 2 && book.getAuthor() < curr->next->book.getAuthor())
           ))
    {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
    count++;
}

/******************** Remove ********************/
void InventoryList::remove(bookNode* node)
{
    if (!head || !node) return;

    if (head == node)
    {
        bookNode* temp = head;
        head = head->next;
        delete temp;
        count--;
        return;
    }

    bookNode* curr = head;
    while (curr->next && curr->next != node)
        curr = curr->next;

    if (curr->next == node)
    {
        curr->next = node->next;
        delete node;
        count--;
    }
}

/******************** Lookup ********************/
bookNode* InventoryList::findISBN(const std::string& isbn) const
{
    for (bookNode* curr = head; curr; curr = curr->next)
    {
        if (curr->book.getISBN() == isbn)
            return curr;
    }
    return nullptr;
}

/******************** Utilities ********************/
bookNode* InventoryList::getHead() const
{
    return head;
}

int InventoryList::size() const
{
    return count;
}

bool InventoryList::empty() const
{
    return head == nullptr;
}
