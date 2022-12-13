#include "Stack.h"

Stack::Stack()
{
	top = nullptr;
}
Stack::~Stack()
{
	makeEmpty();
}
bool Stack::isEmpty()
{
	if (top == nullptr)
		return true;
	else
		return false;
}
bool Stack::makeEmpty()
{
	stackNode* temp;
	while (this->top != nullptr)
	{
		temp = this->top;
		this->top = this->top->getNext();
		delete temp;
	}
	return true;
}
void Stack::push(DataItem data)
{
	top = new stackNode(data, top);
}
DataItem Stack::pop()
{
	stackNode* temp = top;
	DataItem item = top->getData();
	top = top->getNext();
	delete temp;
	return item;
}