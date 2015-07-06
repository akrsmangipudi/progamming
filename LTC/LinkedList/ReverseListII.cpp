# include <iostream>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:

    int FindLen( ListNode* head )
    {
        int retVal = 0;
        
        while( head )
        {
            retVal++;
            head = head->next;
        }
        
        return retVal;
    }
    
    ListNode* ReverseNodes( ListNode *start, ListNode *end, ListNode *nextPtr )
    {
        ListNode *one = start, *two = nextPtr, *three = nextPtr;
        
        while( one != nextPtr )
        {
            two = one;
            one = one->next;
            two->next = three;
            three = two;
        }
        return two;
    }

    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        int lengthOfList = FindLen( head );
        
        // Do not need to reverse anything.
        if ( m > lengthOfList || ( n == m ) )
        {
            return head;
        }
        
        ListNode *returnHead = head;
        
        ListNode *prev = NULL;
        
        int count = 1;
        
        while( count < m )
        {
            if( !prev )
            {
                prev = head;
            }
            else
            {
                prev = prev->next;
            }
            count++;
        }
        
        
        ListNode *one = NULL, *two = NULL;
        
        if( prev == NULL )
        {
            one = head;
        }
        else
        {
            one = prev->next;
        }
        
        two = one;
        
        count = n - m;
        
        while( count > 0 )
        {
            two = two->next;
            count--;
        }
        
        if( !two )
        {
            return head;
        }
        
        if( prev )
        {
         prev->next = ReverseNodes( one, two, two->next );
        }
        else
        {
            returnHead = ReverseNodes( one, two, two->next );
        }

		return returnHead;
    }
};

int main()
{
	Solution s;

	ListNode *head = ( ListNode * ) malloc( sizeof( ListNode ) );

	head->val = 1;
	head->next = NULL;

	ListNode* temp = ( ListNode* )malloc( sizeof( ListNode ));
	temp->val = 2;
	temp->next = NULL;	

	head->next = temp;

	temp = ( ListNode* )malloc( sizeof( ListNode ));
	temp->val = 3;
	temp->next = NULL;

	head->next->next = temp;	
	
	temp = ( ListNode* )malloc( sizeof( ListNode ));
	temp->val = 4;
	temp->next = NULL;

	head->next->next->next = temp;	
		
	temp = ( ListNode* )malloc( sizeof( ListNode ));
	temp->val = 5;
	temp->next = NULL;
	
	head->next->next->next->next = temp;

	ListNode *printPtr = head;

	printf("\n List elements: ");
	while( printPtr )
	{
		printf("\t %d", printPtr->val );
		printPtr = printPtr->next;
	}

	ListNode *newPrintPtr = s.reverseBetween( head, 3, 4 );

	printf("\n New list elements: ");
	while( newPrintPtr )
	{
		printf("\t %d", newPrintPtr->val );
		newPrintPtr = newPrintPtr->next;
	}
	

}
