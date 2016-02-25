// find is strings are one away
// one deleted
// one added
// one replaced.
// 
// pale - bale  (true)
// pale - pal   (true)
// pale - pales (true)
// pale - bales (false)

// Rule is string lengths should be equal or has difference of 1 character.
// 

#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>

using namespace std;
void checkReplace(string str1, string str2){
	cout << "Check replace" << endl;
	int changeCount = 0;
	for (int i = 0; i < str1.length(); i++)
	{
		if (str1[i] != str2[i])
			changeCount++;
	}
	if (changeCount == 1)
	{
		cout << "String are one replace" << endl;
	}
	else
	{
		cout << "String are not one replace" << endl;
	}

}
void checkOneAway(string str1, string str2)
{
	cout << "Check One Away" << endl;
	string longStr, shortStr;
	longStr = (str1.length() > str2.length()) ? str1 : str2;
	shortStr = (str1.length() < str2.length()) ? str1 : str2;
	int changeCount = 0;
	for (int i = 0,j=0; j < longStr.length(); i++,j++)
	{
		if (shortStr[i] != longStr[j])
		{
			i--;
			changeCount++;
		}
	}

	if (changeCount == 1)
	{
		cout << "String are one away" << endl;
	}
	else
	{
		cout << "String are not one away" << endl;
	}

}
int main()
{
	string str1 = "pale";
	string str2 = "bales";

	int lenDiff = abs(int(str2.length()) - int(str1.length()));
	if (lenDiff > 1)
	{
		cout << "Strings are not one away";
		return 0;
	}

	if (lenDiff == 0)
	{
		checkReplace(str1, str2);
	}

	if (lenDiff == 1)
	{
		checkOneAway(str1,str2);
	}
	
	return 0;
}

