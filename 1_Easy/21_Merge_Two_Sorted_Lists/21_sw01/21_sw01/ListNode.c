#include <stdio.h>
#include <stdlib.h>
#include "ListNode.h"

// FUNCTION DEFINITIONS

// addNode - adds a new node to the end of the list. The adding of the new node is done in a sorted manner.
struct ListNode* addNodeSort(struct ListNode* head, int val)
{
	struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));

	if (newNode == NULL)
	{
		printf("Memory allocation failed\n");
		return head;
	}

	newNode->val = val;
	newNode->next = NULL;

	if (head == NULL)
	{
		return newNode;
	}

	struct ListNode* current = head;
	while (current->next != NULL && current->next->val < val)
	{
		current = current->next;
	}

	newNode->next = current->next;
	current->next = newNode;

	return head;
}

// addNode - adds a new node to the end of the list
struct ListNode* addNode(struct ListNode* head, int val)
{
	struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));

	if (newNode == NULL)
	{
		printf("Memory allocation failed\n");
		return head;
	}

	newNode->val = val;
	newNode->next = NULL;

	if (head == NULL)
	{
		return newNode;
	}

	struct ListNode* current = head;
	while (current->next != NULL)
	{
		current = current->next;
	}

	current->next = newNode;

	return head;
}

// printList - prints the list
void printList(struct ListNode* head)
{
	struct ListNode* current = head;

	while (current != NULL)
	{
		printf("%d -> ", current->val);
		current = current->next;
	}
	printf("NULL\n");
}

// freeList - frees the memory allocated for the list
void freeList(struct ListNode* head)
{
	struct ListNode* current = head;
	struct ListNode* temp;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}