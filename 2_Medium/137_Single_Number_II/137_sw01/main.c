#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int singleNumber(int* nums, int numsSize);

int main()
{
	int nums1[] = { 2,2,3,2 }, nums2[] = { 0,1,0,1,0,1,99 };
	int numsSize1 = 4, numsSize2 = 7;
	int expected[] = { 3, 99 }, result;

	// Test 1
	result = singleNumber(nums1, numsSize1);
	if (result == expected[0])
		printf("Test 1: PASSED - Result: %d\n", result);
	else
		printf("Test 1: FAILED - Expected: %d - Result: %d\n", expected[0], result);

	// Test 2
	result = singleNumber(nums2, numsSize2);
	if (result == expected[1])
		printf("Test 2: PASSED - Result: %d\n\n", result);
	else
		printf("Test 2: FAILED - Expected: %d - Result: %d\n\n", expected[1], result);

	system("pause");
	return 0;
}

//int singleNumber(int* nums, int numsSize) {
//	int result = 0, sum;
//
//	// Iterate Bits
//	for (int i = 0; i < 32; i++)
//	{
//		sum = 0;
//
//		// Iterate nums
//		for (int j = 0; j < numsSize; j++)
//			if ((nums[j] >> i) & 1)
//				sum++;
//
//		if (sum % 3 > 0)
//			result |= (1 << i);
//	}
//
//	return result;
//}

int singleNumber(int* nums, int numsSize) {
	int ones = 0, twos = 0;

	for (int i = 0; i < numsSize; i++) {
		ones = (ones ^ nums[i]) & ~twos;
		twos = (twos ^ nums[i]) & ~ones;
	}
	return ones;
}
