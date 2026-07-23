#include <string>
#include <iostream>
#include "Plants.h"
#include <cstdlib>
#include <time.h>
#include <fstream>

using namespace std;



Plants::Plants() {

	string lineString; // #4 Variables

	inFS.open("stringPlantList.txt"); // #6 File I/O
	for (int i = 0; i < 60; ++i) {  // #7 Iteration (loops)
		for (int j = 0; j < 7; ++j) { // #7 Iteration (loops)
			getline(inFS, lineString); // #6 File I/O
			plantStringInfo[i][j] = lineString; // #5 Arrays
		}
	}

}// end constructor

void Plants::getPlantStringInfo(int i) {
	cout << "Your plants name followed by type, light level, water level, coloring possibilities, toxicity, and general notes.\n";
	cout << "Plant Family: " << plantStringInfo[i][0] << " \n";
	cout << "Plant Type: " << plantStringInfo[i][1] << " \n";
	cout << "Light Level: " << plantStringInfo[i][2] << " \n";
	cout << "Water Level: " << plantStringInfo[i][3] << " \n";
	cout << "Colors: " << plantStringInfo[i][4] << " \n";
	cout << "Toxicity: " << plantStringInfo[i][5] << " \n";
	cout << "Notes: " << plantStringInfo[i][6] << " \n";


}
void Plants::getAllPlants() {
	cout << "Your plants name followed by type, light level, water level, coloring possibilities, toxicity, and general notes.\n";
	for (int i = 0; i < 60; i++) // Process for displaying our array #7 Iteration (loops)
	{
		for (int j = 0; j < 7; j++) // Process for displaying our array #7 Iteration (loops)
		{
			cout << plantStringInfo[i][j] << " " << endl;; // Process for displaying our array
		}// end for j
		cout << "\n";
	} // end for i2
}

void Plants::getPlantFamily(string userSearch) {
	for (int i = 0; i < 60; i++) 
	{
		if (userSearch == plantStringInfo[i][0]) {
			cout << "Your plants name followed by type, light level, water level, coloring possibilities, toxicity, and general notes.\n";
			cout << "Plant Family: " << plantStringInfo[i][0] << " \n";
			cout << "Plant Type: " << plantStringInfo[i][1] << " \n";
			cout << "Light Level: " << plantStringInfo[i][2] << " \n";
			cout << "Water Level: " << plantStringInfo[i][3] << " \n";
			cout << "Colors: " << plantStringInfo[i][4] << " \n";
			cout << "Toxicity: " << plantStringInfo[i][5] << " \n";
			cout << "Notes: " << plantStringInfo[i][6] << " \n";
			cout << "Enter another or 1 to quit.\n";
			break;
		}
		else if ((userSearch != plantStringInfo[i][0]) && (i == 59) && (userSearch != "1")) {
			cout << "Please check input spelling and try again\n";
		}
	}

}