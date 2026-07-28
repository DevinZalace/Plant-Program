#include <string>
#include <iostream>
#include <fstream>

// Represents the plant lookup system and its data access methods.
class Plants {
public:
	Plants();

	// Display information for one plant entry.
	void getPlantStringInfo(int i);

	// Print the complete list of stored plants.
	void getAllPlants();

	// Search for a plant by family name and show its details.
	void getPlantFamily(std::string userSearch);

private:
	// Stores plant information as 60 records with 7 fields per record.
	std::string plantStringInfo[60][7];
	std::ifstream inFS;
};