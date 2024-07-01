#include <iostream>
#include <limits> // for numeric_limits
#include "CornerGrocer.h"

using namespace std;

// Function to display menu options
void displayMenu() {
	// Print out the menu options
	cout << "Menu:" << endl;
	cout << "1. Obtain the frequency of a particular item" << endl;
	cout << "2. Print frequency of all items" << endl;
	cout << "3. Print histogram of item frequency" << endl;
	cout << "4. Exit" << endl;
	cout << "Enter your option: ";
}

void handleUserChoice(CornerGrocer& grocer, int choice) {
	// Check if previous input failed (non-int input)
	if (cin.fail()) {
		cout << "Invalid input. Please enter a number." << endl;

		// Clear error state of cin enable further input operations
		cin.clear();

		// Ignore any remaining characters in input buffer up to a newline
		// ensuring the next input operation starts fresh and isn't affected by previous invalid input
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		// Return from the function without processing further, since input is invalid
		return;
	}

	// Handle valid choices based on user input
	switch (choice) {
		case 1: {
			string item;
			cout << "Enter the item you wish to look for: ";
			cin >> item;

			// Display the frequency of the specified grocery item
			cout << "Frequency of " << item << ": " << grocer.obtainFrequency(item) << endl;
			break;
		}
		case 2:
			// Display frequencies of all times
			grocer.displayFrequency();
			break;

		case 3:
			// Display histogram of item frequencies 
			grocer.displayHistogram();
			break;
		case 4:
			// Exit program
			cout << "Exiting program." << endl;
			break;
		default:
			// Handle any other invalid choices not covered by cases 1 to 4
			cout << "Invalid choice. Please try again." << endl;
	}
}