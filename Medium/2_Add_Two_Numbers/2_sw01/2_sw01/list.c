#include <stdio.h>
#include <stdlib.h>
#include "ListNode.h"

struct ListNode* addToList(struct ListNode* head, int val) {
	struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	if (!newNode) {
		printf("Memory allocation failed\n");
		return NULL; // Memory allocation failed
	}
	newNode->val = val;
	newNode->next = head;
	return newNode;
}

struct ListNode* addToListBack(struct ListNode* head, int val) {
	struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	if (!newNode) {
		printf("Memory allocation failed\n");
		return NULL; // Memory allocation failed
	}
	newNode->val = val;
	newNode->next = NULL;

	if (head == NULL) {
		return newNode; // If the list is empty, return the new node as the head
	}

	struct ListNode* current = head;
	while (current->next != NULL) {
		current = current->next; // Traverse to the end of the list
	}
	current->next = newNode; // Link the new node at the end
	return head;
}

void printList(struct ListNode* head) {
	struct ListNode* current = head;
	while (current != NULL) {
		printf("%d -> ", current->val);
		current = current->next;
	}
	printf("NULL\n");
}