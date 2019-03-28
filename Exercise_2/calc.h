/*----- FILE CALC.H --------------------------------------------------*/
/*																      */
/* Header file for CALC.C PUSHPOP.C READTOKN.C 						  */
/* a simple calculator												  */
/*--------------------------------------------------------------------*/

typedef enum toks {
	T_INTEGER,
	T_PLUS,
	T_TIMES,
	T_MINUS,
	T_DIVIDE,
	T_EQUALS,
	T_STOP,
	T_HIGH				//ESTEBAN: added for the highest function
} Token;

Token read_token(char buf[]);

typedef struct int_link {
	struct int_link * next;
	int i;
} IntLink;

typedef struct int_stack {
	IntLink * top;
} IntStack;

extern void push(IntStack *, int);
extern int pop(IntStack *);