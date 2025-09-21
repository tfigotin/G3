





#include "menuhelpers.h"

void clearScreen() {
    cout << "\033[H\033[J";
}

void printBorder() {
    cout << string(COLUMN_WIDTH, '*') << '\n';
}

void printEmptyLine() {
    cout << "*" << string(INNER_WIDTH, ' ') << "*\n";
}

void printCenteredLine(const string &s) {
    int left  = max(0, (INNER_WIDTH - (int)s.length()) / 2);
    int right = INNER_WIDTH - left - (int)s.length();
    cout << "*" << string(left, ' ') << s << string(right, ' ') << "*\n";
}

void printLeftLine(int indent, const string &s) {
    string line = string(indent, ' ') + s;
    int right   = max(0, INNER_WIDTH - (int)line.length());
    cout << "*" << line << string(right, ' ') << "*\n";
}
