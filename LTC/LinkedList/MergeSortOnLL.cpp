# include <iostream>
# include <stdlib.h>

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* FindMidElem( ListNode *head )
    {
        ListNode *slow = head;
        ListNode *fast = head->next;
        
        while( fast && fast->next )
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* MergeLists( ListNode* one, ListNode* two )
    {
        ListNode *result = NULL;
        ListNode **resultPtr = &result;
        
        while( one && two )
        {
            if( one->val <= two->val )
            {
                (*resultPtr) = one;
                one = one->next;
            }
            else
            {
                (*resultPtr) = two;
                two = two->next;
            }
            (*resultPtr)->next = NULL;
            resultPtr = &( (*resultPtr)->next );
        }
        
        if( one && !two )
        {
            (*resultPtr) = one;
        }
        
        if( !one && two )
        {
            (*resultPtr) = two;
        }
        
        return result;
    }

    ListNode* sortList(ListNode* head)
    {
        if( !head || !head->next )
        {
            return head;
        }
        
        ListNode *mid  = FindMidElem( head );
        ListNode *temp = mid->next; 
        mid->next = NULL;
        
        ListNode* listOne = sortList( head );
        ListNode* listTwo = sortList( temp );
        
        ListNode* result = MergeLists( listOne, listTwo );
        
        return result;
    }
};

int main()
{
	Solution s;

	ListNode *head = ( ListNode * )malloc( sizeof( ListNode ) );
	head->val = 2;

	head->next = ( ListNode * )malloc( sizeof( ListNode ) );
	head->next->val = 1;

	head->next->next = NULL;

	ListNode *retVal = s.sortList( head );
}
