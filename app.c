/*
 ============================================================================
 Name        : app.c
 Author      : Ahmed Wael
 Date        : 19/10/2017\9
 Description : Test cases for linked list
 ============================================================================
 */

#include "linked.h"

ST_list list;
ST_list *head_list = &list;

int main(void)
{
	char search;
	createList(&head_list);

	ST_node *node_head = head_list->header;

	insertToList(&node_head,1,50);
	insertToList(&node_head,2,10);
	insertToList(&node_head,3,30);
	insertToList(&node_head,4,20);
	printList(&node_head);
	deleteFromList(&node_head,2);
	printf("\n");
	printList(&node_head);
	printf("\n");
	search = searchIntoList(&node_head,30);
	printf("The Value of 30 is at position = ");
	printf("%d",search);
	sortList(&node_head);
	printf("\n");
	printList(&node_head);
	reverseList(&node_head);
	printf("\n");
	printList(&node_head);

	return 0;
}
