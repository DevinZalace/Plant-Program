#include <iostream>
#include <string>
#include <fstream>
#include "Plants.h"
#include <cstdlib>
using namespace std;


int main() {
	ifstream inFS; // #4 Variables
	string userAnswer; // #4 Variables
	Plants userChoice; // #4 Variables
	int randNum, plantNum; // #4 Variables

	inFS.open("stringPlantList.txt"); // #6 File I/O
	if (!inFS.is_open()) { // #9 Control
		cout << "Could not open file plantList.txt." << endl; // #8 Interaction
	}
	cout << "Do you want to see the full plant list first?\n" << "Enter \"y\" or \"n\" \n";  // #8 Interaction
	cin >> userAnswer; // Input for our game
	while ((userAnswer != "y") && (userAnswer != "n")) { // Processing our userAnswer for validation #9 Control
		cout << "Please enter the correct character under our parameters. ";
		cin >> userAnswer; // Reinput if invalid input
	} // end while

	if (userAnswer == "y") {
		userChoice.getAllPlants();
		cout << endl;
		return 0;
	}
	if (userAnswer == "n") { // Process for procedding forward to further user input
		cout << "Would you like a random plant(1) or to search by Plant Family(2) or select by numerical order(3).\n" << "Enter \"1\" or \"2\" or \"3\"\n"; // #8 Interaction
		cin >> userAnswer; // Input for our game
	}
	while ((userAnswer != "1") && (userAnswer != "2") && (userAnswer != "3")) { // Processing our userAnswer for validation #9 Control
		cout << "Please enter the correct character under our parameters. "; // #8 Interaction
		cin >> userAnswer; // Reinput if invalid input
	} // end while
	if (userAnswer == "1") {
		randNum = rand() % 60;
		cout << "Your random number is " << randNum << endl;  //randomly pulls plant information and displays it #8 Interaction
		userChoice.getPlantStringInfo(randNum);
		cout << endl;
	}
	else if (userAnswer == "2") {
		cout << "Please search by Plant Name, sorry must match identically. Enter 1 to quit.\n";
		userAnswer = "0";
		while (userAnswer != "1") {
			cin >> userAnswer;
			userChoice.getPlantFamily(userAnswer);
		} // end while
	}
	else if (userAnswer == "3") {
		cout << "Please enter a number 1-60 to select a plant from the list.\n";
		cin >> plantNum;
		while ((plantNum > 60) || (plantNum < 1)) {
			cout << "Please enter a valid number 1-60.\n";
			cin >> plantNum;
		} // end while
		userChoice.getPlantStringInfo(plantNum);
	}
	cout << "Would you like another?\n" << "Enter \"y\" or \"n\" \n"; // #8 Interaction
	userAnswer = "0";
	cin >> userAnswer; // Input for our game
	while ((userAnswer != "y") && (userAnswer != "n")) { // Processing our userAnswer for validation #9 Control
		cout << "Please enter the correct character under our parameters. "; // #8 Interaction
		cin >> userAnswer; // Reinput if invalid input
	} // end while
	if (userAnswer == "n") {
		cout << "Thank you for your interest!\n"; // #8 Interaction
		return 0;
	}// end if
	if (userAnswer == "y") { // Process for procedding forward to further user input
		cout << "Would you like a random plant(1) or to search by Plant Family(2) or select by numerical order(3).\n" << "Enter \"1\" or \"2\" or \"3\"\n"; // #8 Interaction
		cin >> userAnswer; // Input for our game
	}
	while ((userAnswer != "1") && (userAnswer != "2") && (userAnswer != "3")) { // Processing our userAnswer for validation #9 Control
		cout << "Please enter the correct character under our parameters. "; // #8 Interaction
		cin >> userAnswer; // Reinput if invalid input
	} // end while
	if (userAnswer == "1") {
		randNum = rand() % 60;
		cout << "Your random number is " << randNum << endl;  //randomly pulls plant information and displays it #8 Interaction
		userChoice.getPlantStringInfo(randNum);
		cout << endl;
	}
	else if (userAnswer == "2") {
		cout << "Please search by Plant Name, sorry must match identically. Enter 1 to quit.\n";
		userAnswer = "0";
		while (userAnswer != "1") {
			cin >> userAnswer;
			userChoice.getPlantFamily(userAnswer);
		} // end while
	}
	else if (userAnswer == "3") {
		cout << "Please enter a number 1-60 to select a plant from the list.\n";
		cin >> plantNum;
		while ((plantNum > 60) || (plantNum < 1)) {
			cout << "Please enter a valid number 1-60.\n";
			cin >> plantNum;
		} // end while
		userChoice.getPlantStringInfo(plantNum);
	}
	cout << "Thank you for your interest!\n"; // #8 Interaction
}// end main
