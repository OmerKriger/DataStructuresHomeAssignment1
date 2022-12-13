#ifndef __COUNTRY_H
#define __COUNTRY_H
#define START 1
#define AFTER_REC 2
#define IN_WHILE 3
#include "NodeList.h"
#include "Stack.h"

class Country
{
	NodeList* country;
	int numOfTowns;
	Country(const Country&);
public:
	Country(int numOfTowns);
	~Country();
	void addRoad(int townA,int townB);
	NodeList& operator[](int index);
	const NodeList& operator[](int index) const;
	const int getNumOfTowns() const;
	bool searchRoadBetween(int TownA, int TownB);
	int TownDistance(int StartingPoint, int Destination, char* TownsColor);
	int TownDistanceIterative(int StartingPoint, int Destination, char* TownsColor);
};
#endif