
#include "stdafx.h"
#include <iostream>
#include <array>



using namespace std;

class node{
private:
	int value;
	node* pNext;
public:
	node() :pNext(NULL){}
	node(int val) : value(val), pNext(NULL){}
	node(int val, node* elem) :value(val), pNext(elem){}
	int getValue()
	{
		return value; 
	}
	node* getNext()
	{
		return pNext;
	}
	void setNext(node* elem)
	{
		pNext = elem;
		
	}

};

class Stack
{
private:
	node* head;
public:
	Stack() : head(NULL){};
	~Stack();
	Stack(Stack &temp);

	Stack& operator=(const Stack& rhs);
	bool push(int value);
	int pop();
	void printStack();
};

Stack& Stack::operator=(const Stack& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	if (&rhs == NULL)
	{
		return Stack();
	}

	node *currRHS = rhs.head;
	head = new node(currRHS->getValue());
	node *curr = head;
	if (currRHS->getNext() != NULL)
		currRHS = currRHS->getNext();
	while (currRHS)
	{
		node *newNode = new node(currRHS->getValue());
		curr->setNext(newNode);
		curr = curr->getNext();
		currRHS = currRHS->getNext();
	}
	
	return *this;
}

Stack::Stack(Stack &rhs)
{
	if (&rhs == NULL)
	{
		head = new node();
		return;
	}

	node *currRHS = rhs.head;
	head = new node(currRHS->getValue());
	node *curr = head;
	if (currRHS->getNext() != NULL)
		currRHS = currRHS->getNext();
	while (currRHS)
	{
		node *newNode = new node(currRHS->getValue());
		curr->setNext(newNode);
		curr = curr->getNext();
		currRHS = currRHS->getNext();
	}

}

bool Stack::push(int value)
{
	node* newNode = new node(value);
	newNode->setNext(head);
	head = newNode;
	return true;
}

int Stack::pop()
{
	int val;
	if (head)
	{
		val = head->getValue();
		node *temp = head->getNext();
		delete head;
		head = temp;
	}
	else
	{
		cout << "Stack is empty" << endl;
		val = -1;
	}

	return val;
}

Stack::~Stack()
{
	cout << "Deleting stack:" << endl;
	while (head)
	{
		node* temp = head;
		cout << temp->getValue() << " ";
		head = head->getNext();
		delete temp;
	}

}

void Stack::printStack()
{
	if (!head)
	{
		cout << "Stack is empty" << endl;
	}
	//cout << "Printing Stack" << endl;
	node *curr = head;
	while (curr)
	{
		cout <<  curr->getValue() << endl;
		curr = curr->getNext();
	}

}

int main()
{
	Stack stack;
		stack.push(2);
		stack.push(3);
		stack.push(4);
		stack.push(5);
		cout << "Printing Stack 1 " << endl;
		stack.printStack();
	Stack stack2(stack);
		cout << "Printing Stack 2 , copied" << endl;
		stack2.printStack();
	Stack stack3;
		cout << "Printing Stack 3 , empty" << endl;
		stack3.printStack();
		stack3 = stack2;
		cout << "Printing Stack 3 , assigned" << endl;
		stack3.printStack();
		stack3.pop();
		stack3.pop();
		stack2.pop();
		stack2.pop();
		cout << "Printing Stacks " << endl;
		stack.printStack();
		stack2.printStack();
		stack3.printStack();
		
}
