// Remove duplicated from LinkedList
// Using hashmap, storing each element and see if that exist then remove current node.
// what if we can't use additional storage.


#include "stdafx.h"
#include <iostream>
#include <unordered_set>

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

	void deleteDuplicate()
	{
		pair <unordered_set<int>::iterator, bool> result;
		unordered_set <int> hashset;
		if (_pHead == NULL || _pHead->getNext()== NULL)
			return;
		
		Node* p = _pHead;
		hashset.insert(p->getValue());
		while (p!= NULL | p->getNext() != NULL){
			result = hashset.insert(p->getNext()->getValue());
			if (!result.second)
			{
				Node* temp = p->getNext();
				if (p->getNext()->getNext() != NULL){
					p->setNext(p->getNext()->getNext());
					delete temp;	
				}
				else{
					p->setNext(NULL);
					delete temp;
					return;
				}
			}
			else{
				p = p->getNext();
			}
		}

	
	}

};

int main(){

	


	LinkedList *newList = new LinkedList();

	newList->addNode(2);
	newList->addNode(2);
	newList->addNode(2);
	newList->addNode(4);
	newList->addNode(4);
	newList->addNode(4);
	newList->addNode(2);
	newList->addNode(5);
	newList->addNode(5);

	newList->deleteDuplicate();
	newList->printList();
	

}
