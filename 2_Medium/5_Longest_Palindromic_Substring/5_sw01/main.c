#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CheckPalindrome(char* s, int i, int j);
char* longestPalindrome(char* s);

int main()
{
	char s1[] = "babad", s2[] = "cbbd";
	char* result;

	result = longestPalindrome(s1);
	printf("TEST 1: %s", result);

	result = longestPalindrome(s2);
	printf("\nTEST 2: %s\n\n", result);

	system("pause");
	return 0;
}

//int CheckPalindrome(char* s, int i, int j)
//{
//	while (i < j)
//	{
//		if (s[i] != s[j])
//			return 0;
//
//		i++;
//		j--;
//	}
//
//	return 1;
//}
//
//char* longestPalindrome(char* s) 
//{
//	int len = strlen(s);
//	int start = 0, maxLen = 1, i, j;
//
//	for (i = 0; i < len; i++) 
//		for (j = i; j < len; j++)
//			if (CheckPalindrome(s, i, j) && (j - i + 1) > maxLen)
//			{
//				start = i;
//				maxLen = j - i + 1;
//			}
//
//	char* result = (char*)malloc(len + 1);
//
//	if (result == NULL)
//		return NULL;
//
//	strcpy(result, s);
//
//	result += start;
//	result[maxLen] = '\0';
//
//	return result;
//}

char* longestPalindrome(char* s) {
    int len = strlen(s);
    if (len == 0) return "";

    int start = 0, maxLen = 1;

    for (int i = 0; i < len; i++) {
        int l = i, r = i;
        while (l >= 0 && r < len && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                start = l;
                maxLen = r - l + 1;
            }
            l--; r++;
        }

        l = i; r = i + 1;
        while (l >= 0 && r < len && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                start = l;
                maxLen = r - l + 1;
            }
            l--; r++;
        }
    }

    char* result = (char*)malloc(maxLen + 1);

    if (result == NULL)
        return "";

    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';
    return result;
}