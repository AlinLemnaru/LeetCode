#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* arrayToList(int* arr, int size);
void printList(struct ListNode* head);
void freeList(struct ListNode* head);
struct ListNode* reverseKGroup(struct ListNode* head, int k);

int main()
{
	int arr[] = { 1,2,3,4,5 }, size = 5, k1 = 2, k2 = 3;
	struct ListNode* head1, * head2;
	struct ListNode* result1, * result2;

	// Test 1
	printf("----------Test 1----------\n");
	head1 = arrayToList(arr, size);
	printf("\nOriginal:\n");
	printList(head1);
	result1 = reverseKGroup(head1, k1);
	printf("\n\nReversed:\n");
	printList(result1);

	// Test 2
	printf("\n\n----------Test 2----------\n");
	head2 = arrayToList(arr, size);
	printf("\nOriginal:\n");
	printList(head2);
	result2 = reverseKGroup(head2, k2);
	printf("\n\nReversed:\n");
	printList(result2);

	// Free
	freeList(result1);
	freeList(result2);

	printf("\n\n\n");

	system("pause");
	return 0;
}

struct ListNode* arrayToList(int* arr, int size)
{
	if (size <= 0)
		return NULL;

	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* current;

	if (head == NULL)
		return NULL;

	head->val = arr[0];
	head->next = NULL;

	current = head;

	for (int i = 1; i < size; i++)
	{
		struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));

		if (node == NULL)
		{
			freeList(head);
			return NULL;
		}

		node->val = arr[i];
		node->next = NULL;

		current->next = node;
		current = node;
	}

	return head;
}

void printList(struct ListNode* head)
{
	struct ListNode* current = head;

	while (current != NULL)
	{
		if (current->next != NULL)
			printf("%d -> ", current->val);
		else
			printf("%d", current->val);

		current = current->next;
	}
}

void freeList(struct ListNode* head)
{
	struct ListNode* current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) 
{
	if (head == NULL || k <= 1)
		return head;

	struct ListNode dummy;
	struct ListNode* groupPrev;
	struct ListNode* groupNext;
	struct ListNode* left;
	struct ListNode* right;
	struct ListNode* toSwap;

	dummy.next = head;
	groupPrev = &dummy;

	while (true)
	{
		left = groupPrev->next;
		right = groupPrev;

		for (int i = 0; i < k && right != NULL; i++)
			right = right->next;

		if (right == NULL)
			break;

		groupNext = right->next;
		toSwap = groupNext;

		while (left != groupNext)
		{
			struct ListNode* tmp = left->next;
			left->next = toSwap;
			toSwap = left;
			left = tmp;
		}

		struct ListNode* tmp = groupPrev->next;
		groupPrev->next = right;
		groupPrev = tmp;
	}

	return dummy.next;
}