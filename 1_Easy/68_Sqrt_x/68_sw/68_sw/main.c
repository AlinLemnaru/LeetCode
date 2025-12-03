/********************************/
/* Author: Lemnaru Alin-Gabriel */
/* Date: 2025-05-01				*/
/********************************/

/* Exercise - Sqrt(x)
 * Given a non-negative integer x, return the square root of x rounded down to the nearest integer. 
 * The returned integer should be non-negative as well.
 * The function should not use any built-in exponentiation or square root functions.
 * The function should have a time complexity of O(log n).
*/

/* Examples
 * Input: x = 4
 * Output: 2
 * Explanation: The square root of 4 is 2, so we return 2.
 *
 * Input: x = 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, we return 2.
*/

#define _CRT_SECURE_NO_WARNINGS

/* LIBRARIES */

#include <stdio.h>
#include <stdlib.h>

/* FUNCTION PROTOTYPES */ 

int mySqrt(int x);
void test_mySqrt(int x, int expected);

/* MAIN FUNCTION */

int main(void)
{
	/* TEST CASES */

	printf("Test cases for mySqrt function:\n");
	printf("====================================\n");
	printf("Test case 1: ");
	test_mySqrt(4, 2);
	printf("Test case 2: ");
	test_mySqrt(8, 2);

	system("pause");
	return 0;
}

/* FUNCTION DEFINITIONS */

int mySqrt(int x)
{
	if (x < 0)
	{
		return -1; // Invalid input
	}
	if (x == 0 || x == 1)
	{
		return x; // Return x for 0 and 1
	}

	int left = 1, right = x / 2, mid;
	while (left <= right)
	{
		mid = left + (right - left) / 2; 
		if (mid * mid == x)
		{
			return mid; // Found exact square root
		}
		else if (mid * mid < x)
		{
			left = mid + 1; // Search in the right half
		}
		else
		{
			right = mid - 1; // Search in the left half
		}
	}
	return right; // Return the largest integer whose square is less than or equal to x
}

void test_mySqrt(int x, int expected)
{
	int result = mySqrt(x);
	if (result == expected)
	{
		printf("V Test PASSED for input %d: expected %d, got %d\n", x, expected, result);
	}
	else
	{
		printf("X Test FAILED for input %d: expected %d, got %d\n", x, expected, result);
	}
}