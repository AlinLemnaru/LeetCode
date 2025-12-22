#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printStringArray(char** array, int size);
char** letterCombinations(char* digits, int* returnSize);

int main()
{
	char digits1[] = "23", digits2[] = "2";
	int returnSize1, returnSize2;
	char* expected1[] = { "ad","ae","af","bd","be","bf","cd","ce","cf" };
	char* expected2[] = { "a","b","c" };
	char** result1, ** result2;

	printf("Test 1:\n");
	result1 = letterCombinations(digits1, &returnSize1);
	printStringArray(result1, returnSize1);
	printf("\n");

	printf("Test 2:\n");
	result2 = letterCombinations(digits2, &returnSize2);
	printStringArray(result2, returnSize2);
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

void printStringArray(char** sArray, int size)
{
	printf("[ ");
	for (int i = 0; i < size; i++)
	{
		printf("[ ");
		for (int j = 0; j < strlen(sArray[i]); j++)
			printf("%c ", sArray[i][j]);
		printf("] ");
	}
	printf("]");
}

void backtrack(char* digits, int index, char* current, char** result, int* returnSize, char** map)
{
	if (digits[index] == '\0')
	{
		result[*returnSize] = _strdup(current);
		(*returnSize)++;
		return;
	}

	char* letters = map[digits[index] - '0'];

	for (int i = 0; letters[i] != '\0'; i++)
	{
		current[index] = letters[i];
		backtrack(digits, index + 1, current, result, returnSize, map);
	}
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) 
{
	*returnSize = 0;

	if (digits[0] == '\0')
		return NULL;

	int maxCombinations = 1, digitsSize = strlen(digits);
	char** result;
	char* current;

	char* map[] = {
		"",     // 0
		"",     // 1
		"abc",  // 2
		"def",  // 3
		"ghi",  // 4
		"jkl",  // 5
		"mno",  // 6
		"pqrs", // 7
		"tuv",  // 8
		"wxyz"  // 9
	};

	for (int i = 0; i < digitsSize; i++)
		maxCombinations *= strlen(map[digits[i] - '0']);

	result = malloc(maxCombinations * sizeof(char*));
	current = malloc((digitsSize + 1) * sizeof(char));

	if (result == NULL || current == NULL)
		return NULL;

	current[digitsSize] = '\0';

	backtrack(digits, 0, current, result, returnSize, map);

	free(current);

	return result;
}