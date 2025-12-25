#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* arrayToList(int* arr, int size);
void printList(struct ListNode* head);
void printListArray(struct ListNode** lists, int listsSize);
void freeList(struct ListNode* head);
//void freeListArray(struct ListNode** lists, int listsSize);
struct ListNode* merge2Lists(struct ListNode* head1, struct ListNode* head2);
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize);

int main()
{
	int arr1[][3] = { {1,4,5}, {1,3,4}, {2,6} }, arr2[][1] = { {0} };
	int sizeCol1[] = { 3,3,2 }, sizeCol2[] = { 0 };
	struct ListNode** lists1, ** lists2, ** lists3;
	struct ListNode* list1, * list2, * list3;
	int listsSize1 = 3, listsSize2 = 1, listsSize3 = 0;

	// case 1
	printf("Test 1:\n");

	printf("Array of Lists:\n");
	lists1 = malloc(listsSize1 * sizeof(struct ListNode*));

	if (lists1 == NULL)
		return NULL;

	for (int i = 0; i < listsSize1; i++)
	{
		lists1[i] = arrayToList(arr1[i], sizeCol1[i]);
	}

	printListArray(lists1, listsSize1);

	printf("\nMerged Lists:\n");
	list1 = mergeKLists(lists1, listsSize1);
	printList(list1);

	// case 2
	printf("\n\nTest 2:\n");

	printf("Array of Lists:\n");
	lists2 = malloc(listsSize2 * sizeof(struct ListNode*));

	if (lists2 == NULL)
		return NULL;

	for (int i = 0; i < listsSize2; i++)
	{
		lists2[i] = arrayToList(arr2[i], sizeCol2[i]);
	}

	printListArray(lists2, listsSize2);

	printf("\nMerged Lists:\n");
	list2 = mergeKLists(lists2, listsSize2);
	printList(list2);

	// case 3
	printf("\n\nTest 3:\n");

	printf("Array of Lists:\n");
	lists3 = malloc(listsSize3 * sizeof(struct ListNode*));

	if (lists3 == NULL)
		return NULL;

	for (int i = 0; i < listsSize3; i++)
	{
		lists3[i] = arrayToList(arr2[i], sizeCol2[i]);
	}

	printListArray(lists3, listsSize3);

	printf("\nMerged Lists:\n");
	list3 = mergeKLists(lists3, listsSize3);
	printList(list3);

	// Free
	free(lists1);
	free(lists2);
	free(lists3);

	freeList(list1);
	freeList(list2);
	freeList(list3);

	printf("\n\n\n");

	system("pause");
	return 0;
}

struct ListNode* arrayToList(int* arr, int size)
{
	if (size == 0)
		return NULL;

	struct ListNode* head;
	struct ListNode* current;

	head = (struct ListNode*)malloc(sizeof(struct ListNode));

	if (head == NULL)
		return NULL;

	head->val = arr[0];
	head->next = NULL;

	current = head;

	for (int i = 1; i < size; i++)
	{
		struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));

		if (node == NULL)
			return head;

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

void printListArray(struct ListNode** lists, int listsSize)
{
	printf("{\n");
	for (int i = 0; i < listsSize; i++)
	{
		printList(lists[i]);
		printf("\n");
	}
	printf("}");
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

//void freeListArray(struct ListNode** lists, int listsSize)
//{
//	for (int i = 0; i < listsSize; i++)
//	{
//		freeList(lists[i]);
//	}
//}

struct ListNode* merge2Lists(struct ListNode* head1, struct ListNode* head2)
{
	struct ListNode dummy;
	struct ListNode* tail = &dummy;

	dummy.next = NULL;

	while (head1 != NULL && head2 != NULL)
	{
		if (head1->val < head2->val)
		{
			tail->next = head1;
			head1 = head1->next;
		}
		else
		{
			tail->next = head2;
			head2 = head2->next;
		}

		tail = tail->next;
	}

	// Add remaining nodes
	if (head1 != NULL)
		tail->next = head1;
	else
		tail->next = head2;

	return dummy.next;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) 
{
	if (listsSize == 0)
		return NULL;

	int interval = 1;
	while (interval < listsSize)
	{
		for (int i = 0; i + interval < listsSize; i += interval * 2)
		{
			lists[i] = merge2Lists(lists[i], lists[i + interval]);
		}
		
		interval *= 2;
	}

	return lists[0];
}