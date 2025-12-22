#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void print2DArray(int** arr, int returnSize, int* returnColumnSizes);
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes);

int main()
{
	int nums1[] = { 1,0,-1,0,-2,2 }, numsSize1 = 6, target1 = 0, nums2[] = { 2,2,2,2,2 }, numsSize2 = 5, target2 = 8;
	int returnSize1, * returnColumnSizes1, returnSize2, * returnColumnSizes2;
	int** result1, ** result2;

	result1 = fourSum(nums1, numsSize1, target1, &returnSize1, &returnColumnSizes1);
	printf("Test 1:\n");
	print2DArray(result1, returnSize1, returnColumnSizes1);
	printf("\n\n");

	result2 = fourSum(nums2, numsSize2, target2, &returnSize2, &returnColumnSizes2);
	printf("Test 2:\n");
	print2DArray(result2, returnSize2, returnColumnSizes2);
	printf("\n\n\n");

	for (int i = 0; i < returnSize1; i++)
		free(result1[i]);
	free(result1);
	free(returnColumnSizes1);

	for (int i = 0; i < returnSize2; i++)
		free(result2[i]);
	free(result2);
	free(returnColumnSizes2);


	system("pause");
	return 0;
}

void print2DArray(int** arr, int returnSize, int* returnColumnSizes)
{
	printf("[ ");
	for (int i = 0; i < returnSize; i++)
	{
		printf("[ ");
		for (int j = 0; j < returnColumnSizes[i]; j++)
			printf("%d ", arr[i][j]);
		printf("] ");
	}
	printf(" ]");
}

int cmp(const void* a, const void* b)
{
	return (*(int*)a) - (*(int*)b);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
	qsort(nums, numsSize, sizeof(int), cmp);

	int capacity = 16, left, right;
	int** result = malloc(capacity * sizeof(int*));

	if (result == NULL)
		return NULL;
	
	*returnSize = 0;
	(*returnColumnSizes) = malloc(capacity * sizeof(int));

	if (*returnColumnSizes == NULL)
		return NULL;

	for (int i = 0; i < numsSize - 3; i++)
	{
		// Skip duplicates
		if (i > 0 && nums[i] == nums[i - 1])
			continue;

		for (int j = i + 1; j < numsSize - 2; j++)
		{
			// Skip duplicates
			if (j > i + 1 && nums[j] == nums[j - 1])
				continue;

			left = j + 1;
			right = numsSize - 1;

			while (left < right)
			{
				long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

				if (sum == target)
				{
					if (*returnSize >= capacity)
					{
						capacity *= 2;

						int** tempResult = realloc(result, capacity * sizeof(int*));
						int* tempReturnColumnSizes = realloc(*returnColumnSizes, capacity * sizeof(int));

						if (tempResult == NULL || tempReturnColumnSizes == NULL)
						{
							for (int k = 0; k < *returnSize; k++)
								free(result[k]);
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

					result[*returnSize] = malloc(4 * sizeof(int));

					if (result[*returnSize] == NULL)
						return NULL;

					result[*returnSize][0] = nums[i];
					result[*returnSize][1] = nums[j];
					result[*returnSize][2] = nums[left];
					result[*returnSize][3] = nums[right];
					(*returnColumnSizes)[*returnSize] = 4;
					(*returnSize)++;

					// Skip duplicates
					while (left < right && nums[left] == nums[left + 1]) left++;
					while (left < right && nums[right] == nums[right - 1]) right--;

					left++;
					right--;
				}
				else if (sum < target)
					left++;
				else
					right--;
			}
		}
	}

	return result;
}