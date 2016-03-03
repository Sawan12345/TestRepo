// Check if LinkedList are intersacting or not and what's intersaction point
// 1->2->3->4->5->6->3  
// 8->9->11->4->5->6->3
// intersecting.
// find tail of both list, it must be same for them to be intersecting
// if intersecting , find length of both and move head pointer of longest list by differece of both list length
// and advance both list pointer until they meet at first location, that's intersection point.
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

class tailInfo{
public:
	int len;
	Node* tail;
	tailInfo(int l, Node* t)
	{
		len = l;
		tail = t;
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
	
	int len(Node* head)
	{
		Node* curr = head;
		int len = 0;
		while (curr->getNext() != NULL)
		{
			curr = curr->getNext();
			len++;
		}
		return len;
	
	}
	Node* getTail(Node* head)
	{
		Node* curr = head;
		int len = 0;
		while (curr->getNext() != NULL)
		{
			curr = curr->getNext();
			len++;
		}
		return curr;
	}
	bool isIntersacting(Node* list1, Node* list2){
		bool result = false;
		Node* tail1 = getTail(list1);
		Node* tail2 = getTail(list2);

		if (tail1 == tail2)
		{
			cout << "Both lists are intersacting" << endl;
		

			Node* longList = (len(list1) >= len(list2)) ? list1 : list2;
			Node* shortList = (len(list1) < len(list2)) ? list1 : list2;

			int lendiff = len(longList) - len(shortList);

			while (lendiff > 0){
				longList = longList->getNext();
				lendiff--;
			}
		
			while (longList != NULL)
			{
				if (longList == shortList)
				{
					break;
				}
				longList = longList->getNext();
				shortList = shortList->getNext();
			}
			cout << "Loop is starting at " << longList->getValue();
			return true;
		}
		
		cout << "List are not intersacting";
		return false;
	}
};


int main(){

	

	Node *a1 = new Node(21);
	Node *a2 = new Node(22);
	Node *a3 = new Node(23);
	Node *a4 = new Node(24);
	Node *a5 = new Node(25);

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
	b9->setNext(b10);

	a1->setNext(a2);
	a2->setNext(a3);
	a3->setNext(a4);
	a4->setNext(a5);
	//a5->setNext(b8);

	LinkedList *newList1 = new LinkedList();
	
	bool res = newList1->isIntersacting(a1,b1);

	if (res)
		cout << "List are intersacting";
	else
		cout << "List are not intersacting";
	
}
