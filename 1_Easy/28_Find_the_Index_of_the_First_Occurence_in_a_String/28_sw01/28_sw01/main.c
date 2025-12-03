/********************************/
/* Author: Lemnaru Alin-Gabriel */
/* Date: 2025-04-22			 	*/
/********************************/

/* Exercise - Find the Index of the First Occurrence in a String
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

/* Examples
* Example 1:
* 
* Input: haystack = "sadbutsad", needle = "sad"
* Output: 0
* 
* Explanation: "sad" occurs at index 0 and 6.
* The first occurrence is at index 0, so we return 0.
* 
* Example 2:
* 
* Input: haystack = "leetcode", needle = "leeto"
* Output: -1
* 
* Explanation: "leeto" did not occur in "leetcode", so we return -1.
*/

/* LIBRARIES */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* FUNCTION PROTOTYPES */

// Function to find the index of the first occurrence of needle in haystack
int strStr(char* haystack, char* needle);

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

int strStr(char* haystack, char* needle) {
	int index = -1; // Initialize index to -1 (not found)

	// Check if needle is an empty string
	if (haystack == NULL || needle == NULL || *needle == '\0')
	{
		return 0; // If needle is empty, return 0
	}

	// Get the lengths of haystack and needle
	int haystackLength = strlen(haystack);
	int needleLength = strlen(needle);

	// Iterate through haystack
	for (int i = 0; i <= haystackLength - needleLength; i++)
	{
		// Check if the substring of haystack starting at index i matches needle
		if (strncmp(haystack + i, needle, needleLength) == 0)
		{
			index = i; // Update index to the current position
			break; // Exit the loop as we found the first occurrence
		}
	}

	return index;
}

/* TEST FUNCTION DEFINITIONS */

int Test_Example1()
{
	int result = 1;
	int expected = 0;

	char* haystack = "sadbutsad";
	char* needle = "sad";

	int index = strStr(haystack, needle);
	printf("Test Example 1: index = %d\n", index);

	if (index == expected) 
	{
		printf("Test passed!\n");
	}
	else 
	{
		printf("Test failed! Expected %d, got %d\n", expected, index);
		result = 0;
	}

	return result;
}

int Test_Example2()
{
	int result = 1;
	int expected = -1;

	char* haystack = "leetcode";
	char* needle = "leeto";

	int index = strStr(haystack, needle);
	printf("Test Example 2: index = %d\n", index);

	if (index == expected)
	{
		printf("Test passed!\n");
	}
	else
	{
		printf("Test failed! Expected %d, got %d\n", expected, index);
		result = 0;
	}

	return result;
}