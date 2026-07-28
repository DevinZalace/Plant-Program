#include <iostream>
#include <string>
#include <fstream>
#include "Plants.h"
#include <cstdlib>

// Entry point for the plant information console application.
int main() {
	std::ifstream inFS;
	std::string userAnswer;
	Plants userChoice;
	int randNum, plantNum;

	// Attempt to open the plant data file before the program begins.
	inFS.open("stringPlantList.txt");
	if (!inFS.is_open()) {
		std::cout << "Could not open file plantList.txt." << std::endl;
	}

	// Ask whether the user wants to view the complete plant list first.
	std::cout << "Do you want to see the full plant list first?\n" << "Enter \"y\" or \"n\" \n";
	std::cin >> userAnswer; // Collect the user's initial choice.

	// Validate the user's response until it is accepted.
	while ((userAnswer != "y") && (userAnswer != "n")) {
		std::cout << "Please enter the correct character under our parameters. ";
		std::cin >> userAnswer;
	}

	if (userAnswer == "y") {
		userChoice.getAllPlants();
		std::cout << std::endl;
		return 0;
	}

	if (userAnswer == "n") {
		std::cout << "Would you like a random plant(1) or to search by Plant Family(2) or select by numerical order(3).\n" << "Enter \"1\" or \"2\" or \"3\"\n";
		std::cin >> userAnswer; // Collect the main navigation choice.
	}

	// Validate the selection for the primary menu.
	while ((userAnswer != "1") && (userAnswer != "2") && (userAnswer != "3")) {
		std::cout << "Please enter the correct character under our parameters. ";
		std::cin >> userAnswer;
	}

	if (userAnswer == "1") {
		randNum = rand() % 60;
		std::cout << "Your random number is " << randNum << std::endl;
		userChoice.getPlantStringInfo(randNum);
		std::cout << std::endl;
	}
	else if (userAnswer == "2") {
		std::cout << "Please search by Plant Name, sorry must match identically. Enter 1 to quit.\n";
		userAnswer = "0";
		while (userAnswer != "1") {
			std::cin >> userAnswer;
			userChoice.getPlantFamily(userAnswer);
		}
	}
	else if (userAnswer == "3") {
		std::cout << "Please enter a number 1-60 to select a plant from the list.\n";
		std::cin >> plantNum;
		while ((plantNum > 60) || (plantNum < 1)) {
			std::cout << "Please enter a valid number 1-60.\n";
			std::cin >> plantNum;
		}
		userChoice.getPlantStringInfo(plantNum - 1);
	}

	// Offer the user another selection after the first action completes.
	std::cout << "Would you like another?\n" << "Enter \"y\" or \"n\" \n";
	userAnswer = "0";
	std::cin >> userAnswer;

	while ((userAnswer != "y") && (userAnswer != "n")) {
		std::cout << "Please enter the correct character under our parameters. ";
		std::cin >> userAnswer;
	}

	if (userAnswer == "n") {
		std::cout << "Thank you for your interest!\n";
		return 0;
	}

	if (userAnswer == "y") {
		std::cout << "Would you like a random plant(1) or to search by Plant Family(2) or select by numerical order(3).\n" << "Enter \"1\" or \"2\" or \"3\"\n";
		std::cin >> userAnswer;
	}

	while ((userAnswer != "1") && (userAnswer != "2") && (userAnswer != "3")) {
		std::cout << "Please enter the correct character under our parameters. ";
		std::cin >> userAnswer;
	}

	if (userAnswer == "1") {
		randNum = rand() % 60;
		std::cout << "Your random number is " << randNum << std::endl;
		userChoice.getPlantStringInfo(randNum);
		std::cout << std::endl;
	}
	else if (userAnswer == "2") {
		std::cout << "Please search by Plant Name, sorry must match identically. Enter 1 to quit.\n";
		userAnswer = "0";
		while (userAnswer != "1") {
			std::cin >> userAnswer;
			userChoice.getPlantFamily(userAnswer);
		}
	}
	else if (userAnswer == "3") {
		std::cout << "Please enter a number 1-60 to select a plant from the list.\n";
		std::cin >> plantNum;
		while ((plantNum > 60) || (plantNum < 1)) {
			std::cout << "Please enter a valid number 1-60.\n";
			std::cin >> plantNum;
		}
		userChoice.getPlantStringInfo(plantNum - 1);
	}

	std::cout << "Thank you for your interest!\n";
}

