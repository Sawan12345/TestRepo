
#include "stdafx.h"
#include <iostream>

using namespace std;
class Node
{
	
private:
	int _value;
	Node* _pNext;

public:
	Node() :_pNext(NULL){}
	Node(int v) : _value(v), _pNext(NULL){}
	Node(int v, Node* elem) : _value(v), _pNext(elem){}
	~Node() {};

	void setValue(int v){
		_value = v;
	}
	int getValue(){
		return _value;
	}
	void setNext(Node* elem)
	{
		_pNext = elem;
	}
	Node* getNext()
	{
		return _pNext;
	}
};


class LinkedList
{
private:
	Node * _pHead;
public:
	LinkedList();
	LinkedList(int value);
	~LinkedList(){}
	void addNode(int value);
	void printList();
};


LinkedList::LinkedList()
{
	_pHead = NULL;
}
LinkedList::LinkedList(int value)
{
	_pHead = new Node(value);
}
void LinkedList::addNode(int value)
{
	Node* elem = new Node(value);
	Node *p = _pHead;
	while (p->getNext() != NULL)
	{
		p = p->getNext();
	}
	p->setNext(elem);

}
void LinkedList::printList()
{
	if (_pHead == NULL)
	{
		cout << "LinkedList is empty" << endl;
		return;
	}

	Node *p = _pHead;
	while (p != NULL)
	{
		cout << p->getValue() << endl;
		p = p->getNext();
	}

}
int main()
{
	LinkedList *head = new LinkedList(5);
	head->addNode(10);
	head->addNode(15);
	head->printList();
	
	return 0;
}
