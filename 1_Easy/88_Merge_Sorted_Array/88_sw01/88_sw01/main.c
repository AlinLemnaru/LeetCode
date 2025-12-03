/********************************/
/* Author: Lemnaru Alin-Gabriel */
/* Date: 2025-05-01				*/
/********************************/

/* Exercise - Merge Sorted Array
* 
* You are given two sorted arrays, nums1 and nums2, of size m and n respectively, which represent the elements of two sorted arrays.
* Merge nums1 and nums2 into a single array sorted in non-decreasing order.
* The final sorted array should not be returned by the function, but instead be stored inside the array nums1.
* To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, 
* and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
* 
*/

/* Examples
* 
* Example 1:
* 
* Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
* Output: [1,2,2,3,5,6]
* 
* Explanation: The arrays we merge are [1,2,3] and [2,5,6]. The result is [1,2,2,3,5,6].
* 
* Example 2:
* 
* Input: nums1 = [1], m = 1, nums2 = [], n = 0
* Output: [1]
* 
* Example 3:
* 
* Input: nums1 = [0], m = 0, nums2 = [1], n = 1
* Output: [1]
* 
*/

#define _CRT_SECURE_NO_WARNINGS

/* INCLUDES */

#include <stdio.h>
#include <stdlib.h>

/* FUNCTION PROTOTYPES */

void printArray(int* arr, int size);
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);

/* TEST FUNCTION PROTOTYPES */

int Test_Example1();
int Test_Example2();
int Test_Example3();

/* MAIN */

int main()
{
	/* TESTING */

	Test_Example1();
	printf("\n");
	Test_Example2();
	printf("\n");
	Test_Example3();

	printf("\n");
	system("pause");
	return 0;
}

/* FUNCTION DEFINITIONS */

void printArray(int* arr, int size)
{
	int i;

	printf("[");

	for (i = 0; i < size - 1; i++)
		printf("%d, ", arr[i]);

	printf("%d]", arr[size - 1]);
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int i = m - 1, j = n - 1, k = m + n - 1;

	while (i >= 0 && j >= 0)
	{
		if (nums1[i] < nums2[j])
			nums1[k--] = nums2[j--];
		else
			nums1[k--] = nums1[i--];
	}

	while (j >= 0)
		nums1[k--] = nums2[j--];
}

/* TEST FUNCTION DEFINITIONS */

int Test_Example1()
{
	int result = 0;
	int nums1[] = { 1, 2, 3, 0, 0, 0}, m = 3, nums2[] = { 2, 5, 6}, n = 3;
	int expected[] = { 1, 2, 2, 3, 5, 6 };

	merge(nums1, sizeof(nums1) / sizeof(int), m, nums2, sizeof(nums2) / sizeof(int), n);

	for (int i = 0; i < sizeof(nums1) / sizeof(int); i++)
	{
		if (nums1[i] != expected[i])
		{
			result = 1;
			break;
		}
	}

	if (result)
	{
		printf("T1: FAILED\nExpected ");
		printArray(expected, sizeof(expected) / sizeof(int));
		printf(", got ");
		printArray(nums1, sizeof(nums1) / sizeof(int));
		printf("\n");
	}
	else
		printf("T1: PASSED\n");

	return result;
}

int Test_Example2()
{
	int result = 0;
	int nums1[] = { 1 }, m = 1, nums2[] = { 0 }, n = 0;
	int expected[] = { 1 };

	merge(nums1, sizeof(nums1) / sizeof(int), m, nums2, sizeof(nums2) / sizeof(int), n);

	for (int i = 0; i < sizeof(nums1) / sizeof(int); i++)
	{
		if (nums1[i] != expected[i])
		{
			result = 1;
			break;
		}
	}

	if (result)
	{
		printf("T2: FAILED\nExpected ");
		printArray(expected, sizeof(expected) / sizeof(int));
		printf(", got ");
		printArray(nums1, sizeof(nums1) / sizeof(int));
		printf("\n");
	}
	else
		printf("T2: PASSED\n");

	return result;
}

int Test_Example3()
{
	int result = 0;
	int nums1[] = { 0 }, m = 0, nums2[] = { 1 }, n = 1;
	int expected[] = { 1 };

	merge(nums1, sizeof(nums1) / sizeof(int), m, nums2, sizeof(nums2) / sizeof(int), n);

	for (int i = 0; i < sizeof(nums1) / sizeof(int); i++)
	{
		if (nums1[i] != expected[i])
		{
			result = 1;
			break;
		}
	}

	if (result)
	{
		printf("T3: FAILED\nExpected ");
		printArray(expected, sizeof(expected) / sizeof(int));
		printf(", got ");
		printArray(nums1, sizeof(nums1) / sizeof(int));
		printf("\n");
	}
	else
		printf("T3: PASSED\n");

	return result;
}