#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int singleNumber(int* nums, int numsSize);

int main()
{
	int nums1[] = { 2,2,1 }, nums2[] = { 4,1,2,1,2 }, nums3[] = { 1 };
	int numsSize1 = 3, numsSize2 = 5, numsSize3 = 1;
	int expected[] = { 1,4,1 }, result;

	// Test 1
	result = singleNumber(nums1, numsSize1);
	if (result == expected[0])
		printf("Test 1: PASSED - Result: %d\n", result);
	else
		printf("Test 1: FAILED - Expected: %d - Result: %d\n", expected[0], result);

	// Test 2
	result = singleNumber(nums2, numsSize2);
	if (result == expected[1])
		printf("Test 2: PASSED - Result: %d\n", result);
	else
		printf("Test 2: FAILED - Expected: %d - Result: %d\n", expected[1], result);

	// Test 3
	result = singleNumber(nums3, numsSize3);
	if (result == expected[2])
		printf("Test 3: PASSED - Result: %d\n\n", result);
	else
		printf("Test 3: FAILED - Expected: %d - Result: %d\n\n", expected[2], result);

	system("pause");
	return 0;
}

int singleNumber(int* nums, int numsSize) {
	int res = 0;

	for (int i = 0; i < numsSize; i++)
		res ^= nums[i];

	return res;
}