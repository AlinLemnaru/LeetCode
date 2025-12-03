/********************************/
/* Author: Lemnaru Alin-Gabriel */
/* Date: 2025-04-28				*/
/********************************/

/* Exercise - Add Binary
* 
* Given two binary strings a and b, return their sum as a binary string.
* The input strings are both non-empty and contain only characters 1 or 0.
* 
*/

/* Examples
* 
* Example 1:
* 
* Input: a = "11", b = "1"
* Output: "100"
* 
* Example 2:
* 
* Input: a = "1010", b = "1011"
* Output: "10101"
* 
*/

/* LIBRARIES */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* FUNCTION PROTOTYPES */

char* addBinary(char* a, char* b);

/* TEST FUNCTION PROTOTYPES */

int Test_Example1(void);
int Test_Example2(void);

/* MAIN FUNCTION */

int main(void)
{
	/* Test the function with example cases */
	if (Test_Example1() == 0)
	{
		printf("Test Example 1 passed.\n");
	}
	else
	{
		printf("Test Example 1 failed.\n");
	}

	if (Test_Example2() == 0)
	{
		printf("Test Example 2 passed.\n");
	}
	else
	{
		printf("Test Example 2 failed.\n");
	}

	system("pause");
	return 0;
}

/* FUNCTION DEFINITIONS */

char* addBinary(char* a, char* b)
{
	char* result;
	size_t lenA = strlen(a);
	size_t lenB = strlen(b);
	size_t maxLen;
	int carry = 0, sum = 0, bitA, bitB;

	if (lenA > lenB)
	{
		maxLen = lenA;
	}
	else
	{
		maxLen = lenB;
	}

	result = (char*)malloc(maxLen + 2); // +1 for carry, +1 for null terminator

	if (result == NULL)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}

	result[maxLen + 1] = '\0'; // Null-terminate the result string

	for (int i = 0; i < maxLen; i++)
	{
		if (i < lenA)
			bitA = a[lenA - 1 - i] - '0'; // Get the bit from string a
		else
			bitA = 0; // If a is shorter, treat missing bits as 0

		if (i < lenB)
			bitB = b[lenB - 1 - i] - '0'; // Get the bit from string b
		else
			bitB = 0; // If b is shorter, treat missing bits as 0

		sum = bitA + bitB + carry;
		result[maxLen - i] = (sum % 2) + '0'; // Store the binary digit in reverse order
		carry = sum / 2;
	}

	if (carry)
	{
		result[0] = '1'; // If there's a carry, place it at the start
		return result;
	}

	return result + 1; // If no carry, return the string starting from the second character
}

/* TEST FUNCTION DEFINITIONS */

int Test_Example1(void)
{
	char* a = "11";
	char* b = "1";
	char* expected = "100";

	char* result = addBinary(a, b);
	int testResult = strcmp(result, expected);

	if (testResult != 0)
	
	{
		printf("Test Example 1 failed. Expected: %s, Got: %s\n", expected, result);
	}

	return testResult;
}

int Test_Example2(void)
{
	char* a = "1010";
	char* b = "1011";
	char* expected = "10101";

	char* result = addBinary(a, b);
	int testResult = strcmp(result, expected);

	if (testResult != 0)
	{
		printf("Test Example 2 failed. Expected: %s, Got: %s\n", expected, result);
	}

	return testResult;
}

