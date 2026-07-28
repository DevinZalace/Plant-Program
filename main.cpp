#include <iostream>
#include <limits>
#include <string>
#include "Plants.h"
#include <cstdlib>
#include <exception>

// Handle the action selected from the primary menu.
void handleMenuChoice(Plants& catalog, const std::string& choice) {
	const int plantCount = catalog.getPlantCount();

	if (choice == "1") {
		const int randomIndex = rand() % plantCount;
		std::cout << "Your random number is " << randomIndex << std::endl;
		catalog.getPlantStringInfo(randomIndex);
		std::cout << std::endl;
	}
	else if (choice == "2") {
		std::string search;
		std::cout << "Please search by Plant Name, sorry must match identically. Enter 1 to quit.\n";

		while (search != "1") {
			std::cin >> search;
			catalog.getPlantFamily(search);
		}
	}
	else if (choice == "3") {
		int plantNumber;
		std::cout << "Please enter a number 1-" << plantCount << " to select a plant from the list.\n";
		std::cin >> plantNumber;

		while ((plantNumber > plantCount) || (plantNumber < 1)) {
			std::cout << "Please enter a valid number 1-" << plantCount << ".\n";
			std::cin >> plantNumber;
		}

		catalog.getPlantStringInfo(plantNumber - 1);
	}
}

// Entry point for the plant information console application.
int main() {
	try {
		std::string userAnswer;
		Plants catalog("stringPlantList.txt");

		// Ask whether the user wants to view the complete plant list first.
		std::cout << "Do you want to see the full plant list first?\n" << "Enter \"y\" or \"n\" \n";
		std::cin >> userAnswer; // Collect the user's initial choice.

		// Validate the user's response until it is accepted.
		while ((userAnswer != "y") && (userAnswer != "n")) {
			std::cout << "Please enter the correct character under our parameters. ";
			std::cin >> userAnswer;
		}

		if (userAnswer == "y") {
			catalog.getAllPlants();
			std::cout << "\nPress Enter to continue...";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.get();
			userAnswer = "y";
		}

		do {
			std::cout << "Would you like a random plant(1) or to search by Plant Family(2) or select by numerical order(3).\n" << "Enter \"1\" or \"2\" or \"3\"\n";
			std::cin >> userAnswer; // Collect the main navigation choice.

			// Validate the selection for the primary menu.
			while ((userAnswer != "1") && (userAnswer != "2") && (userAnswer != "3")) {
				std::cout << "Please enter the correct character under our parameters. ";
				std::cin >> userAnswer;
			}

			handleMenuChoice(catalog, userAnswer);

			// Ask whether the user wants to return to the primary menu.
			std::cout << "Would you like another?\n" << "Enter \"y\" or \"n\" \n";
			std::cin >> userAnswer;

			while ((userAnswer != "y") && (userAnswer != "n")) {
				std::cout << "Please enter the correct character under our parameters. ";
				std::cin >> userAnswer;
			}
		} while (userAnswer == "y");

		std::cout << "Thank you for your interest!\n";
	}
	catch (const std::exception& error) {
		std::cerr << "Plant program could not start: " << error.what() << '\n';
		return 1;
	}
}

