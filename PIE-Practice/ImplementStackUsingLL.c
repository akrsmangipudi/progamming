# include <stdio.h>
# include <stdlib.h>

typedef struct ListNode
{
	int data;
	struct ListNode *next;
} ListNode;

void Push( ListNode **top , int data )
{
	ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
	temp->data = data;
	temp->next = (*top);

	*top = temp;
}

ListNode* Pop( ListNode** top )
{
	ListNode *retVal = NULL;
	if( !(*top) )
	{
		printf("\n Stack is empty. \n");
		return retVal;
	}

	retVal = *top;
	(*top) = (*top)->next;

	printf("\n Element %d popped. \n", retVal->data);

	return retVal;
}

int main()
{
	ListNode *top = NULL;

	Push( &top, 1 );
	Push( &top, 2 );
	Push( &top, 3 );
	Push( &top, 4 );
	Push( &top, 5 );

	Pop( &top );
	Pop( &top );
	Pop( &top );
	Pop( &top );
	Pop( &top );
	Pop( &top );
	
	Push( &top, 7 );
	Pop( &top );
	Pop( &top );

	return 0;
}
