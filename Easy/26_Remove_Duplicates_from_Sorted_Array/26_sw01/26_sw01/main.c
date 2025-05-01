/********************************/
/* Author: Lemnaru Alin-Gabriel */
/* Date: 2025-04-22			 	*/
/********************************/

/* Exercise - Remove Duplicates from Sorted Array
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. 
The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k. 
*/

/* Examples
* 
* Example 1:
* 
* Input: nums = [1,1,2]
* Output: 2, nums = [1,2,_]
* 
* Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively. 
* It does not matter what you leave beyond the returned k (hence they are underscores).
* 
* Example 2:
* 
* Input: nums = [0,0,1,1,1,2,2,3,3,4]
* Output: 5, nums = [0,1,2,3,4]
* 
* Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
*/

/* LIBRARIES */

#include <stdio.h>
#include <stdlib.h>

/* FUNCTION PROTOTYPES */

// Function to remove duplicates from sorted array
int removeDuplicates(int* nums, int numsSize);

/* TEST FUNCTION PROTOTYPES */

int Test_Example1();
int Test_Example2();

/* MAIN FUNCTION */

int main()
{
	Test_Example1();

	printf("\n");
	Test_Example2();

	printf("\n");
	system("pause");
	return 0;
}

/* FUNCTION DEFINITIONS */

int removeDuplicates(int* nums, int numsSize) {
	int k = 0; // Initialize the count of unique elements

	if (numsSize == 0) return 0; // If the array is empty, return 0

	// Start from the second element and compare with the previous one
	for (int i = 1; i < numsSize; i++) {
		if (nums[i] != nums[k]) { // If the current element is different from the last unique element
			k++; // Move to the next position for unique elements
			nums[k] = nums[i]; // Update the array with the new unique element
		}
	}

	// Return the count of unique elements (k + 1 because k is index-based)
	return k + 1; // The number of unique elements is k + 1
}

int Test_Example1()
{
	int nums[] = { 1, 1, 2 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int k = removeDuplicates(nums, numsSize);
	printf("Test Example 1: k = %d\n", k);
	printf("Array after removing duplicates: ");
	for (int i = 0; i < k; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");
	return 0;
}

int Test_Example2()
{
	int nums[] = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int k = removeDuplicates(nums, numsSize);
	printf("Test Example 2: k = %d\n", k);
	printf("Array after removing duplicates: ");
	for (int i = 0; i < k; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");
	return 0;
}