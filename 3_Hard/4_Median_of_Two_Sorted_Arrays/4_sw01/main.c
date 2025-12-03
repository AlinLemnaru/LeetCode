//Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
//
//The overall run time complexity should be O(log(m + n)).

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);

int main()
{
	int nums1[2] = { 1, 3 }, nums1Size = 2, nums2[1] = { 2 }, nums2Size = 1;

	double result = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
	
	printf("result 1: %f", result);

	int nums1_2[2] = { 1, 2 }, nums1Size_2 = 2, nums2_2[2] = { 3, 4 }, nums2Size_2 = 2;

	result = findMedianSortedArrays(nums1_2, nums1Size_2, nums2_2, nums2Size_2);

	printf("\nresult 2: %f\n\n", result);

	system("pause");
	return 0;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	int i = nums1Size - 1, j = nums2Size - 1, k = nums1Size + nums2Size - 1;
	int* mergedNums = (int*)calloc((k + 1), sizeof(int));

	if (mergedNums == NULL)
		return -1;

	while (i >= 0 && j >= 0)
	{
		if (nums1[i] < nums2[j])
			mergedNums[k--] = nums2[j--];
		else
			mergedNums[k--] = nums1[i--];
	}

	while (j >= 0)
		mergedNums[k--] = nums2[j--];

	while (i >= 0)
		mergedNums[k--] = nums1[i--];

	k = nums1Size + nums2Size - 1;

	if (k % 2 == 0)
		return (double)mergedNums[k / 2];
	else
		return (double)(mergedNums[(k - 1) / 2] + mergedNums[(k - 1) / 2 + 1]) / 2;
}