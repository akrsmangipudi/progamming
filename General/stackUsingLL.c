# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct stack
{
	int data;
	struct stack *next;
	
}stack;

void push(stack **head, stack **top, int value)
{
	// Empty Stack. Inserting the first element.
	if((*head) == NULL)
	{
		(*head) = (stack *)malloc(sizeof(stack));
		(*head)->data = value;
		(*head)->next = NULL;
		(*top) = (*head);
	}
	else
	{
		(*top)->next = (stack *)malloc(sizeof(stack));
		(*top)->next->data = value;
		(*top)->next->next = NULL;
		(*top) = (*top)->next;
	}
}

int pop(stack **head, stack **top)
{
	int returnThis = -1;
	if(!(*head))
	{
		printf("\n Nothing to pop. Stack is empty. \n");
	}
	// One element remaining in the stack.
	else if((*head) == (*top))
	{
		stack *temp = (*head);
		(*head) = (*top) = NULL;
		returnThis = temp->data;
		free(temp);
	}
	else
	{
		stack *iterPtr = (*head);
		while(iterPtr->next != (*top))
			iterPtr = iterPtr->next;

		returnThis = iterPtr->next->data;
		(*top) = iterPtr;
		iterPtr = iterPtr->next;
		(*top)->next = NULL;
		free(iterPtr);
	}	
	return returnThis;
}

int main()
{
	stack *head = NULL;
	stack *top  = NULL;
	push(&head, &top, 10);
	push(&head, &top, 9);
	push(&head, &top, 8);
	printf("\n Element popped: %d", pop(&head, &top));
	printf("\n Element popped: %d", pop(&head, &top));
	push(&head, &top, 7);
	push(&head, &top, 6);
	push(&head, &top, 5);
	push(&head, &top, 4);
	push(&head, &top, 3);
	push(&head, &top, 2);
	push(&head, &top, 1);
	push(&head, &top, 1);
//	traverseTheStack();
	printf("\n Element popped: %d", pop(&head, &top));
	printf("\n Element popped: %d", pop(&head, &top));
	printf("\n Element popped: %d", pop(&head, &top));
	printf("\n Element popped: %d", pop(&head, &top));
	printf("\n Element popped: %d", pop(&head, &top));
	printf("\n Element popped: %d", pop(&head, &top));
	printf("\n Element popped: %d", pop(&head, &top));
	printf("\n Element popped: %d", pop(&head, &top));
	printf("\n Element popped: %d", pop(&head, &top));
	printf("\n Element popped: %d", pop(&head, &top));
	printf("\n Element popped: %d", pop(&head, &top));
//	traverseTheStack();
}
