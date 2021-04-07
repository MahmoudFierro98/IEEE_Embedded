#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define STACK_LENGTH 	5
#define EMPTY			(-1)
#define STACK_FULL		(STACK_LENGTH-1)
#define STACK_EMPTY		INT_MIN			// = -2147483648

int stack[STACK_LENGTH];
int top = EMPTY;

bool push(int value) 
{
    if (top >= STACK_FULL) 
	{
        printf("There's no space in the stack!\n");
        return false;
    }
	else
	{
		top++;
		stack[top] = value;
		return true;
	}
}

int pop() 
{
    if (top == EMPTY) 
	{
        printf("Nothing to take from stack!\n");
        return STACK_EMPTY;
    }
	else
	{
		int result = stack[top];
		top--;
		return result;
	}
}

int peek() 
{
    if (top == EMPTY) 
	{
        printf("Nothing to take from stack!\n");
        return STACK_EMPTY;
    }
	else
	{
		int result = stack[top];
		return result;
	}
}


int main(int argc, char* argv[]) 
{
    push(1);
    push(2);
	printf("%d\n",peek());
    push(3);
    push(4);
    push(5);
	printf("%d\n",pop());
    push(6);
	printf("%d\n",pop());
    //push(7);

    int i;
	/*
    for (i = 0; i < STACK_LENGTH; i++) 
	{
        printf("%d ", stack[i]);
    }*/
	
	/*printf("\n");
    for (i = 0; i < STACK_LENGTH; i++) 
	{
        printf("%d ", pop());
    }*/
	
	/*int r; 
	printf("\n");
	while ((r=pop()) != STACK_EMPTY)
	{
		printf("Result = %d\n",r);
	}*/

    return 0;
}