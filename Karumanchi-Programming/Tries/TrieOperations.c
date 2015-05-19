# include <stdio.h>
# include <stdlib.h>

typedef struct TrieNode
{
	unsigned char valAtNode;
	unsigned char isEndOfStr;
	struct TrieNode* child[26];
} TrieNode;

void InitializeRootNode( TrieNode **root )
{
	(*root)->valAtNode  = '1';
	unsigned int i = 0;
	for( i = 0; i < 26; i++ )
	{
		(*root)->child[ i ] = NULL;
	}
	(*root)->isEndOfStr = 0;
}

void InsertIntoTrie( TrieNode **root, char *word )
{
	if( '\0' == ( *word ) )
	{
		return;
	}

	// Check for the existence of the child pointer for the given node.
	if( !(*root)->child[ (*word) - 'a' ] )
	{
		TrieNode *newNode   = (TrieNode *)malloc(sizeof(TrieNode));
		newNode->valAtNode  = *word;
		newNode->isEndOfStr = 0;
		
		unsigned int i = 0;
		for( i = 0; i < 26; i++ )
		{
			newNode->child[ i ] = NULL;
		}
		(*root)->child[ (*word) - 'a' ] = newNode;

		if( *(word + 1) == '\0' )
		{
			(*root)->child[ (*word) - 'a' ]->isEndOfStr = 1;
		}
		InsertIntoTrie( &(*root)->child[ (*word) - 'a' ], (word + 1) );
		return;
	}
	InsertIntoTrie( &(*root)->child[ (*word) - 'a' ], (word + 1) );
}

unsigned int SearchInTrie( TrieNode **root, char *word )
{
	if( ( '\0' == (*word) ) || (NULL == (*root) ) )
	{
		return 0;
	}

	if( 
        ( !(*root)->child[ (*word) - 'a' ] ) ||
        ( (*root)->child[ (*word) - 'a' ]->valAtNode != (*word) )
      )
	{

		return 0;
	}

	if( ( *(word + 1) == '\0' ) && ( 1 == (*root)->child[ (*word) - 'a' ]->isEndOfStr ) )
	{
		return 1;
	}

	return SearchInTrie( &(*root)->child[ (*word) - 'a' ], word + 1 );
}

int main()
{
	TrieNode* triePtr = ( TrieNode * )malloc( sizeof( TrieNode ) );
	InitializeRootNode( &triePtr );

	InsertIntoTrie( &triePtr, "aditya" );
	InsertIntoTrie( &triePtr, "rakesh" ); 
	InsertIntoTrie( &triePtr, "gadde" ); 
	InsertIntoTrie( &triePtr, "prudhvi" ); 
	InsertIntoTrie( &triePtr, "kanth" ); 
	InsertIntoTrie( &triePtr, "sandeep" ); 
	InsertIntoTrie( &triePtr, "prajju" ); 
	InsertIntoTrie( &triePtr, "varun" ); 
	
	char searchStr1[] = "aditya";
	printf("\n %s found in Trie ? %d \n", searchStr1, SearchInTrie( &triePtr,searchStr1 ));

	char searchStr2[] = "prudhvi";
	printf("\n %s found in Trie ? %d \n", searchStr2, SearchInTrie( &triePtr,searchStr2 ));
	
	char searchStr3[] = "gadde";
	printf("\n %s found in Trie ? %d \n", searchStr3, SearchInTrie( &triePtr,searchStr3 ));
	
	char searchStr4[] = "rakesh";
	printf("\n %s found in Trie ? %d \n", searchStr4, SearchInTrie( &triePtr,searchStr4 ));
	
	char searchStr5[] = "varun";
	printf("\n %s found in Trie ? %d \n", searchStr5, SearchInTrie( &triePtr,searchStr5 ));

	char searchStr6[] = "kanth";
	printf("\n %s found in Trie ? %d \n", searchStr6, SearchInTrie( &triePtr,searchStr6 ));

	char searchStr7[] = "prajju";
	printf("\n %s found in Trie ? %d \n", searchStr7, SearchInTrie( &triePtr,searchStr7 ));

	char searchStr8[] = "sandeep";
	printf("\n %s found in Trie ? %d \n", searchStr8, SearchInTrie( &triePtr,searchStr8 ));

	return 0;
}
