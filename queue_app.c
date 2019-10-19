/*
 * queue_app.c
 *
 *  Created on: 19 Oct 2019
 *      Author: RGB
 */

#include "queue_app.h"
/* Evaluate the operations in order Without take operator precedence into consideration.*/
sint64 evaluate(uint8 * expression)
{
	sint32 data , operation;
	uint8 operaion_counter = 0;
	uint16 loop_index ;
	sint64 result=0 ;
	sint8 check_balance ;
	ST_queueInfo Number_queue ;
	ST_queueInfo  Operation_queue ;
	check_balance = balance(expression);
	if(check_balance==BALANCED)
	{

		createQueue(&Number_queue, 100);
		createQueue(&Operation_queue, 100);

		for(loop_index=0 ;expression[loop_index] !='\0';loop_index++)
		{


			if(expression[loop_index]>='0' && expression[loop_index]<='9')
			{

				enqueue(&Number_queue,expression[loop_index]-'0');
			}
			else if (expression[loop_index]=='+' || expression[loop_index]=='-'||expression[loop_index]=='*' ||expression[loop_index]=='/')
			{
				enqueue(&Operation_queue,expression[loop_index]);
				operaion_counter++;
			}


		}
		dequeue(&Number_queue,&data);
		result=data ;

		for(loop_index=0;loop_index < operaion_counter;loop_index++) //op_counter
		{
			dequeue(&Operation_queue,&operation);


			switch ( (char)operation )
			{
			case '+':
				dequeue(&Number_queue,&data);
				result = result + data;
				break;

			case '-':

				dequeue(&Number_queue,&data);
				result = result - data;
				break;

			case '*':
				dequeue(&Number_queue,&data);
				result = result * data;
				break;

			case '/':
				dequeue(&Number_queue,&data);
				if (data != 0)
					result = result / data;
				else
					printf("Error!!!");
				break;

			default:
				break;



			}
		}

	}

	else if (check_balance==UNBLANCED)
	{
		result='$';
	}

	return result ;

}



int main (void)
{
	uint8 ex[]="2+3((-6))*5";
	sint64 res;
	res = evaluate(ex);
	printf("%lld",res);

	return 0;

}

