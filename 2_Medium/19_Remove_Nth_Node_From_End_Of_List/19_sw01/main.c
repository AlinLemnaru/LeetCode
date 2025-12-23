#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

void addNode(struct ListNode** head, int val);
void printList(struct ListNode* head);
void freeList(struct ListNode* head);
struct ListNode* removeNthFromEnd(struct ListNode* head, int n);

int main()
{
	struct ListNode* head1 = NULL, * head2 = NULL, * head3 = NULL;
	int n1 = 2, n2 = 1, n3 = 1;

	// Create 1st List
	addNode(&head1, 1);
	addNode(&head1, 2);
	addNode(&head1, 3);
	addNode(&head1, 4);
	addNode(&head1, 5);

	// Create 2nd List
	addNode(&head2, 1);

	// Create 3rd List
	addNode(&head3, 1);
	addNode(&head3, 2);

	// Print Lists
	printf("List 1:\n");
	printList(head1);
	printf("\n\nList 2:\n");
	printList(head2);
	printf("\n\nList 3:\n");
	printList(head3);

	// Test
	printf("\n\nTest 1:\n");
	head1 = removeNthFromEnd(head1, n1);
	printList(head1);
	printf("\n\nTest 2:\n");
	head2 = removeNthFromEnd(head2, n2);
	printList(head2);
	printf("\n\nTest 3:\n");
	head3 = removeNthFromEnd(head3, n3);
	printList(head3);

	// Free
	freeList(head1);
	freeList(head2);
	freeList(head3);

	printf("\n\n");
	system("pause");
	return 0;
}

void addNode(struct ListNode** head, int val)
{
	struct ListNode* node = malloc(sizeof(struct ListNode));
	struct ListNode* aux;

	if (node == NULL)
		return;

	node->val = val;
	node->next = NULL;

	if (*head == NULL)
		*head = node;
	else
	{
		aux = *head;
		
		while (aux->next != NULL)
			aux = aux->next;

		aux->next = node;
	}
}

void printList(struct ListNode* head)
{
	struct ListNode* aux = head;

	while (aux != NULL)
	{
		if (aux->next != NULL)
			printf("%d -> ", aux->val);
		else
			printf("%d", aux->val);

		aux = aux->next;
	}
}

void freeList(struct ListNode* head)
{
	struct ListNode* aux;

	while (head != NULL)
	{
		aux = head;          
		head = head->next;   
		free(aux);           
	}
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	struct ListNode dummy;
	struct ListNode* fast = &dummy;
	struct ListNode* slow = &dummy;
	struct ListNode* aux;

	dummy.next = head;

	for (int i = 0; i < n; i++)
	{
		if (fast->next == NULL)
			return head;

		fast = fast->next;
	}

	while (fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next;
	}

	aux = slow->next;

	if (slow->next == NULL)
		return head;

	slow->next = slow->next->next;

	free(aux);

	return dummy.next;
}