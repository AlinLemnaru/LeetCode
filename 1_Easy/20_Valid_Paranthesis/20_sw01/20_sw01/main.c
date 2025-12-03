/********************************/
/* Author: Lemnaru Alin-Gabriel */
/* Date: 2025-04-19				*/
/********************************/

/* Exercise - Valid Parentheses
 * Write a function that checks if a string of parentheses is valid.
 * A string of parentheses is valid if:
 * 1. Every opening parenthesis has a corresponding closing parenthesis.
 * 2. Parentheses are closed in the correct order.
 *
 * Example:
 * Input: "()"
 * Output: true
 *
 * Input: "()[]{}"
 * Output: false
 *
 * Input: "())("
 * Output: false
 * 
 * Input: "(]"
 * Output: false
 * 
 * Input: "([])"
 * Output: true
*/

//************** INCLUDES **************/

// Standard Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function Prototypes */

bool isValid(char* s);

// Test Function Prototypes */
int Test_Example1(void);
int Test_Example2(void);
int Test_Example3(void);
int Test_Example4(void);
int Test_Example5(void);

int main(void)
{
	Test_Example1();
	Test_Example2();
	Test_Example3();
	Test_Example4();
	Test_Example5();

	system("pause");
	return 0;
}

//************** FUNCTION DEFINITIONS **************/

// Detailed Description:
// The function isValid checks if a string of parentheses is valid.
// It uses a stack to keep track of opening parentheses and checks if they are closed in the correct order.
// The function returns true if the string is valid and false otherwise.
// The function uses dynamic memory allocation to create a stack of characters.
// The stack is implemented using an array and a top index to keep track of the current position in the stack.
// The function iterates through the string, pushing opening parentheses onto the stack and popping them off when a closing parenthesis is encountered.
// It checks if the popped parenthesis matches the closing parenthesis.
// If the stack is empty at the end, the string is valid; otherwise, it is not.

bool isValid(char* s)
{
	const int len = strlen(s);
	char* stack;
	stack = (char*)malloc(len * sizeof(char));
	int top = -1;


	for (int i = 0; i < len; i++)
	{
		char current = s[i];

		if (current == '(' || current == '{' || current == '[')
		{
			// Dereferencing NULL pointer stack
			if (stack == NULL)
			{
				printf("Memory allocation failed\n");
				return false;
			}
			stack[++top] = current;
		}
		else
		{
			if (top == -1)
				return false;

			char last = stack[top--];

			if ((current == ')' && last != '(') ||
				(current == '}' && last != '{') ||
				(current == ']' && last != '['))
			{
				return false;
			}
		}
	}

	return top == -1;
}

//************** TEST FUNCTION DEFINITIONS **************/

int Test_Example1(void)
{
	char* test = "()";
	if (isValid(test) == true)
	{
		printf("Test 1 passed\n");
		return 0;
	}
	else
	{
		printf("Test 1 failed\n");
		return -1;
	}
}

int Test_Example2(void)
{
	char* test = "()[]{}";
	if (isValid(test) == true)
	{
		printf("Test 2 passed\n");
		return 0;
	}
	else
	{
		printf("Test 2 failed\n");
		return -1;
	}
}

int Test_Example3(void)
{
	char* test = "())(";
	if (isValid(test) == false)
	{
		printf("Test 3 passed\n");
		return 0;
	}
	else
	{
		printf("Test 3 failed\n");
		return -1;
	}
}

int Test_Example4(void)
{
	char* test = "(]";
	if (isValid(test) == false)
	{
		printf("Test 4 passed\n");
		return 0;
	}
	else
	{
		printf("Test 4 failed\n");
		return -1;
	}
}

int Test_Example5(void)
{
	char* test = "([])";
	if (isValid(test) == true)
	{
		printf("Test 5 passed\n");
		return 0;
	}
	else
	{
		printf("Test 5 failed\n");
		return -1;
	}
}