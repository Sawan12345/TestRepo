// Check if string1 is rotation of string2
// str1 = sawan
// str2 = wansa
// output -> true  (wansawansa contains sawan)

// str1= sawan
// str2 = wanas  
// output -> false (wanaswanas doesn't contain sawan)



#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


int main()
{
	string str1 = "sawan";
	string str2 = "wanas";

	if (str1.length() != str2.length())
		cout << "Str1 is not rotation of Str2";

	str2 = str2 + str2;
	if (str2.find(str1) != string::npos)
	{
		cout << "Str1 is rotation of Str2";
	}
	else
	{
		cout << "Str1 is not rotation of Str2";
	}
	return 0;
}
