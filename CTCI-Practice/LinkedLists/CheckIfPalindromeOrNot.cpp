# include <iostream>
# include "stlHeader.h"
# include <stack>

using namespace std;

int CheckIfPalindrome( ListNode *head )
{
	if( !head )
		return 0;

	if( !head->next )
		return 1;

	stack <ListNode*> s;

	struct ListNode *slow = head, *fast = head;

	while( fast && fast->next )
	{
		s.push( slow );
		slow = slow->next;
		fast = fast->next->next;
	}

	if( fast )
		slow = slow->next;

	while( slow && !s.empty() )
	{
		if( slow->data != (s.top())->data )
		{
			return 0;
		}
		s.pop();
		slow = slow->next;
	}

	return 1;
}

int main()
{
	ListNode *head;

	PushElement( &head, 0 );

	ListNode* temp = head;

	int i = 1;
	for( i = 1; i <= 4; i++ )
	{
		PushElement( &temp->next, i );
		temp = temp->next;
	}

	for( i = 4; i >= 1 ; i-- )
	{
		PushElement( &temp->next, i );
		temp = temp->next;
	}

	PrintList( head );

	cout << "Is Input LL Palindrome ? " << CheckIfPalindrome( head ) << "."<< endl;

	return 0;
}
