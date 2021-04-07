#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define STACK_EMPTY		INT_MIN			// = -2147483648

typedef struct 
{
	int value;
	struct node* down;
}node;

typedef node* stack;

//node* head = NULL;

bool push(stack* mystack, int value) 
{
	node* newnode = malloc(sizeof(node));
    if (newnode == NULL) 
	{
        printf("There's no space in the stack!\n");
        return false;
    }
	else
	{
		newnode->value = value;
		newnode->down  = *mystack;
		*mystack       = newnode; 
		return true;
	}
}

int pop(stack* mystack) 
{
    if (*mystack == NULL) 
	{
        printf("Nothing to take from stack!\n");
        return STACK_EMPTY;
    }
	else
	{
		int result = (*mystack)->value;
		node *tmp = *mystack;
		*mystack = (*mystack)->down;
		free(tmp);
		return result;
	}
}

int peek(stack* mystack) 
{
     if (*mystack == NULL) 
	{
        printf("Nothing to take from stack!\n");
        return STACK_EMPTY;
    }
	else
	{
		int result = (*mystack)->value;
		return result;
	}
}


int main(int argc, char* argv[]) 
{
	stack s1=NULL, s2=NULL, s3=NULL;
    push(&s1,1);
    push(&s2,2);
    push(&s2,3);
    push(&s2,4);
    push(&s2,5);
    push(&s3,0);
	
	int r; 
	printf("\n");
	while ((r=pop(&s2)) != STACK_EMPTY)
	{
		printf("Result = %d\n",r);
	}

    return 0;
}