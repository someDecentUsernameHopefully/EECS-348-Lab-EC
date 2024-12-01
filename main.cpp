/*
	This code is simply taken from the lab assignment page.
	I am assuming the spirit of the lab is to actually convert the string to a double.
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Prototype function, defined below.
double extractNumber(const string&);

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
			cout << "The input is: " << fixed << setprecision(4) << output << endl;
		}
		else {
			cout << "The input is invalid!" << endl;
		}
	}

	return 0;
}

double extractNumber(const string& str) {
	double toReturn = 0;
	double multiplier = 0;
	unsigned int length = str.length();
	bool negativeFlag = false;

	try {
		for (unsigned int i = 0; i < length; i++) {
			char character = str[i];
			switch (character) {
			case '+':
				if (i != 0) {
					throw 1;
				}
				break;
			case '-':
				if (i != 0) {
					throw 1;
				}
				else {
					negativeFlag = true;
				}
				break;
			case '.':
				// If decimal multiplier is not zero (placeholder value), then the number is invalid due to having multiple decimal points.
				if (multiplier != 0.) {
					throw 1;
				}
				else {
					// Shift to decimals
					multiplier = 0.1;
				}
				break;
			default:
				// The default behavior for casting strings to integers is to get the ASCII number, so we use that to get a value from 0-9 as follows:
				double num = (double)character - (double)'0';

				// Check if the character is numeric by checking if it's in the range of 0-9:
				if (num < 0. || num > 9.) {
					throw 1;
				}

				// Differing behavior depending on if pre or post decimal point.
				if (multiplier == 0.) {
					toReturn *= 10.;
					toReturn += num;
				}
				else {
					toReturn += num * multiplier;
					multiplier /= 10.;
				}
				break;
			};
		}
	}
	catch (int err) {
		return -999999.99;
	}

	if (negativeFlag) {
		toReturn *= -1.;
	}

	return toReturn;
}