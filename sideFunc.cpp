#include "sideFunc.h"
#include "Country.h"
#include <iostream>
using namespace std;

int getNum()
{
	int num;
	cin >> num;
	while (num <= 0)
	{
		cout << "Number should be positive !, try again" << endl;
		cin >> num;
	}
	return num;
}
int getNum(int maxNum)
{
	int num = getNum();
	while (maxNum < num)
	{
		cout << "The number shoudn't be greater than " << maxNum << " , please try again" << endl;
	}
	return num;
}
void getRoadsFromUser(int numberOfRoads, Country& country)
{
	cout << "enter the road between two towns (two numbers):"<< endl;
	int numOfTowns = country.getNumOfTowns();
	for (int i = 0; i < numberOfRoads; i++)
	{
		int townA = getNum(), townB = getNum();
		bool roadExist = country.searchRoadBetween(townA-1, townB-1);
		while (townA > numOfTowns || townB > numOfTowns || townA == townB || roadExist)
		{
			if (townA == townB)
				cout << "Road cannot be from town to same town, please try again" << endl;
			else if (roadExist)
				cout << "This road between" << townA << "and " << townB << "already exist, please try again" << endl;
			else 
				cout << "one of the towns isn't exist, please try again (between 1 to " << numOfTowns << ")" << endl;
			cout << "enter the road between two towns (two numbers):" << endl;
			townA = getNum();
			townB = getNum();
			roadExist = country.searchRoadBetween(townA-1, townB-1);
		}
		country.addRoad(townA, townB);
	}
}
void setColorArr(char* TownsColor,int size ,char color)
{
	for (int i = 0; i < size; i++)
		TownsColor[i] = color;
}
