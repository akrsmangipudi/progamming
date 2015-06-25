# include <iostream>
# include <map>
# include <stdlib.h>

using namespace std;

struct ListNode
{
	ListNode *prev;
	ListNode *next;
	unsigned char value;
};

struct ADT
{
	ListNode *head;
	ListNode *tail;
	map< char, pair< int, ListNode* > > hashMap;
};

bool InitializeADT( ADT **adtPtr )
{
	(*adtPtr) = ( ADT * )malloc( sizeof( ADT ) );

	if( !(*adtPtr) )
	{
		cout << "Malloc fail."<< endl;
		return false;
	}

	(*adtPtr)->head = NULL;
	(*adtPtr)->tail = NULL;
	(*adtPtr)->hashMap.clear();
	return true;
}

ListNode* CreateNode( char c )
{
	ListNode* temp = ( ListNode * )malloc( sizeof( ListNode ));
	temp->prev  = NULL;
	temp->next  = NULL;
	temp->value = c;
	return temp; 
}

void RemoveNode( ADT *adtPtr, ListNode *nodeToDel )
{
	// The node that we are trying to delete is the only node.
	if( adtPtr->head == adtPtr->tail )
	{
		adtPtr->head = NULL;
		adtPtr->tail = NULL;
		free( nodeToDel );
	}
	else
	{
		if( adtPtr->head == nodeToDel )
		{
			adtPtr->head = adtPtr->head->next;
			adtPtr->head->prev = NULL;
			nodeToDel->next = NULL;
			free( nodeToDel );
		}
		else if( adtPtr->tail == nodeToDel )
		{
			adtPtr->tail = adtPtr->tail->prev;
			adtPtr->tail->next = NULL;
			nodeToDel->prev = NULL;
			free( nodeToDel );
		}
		else // Intermediate node.
		{
			nodeToDel->prev->next = nodeToDel->next;
			nodeToDel->next->prev = nodeToDel->prev;
			nodeToDel->prev = NULL;
			nodeToDel->next = NULL;
			free( nodeToDel );
		}
	}
}

void FindFirstNonRepeatingInStream( string inputStream, ADT *adtPtr )
{
	if( 0 == inputStream.length() || !adtPtr )
	{
		return;
	}

	unsigned int streamIdx = 0;

	// (1) Create a head node with the first character.
	
	adtPtr->head = CreateNode( inputStream[ 0 ] );
	adtPtr->tail = adtPtr->head;

	// (2) Update the hash table with this information.
	
	adtPtr->hashMap[ inputStream[ 0 ] ] = make_pair( 1, (ListNode*) adtPtr->head );
	cout << "First non-repeating character so far is " << adtPtr->head->value << endl;

	for( streamIdx = 1; streamIdx < inputStream.length(); streamIdx++ )
	{
		// Element not found in the hashMap, create a node for it and insert it after the tail ptr and update tail.
		if( adtPtr->hashMap.find( inputStream[ streamIdx ] ) == adtPtr->hashMap.end() )
		{

			// (1) Create a node with the character.

			ListNode *temp = CreateNode( inputStream[ streamIdx ] );

			// (2) If tail pointer exists, update the tail to point to this node and move the tail pointer; otherwise, this is the first node in the list, make head and tail point to this node.

			if( adtPtr->tail )
			{
				adtPtr->tail->next = temp;
				temp->prev   = adtPtr->tail;
				adtPtr->tail = temp;
			}
			else
			{
				adtPtr->tail = temp;
				adtPtr->head = temp;
			}

			// (3) Update the hash table with this information.

			adtPtr->hashMap[ inputStream[ streamIdx ] ] = make_pair( 1, (ListNode*) temp );
		}
		else // Element is already found in the hashMap, free the node, and make the list value point to Null. Update the head and tail pointers accordingly.
		{
			// (1) Free the listnode, by seperating the node from the rest of the list ( if the node exists, and if doesn't, this means we have already freed this node ).

			pair<int, ListNode*> p = adtPtr->hashMap[ inputStream[ streamIdx ] ];

			if( p.second )
			{
				RemoveNode( adtPtr, p.second );
			}

			// (2) Update the hash table with this information.
		
			adtPtr->hashMap[ inputStream[ streamIdx ] ] = make_pair( 1, (ListNode*)NULL );
		}

		if( adtPtr->head )
		{
			cout << "First non-repeating character so far is " << adtPtr->head->value << endl;
		}
		else
		{
			cout << "No first non-repeating character found so far. " << endl;
		}
	}
}

int main()
{
	//string inputStream = "geeksforgeeksandgeeksquizfor";
	string inputStream = "alalskska";

	ADT *adtPtr = NULL;

	bool retVal = InitializeADT( &adtPtr );

	if( retVal )
	{
		FindFirstNonRepeatingInStream( inputStream, adtPtr );
	}

	return 0;
}
