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

node* head = NULL;

bool push(int value) 
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
		newnode->down  = head;
		head           = newnode; 
		return true;
	}
}

int pop() 
{
    if (head == NULL) 
	{
        printf("Nothing to take from stack!\n");
        return STACK_EMPTY;
    }
	else
	{
		int result = head->value;
		node *tmp = head;
		head = head->down;
		free(tmp);
		return result;
	}
}

int peek() 
{
     if (head == NULL) 
	{
        printf("Nothing to take from stack!\n");
        return STACK_EMPTY;
    }
	else
	{
		int result = head->value;
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
	
	
	/*printf("\n");
    for (i = 0; i < STACK_LENGTH; i++) 
	{
        printf("%d ", pop());
    }*/
	
	int r; 
	printf("\n");
	while ((r=pop()) != STACK_EMPTY)
	{
		printf("Result = %d\n",r);
	}

    return 0;
}