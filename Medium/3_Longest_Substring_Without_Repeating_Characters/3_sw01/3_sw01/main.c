/********************************/
/* Author: Lemnaru Alin-Gabriel */
/* Date: 2025-04-26				*/
/********************************/

/* Exercise - Longest substring without repeating characters
 * Given a string, find the length of the longest substring without repeating characters.
 * For example, given "abcabcbb", the answer is "abc", with the length of 3.
 * Given "bbbbb", the answer is "b", with the length of 1.
 * Given "pwwkew", the answer is "wke", with the length of 3.
 * Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

/* Examples
* 
* Example 1:
* 
* Input: s = "abcabcbb"
* Output: 3
* 
* Explanation: The answer is "abc", with the length of 3.
* 
* Example 2:
* 
* Input: s = "bbbbb"
* Output: 1
* 
* Explanation: The answer is "b", with the length of 1.
* 
* Example 3:
* 
* Input: s = "pwwkew"
* Output: 3
* 
* Explanation: The answer is "wke", with the length of 3.
*/

/* LIBRARIES */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* FUNCTION PROTOTYPES */ 

int lengthOfLongestSubstring(char* s);

/* TEST FUNCTION PROTOTYPES*/

int Test_Example1();
int Test_Example2();
int Test_Example3();

/* MAIN FUNCTION */

int main()
{
	/* TESTING */

	int test1 = Test_Example1();
	int test2 = Test_Example2();
	int test3 = Test_Example3();

	if (test1 && test2 && test3) {
		printf("All tests passed.\n");
	}
	else {
		printf("Some tests failed.\n");
	}

	system("pause");
	return 0;
}

/* FUNCTION DEFINITIONS */

int lengthOfLongestSubstring(char* s) {
	int n = strlen(s); // Length of the string
	int maxLength = 0; // Length of the longest substring without repeating characters
	int start = 0; // Start of the current substring
	int charIndex[256] = { 0 }; // Assuming ASCII characters

	for (int i = 0; i < n; i++) {
		if (charIndex[s[i]] > start) {
			start = charIndex[s[i]];
		}
		charIndex[s[i]] = i + 1; // Update the index of the character
		
		if (i - start + 1 > maxLength) {
			maxLength = i - start + 1; // Update the maximum length
		}
	}

	return maxLength;
}

/* TEST FUNCTION DEFINITIONS */

int Test_Example1() {
	char* s = "abcabcbb";
	int result = lengthOfLongestSubstring(s);
	if (result == 3) {
		printf("Test Example 1 passed.\n");
		return 1;
	}
	else {
		printf("Test Example 1 failed. Expected 3, got %d.\n", result);
		return 0;
	}
}

int Test_Example2() {
	char* s = "bbbbb";
	int result = lengthOfLongestSubstring(s);
	if (result == 1) {
		printf("Test Example 2 passed.\n");
		return 1;
	}
	else {
		printf("Test Example 2 failed. Expected 1, got %d.\n", result);
		return 0;
	}
}

int Test_Example3() {
	char* s = "pwwkew";
	int result = lengthOfLongestSubstring(s);
	if (result == 3) {
		printf("Test Example 3 passed.\n");
		return 1;
	}
	else {
		printf("Test Example 3 failed. Expected 3, got %d.\n", result);
		return 0;
	}
}