// Create a stack which returns min all time.
// 1. you can keep integer to track min, but when there is min element removed you need to traverse stack to find new min. not o(1)
// 2. create a node which keeps track of current value and current min, this would use Double the memory to track it
// 3. Keep another stack of min values, one popped value is top of minStack , pop element of minStack too.
// This would take less space compare to first.

// looks easier but gets trickier when need to deal with inheritance
// minStack will inherite Stack
// Need to overload  push/pop operations
// create min operation.

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
protected:
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
	}

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

class minStack : protected Stack{
	Stack *s;
public:
	minStack(){
		s = new Stack();
	}
	void push(int v)
	{
		s->push(v);
		if (stackTop){
			if (stackTop->getValue() >= v)
			{
				Node* temp = new Node(v);
				temp->setNext(stackTop);
				stackTop = temp;
			}
		}
		else{
			stackTop = new Node(v);
		}

	}
	int pop()
	{
		int v = s->pop();
		if (v == stackTop->getValue())
			stackTop = stackTop->getNext();
		return v;
	}
	int min()
	{
		return this->top();
	}


};
int main()
{
	minStack s;
	s.push(5);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);
	cout << "MIn element= " <<  s.min() <<endl;
	s.pop();
	cout << "MIn element= " << s.min() << endl;
	

	return 0;
}
