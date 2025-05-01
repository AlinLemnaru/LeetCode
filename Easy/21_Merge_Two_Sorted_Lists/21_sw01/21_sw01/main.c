/********************************/
/* Author: Lemnaru Alin-Gabriel */
/* Date: 2025-04-19				*/
/********************************/

/* Exercise - Merge Two Sorted Lists 
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
*/

/* Examples
* Example 1:
* 
* Input: list1 = [1,2,4], list2 = [1,3,4]
* Output: [1,1,2,3,4,4]
* 
* Example 2:
* 
* Input: list1 = [], list2 = []
* Output: []
* 
* Example 3:
* 
* Input: list1 = [], list2 = [0]
* Output: [0]
*/

// Constraints
// The number of nodes in both lists is in the range [0, 50].
// -100 <= Node.val <= 100
// Both list1 and list2 are sorted in non-decreasing order.

#define _CRT_SECURE_NO_WARNINGS

// INCLUDES

#include <stdio.h>
#include <stdlib.h>
#include "ListNode.h"

// FUNCTION PROTOTYPES

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2);

// TEST FUNCTION PROTOTYPES

int Test_Example1();
int Test_Example2();
int Test_Example3();

// MAIN FUNCTION

int main()
{
	// TESTING

	printf("Test 1: \n");
	Test_Example1();

	printf("Test 2: \n");
	Test_Example2();

	printf("Test 3: \n");
	Test_Example3();

	system("pause");
	return 0;
}

// FUNCTION DEFINITIONS

// mergeTwoLists - merges two sorted linked lists into one sorted linked list
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
	struct ListNode* mergedList = NULL;
	struct ListNode* current = NULL;
	
	
	while (list1 != NULL || list2 != NULL)
	{
		struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));

		if (newNode == NULL)
		{
			printf("Memory allocation failed\n");
			return mergedList;
		}

		if (list1 == NULL)
		{
			newNode->val = list2->val;
			list2 = list2->next;
		}
		else if (list2 == NULL)
		{
			newNode->val = list1->val;
			list1 = list1->next;
		}
		else  // both lists are not empty
		{
			if (list1->val <= list2->val)
			{
				newNode->val = list1->val;
				list1 = list1->next;
			}
			else
			{
				newNode->val = list2->val;
				list2 = list2->next;
			}
		}

		newNode->next = NULL;

		if (mergedList == NULL)
		{
			mergedList = newNode;
			current = mergedList;
		}
		else
		{
			current->next = newNode;
			current = current->next;
		}
	}

	return mergedList;
}

// TEST FUNCTION DEFINITIONS

int Test_Example1()
{
	struct ListNode* list1 = NULL;
	struct ListNode* list2 = NULL;

	list1 = addNode(list1, 1);
	list1 = addNode(list1, 2);
	list1 = addNode(list1, 4);

	list2 = addNode(list2, 1);
	list2 = addNode(list2, 3);
	list2 = addNode(list2, 4);

	struct ListNode* mergedList = mergeTwoLists(list1, list2);

	printList(mergedList);

	return 0;
}

int Test_Example2()
{
	struct ListNode* list1 = NULL;
	struct ListNode* list2 = NULL;

	struct ListNode* mergedList = mergeTwoLists(list1, list2);

	printList(mergedList);

	return 0;
}

int Test_Example3()
{
	struct ListNode* list1 = NULL;
	struct ListNode* list2 = NULL;

	list2 = addNode(list2, 0);

	struct ListNode* mergedList = mergeTwoLists(list1, list2);

	printList(mergedList);

	return 0;
}