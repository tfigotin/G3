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

#ifndef BOOKINFO_H
#define BOOKINFO_H

#include <string>

using namespace std;

/**
 * @class bookInfo
 * @brief Stores all information related to a single book in the inventory.
 *
 * This class holds metadata such as title, ISBN, author, publisher, pricing,
 * stock quantity, and the date the book was added.
 */
class bookInfo {
private:
    string bookTitle;     /**< Title of the book */
    string isbn;          /**< ISBN identifier */
    string author;        /**< Author name */
    string publisher;     /**< Publisher name */
    string dateAdded;     /**< Date the book was added to inventory */
    int qtyOnHand;        /**< Number of copies available */
    double wholeValue;    /**< Wholesale cost of the book */
    double retailValue;   /**< Retail price of the book */

public:

    /****************** Constructors ********************/

    /**
     * @brief Default constructor initializes empty book info.
     */
    bookInfo();

    /**
     * @brief Full constructor for initializing all book fields.
     *
     * @param title Title of the book
     * @param isbn ISBN code
     * @param author Author name
     * @param publisher Publisher name
     * @param dateAdded Date book was added to inventory
     * @param qOnHand Quantity available
     * @param wValue Wholesale value
     * @param rValue Retail value
     */
    bookInfo(string title, string isbn, string author, string publisher,
             string dateAdded, int qOnHand, double wValue, double rValue);

    /******************** Setters ***********************/

    /** @brief Sets the title of the book. */
    void setBookTitle(string title) { bookTitle = title; }

    /** @brief Sets the ISBN of the book. */
    void setISBN(string id) { isbn = id; }

    /** @brief Sets the author of the book. */
    void setAuthor(string name) { author = name; }

    /** @brief Sets the publisher of the book. */
    void setPublisher(string publish) { publisher = publish; }

    /** @brief Sets the date the book was added. */
    void setDateAdded(string date) { dateAdded = date; }

    /** @brief Sets the quantity on hand. */
    void setQtyOnHand(int qty) { qtyOnHand = qty; }

    /** @brief Sets the wholesale cost. */
    void setWholeValue(double cost) { wholeValue = cost; }

    /** @brief Sets the retail price. */
    void setRetailValue(double price) { retailValue = price; }

    /******************** Getters ********************/

    /** @brief Returns the book title. */
    string getBookTitle() const { return bookTitle; }

    /** @brief Returns the ISBN. */
    string getISBN() const { return isbn; }

    /** @brief Returns the author name. */
    string getAuthor() const { return author; }

    /** @brief Returns the publisher name. */
    string getPublisher() const { return publisher; }

    /** @brief Returns the date the book was added. */
    string getDateAdded() const { return dateAdded; }

    /** @brief Returns the quantity on hand. */
    int getQtyOnHand() const { return qtyOnHand; }

    /** @brief Returns the wholesale value. */
    double getWholeValue() const { return wholeValue; }

    /** @brief Returns the retail value. */
    double getRetailValue() const { return retailValue; }
};

/**
 * @brief Displays all stored information for a given book.
 *
 * @param book The bookInfo object whose data will be printed.
 */
void displayBookInfo(const bookInfo &book);

#endif
