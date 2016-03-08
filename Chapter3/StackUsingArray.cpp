// Stack using array
// 

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

class Stack{
	int *arr;
	int top;
public:
	Stack(int size){
		arr = new int(size);
		top = -1;
	}

	void push(int v)
	{
		arr[++top] = v;
	}

	int pop()
	{
		if (top > -1)
		{
			int v = arr[top];
			top--;
			return v;
			
		}
		cout << "Stack is empty";
		return -1;
	}

	int topp()
	{
		if (top > -1)
			return arr[top];
		cout << "Stack is empty";
		return -1;
	}

	int peek(int index)
	{
		if (index > -1 && index <= top)
			return arr[index];
		cout << "Index out of bound.";
		return -1;
	
	}
	void print()
	{
		if (top > -1)
		{
			for (int i = top ; i >= 0; i--)
			{
				cout << arr[i] << "->" ;
			}
			cout << endl;
			return;
		}
		cout << "Stack is empty";
	}

};


int main()
{
	Stack st(10);
	st.push(100);
	st.push(101);
	st.push(103);
	st.push(106);
	st.push(10);
	st.print();
	cout << st.pop() << endl;
	cout << st.topp() << endl;
	cout << st.peek(4) << endl;
	return 0;
}
