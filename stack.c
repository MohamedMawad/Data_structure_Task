#include "stack.h"

void createStack(struct Stack * stack, uint32  Stack_Size)
{ 
	stack->Stack_Size = Stack_Size; 
	stack->top = -1; 
	stack->Stack_array = (uint8*)malloc(stack->Stack_Size * sizeof(uint8));
} 

uint8 full_stack(struct Stack* stack)
{uint8 retvalue ;
	if(stack->top == stack->Stack_Size - 1)
	{
	retvalue =  0;
	}
	else
	{
		retvalue = 1 ;
	}
	return retvalue ;
}

uint8 empty_stack(struct Stack* stack)
{
	uint8 retvalue ;
	if(stack->top == -1)
	{
		retvalue =0;
	}
	else
	{
		retvalue = 1 ;
	}
	return retvalue ;
}
void push(struct Stack* stack, uint8 item)
{ 	uint8 stack_check ;
stack_check = full_stack(stack);
	if (!stack_check)
	{	printf("sorry stack is full\n");
		return; }


	stack->top++;

	stack->Stack_array[stack->top] = item; 

	printf("%d pushed to stack\n", item);
} 
void pop(struct Stack* stack,uint32 *data)
{  uint8 stack_check ;
stack_check=empty_stack(stack);
	if (!stack_check)
	{*data= '$';}
	else
	{
	*data= stack->Stack_array[stack->top--];
	}
} 

/*test main */
/*
uint32 main()
{ 	uint32 x=0 ;
	struct Stack stack1 ; 
	createStack( &stack1, 2); 

	push(&stack1, 10);
	push(&stack1, 20); 
				
	
		pop(&stack1,&x);
		if (x=='$')
		{
			printf("stack is empty !!\n");
		}
		else 
		{
		printf("%d popped from stack\n",x);
			
		}
		push(&stack1, 30);
	push(&stack1, 40); 
		
	

} 
*/
