#ifndef __NODE_H
#define __NODE_H

class Node
{
	// Data
	int townNumber;
	Node* nextTown;
	// remove copy c'tor
	Node(const Node&);
public:
	Node(int townNumber) : townNumber(townNumber), nextTown(nullptr) {}
	const int& getTownNumber() const { return townNumber; }
	const Node* getNextTown() const { return nextTown; }
	Node* getNextTown() { return nextTown; }
	void setNextTown(Node* newNext);
};


#endif