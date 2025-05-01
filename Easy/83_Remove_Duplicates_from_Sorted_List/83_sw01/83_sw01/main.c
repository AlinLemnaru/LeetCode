/********************************/
/* Author: Lemnaru Alin-Gabriel */
/* Date: 2025-05-01				*/
/********************************/

/* Exercise - Remove Duplicate from Sorted List
* 
* Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
* 
*/

/* Examples
* 
* Example 1:
* 
* Input: head = [1,1,2]
* Output: [1,2]
* 
* Example 2:
* 
* Input: head = [1,1,2,3,3]
* Output: [1,2,3]
* 
*/

#define _CRT_SECURE_NO_WARNINGS

/* INCLUDES */

#include<stdio.h>
#include<stdlib.h>

/* STRUCTURES */ 

struct ListNode {
	int val;
	struct ListNode* next;
};

/* FUNCTION PROTOTYPES */

struct ListNode* createList(int* arr, int size);
void printList(struct ListNode* head);
struct ListNode* deleteDuplicates(struct ListNode* head);

/* TEST FUNCTION PROTOTYPES */

int Test_Example1();
int Test_Example2();

/* MAIN */

int main()
{
	/* TESTING */

	printf("Test Example 1:\n");
	Test_Example1();
	printf("\n");
	printf("Test Example 2:\n");
	Test_Example2();
	printf("\n");

	system("pause");
	return 0;
}

/* FUNCTION DEFINITIONS */

struct ListNode* createList(int* arr, int size) {
	struct ListNode* head = NULL;
	struct ListNode* tail = NULL;

	for (int i = 0; i < size; i++) {
		struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));

		if (newNode == NULL) {
			printf("Memory allocation failed\n");
			exit(1);
		}

		newNode->val = arr[i];
		newNode->next = NULL;

		if (head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}

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

struct ListNode* deleteDuplicates(struct ListNode* head) {

	struct ListNode* temp = NULL;
	struct ListNode* current = head;

	if (head == NULL) return NULL;

	while (current->next != NULL) {

		if (current->val == current->next->val) {
			temp = current->next;
			current->next = current->next->next;
			free(temp);
		}
		else {
			current = current->next;
		}
	}

	return head;
}

/* TEST FUNCTION DEFINITIONS */

int Test_Example1() {
	int arr[] = { 1, 1, 2 };
	struct ListNode* head = createList(arr, sizeof(arr) / sizeof(arr[0]));
	printf("Original List: ");
	printList(head);
	head = deleteDuplicates(head);
	printf("List after removing duplicates: ");
	printList(head);
	return 0;
}

int Test_Example2() {
	int arr[] = { 1, 1, 2, 3, 3 };
	struct ListNode* head = createList(arr, sizeof(arr) / sizeof(arr[0]));
	printf("Original List: ");
	printList(head);
	head = deleteDuplicates(head);
	printf("List after removing duplicates: ");
	printList(head);
	return 0;
}