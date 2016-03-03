// Check if LinkedList is palindrom or not
// 6->1->6  = true
// 6->1->7  = false
// Use stack, push half of the element and then pop them and compare with slow iterator.


#include "stdafx.h"
#include <iostream>
#include <unordered_set>
#include <stack>

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

	bool isPalindrom()
	{
		stack<int> sk;
		Node* slow = _pHead;
		Node* fast = _pHead;

		while (fast != NULL && fast->getNext() != NULL)
		{
			int val = slow->getValue();
			sk.push(val);
			slow = slow->getNext();
			fast = fast->getNext()->getNext();
		}
	
		if (fast != NULL)  // if there are odd number of nodes in list.
			slow = slow->getNext();

		while (slow != NULL)
		{
			if (slow->getValue() != sk.top())
			{
				return false;
			}
			slow = slow->getNext();
			sk.pop();
		}

		
		return true;
	}

};


int main(){

	


	LinkedList *newList1 = new LinkedList();
	LinkedList *newList2 = new LinkedList();
	LinkedList *newList3 = new LinkedList();
	
	newList1->addNode(6);
	newList1->addNode(1);
	newList1->addNode(7);
	newList1->addNode(7);
	newList1->addNode(7);
	newList1->addNode(1);
	newList1->addNode(6);
	newList1->addNode(6);
	
	
	bool res = newList1->isPalindrom();
	if (res)
		cout << "It's palindrom" << endl;
	else
		cout << "It's not palindrom" << endl;

	
	

}
