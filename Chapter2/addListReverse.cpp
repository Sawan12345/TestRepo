// Add two lists in reverse
// 6->1->7
// 9->2->9
//output 1->5->4->6 


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
	int len(){
		int len = 0;
		Node* temp = _pHead;

		while (temp != NULL)
		{
			len++;
			temp = temp->getNext();
		}
		return len;
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
			cout << p->getValue() << "->" ;
			p = p->getNext();
		}
	}


	void addPadding(int len){
		Node* temp = _pHead;
		while (len > 0)
		{
			Node *newNode = new Node(0);
			newNode->setNext(temp);
			temp = newNode;
			len--;
		}
		
		_pHead = temp;
	
	}
	int sumListReverseHelper(Node* list1, Node* list2, int carry){
		int val;
		
		if (list1->getNext() == NULL && list2->getNext() == NULL && carry == 0)
		{
			val = list1->getValue() + list2->getValue();
			carry = val/ 10;
			val = val % 10;
			Node* temp = new Node(val);
			temp->setNext(_pHead);
			_pHead = temp;
			return carry;
		}
		int car = sumListReverseHelper(list1->getNext(), list2->getNext(), carry);
		val = car + list1->getValue() + list2->getValue();
		carry = val / 10;
		val = val % 10;
		Node* temp = new Node(val);
		temp->setNext(_pHead);
		_pHead = temp;
		return carry;


	}
	void sumListReverse(LinkedList* list1, LinkedList* list2, int carry)
	{
		LinkedList *longList = (list1->len() >= list2->len()) ? list1 : list2;
		LinkedList *shortList = (list1->len() < list2->len()) ? list1 : list2;

		shortList->addPadding(longList->len() - shortList->len());
		//shortList->printList();

		carry = sumListReverseHelper(longList->_pHead, shortList->_pHead, 0);

		if (carry != 0){
			Node* temp = new Node(carry);
			temp->setNext(_pHead);
			_pHead = temp;
		}
	}


};


int main(){

	


	LinkedList *newList1 = new LinkedList();
	LinkedList *newList2 = new LinkedList();
	LinkedList *newList3 = new LinkedList();
	
	newList1->addNode(6);
	newList1->addNode(1);
	newList1->addNode(7);
	newList2->addNode(9);
	newList2->addNode(2);
	newList2->addNode(9);
	
	
	

	newList3->sumListReverse(newList1, newList2, 0);
	newList3->printList();
	

}
