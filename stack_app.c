#include "stack.h"
#include <stdio.h>
#include "stack_app.h"


sint32 balance_counter=0;

sint8 balance(uint8 *str_ptr)
{
	sint8 retvalue=1 ;
	uint8 loop_index=0 ;
	uint32 value ;
  struct Stack balance_stack ;
createStack( &balance_stack, 1000);

	for(loop_index=0;str_ptr[loop_index] !='\0';loop_index++)
	{


		if(str_ptr[loop_index]=='{' ||str_ptr[loop_index]=='(' || str_ptr[loop_index]=='[')
			{
				 push(&balance_stack,loop_index) ;
				 balance_counter++;

			}
		else if (str_ptr[loop_index]=='}' ||str_ptr[loop_index]==')' || str_ptr[loop_index]==']')
			{
			if (str_ptr[balance_stack.Stack_array[balance_stack.top]]+1==str_ptr[loop_index])
				{
				pop(&balance_stack,&value);
				printf("%d popped from stack\n ",value);
				balance_counter--;			
				}
			else if (str_ptr[balance_stack.Stack_array[balance_stack.top]]+2==str_ptr[loop_index])
				{
				pop(&balance_stack,&value);
				printf("%d popped from stack\n ",value);
				balance_counter--;			
				}
			else 
				{
				return UNBLANCED ;
				}
				
			}



	}

	if(balance_counter==0)
			{
				retvalue= BALANCED ;
			}

			else
			{
				retvalue= UNBLANCED ;
			}
	return retvalue ;

}

/*TEST main*/

/*
void main (void)
{
uint8 str[] = "5d(({5[]5}));P{lkjhgfb}";
sint8 result=5 ;

result = balance(str);
if (result==1)
{
	printf("BALANCED\n");
}
else 
{
	printf("UNBLANCED");
}
	
	
	
}
*/
