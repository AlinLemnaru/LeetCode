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
void freeList(struct ListNode* head);
struct ListNode* swapPairs(struct ListNode* head);

int main()
{
    int arr1[] = { 1,2,3,4 }, arr2[] = { 0 }, arr3[] = { 1 }, arr4[] = { 1,2,3 };
    int size1 = 4, size2 = 0, size3 = 1, size4 = 3;

    // Create Lists
    struct ListNode* head1 = arrayToList(arr1, size1);
    struct ListNode* head2 = arrayToList(arr2, size2);
    struct ListNode* head3 = arrayToList(arr3, size3);
    struct ListNode* head4 = arrayToList(arr4, size4);

    // Results
    struct ListNode* result1;
    struct ListNode* result2;
    struct ListNode* result3;
    struct ListNode* result4;

    printf("Test 1:\n");
    printList(head1);
    result1 = swapPairs(head1);
    printf("\n");
    printList(result1);

    printf("\n\nTest 2:\n");
    printList(head2);
    result2 = swapPairs(head2);
    printf("\n");
    printList(result2);

    printf("\n\nTest 3:\n");
    printList(head3);
    result3 = swapPairs(head3);
    printf("\n");
    printList(result3);

    printf("\n\nTest 4:\n");
    printList(head4);
    result4 = swapPairs(head4);
    printf("\n");
    printList(result4);

    // Free
    freeList(result1);
    freeList(result2);
    freeList(result3);
    freeList(result4);

    printf("\n\n\n");

	system("pause");
	return 0;
}

struct ListNode* arrayToList(int* arr, int size) {
    if (size == 0) return NULL;

    struct ListNode* head = malloc(sizeof(struct ListNode));
    if (!head) return NULL;
    head->val = arr[0];
    head->next = NULL;

    struct ListNode* current = head;

    for (int i = 1; i < size; i++) {
        struct ListNode* node = malloc(sizeof(struct ListNode));
        if (!node) return head; // partial list if allocation fails
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
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode dummy;
    struct ListNode* prev = &dummy;
    struct ListNode* first;
    struct ListNode* second;
    dummy.next = head;

    while (prev->next && prev->next->next)
    {
        first = prev->next;
        second = first->next;

        first->next = second->next;
        second->next = first;
        prev->next = second;

        prev = first;
    }

    return dummy.next;
}