#ifndef __DATA_ITEM_H
#define __DATA_ITEM_H
#include "Node.h"
class DataItem
{
	int line;
	int sPoint;
	Node* nearbyTown;
public:
	DataItem(int sPoint, int line) : line(line), sPoint(sPoint) , nearbyTown(nullptr) {}
	const int& getLine() const { return line; }
	const int& getStartingPoint() const { return sPoint; }
	Node* getTown() { return nearbyTown; }
	const Node* getTown() const { return nearbyTown; }
	void setLine(int line);
	void setTown(Node* town);
	void setStartingPoint(int sPoint);
};

#endif // !__DATA_ITEM_H
