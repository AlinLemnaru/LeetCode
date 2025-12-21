#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* intToRoman(int num);

int main()
{
	int num;
	char* result;
	char expected[][11] = { "MMMDCCXLIX\0", "LVIII\0" };

	num = 3749;
	result = intToRoman(num);
	
	if (strcmp(result, expected[0]) == 0)
		printf("Test 1: PASSED - RESULT: %s", result);
	else
		printf("Test 1: FAILED - EXPECTED: %s - RESULT: %s", expected[0], result);

	num = 58;
	result = intToRoman(num);

	if (strcmp(result, expected[1]) == 0)
		printf("\nTest 1: PASSED - RESULT: %s\n\n", result);
	else
		printf("\nTest 1: FAILED - EXPECTED: %s - RESULT: %s\n\n", expected[1], result);

	free(result);
	system("pause");
	return 0;
}

char* intToRoman(int num) {
	// Roman numbers in int and string form
	int iRoman[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	char* sRoman[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

	// 1 <= num <= 3999 -> sizeof(result) = 16
	char* result = (char*)malloc(20 * sizeof(char));

	if (result == NULL)
		return NULL;

	int pos = 0;

	while (num > 0)
	{
		for (int i = 0; i < 13; i++)
			if (iRoman[i] <= num)
			{
				num -= iRoman[i];
				
				if (strlen(sRoman[i]) == 1)
					result[pos++] = sRoman[i][0];
				else
				{
					result[pos++] = sRoman[i][0];
					result[pos++] = sRoman[i][1];
				}

				break;
			}
	}

	result[pos] = '\0';

	return result;
}