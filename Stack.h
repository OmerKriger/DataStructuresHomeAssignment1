#ifndef __STACK_H
#define __STACK_H
#include "stackNode.h"


class Stack
{
	stackNode* top;
	Stack(const Stack&);
public:
	Stack();
	~Stack();
	bool isEmpty();
	bool makeEmpty();
	void push(DataItem data);
	DataItem pop();
};


#endif