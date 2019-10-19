/*
 ============================================================================
 Name        : linked.h
 Author      : Ahmed Wael
 Date        : 19/10/2019
 Description : Header file of linked list with functions prototypes
 ============================================================================
 */

#ifndef LINKED_H_
#define LINKED_H_

#include <stdio.h>
#include <stdlib.h>

#define NULL (void*)0

typedef struct node{
	struct node *next;
	int data;
}ST_node;

typedef struct list{
	ST_node *header;
}ST_list;

void createList(ST_list **head);
void insertToList(ST_node **listHead, unsigned char position, int data);
void deleteFromList(ST_node **listHead, unsigned char position);
char searchIntoList(ST_node **listHead, int data);
void sortList(ST_node **listHead);	//Bonus
void reverseList(ST_node **listHead);	//Bonus
void printList(ST_node **listHead);


#endif /* LINKED_H_ */
