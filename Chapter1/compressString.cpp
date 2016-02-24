//compress string
//aaabbbbcddd -> a3b4cd3
// if compressed string is same as original string then return original string.
// aabbccdd -> a2b2c2d2 -> but return aabbccdd

// Thoughts : need new string
// what if value is double digit? :)  , better use std::string so append is easy?


#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

string compressString(string str);

int main()
{
	cout << compressString("");
	cout << compressString("aaaaaaaaaaaaaabbbbcddd");
	cout << compressString("aabbccddd");
	cout << compressString("aabbccddd");
	return 0;
}




string compressString(string str)
{
	if (str.length() == 0)
		return "invalidString";
	string newStr = "";
	char currentChar = str[0];
	int currCount = 1;
	
	for (int i = 1; i <= str.length(); i++)
	{
		if (str[i] == currentChar){
			currCount++;
		}else{
			
			newStr += currentChar;
			if (currCount != 1){
				newStr += to_string(currCount);
			}
			currentChar = str[i];
			currCount = 1;
		}
	}

	if (str.length() == newStr.length())
		return str;
	return newStr;
}
