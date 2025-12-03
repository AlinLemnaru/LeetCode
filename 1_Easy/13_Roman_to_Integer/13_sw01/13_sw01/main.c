/********************************/
/* Author: Lemnaru Alin-Gabriel */
/* Date: 18-04-2025				*/
/********************************/

/* Exercise - Roman to Integer
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.
*/

/* Examples
Example 1:

	Input: s = "III"
	Output: 3

	Explanation: III = 3.

Example 2:

	Input: s = "LVIII"
	Output: 58

	Explanation: L = 50, V= 5, III = 3.

Example 3:

	Input: s = "MCMXCIV"
	Output: 1994

	Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int romanToInt(char* s);
int Test_Example1();
int Test_Example2();
int Test_Example3();

int main()
{
	printf("##########T1##########\n");
	if (Test_Example1())
		printf("\nTest 1: PASSED\n");
	else
		printf("\nTest 1: FAILED\n");
	printf("\n######################\n");

	printf("\n##########T2##########\n");
	if (Test_Example2())
		printf("\nTest 2: PASSED\n");
	else
		printf("\nTest 2: FAILED\n");
	printf("\n######################\n");

	printf("\n##########T3##########\n");
	if (Test_Example3())
		printf("\nTest 3: PASSED\n");
	else
		printf("\nTest 3: FAILED\n");
	printf("\n######################\n\n");

	system("pause");
	return 0;
}

int romanToInt(char* s) {
	int sum = 0;

	while (*s != '\0')
	{
		if (*s == 'I' && *(s + 1) == 'V')
		{
			sum += 4;
			s += 2;
			continue;
		}

		if (*s == 'I' && *(s + 1) == 'X')
		{
			sum += 9;
			s += 2;
			continue;
		}

		if (*s == 'X' && *(s + 1) == 'L')
		{
			sum += 40;
			s += 2;
			continue;
		}

		if (*s == 'X' && *(s + 1) == 'C')
		{
			sum += 90;
			s += 2;
			continue;
		}

		if (*s == 'C' && *(s + 1) == 'D')
		{
			sum += 400;
			s += 2;
			continue;
		}

		if (*s == 'C' && *(s + 1) == 'M')
		{
			sum += 900;
			s += 2;
			continue;
		}

		switch (*s)
		{
		case 'I':
			sum++;
			break;
		case 'V':
			sum += 5;
			break;
		case 'X':
			sum += 10;
			break;
		case 'L':
			sum += 50;
			break;
		case 'C':
			sum += 100;
			break;
		case 'D':
			sum += 500;
			break;
		case 'M':
			sum += 1000;
			break;
		default:
			printf("Incorrect format!");
			exit(EXIT_FAILURE);
			break;
		}

		s++;
	}

	return sum;
}

int Test_Example1()
{
	int result = 1;
	char* s;
	int expected;

	//Input: s = "III"
	//Output: 3

	s = (char*)malloc(4 * sizeof(char));
	if (s == NULL)
	{
		printf("Memory allocation ERROR!");
		exit(EXIT_FAILURE);
	}

	strcpy(s, "III\0");
	expected = 3;

	//Checking result
	if (expected != romanToInt(s))
		result = 0;

	return result;
}

int Test_Example2()
{
	int result = 1;
	char* s;
	int expected;

	//Input: s = "LVIII"
	//Output: 58

	s = (char*)malloc(4 * sizeof(char));
	if (s == NULL)
	{
		printf("Memory allocation ERROR!");
		exit(EXIT_FAILURE);
	}

	strcpy(s, "LVIII\0");
	expected = 58;

	//Checking result
	if (expected != romanToInt(s))
		result = 0;

	return result;
}

int Test_Example3()
{
	int result = 1;
	char* s;
	int expected;

	//Input: s = "MCMXCIV"
	//Output: 1994

	s = (char*)malloc(4 * sizeof(char));
	if (s == NULL)
	{
		printf("Memory allocation ERROR!");
		exit(EXIT_FAILURE);
	}

	strcpy(s, "MCMXCIV\0");
	expected = 1994;

	//Checking result
	if (expected != romanToInt(s))
		result = 0;

	return result;
}