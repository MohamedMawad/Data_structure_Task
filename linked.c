/*
 ============================================================================
 Name        : linked.c
 Author      : Ahmed Wael
 Date        : 19/10/2019
 Description : Source file of linked list with functions definitions
 ============================================================================
 */

#include "linked.h"

ST_node *prev =NULL;
ST_node *post =NULL;
ST_node *del =NULL;

static unsigned char size =0;


void createList(ST_list **head){

	(*head)->header = NULL;
}

void insertToList(ST_node **listHead, unsigned char position, int data){
	size++;
	char i,j;
	ST_node *link = (ST_node*) malloc(sizeof(ST_node));


	if((*listHead) == NULL){
		(*listHead) = link;
		(*listHead)->data = data;
		(*listHead)->next = NULL;
		return;
	}
	prev = (*listHead);
	post = (*listHead);
	if((position == 1) && ((*listHead) != NULL)){
		link->next = (*listHead);
		(*listHead) = link;
		(*listHead)->data = data;
		return;
	}
	if(position <= size){
		for(i=1;i<position;i++){
			post = post->next;
		}
		for(j=1;j<position-1;j++){
			prev = prev->next;
		}
		link->next = post;
		prev->next = link;
		link->data = data;
		return;
	}
}

void deleteFromList(ST_node **listHead, unsigned char position)
{

	char i,j;



	if( (*listHead)->next == NULL){      //at last cell
		del = (*listHead);
		(*listHead) = NULL;
		free(del);
		size--;
		return;
	}
	prev = (*listHead);
	post = (*listHead);
	del=(*listHead);
	if((position == 1) && ((*listHead) != NULL)){
		(*listHead)=(*listHead)->next ;
		free(del);
		size--;
		return;
	}
	if(position>1 && position <=size){
		if(position == size){
			for(i=1;i<=position-2;i++){
				prev= prev->next;
			}
			del = prev->next;
			prev->next = NULL;
			free(del);
			size--;
			return;
		}
		for(i=1;i<=position;i++){
			post = post->next;
		}
		for(j=1;j<position-1;j++){
			prev = prev->next;
		}
		del=prev->next;
		prev->next = post;

		free(del);
		size--;

		return;
	}

}

char searchIntoList(ST_node **listHead, int data){
	char postion=1;
	ST_node * node=(*listHead);
	while(node!=NULL)
	{
		if(node->data==data)
			return postion;
		else
		{
			node=node->next;
			postion++;
		}

	}

	return -1;

}

void sortList(ST_node **listHead){
	char temp=0;
	ST_node * node=(*listHead);
	ST_node * sec_node=(*listHead);
	sec_node = node->next;
	while(node->next!=NULL){
		while(sec_node!=NULL)
		{

			if((node->data) > (sec_node->data))
			{
				temp=sec_node->data;
				sec_node->data=node->data;
				node->data=temp;
			}
			sec_node = sec_node->next;
		}
		node=node->next;
		sec_node = node->next;
	}

}

void reverseList(ST_node **listHead)
{
	ST_node * current = (*listHead);
	ST_node * prev = NULL;
	ST_node * Next = NULL;

	if((*listHead)==NULL)
	{
		printf("Linked List is empty");
		return;
	}
	else
	{
		while(current != NULL)
		{
			Next=current->next;
			current->next=prev;
			prev=current;
			current=Next;
		}
		(*listHead)=prev;
	}


}

void printList(ST_node **listHead)
{

	ST_node *ptr = (*listHead);
	printf("[head] =>");

	//start from the beginning
	while(ptr != NULL)
	{
		printf(" %d =>",ptr->data);
		ptr = ptr->next;
	}

	printf(" [null]\n");
}
