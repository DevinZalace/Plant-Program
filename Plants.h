#include <string>
#include <iostream>
#include <fstream>
#include <vector>

struct Plant {
	std::string name;
	std::string type;
	std::string light;
	std::string water;
	std::string colors;
	std::string toxicity;
	std::string notes;
};

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

	// Return the number of plants loaded from the data file.
	int getPlantCount() const;

private:
	std::vector<Plant> plants;
	std::ifstream inFS;
};