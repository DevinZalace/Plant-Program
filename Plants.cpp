#include <string>
#include <iostream>
#include "Plants.h"
#include <fstream>
#include <stdexcept>
#include <vector>

// Load the plant dataset from disk and build the in-memory catalog.
Plants::Plants(const std::string& filename) {
	std::string lineString;
	std::vector<std::string> lines;
	std::ifstream inputFile(filename);

	if (!inputFile.is_open()) {
		throw std::runtime_error("Could not open data file: " + filename);
	}

	while (std::getline(inputFile, lineString)) {
		lines.push_back(lineString);
	}

	if (inputFile.bad()) {
		throw std::runtime_error("An error occurred while reading: " + filename);
	}

	// Each plant entry consists of seven text fields in the data file.
	const int fieldsPerPlant = 7;

	if (lines.empty()) {
		throw std::runtime_error("No plant records were found in: " + filename);
	}

	if (lines.size() % fieldsPerPlant != 0) {
		throw std::runtime_error("Plant data is incomplete or malformed in: " + filename);
	}

	// The number of plants is derived from the file contents rather than a hard-coded constant.
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

// Print the full details for a specific plant record.
void Plants::printPlantDetails(const Plant& plant) {
	std::cout << "Your plants name followed by type, light level, water level, coloring possibilities, toxicity, and general notes.\n";
	std::cout << "Plant Family: " << plant.name << " \n";
	std::cout << "Plant Type: " << plant.type << " \n";
	std::cout << "Light Level: " << plant.light << " \n";
	std::cout << "Water Level: " << plant.water << " \n";
	std::cout << "Colors: " << plant.colors << " \n";
	std::cout << "Toxicity: " << plant.toxicity << " \n";
	std::cout << "Notes: " << plant.notes << " \n";
}

// Display all fields for a single plant entry at the requested index.
void Plants::getPlantStringInfo(int i) {
	// Guard against invalid indices before accessing the vector.
	if (i < 0 || i >= static_cast<int>(plants.size())) {
		std::cout << "Plant index is out of range.\n";
		return;
	}

	printPlantDetails(plants[i]);
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
			printPlantDetails(plants[i]);
			std::cout << "Enter another or 1 to quit.\n";
			return;
		}
	}

	if (userSearch != "1") {
		std::cout << "Please check input spelling and try again\n";
	}
}
