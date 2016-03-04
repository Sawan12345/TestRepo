//Implement Stack using c++
// push,pop,top,peek


#include "stdafx.h"
#include <iostream>


using namespace std;

class Node{
	int value;
	Node* next;
public:
	Node(){}
	Node(int v) :value(v), next(NULL){}
	Node(int v, Node* elem) :value(v), next(elem){}
	int getValue() { return value; }
	void setValue(int v) { value = v; }
	void setNext(Node* elem) { next = elem; }
	Node* getNext() { return next; }
};

class Stack{
	Node* stackTop;
	
public:
	Stack(){ stackTop = NULL; }
	void push(int v)
	{
		Node* temp = new Node(v);
		if (stackTop == NULL)
		{
			stackTop = temp;
		}
		else{
			temp->setNext(stackTop);
			stackTop = temp;
			cout << "Element pushed successfully." << endl;
		}
	};

	int top(){
		if (stackTop == NULL)
		{
			cout << "Stack is empty." << endl;
			throw;
		}
		else
		{
			return stackTop->getValue();
		}
	}

	int pop(){
		if (stackTop == NULL)
		{
			cout << "Stack is empty." << endl;
			throw;
		}
		else{
			Node* temp = stackTop;
			stackTop = stackTop->getNext();
			cout << "Poping element =" << temp->getValue();
			return temp->getValue();
		}
	}

	void print()
	{
		if (stackTop == NULL)
		{
			cout << "Stack is empty." << endl;
			return;
		}
		Node *curr = stackTop;
		cout << "Printing Stack elements " << endl;
		while (curr != NULL)
		{
			cout << curr->getValue() << " ";
			curr = curr->getNext();
		}
		cout << endl;
	
	}
	int peek(int index)
	{
		if (index < 0)
		{
			cout << "Invalid index." << endl;
			throw;	
		}
		if (!stackTop){
			cout << "Stack is empty." << endl;
			throw;
		}

		int i = 0;
		Node* curr = stackTop;
		while (curr)
		{
			if (i == index)
			{
				return curr->getValue();
			}
			curr = curr->getNext();
			i++;
		}

		cout << "Index out of bound" << endl;
		throw;
	}

};


int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.print();
	cout << "This is top element: " << s.top() << endl;
	cout <<s.peek(0) << endl;
	cout << s.peek(1) << endl;
	cout << s.peek(2) << endl;
	cout << s.peek(3) << endl;
	cout << s.peek(4) << endl;
	cout << s.peek(-1) << endl;

	return 0;
}
