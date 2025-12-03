/********************************/
/* Author: Lemnaru Alin-Gabriel */
/* Date: 18-04-2025             */
/********************************/

/* Exercise - Palindrome
Given an integer x, return true if x is a palindrome, and false otherwise.
*/

/* Examples
Example 1:

	Input: x = 121
	Output: true
	
	Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:

	Input: x = -121
	Output: false
	
	Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:

	Input: x = 10
	Output: false

	Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x);
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

bool isPalindrome(int x) {
	long copy_x = x, invX = 0;

	while (copy_x > 0)
	{
		invX = invX * 10 + copy_x % 10;
		copy_x /= 10;
	}

	return (x == invX) ? true : false;
}

int Test_Example1()
{
	int result = 1;
	int x;
	bool expected;

	//Input: x = 121
	//Output : true

	x = 121;
	expected = true;

	//Checking result
	if (expected != isPalindrome(x))
		result = 0;

	return result;
}

int Test_Example2()
{
	int result = 1;
	int x;
	bool expected;

	//Input: x = -121
	//Output : false

	x = -121;
	expected = false;

	//Checking result
	if (expected != isPalindrome(x))
		result = 0;

	return result;
}

int Test_Example3()
{
	int result = 1;
	int x;
	bool expected;

	//Input: x = 10
	//Output : false

	x = 10;
	expected = false;

	//Checking result
	if (expected != isPalindrome(x))
		result = 0;

	return result;
}