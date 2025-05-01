/********************************/
/* Author: Lemnaru Alin-Gabriel */
/* Date: 2025-05-01				*/
/********************************/

/* Exercise - Climbing Stairs
* 
* You are climbing a staircase. It takes n steps to reach the top.
* Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
* 
*/

/* Examples
* 
* Example 1:
* 
* Input: n = 2
* Output: 2
* 
* Explanation: There are two ways to climb to the top:
* 1. 1 step + 1 step
* 2. 2 steps
* 
* Example 2:
* 
* Input: n = 3
* Output: 3
* 
* Explanation: There are three ways to climb to the top:
* 1. 1 step + 1 step + 1 step
* 2. 1 step + 2 steps
* 3. 2 steps + 1 step
* 
* Example 3:
* 
* Input: n = 4
* Output: 5
* 
* Explanation: There are five ways to climb to the top:
* 1. 1 step + 1 step + 1 step + 1 step
* 2. 1 step + 1 step + 2 steps
* 3. 1 step + 2 steps + 1 step
* 4. 2 steps + 1 step + 1 step
* 5. 2 steps + 2 steps
* 
* Example 4:
* 
* Input: n = 5
* Output: 8
* 
* Explanation: There are eight ways to climb to the top:
* 1. 1 step + 1 step + 1 step + 1 step + 1 step
* 2. 1 step + 1 step + 1 step + 2 steps
* 3. 1 step + 1 step + 2 steps + 1 step
* 4. 1 step + 2 steps + 1 step + 1 step
* 5. 2 steps + 1 step + 1 step + 1 step
* 6. 1 step + 2 steps + 2 steps
* 7. 2 steps + 1 step + 2 steps
* 8. 2 steps + 2 steps + 1 step
*/

#define _CRT_SECURE_NO_WARNINGS

/* INCLUDES */

#include <stdio.h>
#include <stdlib.h>

/* FUNCTION PROTOTYPES */

int climbStairs(int n);
int climbStairsRec(int n);

/* TEST FUNCTION PROTOTYPES */

int Test_Example1(void);
int Test_Example2(void);
int Test_Example3(void);
int Test_Example4(void);

/* MAIN */

int main(void) {
	// Test cases
	Test_Example1();
	Test_Example2();
	Test_Example3();
	Test_Example4();

	// Example usage
	int n = 5; // Number of steps
	int result = climbStairs(n);
	printf("Number of ways to climb %d steps: %d\n", n, result);

	// Example usage of the recursive function
	result = climbStairsRec(n);
	printf("Number of ways to climb %d steps (recursive): %d\n", n, result);

	system("pause");
	return 0;
}

/* FUNCTION DEFINITIONS */

//Logically, the problem can be solved using dynamic programming.
//The number of ways to reach the nth step is the sum of the number of ways to reach the (n-1)th and (n-2)th steps.
int climbStairs(int n) {
	if (n <= 2) {
		return n;
	}
	int first = 1, second = 2, result = 0;
	for (int i = 3; i <= n; i++) {
		result = first + second;
		first = second;
		second = result;
	}
	return result;
}

int climbStairsRec(int n) {
	if (n <= 2) {
		return n;
	}
	return climbStairsRec(n - 1) + climbStairsRec(n - 2);
}

/* TEST FUNCTION DEFINITIONS */ 

int Test_Example1(void) {
	int result = climbStairs(2);
	if (result == 2) {
		printf("Test_Example1 passed\n");
		return 1;
	}
	else {
		printf("Test_Example1 failed. Expected: 2, Got: %d\n", result);
		return 0;
	}
}

int Test_Example2(void) {
	int result = climbStairs(3);
	if (result == 3) {
		printf("Test_Example2 passed\n");
		return 1;
	}
	else {
		printf("Test_Example2 failed. Expected: 3, Got: %d\n", result);
		return 0;
	}
}

int Test_Example3(void) {
	int result = climbStairs(4);
	if (result == 5) {
		printf("Test_Example3 passed\n");
		return 1;
	}
	else {
		printf("Test_Example3 failed. Expected: 5, Got: %d\n", result);
		return 0;
	}
}

int Test_Example4(void) {
	int result = climbStairs(5);
	if (result == 8) {
		printf("Test_Example4 passed\n");
		return 1;
	}
	else {
		printf("Test_Example4 failed. Expected: 8, Got: %d\n", result);
		return 0;
	}
}