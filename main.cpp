#include <iostream>
#include "CornerGrocer.h"

int main() {
	// Define input and output file names
	string nameOFInpFile = "CS210_Project_Three_Input_File.txt";
	string nameOFOutFile = "frequency.dat";

	// Create an instance of CornerGrocer with input and output file names
	CornerGrocer grocer(nameOFInpFile, nameOFOutFile);

	// Read data from input file and populate item frequencies
	grocer.readDataOFinpFile();

	// Create output file with item frequencies for backup
	grocer.createoutFile();

	int userChoice;
	// Display menu and handle user input until user chooses to exit
	do {
		//Display menu
		displayMenu();

		//Prompt user for choice
		cin >> userChoice;

		//Handle user choice based on menu selection
		handleUserChoice(grocer, userChoice);

		//Print newline for formatting
		cout << endl;

	} while (userChoice != 4); //Continue to loop until user chooses option 4 to exit

	return 0;
}