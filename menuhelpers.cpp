


#include "menuhelpers.h"
#include <iomanip>

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

void printAddBookArray(const string &s, int i, const string &value) { // function for string
	cout << "* <" << i << "> " << setw(30) << s;

	if(i != 0 && i !=  9) // 0 & 9 do not have pending values
	{
		string displayValue = value; // make copy of value to truncate
		const int WIDTH = 28;

		if (displayValue.length() > WIDTH)
			displayValue = displayValue.substr(0, WIDTH - 3) + "...";

		cout << " > --" << setw(28) << displayValue << "*";
	}

	else
	{
		cout << right << setw(34) << "*";
	}

	cout << endl << left;
}

void printAddBookArray(const string &s, int i, double &valueDouble) {   //function for double
	cout << "* <" << i << "> " << setw(30) << s;
	cout << " > --$" << setw(6) << fixed << setprecision(2) << valueDouble << right << setw(22) << "*";

	cout << endl << left << setprecision(6);
}

void printAddBookArray(const string&s, int i, int &valueInt) { //function for int
	cout << "* <" << i << "> " << setw(30) << s;
	cout << " > --" << setw(5) << valueInt << right << setw(24) << "*";

	cout << endl << left;
}
