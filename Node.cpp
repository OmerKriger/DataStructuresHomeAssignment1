#include "Node.h"

void Node::setNextTown(Node* newNext)
{
	newNext->nextTown = this->nextTown;
	this->nextTown = newNext;
}