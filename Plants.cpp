#include <string>
#include <iostream>
#include "Plants.h"
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <vector>

// Constructor loads the plant dataset from the text file into memory.
Plants::Plants() {
	std::string lineString;
	std::vector<std::string> lines;

	inFS.open("stringPlantList.txt");
	if (!inFS.is_open()) {
		std::cerr << "Could not open file stringPlantList.txt." << std::endl;
		return;
	}

	while (std::getline(inFS, lineString)) {
		lines.push_back(lineString);
	}

	inFS.close();

	const int fieldsPerPlant = 7;
	const int plantCount = static_cast<int>(lines.size() / fieldsPerPlant);
	plants.reserve(plantCount);

	for (int i = 0; i < plantCount; ++i) {
		const int base = i * fieldsPerPlant;
		Plant plant;
		plant.name = lines[base];
		plant.type = lines[base + 1];
		plant.light = lines[base + 2];
		plant.water = lines[base + 3];
		plant.colors = lines[base + 4];
		plant.toxicity = lines[base + 5];
		plant.notes = lines[base + 6];
		plants.push_back(plant);
	}
}

int Plants::getPlantCount() const {
	return static_cast<int>(plants.size());
}

// Display all fields for a single plant entry at the requested index.
void Plants::getPlantStringInfo(int i) {
	if (i < 0 || i >= static_cast<int>(plants.size())) {
		std::cout << "Plant index is out of range.\n";
		return;
	}

	const Plant& plant = plants[i];
	std::cout << "Your plants name followed by type, light level, water level, coloring possibilities, toxicity, and general notes.\n";
	std::cout << "Plant Family: " << plant.name << " \n";
	std::cout << "Plant Type: " << plant.type << " \n";
	std::cout << "Light Level: " << plant.light << " \n";
	std::cout << "Water Level: " << plant.water << " \n";
	std::cout << "Colors: " << plant.colors << " \n";
	std::cout << "Toxicity: " << plant.toxicity << " \n";
	std::cout << "Notes: " << plant.notes << " \n";
}

// Print every plant record stored in the dataset.
void Plants::getAllPlants() {
	std::cout << "Your plants name followed by type, light level, water level, coloring possibilities, toxicity, and general notes.\n";
	for (int i = 0; i < static_cast<int>(plants.size()); ++i) {
		const Plant& plant = plants[i];
		std::cout << plant.name << " " << plant.type << " " << plant.light << " " << plant.water << " " << plant.colors << " " << plant.toxicity << " " << plant.notes << std::endl;
		std::cout << "\n";
	}
}

// Search for a matching plant family name and display its details.
void Plants::getPlantFamily(std::string userSearch) {
	for (int i = 0; i < static_cast<int>(plants.size()); ++i) {
		if (userSearch == plants[i].name) {
			std::cout << "Your plants name followed by type, light level, water level, coloring possibilities, toxicity, and general notes.\n";
			std::cout << "Plant Family: " << plants[i].name << " \n";
			std::cout << "Plant Type: " << plants[i].type << " \n";
			std::cout << "Light Level: " << plants[i].light << " \n";
			std::cout << "Water Level: " << plants[i].water << " \n";
			std::cout << "Colors: " << plants[i].colors << " \n";
			std::cout << "Toxicity: " << plants[i].toxicity << " \n";
			std::cout << "Notes: " << plants[i].notes << " \n";
			std::cout << "Enter another or 1 to quit.\n";
			return;
		}
	}

	if (userSearch != "1") {
		std::cout << "Please check input spelling and try again\n";
	}
}