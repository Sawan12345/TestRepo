// Implement an algorithm to determine, if a string has all unique characters - part1
// What if you can't use additional data structure? - part2
// This would do case sensitive match, if you want to treat  'S' and 's' same charcters, you need to convert string in uppercase or lowercase.


// Questions:  is it ascii string or unicode string?
// assume it's ascii, then no need to check string if it's length is greater then 256.
// part2- use int value which is of 2 bytes and do bit manupulation.



#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


bool isUniqueCharcteredString(string str)
{
	bool arr[256]= {false};
	for(int i=0;i<str.size();i++)
	{
		char c = str[i];
		int ascii = static_cast<int>(str[i]);
		if(arr[ascii])
		{
			return false;
		}
		else{
			arr[ascii] = true;
		}
	}
	return true;
}

bool isUniqueCharcteredStringNoDS(string str)
{
	// TODO
	return true;
}

int main()
{
	string str;
	str = "Swan";

	if(str.size() > 256)
	{
		cout<< "Charcters in string " << str << " are not unique";
		return 0;
	}
	if(isUniqueCharcteredString(str)){
		cout<< "All charcters in string "<<str << " are unique";
	}else{
		cout<< "Charcters in string " << str << " are not unique";
	}

	return 0;	
}
