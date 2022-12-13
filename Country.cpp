#include "Country.h"


Country::Country(int numOfTowns)
{
	country = new NodeList[numOfTowns];
	this->numOfTowns = numOfTowns;
}
Country::~Country()
{
	delete[] country;
}
void Country::addRoad(int townA, int townB)
{
	this->country[townA - 1].insertNode(townB);
	this->country[townB - 1].insertNode(townA);
}
bool Country::searchRoadBetween(int TownA, int TownB)
{
	return this->country[TownA].searchNodeInList(TownB);
}
NodeList& Country::operator[](int index)
{
	return country[index];
}
const NodeList& Country::operator[](int index) const
{
	return country[index];
}
const int Country::getNumOfTowns() const
{
	return numOfTowns;
}
int Country::TownDistance(int StartingPoint, int Destination, char* TownsColor)
{
	TownsColor[StartingPoint - 1] = 'B';
	if (StartingPoint == Destination)
		return 0;
	else
	{
		Node* nearbyTown = country[StartingPoint - 1].getHead();
		while (nearbyTown != nullptr)
		{
			if (TownsColor[nearbyTown->getTownNumber() - 1] == 'W')
			{
				int distance = TownDistance(nearbyTown->getTownNumber(), Destination, TownsColor);
				if (distance != -1)
					return distance + 1;
			}
			nearbyTown = nearbyTown->getNextTown();

		}
		return -1;
	}
}
int Country::TownDistanceIterative(int StartingPoint, int Destination, char* TownsColor)
{
	Stack stack; // set empty stack
	bool returnFromRec = false,skip = false; // some flags for the function
	DataItem curr(StartingPoint,START); // create starting item
	int returnedValue = -1;
	do
	{
		if (returnFromRec)
			curr = stack.pop();

		switch (curr.getLine())
		{
		case START:
			TownsColor[curr.getStartingPoint() - 1] = 'B';  // set color of starting point to Black
			if (curr.getStartingPoint() == Destination)
			{
				returnFromRec = true;
				returnedValue = 0;
				break;
			}
		case IN_WHILE:
			if(curr.getTown() == nullptr) // check for first time run of this curr (default in nullptr)
				curr.setTown(country[curr.getStartingPoint() - 1].getHead());
			while (curr.getTown() != nullptr)
			{
				if (TownsColor[curr.getTown()->getTownNumber() - 1] == 'W') // check Color of the nearby town
				{
					curr.setLine(AFTER_REC);
					stack.push(curr); // push the curr item to the stack
					// set the "recursive call" vars in curr
					curr.setLine(START);
					returnFromRec = false;
					curr.setStartingPoint(curr.getTown()->getTownNumber());
					curr.setTown(nullptr);
					skip = true; // skip flag for if statement for return after this loop for recursive call
					break; // from here we want to jump to START case
				}
				else
					curr.setTown(curr.getTown()->getNextTown());
			}
			if (curr.getTown() == nullptr && skip == false) // if we dont want skip and while end (curr nearbytown is nullptr) we want return -1
			{
				returnFromRec = true;
				returnedValue = -1;
				break;
			}
			skip = false; // reset skip to false
			break;
		case AFTER_REC:
			if (returnedValue != -1) // after "recursive call" we want to check if returned meanful value and continue the return
			{
				returnFromRec = true;
				returnedValue = returnedValue + 1;
			}
			else // if returned -1 we want continue the while loop from where we stopped before the "recursive call"
			{
				curr.setLine(IN_WHILE); // mark back to while loop
				returnFromRec = false;
				curr.setTown(curr.getTown()->getNextTown());
			}				
		}

	} while (stack.isEmpty() == false || returnFromRec == false); // we want to finish the pogram only if we returned meanful value in way back from "recursive call" and stack is empty

	return returnedValue;
}