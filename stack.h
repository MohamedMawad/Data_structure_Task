#include <stdio.h> 
#include <stdlib.h>
#include "stdtypes.h"
struct Stack {
	sint32 top;
	uint32 Stack_Size;
	uint8* Stack_array;
};
extern void createStack(struct Stack * stack, uint32  Stack_Size) ;
extern void push(struct Stack* stack, uint8 item) ;
extern void pop(struct Stack* stack,uint32*);
extern uint8 full_stack(struct Stack* stack);
extern uint8 empty_stack(struct Stack* stack);


