
/********************************/
/* Author: Lemnaru Alin-Gabriel */
/* Date: 18-04-2025				*/
/********************************/

/* Exercise - Two Sum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/

/* Examples
Example 1:

	Input: nums = [2, 7, 11, 15], target = 9
	Output : [0, 1]
	
	Explanation : Because nums[0] + nums[1] == 9, we return[0, 1].

Example 2 :

	Input : nums = [3, 2, 4], target = 6
	Output : [1, 2]

Example 3 :

	Input : nums = [3, 3], target = 6
	Output : [0, 1]
*/

#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);
int Test_Example1();
int Test_Example2();
int Test_Example3();

int main()
{
	printf("##########T1##########\n\n");
	if (Test_Example1())
		printf("\nTest 1: PASSED\n");
	else
		printf("\nTest 1: FAILED\n");
	printf("\n######################\n\n");

	printf("##########T2##########\n\n");
	if (Test_Example2())
		printf("\nTest 2: PASSED\n");
	else
		printf("\nTest 2: FAILED\n");
	printf("\n######################\n\n");

	printf("##########T3##########\n\n");
	if (Test_Example3())
		printf("\nTest 3: PASSED\n");
	else
		printf("\nTest 3: FAILED\n");
	printf("\n######################\n\n");

	system("pause");
	return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int sum = 0;
	int* ret;

	*returnSize = 2;
	ret = (int*)malloc(*(returnSize) * sizeof(int));
	if (ret == NULL)
	{
		printf("\nMemory allocation ERROR!\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < numsSize - 1; i++)
	{
		for (int j = i + 1; j < numsSize; j++)
		{
			sum = (*(nums + i)) + (*(nums + j));
			if (sum == target)
			{
				*(ret) = i;\
				*(ret + 1) = j;
				return ret;
			}
		}
	}

	return ret;
}

int Test_Example1()
{
	int result = 1;
	int* expected;

	int* nums, * returnSize;
	int numsSize, target;

	//Input: nums = [2, 7, 11, 15], target = 9
	//Output : [0, 1]

	numsSize = 4;
	target = 9;
	expected = (int*)malloc(2 * sizeof(int));

	if (expected == NULL)
	{
		printf("\nMemory allocation ERROR!\n");
		exit(EXIT_FAILURE);
	}

	*(expected) = 0;
	*(expected + 1) = 1;

	nums = (int*)malloc(numsSize * sizeof(int));
	if (nums == NULL)
	{
		printf("\nMemory allocation ERROR!\n");
		exit(EXIT_FAILURE);
	}

	*(nums) = 2;
	*(nums + 1) = 7;
	*(nums + 2) = 11;
	*(nums + 3) = 15;

	returnSize = (int*)malloc(sizeof(int));
	if (returnSize == NULL)
	{
		printf("\nMemory allocation ERROR!\n");
		exit(EXIT_FAILURE);
	}

	//Display expected and result
	printf("Expected: [%d, %d]\n", *(expected), *(expected + 1));
	printf("Result: [%d, %d]\n", *(twoSum(nums, numsSize, target, returnSize)), *(twoSum(nums, numsSize, target, returnSize) + 1));

	//Checking the result
	if ((*(expected) == *(twoSum(nums, numsSize, target, returnSize))) && (*(expected + 1) == *(twoSum(nums, numsSize, target, returnSize) + 1)))
		result = 1;
	else
		result = 0;

	free(expected);
	free(nums);
	free(returnSize);

	return result;
}

int Test_Example2()
{
	int result = 1;
	int* expected;

	int* nums, * returnSize;
	int numsSize, target;

	//Input: nums = [3, 2, 4], target = 6
	//Output : [1, 2]

	numsSize = 3;
	target = 6;
	expected = (int*)malloc(2 * sizeof(int));

	if (expected == NULL)
	{
		printf("\nMemory allocation ERROR!\n");
		exit(EXIT_FAILURE);
	}

	*(expected) = 1;
	*(expected + 1) = 2;

	nums = (int*)malloc(numsSize * sizeof(int));
	if (nums == NULL)
	{
		printf("\nMemory allocation ERROR!\n");
		exit(EXIT_FAILURE);
	}

	*(nums) = 3;
	*(nums + 1) = 2;
	*(nums + 2) = 4;
	
	returnSize = (int*)malloc(sizeof(int));
	if (returnSize == NULL)
	{
		printf("\nMemory allocation ERROR!\n");
		exit(EXIT_FAILURE);
	}

	//Display expected and result
	printf("Expected: [%d, %d]\n", *(expected), *(expected + 1));
	printf("Result: [%d, %d]\n", *(twoSum(nums, numsSize, target, returnSize)), *(twoSum(nums, numsSize, target, returnSize) + 1));

	//Checking the result
	if ((*(expected) == *(twoSum(nums, numsSize, target, returnSize))) && (*(expected + 1) == *(twoSum(nums, numsSize, target, returnSize) + 1)))
		result = 1;
	else
		result = 0;

	free(expected);
	free(nums);
	free(returnSize);

	return result;
}

int Test_Example3()
{
	int result = 1;
	int* expected;

	int* nums, * returnSize;
	int numsSize, target;

	//Input: nums = [3, 3], target = 6
	//Output : [0, 1]

	numsSize = 2;
	target = 6;
	expected = (int*)malloc(2 * sizeof(int));

	if (expected == NULL)
	{
		printf("\nMemory allocation ERROR!\n");
		exit(EXIT_FAILURE);
	}

	*(expected) = 0;
	*(expected + 1) = 1;

	nums = (int*)malloc(numsSize * sizeof(int));
	if (nums == NULL)
	{
		printf("\nMemory allocation ERROR!\n");
		exit(EXIT_FAILURE);
	}

	*(nums) = 3;
	*(nums + 1) = 3;

	returnSize = (int*)malloc(sizeof(int));
	if (returnSize == NULL)
	{
		printf("\nMemory allocation ERROR!\n");
		exit(EXIT_FAILURE);
	}

	//Display expected and result
	printf("Expected: [%d, %d]\n", *(expected), *(expected + 1));
	printf("Result: [%d, %d]\n", *(twoSum(nums, numsSize, target, returnSize)), *(twoSum(nums, numsSize, target, returnSize) + 1));

	//Checking the result
	if ((*(expected) == *(twoSum(nums, numsSize, target, returnSize))) && (*(expected + 1) == *(twoSum(nums, numsSize, target, returnSize) + 1)))
		result = 1;
	else
		result = 0;

	free(expected);
	free(nums);
	free(returnSize);

	return result;
}