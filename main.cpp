#include <iostream>
#include "sideFunc.h"
#include "Country.h"
using namespace std;
int main()
{
	int numberOfTowns, numberOfRoads, StartingPoint, Destination; // int declerations
	// Set the Country from User
	cout << "enter number of citys and roads" << endl;
	numberOfTowns = getNum();
	numberOfRoads = getNum();
	Country country(numberOfTowns);
	getRoadsFromUser(numberOfRoads, country);
	cout << "Enter Start point (Town number)" << endl;
	StartingPoint = getNum(numberOfTowns);
	Destination = getNum(numberOfTowns);
	// ---------------------------------

	// PreSet For recursive function
	char* TownsColor = new char[numberOfTowns]; // create Color
	setColorArr(TownsColor, numberOfTowns,'W'); // set colors to white for recursive function
	// Recursive function call
	int dBetweenTownsRec = country.TownDistance(StartingPoint, Destination, TownsColor);

	// PreSet for interative function
	setColorArr(TownsColor, numberOfTowns, 'W'); // set colors to white for interative function
	// Interative function call
	int dBetweenTownsIter = country.TownDistanceIterative(StartingPoint, Destination, TownsColor);

	// ---- Print Results ----
	cout << "From recursive function TownDistance found the favorite path long is " << dBetweenTownsRec << endl;
	cout << "From Interative function TownDistance found the favorite path long is " << dBetweenTownsIter << endl;
	// ---- Finish Pogram ----
	cout << "-----------" << endl << endl << "Pogram out!" << endl << endl << "-----------";
	delete[] TownsColor;
}                               