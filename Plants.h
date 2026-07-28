#include <string>
#include <vector>

// Represents a single plant record loaded from the data file.
struct Plant {
	std::string name;
	std::string type;
	std::string light;
	std::string water;
	std::string colors;
	std::string toxicity;
	std::string notes;
};

// Stores the plant catalog in memory and provides lookup and display helpers.
class Plants {
public:
	explicit Plants(const std::string& filename);

	// Display information for one plant entry.
	void getPlantStringInfo(int i);

	// Print the complete list of stored plants.
	void getAllPlants();

	// Search for a plant by family name and show its details.
	void getPlantFamily(std::string userSearch);

	// Return the number of plants loaded from the data file.
	int getPlantCount() const;

private:
	// Print the full details for a specific plant record.
	void printPlantDetails(const Plant& plant);

	std::vector<Plant> plants;
};
