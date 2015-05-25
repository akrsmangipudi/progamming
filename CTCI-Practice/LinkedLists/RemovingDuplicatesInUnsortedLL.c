# include "stlHeader.h"

void SplitList( ListNode *head, ListNode **a )
{
	// Acts as a slow pointer.
	(*a) = head;
	
	// Acts as a fast pointer.
	ListNode *b = head->next;

	while( (*a) && b && b->next )
	{
		(*a) = (*a)->next;
		b = b->next->next;
	}

	// At the end of this, (*a) is pointing to the mid element of the list, and b is pointing either to NULL or to the last element in the list.
}

void MergeLists( ListNode *a, ListNode *b, ListNode **result )
{
	if( a || b )
	{
		if( a && b )
		{
			if( a->data <= b->data )
			{
				(*result) = a;
				a = a->next;
				(*result)->next = NULL;
			}
			else
			{
				(*result) = b;
				b = b->next;
				(*result)->next = NULL;
			}
			MergeLists( a, b, &( (*result)->next ) );
		}
		else
		{
			if( a && !b )
			{
				(*result) = a;
			}
			else
			{
				(*result) = b;
			}
		}
	}
}

void MergeSortOnLL( ListNode **headRef )
{
	// If 0 or 1 elements in the input list, return from here.
	if( !(*headRef) || !(*headRef)->next )
		return;

	ListNode* a = NULL;

	SplitList( (*headRef), &a );

	ListNode *temp = a->next;
	a->next = NULL;
	
	MergeSortOnLL( headRef );
	MergeSortOnLL( &temp );

	ListNode *result = NULL;
	MergeLists( *headRef, temp, &result );

	*headRef = result;
}

void RemoveDuplicatesFromList( ListNode *head )
{
	while( head )
	{
		ListNode *temp = head->next;

		while( temp && ( head->data == temp->data ) )
		{
			ListNode* delNode = temp;
			temp = temp->next;
			head->next = temp; 
			free(delNode);	
		}

		head = temp;
	}
}

int main()
{
	ListNode* head = NULL;

	PushElement( &head, 3);
	ListNode *temp = head;

	int i = 0;
	for( i = 0; i < 500; i++ )
	{
		PushElement( &head->next,  i % 20 );
		head = head->next;
	}

	head = temp;
	
#if 0
	PushElement( &head, 3);
	PushElement( &(head->next), 2 );
	PushElement( &(head->next->next), 2 );
	PushElement( &(head->next->next->next), 1 );
	PushElement( &(head->next->next->next->next, 3);
	PushElement( &(head->next->next->next->next->next), 2 );
	PushElement( &(head->next->next->next->next->next->next), 2 );
	PushElement( &(head->next->next->next->next->next->next), 1 );
	PushElement( &head, 3);
	PushElement( &(head->next), 2 );
	PushElement( &(head->next->next), 2 );
	PushElement( &(head->next->next->next), 1 );
//	PushElement( &(head->next->next->next->next), 1 );
#endif

	// Sort the linked list.
	MergeSortOnLL( &head );

	PrintList( head );

	RemoveDuplicatesFromList( head );
	
	PrintList( head );
}
