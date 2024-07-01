#pragma once
#ifndef CORNER_GROCER_H
#define CORNER_GROCER_H

#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

class CornerGrocer {
private:
	map<string, int> frequnecyOfItem; // Map to store item frequencies
	string nameOFInpFile; // Input file name
	string nameOFOutFile; // Output file name

public:
	// Constructor to initialize input and output of file names
	CornerGrocer(const string& nameOFInpFile, const string& nameOFOutFile);

	// Function to read data from the input file and populate frequencyOfItem map
	void readDataOFinpFile();

	// Funciton to obtain the frequency of a particular grocer item
	int obtainFrequency(const string& grocerItem);

	// Function to display frequency of all times 
	void displayFrequency();

	// Function to display histogram of item frequencies
	void displayHistogram();

	// Function to create output file with item frequencies for backup
	void createoutFile();
};

// Function to display menu options
void displayMenu();

// Function to handle user choice from the menu and invoke corresponding actions
void handleUserChoice(CornerGrocer& grocer, int choice);

#endif // CORNER_GROCER_H
