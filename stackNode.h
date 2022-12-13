#ifndef __STACK_NODE_H
#define __STACK_NODE_H
#include "DataItem.h"
class stackNode
{
	DataItem data;
	stackNode* next;
public:
	stackNode(DataItem item, stackNode* next) : data(item), next(next) { }
	DataItem getData() { return data; }
	const stackNode* getNext() const { return next;  }
	stackNode* getNext() { return next; }
};

#endif // !__STACK_NODE_H
