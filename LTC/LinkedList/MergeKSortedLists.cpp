# include <iostream>
# include <vector>
# include <list>
# include <stdlib.h>

using namespace std;


  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:

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

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        ListNode *result = NULL;
        
        if( lists.size() < 2 )
        {
            return result;
        }
        
       	int n = lists.size();

		while( n > 1 )
		{
			if( n % 2 == 1 )
			{
				lists.push_back( NULL );
				n++;
			}

			for( int i = 0; i < n/2; i++ )
			{
				lists[ i ] = MergeLists( lists[ i ], lists[ i + n/2 ] );
			}
			n = n/2;
		}

		result = lists[ 0 ];
	}
};

int main()
{

	vector<ListNode*> lists;

	ListNode* one = ( ListNode* )malloc( sizeof( ListNode ) );
	one.push_back( -6 );
	one.push_back( -3 );
	one.push_back( -1 );
	one.push_back( 1 );
	one.push_back( 2 );
	one.push_back( 2 );
	one.push_back( 2 );
	one.push_back( one );
	one.clear();

	one.push_back( -10 );
	one.push_back( -8 );
	one.push_back( -6 );
	one.push_back( -2 );
	one.push_back( 4 );
	one.push_back( one );
	one.clear();

	one.push_back( -2 );
	one.push_back( one );
	one.clear();

	one.push_back( -8 );
	one.push_back( -4 );
	one.push_back( -3 );
	one.push_back( -3 );
	one.push_back( -2 );
	one.push_back( -1 );
	one.push_back( 1 );
	one.push_back( 2 );
	one.push_back( 3 );
	one.push_back( one );
	one.clear();
	
	one.push_back( -8 );
	one.push_back( -6 );
	one.push_back( -5 );
	one.push_back( -4 );
	one.push_back( -2 );
	one.push_back( -2 );
	one.push_back( 2 );
	one.push_back( 4 );
	one.push_back( one );
	one.clear();
	
	Solution s;

	ListNode* result = s.mergeKLists( lists );

	return 0;
}
