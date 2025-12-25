#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isAlpha(char c);
char toLower(char c);
bool isPalindrome(char* s);

int main()
{
	char s1[] = "A man, a plan, a canal: Panama";
	char s2[] = "race a car";
	char s3[] = " ";

	// Test 1
	if (isPalindrome(s1) == true)
		printf("Test 1: PASSED");
	else
		printf("Test 1: FAILED");

	// Test 2
	if (isPalindrome(s2) == false)
		printf("\nTest 2: PASSED");
	else
		printf("\nTest 2: FAILED");

	// Test 3
	if (isPalindrome(s3) == true)
		printf("\nTest 3: PASSED\n\n");
	else
		printf("\nTest 3: FAILED\n\n");

	system("pause");
	return 0;
}

bool isAlpha(char c)
{
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

char toLower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + ('a' - 'A');

	return c;
}

bool isPalindrome(char* s) 
{
	int left = 0, right = strlen(s) - 1;

	while (left < right)
	{
		// Skip non alphanumerical char
		while (left < right && !isAlpha(s[left]))
			left++;

		while (left < right && !isAlpha(s[right]))
			right--;

		if (toLower(s[left]) != toLower(s[right]))
			return false;

		left++;
		right--;
	}

	return true;
}