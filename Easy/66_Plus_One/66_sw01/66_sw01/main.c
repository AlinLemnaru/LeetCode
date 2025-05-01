/********************************/
/* Author: Lemnaru Alin-Gabriel */
/* Date: 2025-04-26				*/
/********************************/

/* Exercise - Plus One 
* Write a function that takes a non-negative integer represented as an array of digits and returns the integer plus one.
* The digits are ordered from most significant to least significant in left-to-right order. No leading 0's.
*/

/* Examples
* 
* Example 1:
* 
* Input: digits = [1,2,3]
* Output: [1,2,4]
* 
* Explanation: The array represents the integer 123.
* Incrementing by one gives 123 + 1 = 124.
* Thus, the result should be [1,2,4].
* 
* Example 2:
* 
* Input: digits = [4,3,2,1]
* Output: [4,3,2,2]
* 
* Explanation: The array represents the integer 4321.
* Incrementing by one gives 4321 + 1 = 4322.
* Thus, the result should be [4,3,2,2].
* 
* Example 3:
* 
* Input: digits = [9]
* Output: [1,0]
* 
* Explanation: The array represents the integer 9.
* Incrementing by one gives 9 + 1 = 10.
* Thus, the result should be [1,0].
*/

/* LIBRARIES */

#include <stdio.h>
#include <stdlib.h>

/* FUNCTION PROTOTYPES */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize);

/* TEST FUNCTION PROTOTYPES */

int Test_Example1();
int Test_Example2();
int Test_Example3();

/* MAIN */

int main()
{
	/* TESTING */

	printf("Testing Example 1...\n");
	Test_Example1();
	printf("Testing Example 2...\n");
	Test_Example2();
	printf("Testing Example 3...\n");
	Test_Example3();

	printf("All tests completed.\n");

	system("pause");
	return 0;
}

/* FUNCTION DEFINITIONS */

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
	int sum = 0, carry = 1;
	int* result = (int*)malloc((digitsSize + 1) * sizeof(int));
	if (result == NULL)
	{
		*returnSize = 0;
		printf("\nError in memory allocation\n");
		return NULL;
	}

	for (int i = digitsSize - 1; i >= 0; i--)
	{
		sum = digits[i] + carry;
		result[i + 1] = sum % 10;
		carry = sum / 10;
	}

	if (carry > 0)
	{
		result[0] = carry;
		*returnSize = digitsSize + 1;
	}
	else
	{
		for (int i = 0; i < digitsSize; i++)
		{
			result[i] = result[i + 1];
		}
		*returnSize = digitsSize;
	}

	return result;
}

/* TEST FUNCTION DEFINITIONS */

int Test_Example1()
{
	int digits[] = { 1,2,3 };
	int digitsSize = sizeof(digits) / sizeof(digits[0]);
	int returnSize;
	int* result = plusOne(digits, digitsSize, &returnSize);

	// Print the result
	printf("Result: ");
	for (int i = 0; i < returnSize; i++)
	{
		printf("%d ", result[i]);
	}
	printf("\n");

	free(result);
	return 0;
}

int Test_Example2()
{
	int digits[] = { 4,3,2,1 };
	int digitsSize = sizeof(digits) / sizeof(digits[0]);
	int returnSize;
	int* result = plusOne(digits, digitsSize, &returnSize);

	// Print the result
	printf("Result: ");
	for (int i = 0; i < returnSize; i++)
	{
		printf("%d ", result[i]);
	}
	printf("\n");

	free(result);
	return 0;
}

int Test_Example3()
{
	int digits[] = { 9 };
	int digitsSize = sizeof(digits) / sizeof(digits[0]);
	int returnSize;
	int* result = plusOne(digits, digitsSize, &returnSize);

	// Print the result
	printf("Result: ");
	for (int i = 0; i < returnSize; i++)
	{
		printf("%d ", result[i]);
	}
	printf("\n");

	free(result);
	return 0;
}