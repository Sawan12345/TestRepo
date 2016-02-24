// Check if string is palindrom permutation
// only single char can be odd 



#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


int main()
{
	char str[10] = "acobocca";
	int arr[26] = { 0 };
	int index;
	for (char c : str)
	{
		index = int(c) - 97;
		arr[index] += 1;
	}

	int singleOddCount = 0;

	for (int i = 0; i < 26; i++)
	{
		if (arr[i] % 2 == 1)
			singleOddCount++;
	}

	if (singleOddCount <= 1)
	{
		cout << "Its palindrom permutation";
	}
	else
	{
		cout << "Its not palindrom permutation";
	}
	
	return 0;
}
