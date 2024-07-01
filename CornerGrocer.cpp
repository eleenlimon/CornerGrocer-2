#include "CornerGrocer.h"

using namespace std;

// Constructor to intialize input and output file names
CornerGrocer::CornerGrocer(const string& nameOFInpFile, const string& nameOFOutFile) {
	this->nameOFInpFile = nameOFInpFile;
	this->nameOFOutFile = nameOFOutFile;
}

// Function to read data from the input file and populate item frequencies
void CornerGrocer::readDataOFinpFile() {
	// Open input file
	ifstream inpFile(nameOFInpFile);
	if (!inpFile) {
		// Print error message if file cannot be opened
		cerr << "Error opening input file." << endl;
		return;
	}
	string groceryItem;
	// Read items from the input file and update their frequencies in map
	while (inpFile >> groceryItem) {
		frequnecyOfItem[groceryItem]++;
	}

	// Close input file
	inpFile.close();
}

// Function to obtain the frequency of specific grocery item
int CornerGrocer::obtainFrequency(const string& groceryItem) {
	return frequnecyOfItem[groceryItem];
}

// Function to display all grocery items and their frequencies
void CornerGrocer::displayFrequency() {
	for (const auto& itemPair : frequnecyOfItem) {
		cout << itemPair.first << " " << itemPair.second << endl;
	}
}

// Fucntion to display histogram of item frequencies using (*)
void CornerGrocer::displayHistogram() {
	for (const auto& itemPair : frequnecyOfItem) {
		cout << itemPair.first << " ";
		// Print (*) corresponding to frequency of each item
		for (int i = 0; i < itemPair.second; i++) {
			cout << "*";
		}
		cout << endl;
	}
}

// Fucntion to create output file with grocery items and their frequencies
void CornerGrocer::createoutFile() {
	// Open output file
	ofstream outFile(nameOFOutFile);
	if (!outFile) {
		// Print error message if file cannot be created 
		cerr << "Error creating output file." << endl;
		return;
	}

	// Write each grocery item and its frequency to output files
	for (const auto& itemPair : frequnecyOfItem) {
		outFile << itemPair.first << " " << itemPair.second << endl;
	}

	// Close output file 
	outFile.close();
	cout << "Output file created successfully." << endl;

}