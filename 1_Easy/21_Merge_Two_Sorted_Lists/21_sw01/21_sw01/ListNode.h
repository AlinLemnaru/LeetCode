#pragma once

// Definition for singly-linked list.

struct ListNode {
	int val;
	struct ListNode* next;
};

// FUNCTION PROTOTYPES

struct ListNode* addNodeSort(struct ListNode* head, int val);
struct ListNode* addNode(struct ListNode* head, int val);
void printList(struct ListNode* head);
void freeList(struct ListNode* head);