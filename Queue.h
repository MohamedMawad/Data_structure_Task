#ifndef QUEUE_H_
#define QUEUE_H_


#include <stdio.h>
#include "stdtypes.h"
#include <stdlib.h>



typedef struct {

	sint32 front ;
	sint32 rear ;
	sint32 *queue_ptr ;
	uint32 max_size ;
	

}ST_queueInfo;

void createQueue(ST_queueInfo* info, uint32 maxSize);
void enqueue(ST_queueInfo* info, sint32 data);
void dequeue(ST_queueInfo* info, sint32* data);


#endif
