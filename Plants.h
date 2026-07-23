#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Plants {
public:
	Plants();

	void getPlantStringInfo(int i);
	void getAllPlants();
	void getPlantFamily(string userSearch);


private:
	string plantStringInfo[60][7]; // #5 Arrays
	ifstream inFS; // #6 File I/O

};