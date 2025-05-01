/********************************/
/* Author: Lemnaru Alin-Gabriel */
/* Date: 2025-04-26				*/
/********************************/

/* Exercise - Add Two Numbers
*You are given two non-empty linked lists representing two non-negative integers. 
*The digits are stored in reverse order, and each of their nodes contains a single digit. 
*Add the two numbers and return the sum as a linked list.
*
*You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

/* Examples
* Example 1:
* 
* Input: l1 = [2,4,3], l2 = [5,6,4]
* Output: [7,0,8]
* 
* Explanation: 342 + 465 = 807.
* 
* Example 2:
* 
* Input: l1 = [0], l2 = [0]
* Output: [0]
* 
* Example 3:
* 
* Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9]
* Output: [8,9,9,9,0,0,0,1]
* 
* Explanation: 9999999 + 999 = 10009998.
*/

/* LIBRARIES */

#include <stdio.h>
#include <stdlib.h>
#include "ListNode.h"

/* FUNCTION PROTOTYPES */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

/* TEST FUNCTION PROTOTYPES */

int Test_Example1();
int Test_Example2();
int Test_Example3();

/* MAIN FUNCTION */ 

int main() {
	// Test cases
	printf("Test Example 1: %s\n", Test_Example1() ? "Passed" : "Failed");
	printf("Test Example 2: %s\n", Test_Example2() ? "Passed" : "Failed");
	printf("Test Example 3: %s\n", Test_Example3() ? "Passed" : "Failed");

	system("pause");
	return 0;
}

/* FUNCTION DEFINITIONS */

//struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
//	struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* current = dummyHead;
//	int carry = 0;
//
//	while (l1 != NULL || l2 != NULL || carry != 0) {
//		int sum = carry;
//		if (l1 != NULL) {
//			sum += l1->val;
//			l1 = l1->next;
//		}
//		if (l2 != NULL) {
//			sum += l2->val;
//			l2 = l2->next;
//		}
//		carry = sum / 10;
//		current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//		current->next->val = sum % 10;
//		current->next->next = NULL;
//		current = current->next;
//	}
//
//	struct ListNode* result = dummyHead->next;
//	free(dummyHead);
//	return result;
//}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	int sum = 0, carry = 0;

	//Creating a new list to return
	struct ListNode* result = NULL;

	//While at least one number still has digits
	while (l1 || l2)
	{
		//l1 still has digits => add
		if (l1)
		{
			sum += l1->val;
			l1 = l1->next;
		}

		//l2 still has digits => add
		if (l2)
		{
			sum += l2->val;
			l2 = l2->next;
		}

		//Adding the carry to the sum
		sum += carry;

		//Adding the sum of the digits to the result and carry if it is the case
		result = addToListBack(result, sum % 10);
		carry = sum / 10;

		//making sum = 0 again
		sum = 0;
	}

	//If there is still a carry, add it to the result
	if (carry)
		result = addToListBack(result, carry);

	return result;
}

/* TEST FUNCTION DEFINITIONS */

int Test_Example1() {
	struct ListNode* l1 = NULL;
	struct ListNode* l2 = NULL;

	l1 = addToList(l1, 3);
	l1 = addToList(l1, 4);
	l1 = addToList(l1, 2);

	l2 = addToList(l2, 4);
	l2 = addToList(l2, 6);
	l2 = addToList(l2, 5);

	struct ListNode* result = addTwoNumbers(l1, l2);
	printList(result); // For debugging
	int expected[] = { 7, 0, 8 };
	int size = sizeof(expected) / sizeof(expected[0]);

	for (int i = 0; i < size; i++) {
		if (result == NULL || result->val != expected[i]) {
			return 0; // Failed
		}
		result = result->next;
	}

	return result == NULL; // Passed if result is NULL
}

int Test_Example2() {
	struct ListNode* l1 = NULL;
	struct ListNode* l2 = NULL;

	l1 = addToList(l1, 0);
	l2 = addToList(l2, 0);

	struct ListNode* result = addTwoNumbers(l1, l2);
	printList(result); // For debugging
	int expected[] = { 0 };
	int size = sizeof(expected) / sizeof(expected[0]);

	for (int i = 0; i < size; i++) {
		if (result == NULL || result->val != expected[i]) {
			return 0; // Failed
		}
		result = result->next;
	}

	return result == NULL; // Passed if result is NULL
}

int Test_Example3() {
	struct ListNode* l1 = NULL;
	struct ListNode* l2 = NULL;

	l1 = addToList(l1, 9);
	l1 = addToList(l1, 9);
	l1 = addToList(l1, 9);
	l1 = addToList(l1, 9);
	l1 = addToList(l1, 9);
	l1 = addToList(l1, 9);
	l1 = addToList(l1, 9);
	l2 = addToList(l2, 9);
	l2 = addToList(l2, 9);
	l2 = addToList(l2, 9);
	l2 = addToList(l2, 9);

	struct ListNode* result = addTwoNumbers(l1, l2);
	// Expected output: 8 -> 9 -> 9 -> 9 -> 0 -> 0 -> 0 -> 1
	printList(result); // For debugging
	int expected[] = { 8, 9, 9, 9, 0, 0, 0, 1 };
	int size = sizeof(expected) / sizeof(expected[0]);
	for (int i = 0; i < size; i++) {
		if (result == NULL || result->val != expected[i]) {
			return 0; // Failed
		}
		result = result->next;
	}
	return result == NULL; // Passed if result is NULL
}