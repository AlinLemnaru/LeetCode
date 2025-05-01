/********************************/
/* Author: Lemnaru Alin-Gabriel */
/* Date: 2025-04-26				*/
/********************************/

/* Exercise - Search Insert Position
* Given a sorted array of distinct integers and a target value, return the index if the target is found.
* If not, return the index where it would be if it were inserted in order.
* You must write an algorithm with O(log n) runtime complexity.
*/

/* Examples
* 
* Example 1:
* 
* Input: nums = [1,3,5,6], target = 5
* Output: 2
* 
* Example 2:
* 
* Input: nums = [1,3,5,6], target = 2
* Output: 1
* 
* Example 3:
* 
* Input: nums = [1,3,5,6], target = 7
* Output: 4
*/

/* LIBRARIES */

#include <stdio.h>
#include <stdlib.h>

/* FUNCTION PROTOTYPES */

int searchInsert(int* nums, int numsSize, int target);

/* TEST FUNCTION PROTOTYPES */

int Test_Example1();
int Test_Example2();
int Test_Example3();


/* MAIN FUNCTION */

int main()
{
	/* TESTING */

	int test1 = Test_Example1();
	int test2 = Test_Example2();
	int test3 = Test_Example3();

	if (test1 && test2 && test3)
	{
		printf("All tests passed!\n");
	}
	else
	{
		printf("Some tests failed.\n");
	}
	
	system("pause");
	return 0;
}

/* FUNCTION DEFINITIONS */

/* Description: 
* Given a sorted array of distinct integers and a target value, return the index if the target is found.
* If not, return the index where it would be if it were inserted in order.
* You must write an algorithm with O(log n) runtime complexity.
*/
int searchInsert(int* nums, int numsSize, int target)
{
	int left = 0, right = numsSize - 1, mid = 0; // Initialize left and right pointers for binary search

	while (left <= right) // Binary search loop
	{
		// Calculate mid index to avoid overflow
		// mid = (left + right) / 2; // This can cause overflow
		// mid = left + (right - left) / 2; // This avoids overflow
		mid = left + (right - left) / 2; 

		if (nums[mid] == target)
			return mid;
		else if (nums[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return left;
}

/* TEST FUNCTION DEFINITIONS*/

int Test_Example1()
{
	int nums[] = { 1,3,5,6 };
	int target = 5;
	int expected = 2;
	int result = searchInsert(nums, sizeof(nums) / sizeof(nums[0]), target);
	if (result == expected)
	{
		printf("Test_Example1 passed\n");
		return 1;
	}
	else
	{
		printf("Test_Example1 failed\n");
		printf("Expected: %d, Got: %d\n", expected, result);
		return 0;
	}
}

int Test_Example2()
{
	int nums[] = { 1,3,5,6 };
	int target = 2;
	int expected = 1;
	int result = searchInsert(nums, sizeof(nums) / sizeof(nums[0]), target);
	if (result == expected)
	{
		printf("Test_Example2 passed\n");
		return 1;
	}
	else
	{
		printf("Test_Example2 failed\n");
		printf("Expected: %d, Got: %d\n", expected, result);
		return 0;
	}
}

int Test_Example3()
{
	int nums[] = { 1,3,5,6 };
	int target = 7;
	int expected = 4;
	int result = searchInsert(nums, sizeof(nums) / sizeof(nums[0]), target);
	if (result == expected)
	{
		printf("Test_Example3 passed\n");
		return 1;
	}
	else
	{
		printf("Test_Example3 failed\n");
		printf("Expected: %d, Got: %d\n", expected, result);
		return 0;
	}
}