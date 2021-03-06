/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	struct node* result = NULL;
	// returning a list if other list is empty
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	// if 1 is smaller, taking it as head and sorting the remaining list
	if (head1->num <= head2->num) {
		result = head1;
		result->next = merge2LinkedLists(head1->next, head2);
	}
	// if 2 is smaller, taking it as head and sorting the remaining list
	else {
		result = head2;
		result->next = merge2LinkedLists(head1, head2->next);
	}
	return result;
}
