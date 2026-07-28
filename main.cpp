#include <exception>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include "Plants.h"
#include "TerminalUI.h"

// Show the main navigation screen.
void printMainMenu(int plantCount) {
	TerminalUI::clearScreen();
	TerminalUI::printTitle(
		"PLANT PROGRAM",
		"Explore " + std::to_string(plantCount) + " ornamental plants"
	);
	TerminalUI::printLine();
	TerminalUI::printMenuOption("1", "Show me a random plant");
	TerminalUI::printMenuOption("2", "Search by plant family");
	TerminalUI::printMenuOption("3", "Select by catalog number");
	TerminalUI::printMenuOption("4", "Browse the complete catalog");
	TerminalUI::printMenuOption("Q", "Quit");
	TerminalUI::printLine();
	TerminalUI::printBorder('=');
}

// Read a catalog number without leaving invalid input in the stream.
bool parseCatalogNumber(const std::string& input, int maxValue, int& value) {
	std::istringstream inputStream(input);
	char extraCharacter;

	return inputStream >> value
		&& value >= 1
		&& value <= maxValue
		&& !(inputStream >> extraCharacter);
}

// Search repeatedly until the user returns to the main menu.
void showSearch(Plants& catalog) {
	while (true) {
		TerminalUI::clearScreen();
		TerminalUI::printTitle("SEARCH", "Plant family names are not case-sensitive");
		TerminalUI::printLine("Enter a complete plant family name, or B to go back.");
		TerminalUI::printBorder();

		const std::string search = TerminalUI::trim(TerminalUI::readLine("\nSearch: "));
		if (TerminalUI::lowercase(search) == "b") {
			return;
		}

		TerminalUI::clearScreen();
		if (!catalog.getPlantFamily(search)) {
			TerminalUI::printTitle("NO MATCH");
			TerminalUI::printLine(
				"No plant family matched \"" + search + "\".",
				TerminalUI::red
			);
			TerminalUI::printLine("Check the spelling or browse the catalog for available names.");
			TerminalUI::printBorder();
		}

		TerminalUI::pause();
	}
}

// Prompt until the user selects a valid catalog number or goes back.
void showNumberSelection(Plants& catalog) {
	const int plantCount = catalog.getPlantCount();

	while (true) {
		TerminalUI::clearScreen();
		TerminalUI::printTitle(
			"SELECT BY NUMBER",
			"Choose a catalog number from 1 to " + std::to_string(plantCount)
		);
		TerminalUI::printLine("Enter B to return to the main menu.");
		TerminalUI::printBorder();

		const std::string input = TerminalUI::trim(TerminalUI::readLine("\nCatalog number: "));
		if (TerminalUI::lowercase(input) == "b") {
			return;
		}

		int plantNumber;
		if (parseCatalogNumber(input, plantCount, plantNumber)) {
			TerminalUI::clearScreen();
			catalog.getPlantStringInfo(plantNumber - 1);
			TerminalUI::pause();
			return;
		}

		std::cout << '\n' << TerminalUI::red
			<< "Please enter a whole number from 1 to " << plantCount << "."
			<< TerminalUI::reset << '\n';
		TerminalUI::pause();
	}
}

// Handle the action selected from the main menu.
void handleMenuChoice(Plants& catalog, const std::string& choice) {
	if (choice == "1") {
		static std::mt19937 generator(std::random_device{}());
		std::uniform_int_distribution<int> distribution(0, catalog.getPlantCount() - 1);

		TerminalUI::clearScreen();
		catalog.getPlantStringInfo(distribution(generator));
		TerminalUI::pause();
	}
	else if (choice == "2") {
		showSearch(catalog);
	}
	else if (choice == "3") {
		showNumberSelection(catalog);
	}
	else if (choice == "4") {
		TerminalUI::clearScreen();
		catalog.getAllPlants();
		TerminalUI::pause();
	}
}

// Entry point for the plant information console application.
int main() {
	try {
		Plants catalog("stringPlantList.txt");

		while (true) {
			printMainMenu(catalog.getPlantCount());
			const std::string choice = TerminalUI::lowercase(
				TerminalUI::trim(TerminalUI::readLine("\nChoose an option: "))
			);

			if (choice == "q") {
				break;
			}

			if (choice == "1" || choice == "2" || choice == "3" || choice == "4") {
				handleMenuChoice(catalog, choice);
			}
			else {
				std::cout << '\n' << TerminalUI::red
					<< "Please choose 1, 2, 3, 4, or Q."
					<< TerminalUI::reset << '\n';
				TerminalUI::pause();
			}
		}

		TerminalUI::clearScreen();
		TerminalUI::printTitle("THANK YOU", "Happy growing!");
	}
	catch (const std::exception& error) {
		std::cerr << TerminalUI::red
			<< "Plant program could not start: " << error.what()
			<< TerminalUI::reset << '\n';
		return 1;
	}
}

