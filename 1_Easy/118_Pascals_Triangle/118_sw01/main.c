#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void print2DArray(int** arr, int returnSize, int* returnColumnSizes);
int** generate(int numRows, int* returnSize, int** returnColumnSizes);

int main()
{
	int numRows1 = 5, numRows2 = 1;
	int returnSize1, returnSize2;
	int* returnColumnSizes1, * returnColumnSizes2;
	int** result1, ** result2;

	// Test 1
	printf("Test 1:\n");
	result1 = generate(numRows1, &returnSize1, &returnColumnSizes1);
	print2DArray(result1, returnSize1, returnColumnSizes1);

	// Test 2
	printf("\n\nTest 2:\n");
	result2 = generate(numRows2, &returnSize2, &returnColumnSizes2);
	print2DArray(result2, returnSize2, returnColumnSizes2);

	// Free
	if (result1 != NULL)
	{
		for (int i = 0; i < returnSize1; i++)
			free(result1[i]);
		free(result1);
	}

	if (result2 != NULL)
	{
		for (int i = 0; i < returnSize2; i++)
			free(result2[i]);
		free(result2);
	}

	if (returnColumnSizes1 != NULL)
		free(returnColumnSizes1);

	if (returnColumnSizes2 != NULL)
		free(returnColumnSizes2);

	printf("\n\n\n");

	system("pause");
	return 0;
}

void print2DArray(int** arr, int returnSize, int* returnColumnSizes)
{
	for (int i = 0; i < returnSize; i++)
	{
		for (int j = 0; j < returnColumnSizes[i]; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
	if (numRows <= 0)
		return NULL;
	
	*returnSize = 0;
	*returnColumnSizes = malloc(numRows * sizeof(int));
	int** result = malloc(numRows * sizeof(int*));

	if (result == NULL || *returnColumnSizes == NULL)
		return NULL;

	for (int i = 0; i < numRows; i++)
	{
		(*returnColumnSizes)[i] = i + 1;

		result[i] = malloc((*returnColumnSizes)[i] * sizeof(int));

		if (result[i] == NULL)
			return result;

		(*returnSize)++;

		for (int j = 0; j < (*returnColumnSizes)[i]; j++)
		{
			if (j == 0 || j == ((*returnColumnSizes)[i] - 1))
				result[i][j] = 1;
			else
				result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
		}
	}

	return result;
}