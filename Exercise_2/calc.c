/*----- FILE CALC.C --------------------------------------------------*/
/* 																	  */
/* A simple calculator that does operations on integers that          */
/* are pushed and popped on a stack                                   */
/*--------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

IntStack stack = { 0 };
int first_op;								//ESTEBAN: added for display results function

void print_op(char op[], int a, int b){ 	//ESTEBAN: added for display results function
	if(first_op==1){
		printf("%i%s%i",a,op,b);
		first_op=0;
	}else{
		printf("%s%i",op,b);
	}
}

int main() 									//ESTEBAN: fixed the type of the fucnction as "int"
{		
	Token tok;
	char word[100];							
	char buf_out[100];						//ESTEBAN: variable doesn't have a real functionality
	int num, num2;
	int index;								//ESTEBAN: added for highest function

	first_op = 1; 							//ESTEBAN: added for display results function
	index = 0; 								//ESTEBAN: added for highest function
	printf("The operation result is: \n"); 	//ESTEBAN: added for display results function

	for(;;)
	{	
		tok=read_token(word);
		//printf("word: %s\n", word);
		switch(tok)
		{
			case T_STOP:				
				print_op("=",num,num); 		//ESTEBAN: added for display results function
				break;
			case T_INTEGER:				
				num = atoi(word);
				push(&stack,num);
				index++;				
				/* CALC1 statement */
				break;

			case T_PLUS:
				num = pop(&stack); 
				num2 = pop(&stack);
				print_op("+",num,num2);	//ESTEBAN: added for display results function
				push(&stack, num + num2);
				break;

			case T_MINUS:				
				num = pop(&stack);
				num2 = pop(&stack);
				print_op("-",num2,num);		//ESTEBAN: added for display results function
				push(&stack, num2-num);		//ESTEBAN: fixed order in minus operation was inverse
				
				break;

			case T_TIMES:				
				num = pop(&stack);
				num2 = pop(&stack);
				print_op("*",num,num2);		//ESTEBAN: added for display results function
				push(&stack, num*num2);		
				break;

			case T_DIVIDE:				
				num2 = pop(&stack);
				num = pop(&stack);
				print_op("/",num,num2);				
				push(&stack, num/num2);				
				/* CALC2 statement */
				break;

			case T_EQUALS:				
				num = pop(&stack);				
				sprintf(buf_out,"= %d ",num);
				push(&stack,num);				
				break;

			case T_HIGH:				//ESTEBAN: added for the highest function				
				for (int i = 0; i < index; ++i)
				{
					num = pop(&stack);
					num2 = pop(&stack);
					if (num>num2){						
						push(&stack,num);						
					}else
					{	
						push(&stack,num2);												
					}
				}
				first_op = 0;
				printf("Highest");
				break;
		}

		if (tok==T_STOP)			
			break;
	}
	printf("\n");
	return 0;
}