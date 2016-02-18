// Reverse null terminated string
// 


// Questions: 
//



#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


void reverse(char* str)
{
	if(str == NULL)
		return;

	int len = strlen(str);
	
	for(int i=0; i<=len/2; i++)
	{
		char temp;
		temp = str[i];
		str[i] = str[len-1-i];
		str[len-1-i] = temp;
	
	}
	return;
}

int main()
{
	
	char stri[6] = "Sawan";
	char *str= NULL;
	//cout<< str;
	reverse(str);
	//cout << str;
	return 0;	
}


