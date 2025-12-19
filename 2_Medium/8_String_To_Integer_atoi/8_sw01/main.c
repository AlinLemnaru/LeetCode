#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myAtoi(char* s);

int main()
{
	char s[6][15] = { "+-12", "42\0", " -042\0", "1337c0d3\0", "0-1", "words and 987"};
	int expected[] = { 0, 42,-42,1337,0,0 };
	int index = 1, result;

	for (index = 0; index < 6; index++)
	{
		result = myAtoi(s[index]);

		if (result == expected[index])
			printf("Test %d - PASSED\n result: %d\n\n", index + 1, result);
		else
			printf("Test %d - FAILED\n expected: %d\n received:%d\n\n", index + 1, expected[index], result);
	}

	system("pause");
	return 0;
}

int myAtoi(char* s) {
	int result = 0, index = 0, sign = 1, digit;
	
	while (s[index] == ' ')
		index++;

	if (s[index] == '+' || s[index] == '-')
	{
		if (s[index] == '-')
			sign = -1;
		index++;
	}

	while (s[index] >= '0' && s[index] <= '9')
	{
		digit = s[index] - '0';

		if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10))
		{
			if (sign == 1)
				return INT_MAX;
			else
				return INT_MIN;
		}

		result = result * 10 + digit;

		index++;
	}

	return result * sign;
}