#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b);
int threeSumClosest(int* nums, int numsSize, int target);

int main()
{
	int nums1[] = { -1,2,1,-4 }, numsSize1 = 4, target1 = 1;
	int nums2[] = { 0,0,0 }, numsSize2 = 3, target2 = 1;
	int expected[] = { 2,0 };
	int result;

	result = threeSumClosest(nums1, numsSize1, target1);
	if (result == expected[0])
		printf("Test 1: PASSED - RESULT: %d\n", result);
	else
		printf("Test 1: FAILED - EXPECTED: %d - RESULT: %d\n", expected[0], result);

	result = threeSumClosest(nums2, numsSize2, target2);
	if (result == expected[1])
		printf("Test 1: PASSED - RESULT: %d\n\n", result);
	else
		printf("Test 1: FAILED - EXPECTED: %d - RESULT: %d\n\n", expected[1], result);


	system("pause");
	return 0;
}

int cmp(const void* a, const void* b)
{
	return (*(int*)a) - (*(int*)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
	// Sort array
	qsort(nums, numsSize, sizeof(int), cmp);

	int left, right, sum, closestSum = nums[0] + nums[1] + nums[2];

	for (int i = 0; i < numsSize - 2; i++)
	{
		left = i + 1;
		right = numsSize - 1;

		while (left < right)
		{
			sum = nums[i] + nums[left] + nums[right];

			if (abs(sum - target) < abs(closestSum - target))
				closestSum = sum;

			if (sum < target)
				left++;
			else if (sum > target)
				right--;
			else
				return sum;
		}
	}

	return closestSum;
}