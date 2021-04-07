#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define STACK_LENGTH 	5
#define EMPTY			(-1)
#define STACK_FULL		(STACK_LENGTH-1)
#define STACK_EMPTY		INT_MIN			// = -2147483648

typedef struct
{
	int stackValues[STACK_LENGTH];
	int top;
}stack;

bool push(stack* mystack, int value) 
{
    if (mystack->top >= STACK_FULL) 
	{
        printf("There's no space in the stack!\n");
        return false;
    }
	else
	{
		(mystack->top)++;
		mystack->stackValues[mystack->top] = value;
		return true;
	}
}

int pop(stack* mystack) 
{
    if (mystack->top == EMPTY) 
	{
        printf("Nothing to take from stack!\n");
        return STACK_EMPTY;
    }
	else
	{
		int result = mystack->stackValues[mystack->top];
		(mystack->top)--;
		return result;
	}
}

int peek(stack* mystack) 
{
    if (mystack->top == EMPTY) 
	{
        printf("Nothing to take from stack!\n");
        return STACK_EMPTY;
    }
	else
	{
		int result = mystack->stackValues[mystack->top];
		return result;
	}
}


int main(int argc, char* argv[]) 
{
	stack s1;
	s1.top = EMPTY;
	stack s2;
	s2.top = EMPTY;
    push(&s1,1);
    push(&s1,2);
	push(&s1,3);
    push(&s2,4);
    push(&s2,5);
	push(&s2,6);
	
	
	int r; 
	printf("\n");
	while ((r=pop(&s1)) != STACK_EMPTY)
	{
		printf("Result = %d\n",r);
	}

    return 0;
}