// NxN matrix , rotate it to 90 degree
// 1 1 1 1			4 3 2 1 
// 2 2 2 2 -->  4 3 2 1
// 3 3 3 3			4 3 2 1
// 4 4 4 4			4 3 2 1



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

void rotateMatrix(int matrix[][4], int rowlength, int collength)
{
	for (int layer = 0; layer < rowlength / 2; layer++)
	{
		int first = layer;
		int last = rowlength - 1 - layer;
		for (int i = first; i < last; i++)
		{
			int offset = i - first;
			int top = matrix[first][i];
			matrix[first][i] = matrix[last - offset][first];
			matrix[last - offset][first] = matrix[last][last - offset];
			matrix[last][last - offset] = matrix[i][last];
			matrix[i][last] = top;

		}
	}
	printMatrix(matrix,4,4);
}

int main()
{
	int matrix[4][4] = { { 1, 1, 1, 1 }, { 2, 2, 2, 2 }, { 3, 3, 3, 3 }, { 4, 4, 4, 4 } };
	
	rotateMatrix(matrix, 4, 4);
	return 0;
}

