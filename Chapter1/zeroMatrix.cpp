// Zero MxN row or column if it contains Zero
// 1 1 1 1			4 0 0 1 
// 2 0 2 2   --->   0 0 0 0
// 3 3 0 3			0 0 0 0
// 4 4 4 4			4 0 0 1



#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


void printMatrix(int matrix[][4], int rowlength, int collength){
	for (int i = 0; i < rowlength; i++)
	{
		for (int j = 0; j < collength; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}



int main()
{
	int matrix[4][4] = { { 1, 1, 1, 0 }, { 2, 2, 2, 2 }, { 3, 3, 3, 3 }, { 4, 4, 4, 4 } };
	
	bool rowZero = false;
	bool colZero = false;

	printMatrix(matrix, 4, 4);

	for (int i = 0; i < 4; i++)
	{
		if (matrix[0][i] == 0)
		{
			rowZero = true;
			break;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (matrix[i][0] == 0)
		{
			colZero = true;
			break;
		}
	}

	for (int i = 1; i < 4; i++){
		for (int j = 1; j < 4; j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (matrix[i][0] == 0)
		{
			for (int j = 0; j < 4; j++)
				matrix[i][j] = 0;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (matrix[0][i] == 0)
		{
			for (int j = 0; j < 4; j++)
				matrix[j][i] = 0;
		}
	}

	if (rowZero)
	{
		for (int i = 0; i < 4; i++)
			matrix[0][i] = 0;
	}
	if (colZero)
	{
		for (int i = 0; i < 4; i++)
			matrix[i][0] = 0;
	}


	printMatrix(matrix, 4, 4);
	return 0;
}





