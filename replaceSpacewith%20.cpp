//replace space with %20 in given string
// Questions: is string not constant and if it does it have empty spaces at end to store addition data? if no we can't do in place.
// 

// API ,  take string input and its final length.

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int calculateSpaces(char* str, int length);
void replaceSpacewith20(char *str, int length);
int main()
{
	char str[16] = "Sawan Panchal  ";
	char* test = str;
	replaceSpacewith20(test, 13);
	return 0;
}


void replaceSpacewith20(char *str, int length)
{
	int spaces = calculateSpaces(str,length);
	int newSize = length -1 + (2 * spaces);
	for (int i = length - 1; i >= 0; i--)
	{
		if (str[i] == ' ')
		{
			str[newSize--] = '0';
			str[newSize--] = '2';
			str[newSize--] = '%';
		}
		else
		{
			str[newSize--] = str[i];
		}
	}
	cout << str;

}

int calculateSpaces(char* str, int length)
{
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == ' ')
			count++;
	}
	return count;
}
