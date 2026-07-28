#include <string>
#include <iostream>
#include "Plants.h"
#include <cstdlib>
#include <time.h>
#include <fstream>

// Constructor loads the plant dataset from the text file into memory.
Plants::Plants() {
	std::string lineString;

	inFS.open("stringPlantList.txt");
	for (int i = 0; i < 60; ++i) {
		for (int j = 0; j < 7; ++j) {
			std::getline(inFS, lineString);
			plantStringInfo[i][j] = lineString;
		}
	}
}

// Display all fields for a single plant entry at the requested index.
void Plants::getPlantStringInfo(int i) {
	std::cout << "Your plants name followed by type, light level, water level, coloring possibilities, toxicity, and general notes.\n";
	std::cout << "Plant Family: " << plantStringInfo[i][0] << " \n";
	std::cout << "Plant Type: " << plantStringInfo[i][1] << " \n";
	std::cout << "Light Level: " << plantStringInfo[i][2] << " \n";
	std::cout << "Water Level: " << plantStringInfo[i][3] << " \n";
	std::cout << "Colors: " << plantStringInfo[i][4] << " \n";
	std::cout << "Toxicity: " << plantStringInfo[i][5] << " \n";
	std::cout << "Notes: " << plantStringInfo[i][6] << " \n";
}

// Print every plant record stored in the dataset.
void Plants::getAllPlants() {
	std::cout << "Your plants name followed by type, light level, water level, coloring possibilities, toxicity, and general notes.\n";
	for (int i = 0; i < 60; i++) {
		for (int j = 0; j < 7; j++) {
			std::cout << plantStringInfo[i][j] << " " << std::endl;
		}
		std::cout << "\n";
	}
}

// Search for a matching plant family name and display its details.
void Plants::getPlantFamily(std::string userSearch) {
	for (int i = 0; i < 60; i++) {
		if (userSearch == plantStringInfo[i][0]) {
			std::cout << "Your plants name followed by type, light level, water level, coloring possibilities, toxicity, and general notes.\n";
			std::cout << "Plant Family: " << plantStringInfo[i][0] << " \n";
			std::cout << "Plant Type: " << plantStringInfo[i][1] << " \n";
			std::cout << "Light Level: " << plantStringInfo[i][2] << " \n";
			std::cout << "Water Level: " << plantStringInfo[i][3] << " \n";
			std::cout << "Colors: " << plantStringInfo[i][4] << " \n";
			std::cout << "Toxicity: " << plantStringInfo[i][5] << " \n";
			std::cout << "Notes: " << plantStringInfo[i][6] << " \n";
			std::cout << "Enter another or 1 to quit.\n";
			break;
		}
		else if ((userSearch != plantStringInfo[i][0]) && (i == 59) && (userSearch != "1")) {
			std::cout << "Please check input spelling and try again\n";
		}
	}
}