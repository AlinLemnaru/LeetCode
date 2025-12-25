#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int val;
	struct Node* next;
	struct Node* random;
};

struct Node* arrayToList(int* arr, int size);
void addRandomPointers(struct Node* head, int* arr, int size);
void printListWithRandom(struct Node* head);
void freeList(struct Node* head);
struct Node* copyRandomList(struct Node* head);

int main()
{
	int arr1[] = { 7,13,11,10,1 }, sizeArr1 = 5;
	int arr2[] = { 1,2 }, sizeArr2 = 2;
	int arr3[] = { 3,3,3 }, sizeArr3 = 3;
	int arrRandom1[] = { -1,0,4,2,0 };
	int arrRandom2[] = { 1,1 };
	int arrRandom3[] = { -1,0,-1 };
	struct Node* head1, *headResult1;
	struct Node* head2, *headResult2;
	struct Node* head3, *headResult3;

	// Test 1
	printf("---------- T1 ----------\n");
	head1 = arrayToList(arr1, sizeArr1);
	addRandomPointers(head1, arrRandom1, sizeArr1);
	printf("Original 1:\n");
	printListWithRandom(head1);
	headResult1 = copyRandomList(head1);
	printf("\n\nCopy 1:\n");
	printListWithRandom(headResult1);

	// Test 2
	printf("\n\n---------- T2 ----------\n");
	head2 = arrayToList(arr2, sizeArr2);
	addRandomPointers(head2, arrRandom2, sizeArr2);
	printf("Original 2:\n");
	printListWithRandom(head2);
	headResult2 = copyRandomList(head2);
	printf("\n\nCopy 2:\n");
	printListWithRandom(headResult2);

	// Test 3
	printf("\n\n---------- T3 ----------\n");
	head3 = arrayToList(arr3, sizeArr3);
	addRandomPointers(head3, arrRandom3, sizeArr3);
	printf("Original 3:\n");
	printListWithRandom(head3);
	headResult3 = copyRandomList(head3);
	printf("\n\nCopy 3:\n");
	printListWithRandom(headResult3);

	// Free
	freeList(head1);
	freeList(head2);
	freeList(head3);

	freeList(headResult1);
	freeList(headResult2);
	freeList(headResult3);

	printf("\n\n\n");

	system("pause");
	return 0;
}

struct Node* arrayToList(int* arr, int size)
{
	if (size == 0)
		return NULL;

	struct Node* head = (struct Node*)malloc(sizeof(struct Node));
	struct Node* current;
	
	if (head == NULL)
		return NULL;


	head->val = arr[0];
	head->next = NULL;

	current = head;

	for (int i = 1; i < size; i++)
	{
		struct Node* node = (struct Node*)malloc(sizeof(struct Node));

		if (node == NULL)
			return head;	

		node->val = arr[i];
		node->next = NULL;
		current->next = node;
		current = node;
	}

	return head;
}

void addRandomPointers(struct Node* head, int* arr, int size)
{
	struct Node* current = head;

	for (int i = 0; i < size && current != NULL; i++)
	{
		if (arr[i] < 0)
		{
			current->random = NULL;
		}
		else
		{
			struct Node* aux = head;
			int steps = 0;
			while (steps < arr[i] && aux != NULL)
			{
				aux = aux->next;
				steps++;
			}
			current->random = aux; // can be NULL safely
		}

		current = current->next;
	}
}




void printListWithRandom(struct Node* head)
{
	struct Node* current = head;

	while (current != NULL)
	{
		printf("%d", current->val);

		if (current->random != NULL)
			printf(" -> %d", current->random->val);
		else
			printf(" -> NULL");

		printf("\n");

		if (current->next == NULL)
			printf("|\nNULL");
		else
			printf("|\n");

		current = current->next;
	}
}

void freeList(struct Node* head)
{
	struct Node* current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */
struct Node* copyRandomList(struct Node* head) {
	if (head == NULL)
		return NULL;

	struct Node* current = head;
	struct Node* dummy = (struct Node*)malloc(sizeof(struct Node));

	if (dummy == NULL)
		return NULL;

	struct Node* copyCurrent = dummy;
	struct Node* copyHead;

	// Interweave Lists
	while (current != NULL)
	{
		struct Node* copy = (struct Node*)malloc(sizeof(struct Node));

		if (copy == NULL)
			return NULL;

		copy->val = current->val;
		copy->next = current->next;
		current->next = copy;
		current = copy->next;
	}

	current = head;

	// Assign Random
	while (current != NULL)
	{
		if (current->random != NULL)
			current->next->random = current->random->next;
		else
			current->next->random = NULL;

		current = current->next->next;
	}

	current = head;

	// Separate Lists
	while (current != NULL)
	{
		copyCurrent->next = current->next;
		copyCurrent = copyCurrent->next;

		current->next = current->next->next;
		current = current->next;
	}

	copyHead = dummy->next;

	free(dummy);

	return copyHead;
}