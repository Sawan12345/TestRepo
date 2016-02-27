
#include "stdafx.h"
#include <iostream>
#include <array>

using namespace std;

class node{
private:
	int value;
	node* pNext;
	node* pPrev;

public:
	node() :pNext(NULL), pPrev(NULL){}
	node(int v): value(v),pNext(NULL), pPrev(NULL){}
	void setValue(int v)
	{
		value = v;
	}
	int getValue()
	{
		return value;
	}
	void setNext(node* elem)
	{
		pNext = elem;
	}
	node* getNext()
	{
		return pNext;
	}
	void setPrev(node* elem)
	{
		pPrev = elem;
	}
	node* getPrev()
	{
		return pPrev;
	}
};

class DoublyLinkList
{
private:
	node* head;
	node* tail;
public:
	DoublyLinkList() :head(NULL), tail(NULL){}
	DoublyLinkList(int a[], int size);

	bool addAtFront(int val);
	bool addAtEnd(int val);
	void printList();
	void printReverseList();
	bool addAt(int val, int index); // negative will add from end
	bool deleteFromList(int val);
};


DoublyLinkList::DoublyLinkList(int a[], int size)
{
	head = NULL;
	tail = NULL;
	if (size > 0)
	{
		node *curr = new node(a[0]);
		head = tail = curr;
		for (int i = 1; i < size; i++)
		{
			node *temp = new node(a[i]);
			curr->setNext(temp);
			temp->setPrev(curr);
			curr = tail = temp;

		}

	}
}

void DoublyLinkList::printList()
{
	node* curr = head;
	while (curr)
	{
		cout << curr->getValue() << endl;
		curr = curr->getNext();
	}
}
void DoublyLinkList::printReverseList()
{
	node* curr = tail;
	while (curr)
	{
		cout << curr->getValue() << endl;
		curr = curr->getPrev();
	}
}

bool DoublyLinkList::addAtFront(int val)
{
	node *temp = new node(val);
	if (!head)
	{
		head = tail = temp;
		return true;
	}
	
	temp->setNext(head);
	head->setPrev(temp);
	head = temp;
	return true;
}

bool DoublyLinkList::addAtEnd(int val)
{
	node *temp = new node(val);
	if (!head || !tail)
	{
		head = tail = temp;
		return true;
	}
	tail->setNext(temp);
	temp->setPrev(tail);
	tail = temp;
	
	return true;
}

bool DoublyLinkList::addAt(int val, int index)
{
	if (index == 0)
	{
		addAtFront(val);
		return true;
	}
	
	else if (index > 0)
	{
		node* curr = head;
		int i = 1;
		while (curr)
		{
			if (i == index)
			{
				node *temp = new node(val);
				temp->setPrev(curr);
				temp->setNext(curr->getNext());
				curr->setNext(temp);
				if (temp->getNext() != NULL)
					temp->getNext()->setPrev(temp); // assign this if node is not last node.
				else
					tail = temp;  // update tail if adding at end
				return true;
			}
			curr = curr->getNext();
			i++;
		}
	}
	if (index < 0)
	{
		node *curr = tail;
		int i = -1;
		while (curr)
		{
			if (i == index)
			{
				node* temp = new node(val);
				temp->setPrev(curr->getPrev());
				temp->setNext(curr);
				curr->setPrev(temp);
				if (temp->getPrev() != NULL)
				{
					temp->getPrev()->setNext(temp);
				}
				else
				{
					head = temp;
				}
				return true;
			}
			curr = curr->getPrev();
			i--;
		}
	}

	return false;
}

bool DoublyLinkList::deleteFromList(int val)
{
	node *curr;
	if (!head || !tail)
	{
		return false;
	}
	if (head->getNext() == NULL || tail->getPrev() == NULL)
	{
		curr = head;
		head = tail = NULL;
		delete curr;
		return true;
	}
	if (head->getValue() == val)
	{
		curr = head->getNext();
		curr->setPrev(NULL);
		delete head;
		head = curr;
		return true;
	}
	if (tail->getValue() == val)
	{
		curr = tail->getPrev();
		curr->setNext(NULL);
		delete tail;
		tail = curr;
		return true;
	}

	curr = head;
	while (curr)
	{
		if (curr->getValue() == val)
		{
			curr->getNext()->setPrev(curr->getPrev());
			curr->getPrev()->setNext(curr->getNext());
			delete curr;
			return true;
		}
		curr = curr->getNext();
	}
	return false;
}

int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	DoublyLinkList dl(a,5);
	bool suc = dl.deleteFromList(1);
	dl.printList();
	dl.printReverseList();
	cout << "Suc = " << suc << endl;
}	
