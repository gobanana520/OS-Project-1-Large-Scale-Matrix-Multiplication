#include <stdio.h>

const int COLS=3;
void printMatrix(int *pArray, int rows, int cols);
void printMatix2(int (*pArray)[COLS],int rows);

int main()
{
	int A[4][4] = { {1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4} };
	int B[4][4] = { {4,3,2,1},{4,3,2,1},{4,3,2,1},{4,3,2,1} };
	
	printMatrix(A, 4, 4);
	printMatrix(B, 4, 4);
	
}

void printMatrix(int *pArray, int rows, int cols)
{
	int i;
	int j;
	
	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < cols; j++)
		{
			printf("%d\t", *pArray+i*cols+j);
		}
		printf("\n");
	}
}

