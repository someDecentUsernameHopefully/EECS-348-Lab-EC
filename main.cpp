/*
	This code is simply taken from the lab assignment page.
	I am assuming the spirit of the lab is to actually convert the string to a double.
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Prototype function, which will be implemented in another file.
double extractNumber(const string& str);

#include "stringToNumber.cpp"

int main() {
	string input;

	while (true) {
		// Get input
		cout << "Enter a string (or 'END' to quit):\t";
		cin >> input;

		// End loop if it should
		if (input == "END") {
			break;
		}

		// Get number as double and print it back to the user.
		double output = extractNumber(input);

		if (output != -999999.99) {
			cout << "The input is: " << fixed << setprecision(4) << number << endl;
		}
		else {
			cout << "The input is invalid!" << endl;
		}
	}

	return 0;
}