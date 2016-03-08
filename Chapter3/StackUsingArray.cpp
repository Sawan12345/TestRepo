// Stack using array
// 

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

template <class T>
class Stack{
	T *arr;
	int top;
public:
	Stack(int size){
		arr = new T[size];
		top = -1;
	}

	void push(T v)
	{
		arr[++top] = v;
	}

	T pop()
	{
		if (top > -1)
		{
			T v = arr[top];
			top--;
			return v;
			
		}
		cout << "Stack is empty";
		throw;
	}

	T topp()
	{
		if (top > -1)
			return arr[top];
		cout << "Stack is empty";
		throw;
	}

	T peek(int index)
	{
		if (index > -1 && index <= top)
			return arr[index];
		cout << "Index out of bound.";
		throw;
	
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
	Stack<string> st(10);
	st.push("100");
	st.push("101");
	st.push("103");
	st.push("106");
	st.push("10");
	st.print();
	cout << st.pop() << endl;
	cout << st.topp() << endl;
	cout << st.peek(4) << endl;
	return 0;
}
