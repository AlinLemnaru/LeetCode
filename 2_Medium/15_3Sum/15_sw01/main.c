#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void print2DArray(int** array, int returnSize, int* returnColumnSizes);
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);

int main()
{
	int nums1[] = { -1,0,1,2,-1,-4 }, nums2[] = { 0,1,1 }, nums3[] = { 0,0,0 };
	int numsSize1 = 6, numsSize2 = 3, numsSize3 = 3;
	int returnSize, * returnColumnSizes, ** result;

	printf("Test 1:\n");
	result = threeSum(nums1, numsSize1, &returnSize, &returnColumnSizes);
	print2DArray(result, returnSize, returnColumnSizes);

	printf("\n\n");

	printf("Test 2:\n");
	result = threeSum(nums2, numsSize2, &returnSize, &returnColumnSizes);
	print2DArray(result, returnSize, returnColumnSizes);

	printf("\n\n");

	printf("Test 3:\n");
	result = threeSum(nums3, numsSize3, &returnSize, &returnColumnSizes);
	print2DArray(result, returnSize, returnColumnSizes);

	printf("\n\n\n");

	for (int i = 0; i < returnSize; i++)
		free(result[i]);
	free(result);
	free(returnColumnSizes);

	system("pause");
	return 0;
}

void print2DArray(int** array, int returnSize, int* returnColumnSizes)
{
	printf("[ ");
	for (int i = 0; i < returnSize; i++) 
	{
		printf("[");
		for (int j = 0; j < returnColumnSizes[i]; j++)
			printf("%d ", array[i][j]);
		printf("] ");
	}
	printf("]");
}

int cmp(const void* a, const void* b) {
	return (*(int*)a) - (*(int*)b);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	if (numsSize < 3) {
		*returnSize = 0;
		*returnColumnSizes = NULL;
		return NULL;
	}

	qsort(nums, numsSize, sizeof(int), cmp);

	int left, right, sum = 0;
	int capacity = numsSize / 3; // initial capacity
	int** result = malloc(capacity * sizeof(int*));

	if (result == NULL)
		return NULL;

	*returnSize = 0;

	*returnColumnSizes = malloc(capacity * sizeof(int));

	if (*returnColumnSizes == NULL)
		return NULL;

	for (int i = 0; i < numsSize - 2; i++)
	{
		// Skip duplicates
		if (i > 0 && nums[i] == nums[i - 1])
			continue;

		left = i + 1;
		right = numsSize - 1;

		while (left < right)
		{
			sum = nums[i] + nums[left] + nums[right];
			if (sum == 0)
			{
				if (*returnSize >= capacity)
				{
					capacity *= 2;
					
					int** tempResult = realloc(result, capacity * sizeof(int*));
					int* tempReturnColumnSizes = realloc(*returnColumnSizes, capacity * sizeof(int));

					if (tempResult == NULL || tempReturnColumnSizes == NULL)
					{
						for (int k = 0; k < *returnSize; k++) free(result[k]);
						free(result);
						free(*returnColumnSizes);
						*returnSize = 0;
						*returnColumnSizes = NULL;
						return NULL;
					}
					else
					{
						result = tempResult;
						*returnColumnSizes = tempReturnColumnSizes;
					}
				}

				result[*returnSize] = malloc(3 * sizeof(int));

				if (result[*returnSize] == NULL)
					return NULL;

				result[*returnSize][0] = nums[i];
				result[*returnSize][1] = nums[left];
				result[*returnSize][2] = nums[right];
				(*returnColumnSizes)[*returnSize] = 3;
				(*returnSize)++;

				// Skip duplicates
				while (left < right && nums[left] == nums[left + 1]) left++;
				while (left < right && nums[right] == nums[right - 1]) right--;

				left++;
				right--;
			}
			else if (sum < 0)
				left++;
			else
				right--;
		}
	}

	return result;
}