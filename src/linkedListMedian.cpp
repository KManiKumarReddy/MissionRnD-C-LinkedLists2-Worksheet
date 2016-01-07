/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	// handling excepions
	if (!head)
		return -1;
	// taking two pointers for traversal, one moves twice as fast as other
	struct node *traverseOnce = head, *traverseTwice = head;
	int count = 1;
	while (traverseTwice->next) {
		count++;
		traverseTwice = traverseTwice->next;
		if (traverseTwice->next) {
			count++;
			traverseTwice = traverseTwice->next;
			traverseOnce = traverseOnce->next;
		}
	}
	// if even number of items, returning mean of 2 middle elements
	return count & 1 ? traverseOnce->num : (traverseOnce->num + traverseOnce->next->num) / 2;
}
