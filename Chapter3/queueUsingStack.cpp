// Create a Queue using stacks.
// 

#include "stdafx.h"
#include <iostream>
#include <stack>

using namespace std;

class Queue{
	stack<int> *back;
	stack<int> *front;
public:
	Queue(){
		back = new stack<int>;
		front = new stack<int>;
	}
	void push(int v)
	{
		back->push(v);
	}

	int pop()
	{
		int val;
		if (!front->empty())
		{
			val = front->top();
		}
		else if(!back->empty()){
			while (!back->empty())
			{
				front->push(back->top());
				back->pop();
			}
			val = front->top();
		}
		else{
			cout << "Queue is empty" << endl;
			return -1;
		}
		front->pop();
		return val;
	}
};

int main()
{
	Queue q;
	q.push(4);
	q.push(5);
	q.push(6);
	
	cout << "popping = " << q.pop();
	cout << "popping = " << q.pop();
	cout << "popping = " << q.pop();
	

	q.push(1);
	q.push(2);
	q.push(3);
	cout << "popping = " << q.pop();
	return 0;
}
