# include "stlHeader.h"

void RemoveNode( ListNode *node )
{
	// Current Node is tail.
	if( !node->next )
	{
		free( node );
		return;
	}

	printf("\n Copying %d to %d. \n", node->next->data, node->data );

	node->data = node->next->data;
	ListNode *delNode = node->next;

	node->next = node->next->next;
	free(delNode);

	return;
}

int main()
{
	ListNode *head = NULL;

	PushElement( &head, 1 );
	ListNode *temp = head;

	ListNode *delNode = head;

	int i = 1;
	for( i = 2; i <=  10; i++ )
	{
		PushElement( &head->next,  i );
		head = head->next;
	
		if( i == 10 )
			delNode = head;
	}

	head = temp;

	PrintList( head );

	printf("\n Deleting %d. \n", delNode->data );

	RemoveNode( delNode );

	PrintList( head );

	DeleteLL( &head ); 
	
//	PrintList( head );
	return 0;
}
