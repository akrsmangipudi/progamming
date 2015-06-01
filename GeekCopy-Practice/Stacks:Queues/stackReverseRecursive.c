# include <stdio.h>
# include <stdlib.h>

typedef struct StackList
{
	char data;
	struct StackList *next;
}StackList;

void push(char c, StackList **top)
{
	if(!*top)
	{
		*top = (StackList *)malloc(sizeof(StackList));
		(*top)->data = c;
		(*top)->next = NULL;
	}
	else
	{
		StackList *temp = (StackList *)malloc(sizeof(StackList));
		temp->data = c;
		temp->next = *top;
		*top = temp;
	}
}

char pop(StackList **top)
{
	char retVal = '0';
	if(!*top)
	{
		printf("\n Stack is empty.");
	}
	else
	{
		StackList *temp = *top;
		*top = (*top)->next;
		retVal = temp->data;
		temp->next  = NULL;
	}
	return retVal;
}

void insertIntoStackReverseOrder(char poppedElem, StackList **top)
{
	if(!*top)
	{
		push(poppedElem, top);
	}
	else
	{
		char p2 = pop(top);
		insertIntoStackReverseOrder(poppedElem, top);
		push(p2, top);
	}
}

void ReverseStackElements(StackList **top)
{
	if(!*top)
	{
		return;
	}

	char p1 = pop(top);
	printf("\n %c popped. \n", p1);
	ReverseStackElements(top);
	insertIntoStackReverseOrder(p1, top);
}

int main()
{
	StackList *top = NULL;
	push('A', &top);
	push('B', &top);
	push('C', &top);
	push('D', &top);
#if 0
	char c1 = pop(&top);
	char c2 = pop(&top);
	char c3 = pop(&top);
	char c4 = pop(&top);
	printf("\n %c %c %c %c \n", c1, c2, c3, c4);
#endif
	ReverseStackElements(&top);
	char c1 = pop(&top);
	char c2 = pop(&top);
	char c3 = pop(&top);
	char c4 = pop(&top);
	printf("\n %c %c %c %c \n", c1, c2, c3, c4);
	return 0;
}
