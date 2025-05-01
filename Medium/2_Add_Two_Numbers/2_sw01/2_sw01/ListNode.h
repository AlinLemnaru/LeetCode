#pragma once

// Definition for singly-linked list.
struct ListNode {
	int val;
	struct ListNode* next;
};

/* LIST FUNCTION PROTOTYPES */

struct ListNode* addToList(struct ListNode* head, int val);
struct ListNode* addToListBack(struct ListNode* head, int val);
void printList(struct ListNode* head);