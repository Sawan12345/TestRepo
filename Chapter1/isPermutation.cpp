//Given two string find if one is permutation of other
// Questions: Is it case sensitive?

// If both string length are not same then return false
// Using Sorting 
// Using Hashmap 
// Case sensitive check

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

bool isPermutationCaseInsensitive(string orgStr, string strToCheck);
bool isPermutationUsingSorting(string orgStr, string strToCheck);
bool isPermutationWithoutSorting(string orgStr, string strToCheck);
int main()
{
	
	string str1, str2;
	str1 = "Sawan";
	str2 = "aswan";
	cout << str1 << endl;
	cout << str2 << endl;
	bool result = isPermutationCaseInsensitive(str1, str2);
	cout << result << endl;
	cout << isPermutationUsingSorting("Sawan", "Sawap") << endl;
	cout << isPermutationUsingSorting("Saawn", "Sawan") << endl;
	cout << isPermutationUsingSorting("saawn", "sawan") << endl;
	return 0;
}


bool isPermutationCaseInsensitive(string orgStr, string strToCheck)
{
	if (orgStr.length() == strToCheck.length())
	{
		std::transform(orgStr.begin(), orgStr.end(), orgStr.begin(), ::tolower);
		std::transform(strToCheck.begin(), strToCheck.end(), strToCheck.begin(), ::tolower);
		sort(orgStr.begin(), orgStr.end());
		sort(strToCheck.begin(), strToCheck.end());
		if (orgStr == strToCheck)
			return true;
		std::cout << orgStr << endl;
		std::cout << strToCheck << endl;
	
	}
	return false;
}
bool isPermutationUsingSorting(string orgStr, string strToCheck){
	// return false is strings length are different
	if (orgStr.length() == strToCheck.length())
	{
		sort(orgStr.begin(), orgStr.end());
		sort(strToCheck.begin(), strToCheck.end());
		if (orgStr == strToCheck)
			return true;
	}
	return false;
}

bool isPermutationWithoutSorting(string orgStr, string strToCheck){

	if (orgStr.length() == strToCheck.length())
	{
		int charArr[256] = { 0 };
		for (char c : orgStr)
		{
			charArr[c] += 1;
		}
		for (char c : strToCheck)
		{
			charArr[c] -= 1;
		}
		for (int i = 0; i < 256; i++)
		{
			if (charArr[i] != 0)
				return false;
		}
		return true;
	}
	return false;
}
