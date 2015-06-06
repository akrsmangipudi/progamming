#include <iostream>
#include <stdlib.h>
# include <assert.h>
using namespace std;

struct ListNode
{
    int element;
    ListNode* next;
};

ListNode* CreateList( int N )
{
    if( N == 0 )
        return NULL;
    
    int count = 1;        
    ListNode *head = NULL;
    ListNode *current = NULL;
    ListNode *prev = NULL;
    
    head = (ListNode *)malloc(sizeof(ListNode));
       if( !head )
           return NULL;
         
    head->element = 1;
    head->next = NULL;
    prev = head;
	N = N - 1;
    
    while( N-- )
    {
        current = (ListNode *)malloc(sizeof(ListNode));
        if( !current )
           return NULL;
        
        current->element = ++count;
        current->next = NULL;
        prev->next    = current;
        prev    = current;        
    }
    
    prev->next = head;
    return head;
}

void PrintWinners( ListNode* head )
{
    if( !head || (head->element == 0) )
        return;
    
    cout << head->element << endl;
    
    ListNode *temp = head->next;

//	assert( temp != head );
    
    while( temp != head )
    {
        cout << temp->element << endl;
        temp = temp->next;
    }
    return;
}

void DeclareWinners( ListNode *head, int N, int M )
{
    if( M > N )
	{ 
        PrintWinners( head );
		return;
	}
    
    ListNode *prev = head;
    ListNode *curr = head;
    
    int count = 1;
    
    while( N >= M )
    {        
        if( count == M )
        {
            prev->next = curr->next;
			if( curr == head )
				head = head->next;

            free(curr);
            N--;
            count = 1;
            curr = prev->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
    }
    
    PrintWinners( head );
}

int main() 
{
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
int N, M;
cin >> N;
cin >> M;

ListNode *head = NULL;
head = CreateList( N );

    if( head == NULL )
    return -1;
    
DeclareWinners( head, N, M );

return 0;
}
