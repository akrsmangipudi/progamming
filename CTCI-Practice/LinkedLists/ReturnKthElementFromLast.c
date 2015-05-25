# include "stlHeader.h"

int KthElemFromEnd( int k, ListNode *head )
{
//	int length = LengthOfLL( head );

//	if( ( k == 0 ) || ( length < k ) )
//		return -1;

	ListNode* helper = head;

	int i = 0;
	while( helper && ( i < (k - 1) ) )
	{
		helper = helper->next;
		i++;
	}

	if( !helper && ( i <= (k - 1) ) )
	{
		return -1;
	}

	while( helper->next )
	{
		head   = head->next;
		helper = helper->next;
	}
	return head->data;
}

int main()
{
	ListNode *head = NULL;

	PushElement( &head, 1 );
	ListNode *temp = head;

	int i = 1;
	for( i = 2; i <=  100; i++ )
	{
		PushElement( &head->next,  i );
		head = head->next;
	}

	head = temp;
//	PushElement( &head->next, 2 );
//	PushElement( &head->next->next, 3 );

	int k = 1;
	for( k = 1; k <= 102; k++ )
		printf("\n Element number %d from the last: %d. \n", k, KthElemFromEnd( k, head ) );

}
