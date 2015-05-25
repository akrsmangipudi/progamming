# include <stdio.h>
# include <stdlib.h>

typedef struct ListNode
{
	int data;
	struct ListNode* next;
} ListNode;

void PrintList( ListNode *head )
{
	if( !head )
	{
		printf("\n Empty List. \n");
		return;
	}

	printf("\n List Elements: ");
	while( head )
	{
		printf("\t %d", head->data );
		head = head->next;
	}
	printf("\n");
}

int LengthOfLL( ListNode *head )
{
	int retVal = 0;
	while( head )
	{
		head = head->next;
		retVal++;
	}
	return retVal;
}

void PushElement( ListNode **node, int data )
{
	(*node) = (ListNode *)malloc(sizeof(ListNode));
	(*node)->data = data;
	(*node)->next = NULL;
}

void DeleteLL( ListNode **head )
{
	if( !(*head) )
	{
		return;
	}

	while( (*head) )
	{
		ListNode *temp = (*head);
		(*head) = (*head)->next;
		printf("\n Freeing %d. \n", temp->data );
		free(temp);
	}
}
