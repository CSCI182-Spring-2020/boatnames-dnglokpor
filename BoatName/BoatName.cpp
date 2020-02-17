/*
CSCI 182 - Assignment 6
BoatName.cpp
Read a file, copy its content into an array and print the array

Brett Huffman
v1.0 2/16/2020
*/

#include <iostream>
#include <iomanip>
#include <fstream>

#define MAX_BOAT_COUNT 30

using namespace std;

struct Boat {
	int nYearBuilt;
	string Name;
};

/// <summary>
/// Print out the information on all the boats of the passed fleet
/// </summary>
void ShowFleet(Boat aFleet[]) {
	for (int thisBoat = 0; thisBoat < MAX_BOAT_COUNT; thisBoat++) {
		cout << (thisBoat + 1) << " " << aFleet[thisBoat].Name << " " << aFleet[thisBoat].nYearBuilt << endl;
	}
}

int main()
{


	// Start by reading in the files
	ifstream inFile;

	inFile.open("BoatNames.txt");
	if (!inFile) {
		cout << "Unable to open file";
		exit(1); // terminate with error
	}


	Boat Fleet[MAX_BOAT_COUNT];

	// Put all the boat names into an array, then print them to the screen
	char tempName[80];
	int nYear;
	int importCount = 0;

	// Read the input file for each player
	while (!inFile.eof() && importCount < MAX_BOAT_COUNT) {
		// Read in line
		inFile >> tempName >> nYear;


		// Write to Fleet's Structure here
		Fleet[importCount].Name = tempName;
		Fleet[importCount].nYearBuilt = nYear;

		importCount++;
	}
	// Close the input file
	inFile.close();


	// Now, print out each boat name by calling a
	// function to print each array item
	ShowFleet(Fleet);



}