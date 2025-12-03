/********************************/
/* Author: Lemnaru Alin-Gabriel */
/* Date: 2025-04-22			 	*/
/********************************/

/* Exercise - Remove Element
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. 
The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. 
The remaining elements of nums are not important as well as the size of nums.
Return k.
*/

/* Examples
*
* Example 1:
*
* Input: nums = [3,2,2,3], val = 3
* Output: 2, nums = [2,2,_,_]
*
* Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
* It does not matter what you leave beyond the returned k (hence they are underscores).
* Note that the five elements can be returned in any order.
* 
* Example 2:
*
* Input: nums = [0,1,2,2,3,0,4,2], val = 2
* Output: 5, nums = [0,1,4,0,3,_,_,_]
*
* Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
*/

/* LIBRARIES */

#include <stdio.h>
#include <stdlib.h>

/* FUNCTION PROTOTYPES */

// Function to remove duplicates from sorted array
int removeElement(int* nums, int numsSize, int val);

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

int removeElement(int* nums, int numsSize, int val) {
	int aux; // Auxiliary variable to store the value of the current element
	if (numsSize == 0) return 0; // If the array is empty, return 0

	// Start from the second element and compare with the previous one
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] == val) { // If the current element is different from the value to remove
			aux = nums[i]; // Store the current element in aux
			nums[i] = nums[numsSize - 1]; // Update the array
			nums[numsSize - 1] = aux; // Swap the elements
			i--; // Decrement i to check the new value at this index
			numsSize--; // Decrease the size of the array
		}
	}

	// Return the count of unique elements (k + 1 because k is index-based)
	return numsSize;
}

int Test_Example1()
{
	int nums[] = { 3, 2, 2, 3 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int k = removeElement(nums, numsSize, 3);
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
	int nums[] = { 0, 1, 2, 2, 3, 0, 4, 2 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int k = removeElement(nums, numsSize, 2);
	printf("Test Example 2: k = %d\n", k);
	printf("Array after removing duplicates: ");
	for (int i = 0; i < k; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");
	return 0;
}