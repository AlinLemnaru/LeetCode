#define _CRT_SECURE_NO_WARNINGS	

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print2DCharArray(char** arr, int returnSize);
int catalan(int n);
void backtrack(int n, int open, int close, char* current, int pos, char** result, int* returnSize);
char** generateParenthesis(int n, int* returnSize);

int main()
{
	int n1 = 3, returnSize1, n2 = 1, returnSize2;
	char** result1, ** result2;

	printf("Test 1:\n");
	result1 = generateParenthesis(n1, &returnSize1);
	print2DCharArray(result1, returnSize1);

	printf("Test 2:\n");
	result2 = generateParenthesis(n2, &returnSize2);
	print2DCharArray(result2, returnSize2);

	printf("\n\n");

	for (int i = 0; i < returnSize1; i++)
		free(result1[i]);
	free(result1);

	for (int i = 0; i < returnSize2; i++)
		free(result2[i]);
	free(result2);

	system("pause");
	return 0;
}

void print2DCharArray(char** arr, int returnSize)
{
	printf("[ ");
	for (int i = 0; i < returnSize; i++)
		printf("[ %s ]", arr[i]);
	printf(" ]");
}

int catalan(int n) {
	long long res = 1;
	for (int i = 0; i < n; i++)
		res = res * 2 * (2 * i + 1) / (i + 2);
	return (int)res;
}

void backtrack(int n, int open, int close, char* current, int pos, char** result, int* returnSize)
{
	if (pos == 2 * n)
	{
		current[pos] = '\0';
		result[*returnSize] = _strdup(current); //strdup
		(*returnSize)++;
		return;
	}

	if (open < n)
	{
		current[pos] = '(';
		backtrack(n, open + 1, close, current, pos + 1, result, returnSize);
	}

	if (close < open)
	{
		current[pos] = ')';
		backtrack(n, open, close + 1, current, pos + 1, result, returnSize);
	}
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize) {
	*returnSize = 0;

	if (n == 0)
		return NULL;

	// Catalan numbers
	int capacity = catalan(n);

	char** result = malloc(capacity * sizeof(char*));
	char* current = malloc((2 * n + 1) * sizeof(char));

	if (result == NULL || current == NULL)
		return NULL;

	backtrack(n, 0, 0, current, 0, result, returnSize);

	free(current);

	return result;
}