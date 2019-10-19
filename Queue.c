#include "Queue.h"
//#include"stdio.h"



void createQueue(ST_queueInfo* info, uint32 maxSize)
{

	info->front = -1;
	info->rear  = -1;
	info->max_size = maxSize;

	info->queue_ptr = (sint32*) malloc(maxSize * sizeof(sint32));

}

void enqueue(ST_queueInfo* info, sint32 data)
{
	if ( info->rear >= 0 && info->rear  <  ( (info->max_size) - 1 ) )
	{
		info->rear++;
		*(info->queue_ptr + info->rear) = data;
	}
	else if (info->front == -1 && info->rear == -1)
	{


		info->front = 0;
		info->rear  = 0;
		*(info->queue_ptr + info->rear) = data;
		//printf("%d \n", data);
		//printf("%d \n", *(info->queue_ptr + info->front) );

	}
	else
	{
		/* queue is full */

		//printf("queue is full \n");

	}


}

void dequeue(ST_queueInfo* info, sint32* data)
{

	if ( info->front < info->rear)
	{
		*data = *(info->queue_ptr + info->front);
		info->front++;

	}
	else if (info->rear == -1 && info->front == -1)
	{
		/* queue is empty */
		*data = '$';
		//printf("queue is empty \n");

	}
	else if ( info->rear  == info->front )
	{
		*data = *(info->queue_ptr + info->rear);
		info->rear  = -1;
		info->front = -1;

	}



}


unsigned char Check_queue_is_full(ST_queueInfo* info)
{
	unsigned char retval;
	if (info->rear == (info->max_size - 1) && info->front == (info->max_size - 1))
		retval = 0;
	else
		retval = 1;


	return retval ;

}

unsigned char Check_queue_is_empty(ST_queueInfo* info)
{
	unsigned char retval;
	if (info->rear == -1 && info->front == -1)
		retval = 0;
	else
		retval = 1;


	return retval ;

}


/* TEST main*/
/*
void main ()
{
	ST_queueInfo Q1;
	sint32 maxSize = 5;
	sint32 data;
	//createQueue(&Q1, maxSize);
	//enqueue(&Q1, 45);

	createQueue(&Q1, maxSize);


    printf("%d \n", Q1.rear);
	enqueue(&Q1, 45);
	printf("%d \n", Q1.rear);
	enqueue(&Q1, 5);
	printf("%d \n", Q1.rear);
	enqueue(&Q1, 6);
	printf("%d \n", Q1.rear);
	enqueue(&Q1, 6);
    printf("%d \n", Q1.rear);
	dequeue(&Q1, &data);
	printf("%d \n", data);
	dequeue(&Q1, &data);
	printf("%d \n", data);
	dequeue(&Q1, &data);
	printf("%d \n", data);
	dequeue(&Q1, &data);
	printf("%d \n", data);
	dequeue(&Q1, &data);
	printf("%d \n", data);
}
*/
