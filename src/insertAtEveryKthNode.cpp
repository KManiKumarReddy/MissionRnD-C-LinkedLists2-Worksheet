/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (!head || K < 1)
		return NULL;

	struct node * temp = head;
	int check = K - 1;
	while (temp) {
		if (check--) temp = temp->next;
		else {
			check = K - 1;
			if (temp->next) {
				struct node * temp1 = temp->next;
				temp->next = (struct node *)malloc(sizeof(node));
				temp->next->num = K;
				temp->next->next = temp1;
				temp = temp1;
			}
			else {
				temp->next = (struct node *)malloc(sizeof(node));
				temp->next->num = K;
				temp->next->next = NULL;
				return head;
			}
		}
	}
	return head;
}
