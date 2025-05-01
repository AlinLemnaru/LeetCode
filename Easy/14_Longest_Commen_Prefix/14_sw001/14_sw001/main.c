/********************************/
/* Author: Lemnaru Alin-Gabriel */
/* Date: 19-04-2025             */
/********************************/

/* Exercise - Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
*/

/* Examples
Example 1:

	Input: strs = ["flower","flow","flight"]
	Output: "fl"

Example 2:

	Input: strs = ["dog","racecar","car"]
	Output: ""

	Explanation: There is no common prefix among the input strings.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize);
int Test_Example1();
int Test_Example2();

int main()
{
	printf("##########T1##########\n");
	if (Test_Example1())
		printf("\nTest 1: PASSED\n");
	else
		printf("\nTest 1: FAILED\n");
	printf("\n######################\n");

	printf("\n##########T2##########\n");
	if (Test_Example2())
		printf("\nTest 2: PASSED\n");
	else
		printf("\nTest 2: FAILED\n");
	printf("\n######################\n\n");

	system("pause");
	return 0;
}

char* longestCommonPrefix(char** strs, int strsSize) {
	char* prefix;

	prefix = (char*)malloc((strlen(*strs) + 1) * sizeof(char));
	if (prefix == NULL)
	{
		printf("\nMemory allocation ERROR!\n");
		exit(EXIT_FAILURE);
	}

	strcpy(prefix, *strs);

	for (int i = 0; i < strsSize; i++)
	{
		char* p1 = prefix;
		char* p2 = *(strs + i);

		while (*p1 == *p2 && *p1 && *p2)
		{
			p1++;
			p2++;
		}

		*p1 = '\0';

		if (*prefix == '\0')
			break;
	}

	return prefix;
}

int Test_Example1()
{
	int result = 1;

	//Input: strs = ["flower", "flow", "flight"]
	//Output : "fl"

	char* strs[7] = {"flower\0", "flow\0",  "flight\0"};
	char expected[3] = "fl\0";

	if (strcmp(expected, longestCommonPrefix(strs, 3)) != 0)
		result = 0;

	return result;
}

int Test_Example2()
{
	int result = 1;

	//Input: strs = ["dog","racecar","car"]
	//Output : ""

	char* strs[7] = { "dog\0", "racecar\0",  "car\0" };
	char expected[3] = "";

	if (strcmp(expected, longestCommonPrefix(strs, 3)) != 0)
		result = 0;

	return result;
}