#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows);

int main()
{
	char s[] = "PAYPALISHIRING";
	char* result = (char*)calloc(strlen(s), sizeof(char));

	if (result == NULL)
		return -1;

	strcpy(result, convert(s, 3));
	printf("Test 1: %s\n", result);
	
	strcpy(result, convert(s, 4));
	printf("\nTest 2: %s\n\n", result);

	system("pause");
	return 0;
}

/*
* rows = 3
* | |
* |/|
* |	|
* 
* rows = 4
* 
* |  | 
* | /|
* |/ |
* |  |
* 
* s = TELEENCICLOPEDIE, rows = 4
* T     C     E
* E   N I   P D
* L E   C O   I
* E     L     E
* 
* s = 0123456789ABCDEF, rows = 4
* 0     6     C
* 1   5 7   B D
* 2 4   8 A   E
* 3     9     F
*/

char* convert(char* s, int numRows) 
{
	char** zigzag = (char**)calloc(numRows, sizeof(char*));
	char* result = (char*)calloc(strlen(s) + 1, sizeof(char));
	int* sizes = (int*)calloc(numRows, sizeof(int));
	int i, j, k = 0, direction, currentRow = 0;

	if (numRows == 1 || numRows >= strlen(s))
	{
		strcpy(result, s);
		return result;
	}

	if (zigzag == NULL || result == NULL || sizes == NULL)
		return "";


	for (i = 0; i < numRows; i++)
	{
		zigzag[i] = (char*)calloc(strlen(s) + 1, sizeof(char));

		if (zigzag[i] == NULL)
			return "";
	}

	for (i = 0; i < strlen(s); i++)
	{
		zigzag[currentRow][sizes[currentRow]++] = s[i];

		if (currentRow == 0)
			direction = 1;
		else if (currentRow == numRows - 1)
			direction = -1;

		currentRow += direction;
	}

	for (i = 0; i < numRows; i++)
		for (j = 0; j < sizes[i]; j++)
			result[k++] = zigzag[i][j];

	result[k] = '\0';

	for (i = 0; i < numRows; i++)
		free(zigzag[i]);
	free(zigzag);
	free(sizes);

	return result;
}