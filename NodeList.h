#ifndef __NODE_LIST_H
#define __NODE_LIST_H
#include "Node.h"
#include <iostream>
using namespace std;

class NodeList
{
	Node* head;
public:
	NodeList();
	~NodeList();
	bool isEmpty();
	bool insertNode(int num);
	const Node* getHead() const { return head; }
	Node* getHead() { return head; }
	bool searchNodeInList(int num);
};

#endif