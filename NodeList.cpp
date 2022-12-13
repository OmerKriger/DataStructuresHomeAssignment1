#include "NodeList.h"

bool NodeList::isEmpty()
{
	if (head == nullptr)
		return true;
	else
		return false;
}

bool NodeList::insertNode(int num)
{
	Node* newNode = new Node(num);
	if (isEmpty())
		this->head = newNode;
	else if (this->head->getTownNumber() > num)
	{
		newNode->setNextTown(head);
		this->head = newNode;
	}
	else
	{
		Node* currNode = head;
		while (currNode != nullptr)
		{
			if (currNode->getTownNumber() == num)
			{
				cout << "Road already exist !";
				delete newNode;
				return false;
			}
			if (currNode->getTownNumber() < num && currNode->getNextTown() == nullptr)
			{
				currNode->setNextTown(newNode);
				break;
			}
			else if (currNode->getTownNumber() < num && num < currNode->getNextTown()->getTownNumber())
			{
				currNode->setNextTown(newNode);
				break;
			}
			else
				currNode = currNode->getNextTown();
		}
	}
}

NodeList::NodeList() : head(nullptr) {}

NodeList::~NodeList()
{
	Node* curr = head, * next;
	while (curr != nullptr)
	{
		next = curr->getNextTown();
		delete curr;
		curr = next;
	}
}

bool NodeList::searchNodeInList(int num)
{
	Node* curr = head;
	while (curr != nullptr)
	{
		if (curr->getTownNumber() == num)
			return true;
		curr = curr->getNextTown();
	}
	return false;
}

