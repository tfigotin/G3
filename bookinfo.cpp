/****************************************************************
 * CS1B - G3 :             *
 * Partner A : Tamar Figotin (A00328312) - role: driver         *
 * Partner B : Luke Leibee   (1248406) - role: function         *
 * Due Date  : 2025-                                      *
 * Purpose   : .  *
 * Build     :                                     *
 ****************************************************************/

#include "bookinfo.h"


/******************** Default Constructor ********************/
bookInfo::bookInfo() {
    bookTitle = "EMPTY";
    isbn = "EMPTY";
    author = "EMPTY";
    dateAdded = "EMPTY";
    qtyOnHand = 0;
    wholeValue = 0.00;
    retailValue = 0.00;
}

/******************** Full Constructor ********************/
bookInfo::bookInfo(string t, string i, string a, string d,
                   int q, double w, double r) {
    bookTitle = t;
    isbn = i;
    author = a;
    dateAdded = d;
    qtyOnHand = q;
    wholeValue = w;
    retailValue = r;
}
