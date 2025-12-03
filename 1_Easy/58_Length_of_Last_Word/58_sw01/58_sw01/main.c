/********************************/
/* Author: Lemnaru Alin-Gabriel */
/* Date: 2025-04-26				*/
/********************************/

/* Exercise - Length of Last Word
 * Write a function that takes a string as input and returns the length of the last word in the string.
 * A word is defined as a sequence of non-space characters. The function should ignore any trailing spaces in the input string.
 * For example, given the input "Hello World  ", the function should return 5, as "World" is the last word with length 5.
 */

/* Examples
* 
* Example 1:
* 
* Input: "Hello World"
* Output: 5
* 
* Example 2:
* 
* Input: "   fly me   to   the moon  "
* Output: 4
* 
* Example 3:
* 
* Input: "luffy is still joyboy"
* Output: 6
*/

/* LIBRARIES */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* FUNCTION PROTOTYPES */

int lengthOfLastWord(char* s);

/* TEST FUNCTION PROTOTYPES */

int Test_Example1(void);
int Test_Example2(void);
int Test_Example3(void);

/* MAIN */

int main(void)
{
	/* TESTING */
	int result = 0;
	result += Test_Example1();
	result += Test_Example2();
	result += Test_Example3();

	if (result == 0)
	{
		printf("All tests passed.\n");
	}
	else
	{
		printf("%d tests failed.\n", result);
	}

	system("pause");
	return 0;
}

/* FUNCTION DEFINITIONS */

int lengthOfLastWord(char* s)
{
	int length = 0;
	int i = strlen(s) - 1;

	// Skip trailing spaces
	while (i >= 0 && s[i] == ' ')
	{
		i--;
	}

	// Count the length of the last word
	while (i >= 0 && s[i] != ' ')
	{
		length++;
		i--;
	}

	return length;
}

/* TEST FUNCTION DEFINITIONS */

int Test_Example1(void)
{
	char str[] = "Hello World";
	int result = lengthOfLastWord(str);
	if (result == 5)
	{
		printf("Test Example 1 passed.\n");
		return 0;
	}
	else
	{
		printf("Test Example 1 failed. Expected 5, got %d\n", result);
		return 1;
	}
}

int Test_Example2(void)
{
	char str[] = "   fly me   to   the moon  ";
	int result = lengthOfLastWord(str);
	if (result == 4)
	{
		printf("Test Example 2 passed.\n");
		return 0;
	}
	else
	{
		printf("Test Example 2 failed. Expected 4, got %d\n", result);
		return 1;
	}
}

int Test_Example3(void)
{
	char str[] = "luffy is still joyboy";
	int result = lengthOfLastWord(str);
	if (result == 6)
	{
		printf("Test Example 3 passed.\n");
		return 0;
	}
	else
	{
		printf("Test Example 3 failed. Expected 6, got %d\n", result);
		return 1;
	}
}