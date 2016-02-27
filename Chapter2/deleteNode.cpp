

// Remove duplicated from LinkedList
// Using hashmap, storing each element and see if that exist then remove current node.
// what if we can't use additional storage.


#include "stdafx.h"
#include <iostream>

using namespace std;

class Node{
private:	
	int _value;
	Node *_pNext;

public:
	Node():_pNext(NULL){}
	Node(int val) :_value(val),_pNext(NULL) {}
	Node(int val, Node* elem) : _value(val), _pNext(elem){}
	~Node(){};

	void setValue(int val){
		_value = val;
	}
	int getValue(){
		return _value;
	}
	void setNext(Node* elem){
		_pNext = elem;
	}
	Node* getNext(){
		return _pNext;
	}
};


class LinkedList{
private:
	Node* _pHead;

public:
	LinkedList() :_pHead(NULL){};
	LinkedList(int a){
		_pHead = new Node(a);
	}
	void addNode(int a){
		Node* elem = new Node(a);
		if (_pHead != NULL){
			Node *p = _pHead;
			while (p->getNext() != NULL){
				p = p->getNext();
			}
			p->setNext(elem);
		}
		else{
			_pHead = elem;
		
		}
	}
	void printList()
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

	bool deleteNode(int val)
	{
		if (_pHead == NULL)
		{
			cout << "List is empty";
			return false;
		}
		if (_pHead->getValue() == val)
		{
			Node* temp = _pHead;
			if (_pHead->getNext() != NULL)
			{
				_pHead = _pHead->getNext();
			}
			else{
				_pHead = NULL;
			}
			delete temp;
		}

		Node* ptr = _pHead;
		
		while (ptr != NULL && ptr->getNext() !=NULL)
		{
			if (ptr->getNext()->getValue() == val)
			{
				Node* temp = ptr->getNext();
				if (ptr->getNext()->getNext() != NULL)
					ptr->setNext(ptr->getNext()->getNext());
				else
					ptr->setNext(NULL);
				delete temp;
			}
			ptr = ptr->getNext();
		}
	
	}

	void deleteAllNode(int val)
	{
		if (_pHead == NULL)
		{
			cout << "List is empty";
			return;
		}
		if (_pHead->getValue() == val)
		{
			Node* temp = _pHead;
			if (_pHead->getNext() != NULL)
			{
				_pHead = _pHead->getNext();
				delete temp;
				deleteAllNode(val);
			}
			else{
				_pHead = NULL;
				delete temp;
			}
			
		}

		Node* ptr = _pHead;

		while (ptr != NULL && ptr->getNext() != NULL)
		{
			if (ptr->getNext()->getValue() == val)
			{
				Node* temp = ptr->getNext();
				if (ptr->getNext()->getNext() != NULL)
				{
					ptr->setNext(ptr->getNext()->getNext());
					delete temp;
					deleteAllNode(val);
				}
				else{
					ptr->setNext(NULL);
					delete temp;
				}
			}
			ptr = ptr->getNext();
		}
		return;

	}

};

int main(){
	LinkedList *newList = new LinkedList();

	newList->addNode(2);
	newList->addNode(2);
	newList->addNode(2);
	//newList->addNode(4);
	//newList->addNode(2);

	newList->printList();
	//newList->deleteNode(1);
	newList->deleteAllNode(2);
	cout << "deleted List" << endl;
	newList->printList();
	newList->addNode(2);
	cout << "deleted List" << endl;
	newList->printList();

}
