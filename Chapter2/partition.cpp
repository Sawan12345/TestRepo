// partition listnked list in higher/lower division by given number
// input 3->5->8->5->10->2->1 (int is 5)
// output 3->2->1->5->5->8->10
		

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


	void partition2(int x)
	{
		if (_pHead == NULL || _pHead->getNext() == NULL)
			return;

		Node* head = _pHead;
		Node* tail = _pHead;

		while (_pHead != NULL )
		{
			Node* temp = _pHead->getNext();
			if (_pHead->getValue() < x)
			{
				_pHead->setNext(head);
				head = _pHead;
			}
			else
			{
				tail->setNext(_pHead);
				tail = _pHead;
			}
			_pHead = temp;
		}
		tail->setNext(NULL);
		_pHead = head;
	}
	void partition(int x)
	{
		// input 3->5->8->5->10->2->1
		// output 3->2->1->5->5->8->10

		// create newlist
		if (_pHead == NULL || _pHead->getNext() == NULL)
			return;
		Node *listHead1;
		Node *listHead2;
		Node *listCurr1;
		Node *listCurr2;

		while (_pHead != NULL)
		{
			
			if (_pHead->getValue() >= x){
				Node *newNode = new Node(_pHead->getValue());
				if (listHead1 == NULL){
					listHead1 = newNode;
					listCurr1 = listHead1;
				}else{
					listCurr1->setNext(newNode);
					listCurr1 = listCurr1->getNext();
				}
			}else{
				Node *newNode = new Node(_pHead->getValue());
				if (listHead2 == NULL){
					listHead2 = newNode;
					listCurr2 = listHead2;
				}
				else{
					listCurr2->setNext(newNode);
					listCurr2 = listCurr2->getNext();
				}
			}
			_pHead = _pHead->getNext();
		}

		if (listHead1 != NULL){
			listCurr1->setNext(listHead2);
			_pHead = listHead1;
		}
		else{
			_pHead = listHead2;
		}
		
	}

};


int main(){

	


	LinkedList *newList = new LinkedList();

	newList->addNode(3);
	newList->addNode(4);
	newList->addNode(8);
	newList->addNode(5);
	newList->addNode(10);
	newList->addNode(2);
	newList->addNode(1);
	newList->addNode(5);
	newList->addNode(5);

	newList->partition2(15);
	newList->printList();
	

}
