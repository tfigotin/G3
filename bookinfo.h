#ifndef BOOKINFO_H
#define BOOKINFO_H

#include <string>

using namespace std;

class bookInfo {
private:
	string bookTitle;
	string isbn;
	string author;
	string publisher;
	string dateAdded;
	int qtyOnHand;
	double wholeValue;
	double retailValue;

public:

	/****************** Constructors ********************/
	bookInfo(); //default
	bookInfo(string title, string isbn, string author, string publisher, string dateAdded,
				int qOnHand, double wValue, double rValue); //full constructor

	/******************** Setters ***********************/
	void setBookTitle(string title) { bookTitle = title; }
   void setISBN(string id) { isbn = id; }
   void setAuthor(string name) { author = name; }
	void setPublisher(string publish) { publisher = publish; }
   void setDateAdded(string date) { dateAdded = date; }
   void setQtyOnHand(int qty) { qtyOnHand = qty; }
   void setWholeValue(double cost) { wholeValue = cost; }
   void setRetailValue(double price) { retailValue = price; }

   /******************** Getters ********************/
   string getBookTitle() const { return bookTitle; }
   string getISBN() const { return isbn; }
   string getAuthor() const { return author; }
	string getPublisher() const { return publisher; }
   string getDateAdded() const { return dateAdded; }
   int getQtyOnHand() const { return qtyOnHand; }
   double getWholeValue() const { return wholeValue; }
   double getRetailValue() const { return retailValue; }
};

void displayBookInfo(const bookInfo &book);

#endif
