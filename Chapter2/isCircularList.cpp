// Check if LinkedList circular or not and find loop entry
// 1->2->3->4->5->6->3  = true
// 1->2->3->4->5->6->7  = false
// use two iterator fast and slow, if they meet -> it's circular list
// set back slow to head and move fast and slow with single increment, meeting point is entry of loop.

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

	bool isCircularList(Node* list){
		bool result = false;
		Node* slow = list;
		Node* fast = list;

		while (fast!=NULL && fast->getNext() != NULL )
		{
			
			slow = slow->getNext();
			fast = fast->getNext()->getNext();
			if (fast == slow)
				break;

		}
		
		if (fast == NULL || fast->getNext() == NULL  )
			return false;

		slow = list;
		while (fast != slow)
		{
			fast = fast->getNext();
			slow = slow->getNext();
		}

		cout << "Loop is starting at " << fast->getValue() << endl;
		return true;
	}
};


int main(){

	
	Node *b1 = new Node(1);
	Node *b2 = new Node(2);
	Node *b3 = new Node(3);
	Node *b4 = new Node(4);
	Node *b5 = new Node(5);
	Node *b6 = new Node(6);
	Node *b7 = new Node(7);
	Node *b8 = new Node(8);
	Node *b9 = new Node(9);
	Node *b10 = new Node(10);
	Node *b11 = new Node(11);

	b1->setNext(b2);
	b2->setNext(b3);
	b3->setNext(b4);
	b4->setNext(b5);
	b5->setNext(b6);
	b6->setNext(b7);
	b7->setNext(b8);
	b8->setNext(b9);
	b9->setNext(b4);

	LinkedList *newList1 = new LinkedList();
	
	bool res = newList1->isCircularList(b1);

	if (res)
		cout << "It's circular list";
	else
		cout << "It's not circular list";
	
	

}
