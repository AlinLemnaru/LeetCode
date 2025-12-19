#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int reverse(int x);

int main()
{
	int x, result;

	x = 123;
	result = reverse(x);
	printf("Test 1: %d", result);

	x = -123;
	result = reverse(x);
	printf("\nTest 2: %d", result);

	x = 120;
	result = reverse(x);
	printf("\nTest 3: %d\n\n", result);

	system("pause");
	return 0;
}

int reverse(int x) 
{
	int result = 0;

	while (x != 0)
	{
		if (result > INT_MAX / 10 || result < INT_MIN / 10)
			return 0;

		result = result * 10 + x % 10;
		x /= 10;
	}

	return result;
}