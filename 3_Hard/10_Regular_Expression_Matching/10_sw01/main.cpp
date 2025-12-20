#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isMatch(char* s, char* p);

int main()
{
	char s1[] = "aa", p1[] = "a", s2[] = "aa", p2[] = "a*", s3[] = "ab", p3[] = ".*";

	if (isMatch(s1, p1) == false)
		printf("Test 1: PASSED");
	else
		printf("Test 1: FAILED");

	if (isMatch(s2, p2) == true)
		printf("\nTest 2: PASSED");
	else
		printf("\nTest 2: FAILED");

	if (isMatch(s3, p3) == true)
		printf("\nTest 3: PASSED\n\n");
	else
		printf("\nTest 3: FAILED\n\n");

	system("pause");
	return 0;
}

bool isMatch(char* s, char* p) {
	if (*p == '\0')
		return *s == '\0';


	bool first_match = (*s != '\0' && (*s == *p || *p == '.'));

	if (*(p + 1) == '*')
		return isMatch(s, p + 2) || (first_match && isMatch(s + 1, p));
	else
		return first_match && isMatch(s + 1, p + 1);
}