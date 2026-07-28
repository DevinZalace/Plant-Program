#include <algorithm>
#include <cctype>
#include <iomanip>
#include <string>
#include <iostream>
#include "Plants.h"
#include "TerminalUI.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>

namespace {
	std::string lowercase(std::string text) {
		std::transform(text.begin(), text.end(), text.begin(), [](unsigned char character) {
			return static_cast<char>(std::tolower(character));
		});
		return text;
	}
}

// Load the plant catalog from disk into memory.
Plants::Plants(const std::string& filename) {
	std::string lineString;
	std::vector<std::string> lines;
	std::ifstream inputFile(filename);

	if (!inputFile.is_open()) {
		throw std::runtime_error("Could not open data file: " + filename);
	}

	while (std::getline(inputFile, lineString)) {
		if (!lineString.empty() && lineString.back() == '\r') {
			lineString.pop_back();
		}
		lines.push_back(lineString);
	}

	if (inputFile.bad()) {
		throw std::runtime_error("An error occurred while reading: " + filename);
	}

	// Each plant entry spans seven text fields in the data file.
	const int fieldsPerPlant = 7;

	if (lines.empty()) {
		throw std::runtime_error("No plant records were found in: " + filename);
	}

	if (lines.size() % fieldsPerPlant != 0) {
		throw std::runtime_error("Plant data is incomplete or malformed in: " + filename);
	}

	// Determine the number of plants from the file contents.
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

// Print the full details for one plant record.
void Plants::printPlantDetails(const Plant& plant) {
	TerminalUI::printTitle(plant.name, "Plant details");
	TerminalUI::printField("Type", plant.type);
	TerminalUI::printField("Light", plant.light);
	TerminalUI::printField("Water", plant.water);
	TerminalUI::printField("Colors", plant.colors);
	TerminalUI::printField("Toxicity", plant.toxicity);
	TerminalUI::printField("Notes", plant.notes);
	TerminalUI::printBorder();
}

// Display the details for the plant at the requested index.
void Plants::getPlantStringInfo(int i) {
	// Guard against invalid indices before accessing the vector.
	if (i < 0 || i >= static_cast<int>(plants.size())) {
		TerminalUI::printLine("Plant index is out of range.", TerminalUI::red);
		return;
	}

	printPlantDetails(plants[i]);
}

// Print every plant record in the catalog.
void Plants::getAllPlants() {
	TerminalUI::printTitle(
		"PLANT CATALOG",
		std::to_string(plants.size()) + " plants available"
	);

	for (int i = 0; i < static_cast<int>(plants.size()); ++i) {
		const Plant& plant = plants[i];
		std::ostringstream row;
		row << std::right << std::setw(3) << (i + 1) << ".  "
			<< std::left << std::setw(18) << plant.name
			<< plant.type;
		TerminalUI::printLine(row.str());
	}

	TerminalUI::printBorder();
}

// Search for a plant by name and display its details.
bool Plants::getPlantFamily(const std::string& userSearch) {
	const std::string normalizedSearch = lowercase(userSearch);

	for (int i = 0; i < static_cast<int>(plants.size()); ++i) {
		if (normalizedSearch == lowercase(plants[i].name)) {
			printPlantDetails(plants[i]);
			return true;
		}
	}

	return false;
}
