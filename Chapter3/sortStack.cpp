// Sort Stack using Stack.
// 

#include "stdafx.h"
#include <iostream>
#include <stack>

using namespace std;

void print(stack<int> s)
{
	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}

}

void sortStack(stack<int>& unsorted){
	stack<int> sorted;
	int val;

	if (unsorted.empty())
	{
		cout << "Empty stack";
		return;
	}
	

	while (!unsorted.empty()){
			
			
		if (!sorted.empty() && unsorted.top() > sorted.top())
		{
			val = unsorted.top();
			unsorted.pop();
			while (!sorted.empty())
			{
				unsorted.push(sorted.top());
				sorted.pop();
			}
			sorted.push(val);
		}
		else{
			sorted.push(unsorted.top());
			unsorted.pop();
		}
	
	}

	unsorted = sorted;
}


int main()
{
	stack<int> unsorted;
	unsorted.push(7);
	unsorted.push(2);
	unsorted.push(4);
	unsorted.push(1);
	unsorted.push(9);
	unsorted.push(19);
	unsorted.push(4);

	print(unsorted);
	sortStack(unsorted);
	print(unsorted);
	
	return 0;
}
