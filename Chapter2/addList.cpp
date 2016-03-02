// Add two integer list to sum them
// 8->7->1->6
// 5->9->2
// output: 3->7->4->6


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

	void sumList(LinkedList* list1, LinkedList* list2){
		if (list1 == NULL && list2 == NULL)
			return;
		if (list1 == NULL )
		{
			_pHead = list2->_pHead;
			
		}
		else if(list2== NULL){
			_pHead = list1->_pHead;
			
		}
		else{
			int carry = 0;
			int val = 0;
			Node* list1p = list1->_pHead;
			Node* list2p = list2->_pHead;
			Node* curr = NULL;
			_pHead = curr;
			while (list1p != NULL || list2p != NULL)
			{
				
				if (list1p != NULL && list2p != NULL)
				{
					val = list1p->getValue() + list2p->getValue() + carry;
					list1p = list1p->getNext();
					list2p = list2p->getNext();
				}
				else if (list1p == NULL)
				{
					val = list2p->getValue()+ carry;
					list2p = list2p->getNext();
				}
				else
				{
					val = list1p->getValue() + carry;
					list1p = list1p->getNext();
				}

				carry = val / 10;
				val %= 10;

				Node* temp = new Node(val);
				if (curr == NULL)
				{
					_pHead = temp;
					curr = temp;
				}
				else
				{
					curr->setNext(temp);
					curr = curr->getNext();
				}
			}

		
		
		}


	
	
	}
	void sumListRecursive(LinkedList* list1, LinkedList* list2, int carry){
		sumListRecursive(list1->_pHead, list2->_pHead, carry);
	
	}
	
	void sumListRecursive(Node* list1, Node* list2, int carry){
		if (list1 == NULL && list2 == NULL && carry == 0)
			return;
		

		int result = carry;
		if (list1 != NULL)
		{
			result += list1->getValue();
			list1 = (list1->getNext() == NULL) ? NULL : list1->getNext();
		}
		if (list2 != NULL)
		{
			result += list2->getValue();
			list2 = (list2->getNext() == NULL) ? NULL : list2->getNext();
		}

		carry = result / 10;
		result = result % 10;

		
		

		sumListRecursive(list1, list2, carry);
		
		Node* curr = new Node(result);

		if (_pHead == NULL)
		{
			_pHead = curr;
		}
		else
		{
			curr->setNext(_pHead);
			_pHead = curr;
		}
	}
};


int main(){

	


	LinkedList *newList1 = new LinkedList();
	LinkedList *newList2 = new LinkedList();
	LinkedList *newList3 = new LinkedList();
	
	newList1->addNode(7);
	newList1->addNode(1);
	newList1->addNode(6);
	newList2->addNode(8);
	newList2->addNode(5);
	newList2->addNode(9);
	newList2->addNode(2);
	newList2->addNode(2);
	//newList3->sumList(newList1, newList2);

	

	newList3->sumListRecursive(newList1, newList2, 0);
	newList3->printList();
	

}
