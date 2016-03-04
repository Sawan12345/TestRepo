// Create a setOfstack which creates stack as required.
// 

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
	int capacity;
	int size;
public:
	Stack(int cap)
	{
		size = 0;
		capacity = cap;
		stackTop = NULL;
	}
	void setSize(int s)
	{
		size = s;
	}
	int getSize()
	{
		return size;
	}
	void setCapacity(int cap){
		capacity = cap;
	}
	int getCapacity()
	{
		return capacity;
	}
	
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
			//cout << "Element pushed successfully." << endl;
		}
		size++;
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
		
			Node* temp = stackTop;
			stackTop = stackTop->getNext();
			cout << "Poping element =" << temp->getValue() << endl;
			size--;
			return temp->getValue();
		
		
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

class setOfStacks{
	Stack **stack;
	int totalStacks;
	int capacity;
	int currStackNum;
public:
	setOfStacks(int cap, int total_stacks){
		currStackNum = 0;
		totalStacks = total_stacks;
		capacity = cap;
		stack = new Stack*[total_stacks];
		stack[currStackNum] = new Stack(capacity);
	}
	void push(int val)
	{
		if (stack[currStackNum]->getSize() == (stack[currStackNum]->getCapacity()))
		{
			currStackNum++;
			if (currStackNum < totalStacks)
				stack[currStackNum] = new Stack(capacity);
			else{
				cout << "Can't create anymore stacks" << endl;
				return;
			}
		}
		stack[currStackNum]->push(val);
	}
	int pop()
	{
		if (currStackNum == 0 && stack[currStackNum]->getSize() == 0)
		{
			cout << "setOfStacks is empty ";
			return -1;
		}
		if (stack[currStackNum]->getSize() == 0 && totalStacks != 0)
		{
			currStackNum--;
		}
		return stack[currStackNum]->pop();
	}
	void print()
	{
		for (int i = 0; i <= currStackNum; i++)
		{
			cout << "Stack - " << i << endl;
			stack[i]->print();
			cout << endl;
		}
	}
	int peek(int index)
	{
		if (index < 0)
		{
			cout << "Invalid Index";
			return -1;
		}
		int stackNum = index / capacity;
		
		index = index % capacity;
		index = (stack[stackNum]->getSize()) - index -1;
		if (index < 0)
		{
			cout << "Invalid Index";
			return -1;
		}
		int val = stack[stackNum]->peek(index);
		cout << "Value at asked index = " << val << endl;
		return val;
	}


};
int main()
{
	setOfStacks sos(3,5);
	sos.push(1);
	sos.push(2);
	sos.push(3);
	sos.push(4);
	sos.push(5);
	sos.push(6);
	sos.push(7);
	sos.push(8);
	sos.push(9);
	sos.push(10);
	//sos.peek(10);
	sos.peek(0);
	sos.peek(5);
	sos.peek(6);
	sos.peek(8);
	sos.peek(11);
	sos.print();
	sos.pop();
	sos.pop();
	sos.pop();
	sos.pop();
	sos.pop();
	sos.pop();
	sos.pop();
	sos.pop();
	sos.pop();
	sos.pop();
	sos.pop();
	sos.print();
	return 0;
}
