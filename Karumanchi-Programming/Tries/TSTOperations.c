# include <stdio.h>
# include <stdlib.h>

typedef struct TSTNode
{
	unsigned char nodeVal;
	unsigned char isEndOfStr;
	struct TSTNode *left;
	struct TSTNode *right;
	struct TSTNode *equal;
}TSTNode;

void InsertIntoTST( TSTNode **tstPtr, char *word )
{
	if( '\0' == *(word) )
	{
		return;
	}

	if( !(*tstPtr) )
	{
		(*tstPtr) = ( TSTNode * )malloc( sizeof( TSTNode ) );
		(*tstPtr)->nodeVal = (*word);
		(*tstPtr)->left  = NULL;
		(*tstPtr)->right = NULL;
		(*tstPtr)->equal = NULL;

		if( *(word + 1) == '\0' )
		{
			(*tstPtr)->isEndOfStr = 1;
			return;
		}

		InsertIntoTST( &(*tstPtr)->equal, word + 1 );
		return;
	}

	if( (*tstPtr)->nodeVal == (*word) )
	{
		if( *(word + 1) == '\0' )
		{
			(*tstPtr)->isEndOfStr = 1;
			return;
		}

		InsertIntoTST( &(*tstPtr)->equal, word + 1 );
	}
	else if( (*tstPtr)->nodeVal > (*word) )
	{
		InsertIntoTST( &(*tstPtr)->left, word );
	}
	else
	{
		InsertIntoTST( &(*tstPtr)->right, word );
	}
}

unsigned int SearchInTST( TSTNode **tstPtr, char *word )
{
	if( (*word) == '\0' )
	{
		return 1;
	}

	if( !(*tstPtr) )
	{
		return 0;
	}

	if( (*tstPtr)->nodeVal > *word )
	{
		return SearchInTST( &(*tstPtr)->left, word );
	}
	else if( (*tstPtr)->nodeVal < *word )
	{
		return SearchInTST( &(*tstPtr)->right, word );
	}
	else
	{
		if( *(word + 1) == '\0' )
		{
			return (*tstPtr)->isEndOfStr;
		}
		else
		{
			return SearchInTST( &(*tstPtr)->equal, word + 1 );
		}
	}
}

void PrintElem( TSTNode *tstPtr, char path[], int level )
{
	if( tstPtr )
	{
		PrintElem( tstPtr->left, path, level );
		path[ level ] = tstPtr->nodeVal;
		if( tstPtr->isEndOfStr )
		{
			path[ level + 1 ] = '\0';
			printf("\n %s \n", path );
		}
		PrintElem( tstPtr->equal, path, level + 1 );
		PrintElem( tstPtr->right, path, level );
	}
}

void PrintElements( TSTNode *tstPtr )
{
	char traverse[ 10 ];
	PrintElem( tstPtr, traverse, 0);
} 

int main()
{
	TSTNode *tstPtr = NULL;
	
	InsertIntoTST( &tstPtr, "aditya");
	InsertIntoTST( &tstPtr, "rakesh"); 
	InsertIntoTST( &tstPtr, "gadde" ); 
	InsertIntoTST( &tstPtr, "prudhvi" ); 
	InsertIntoTST( &tstPtr, "kanth" ); 
	InsertIntoTST( &tstPtr, "sandeep" ); 
	InsertIntoTST( &tstPtr, "prajju" ); 
	InsertIntoTST( &tstPtr, "varun" ); 
	
	InsertIntoTST( &tstPtr, "boats" ); 
	InsertIntoTST( &tstPtr, "boat" ); 
	InsertIntoTST( &tstPtr, "bat" ); 
	InsertIntoTST( &tstPtr, "bats" );

#if 0
	char searchStr1[] = "aditya";
	printf("\n %s found in Trie ? %d \n", searchStr1, SearchInTST( &tstPtr,searchStr1 ));

	char searchStr2[] = "prudhvi";
	printf("\n %s found in Trie ? %d \n", searchStr2, SearchInTST( &tstPtr,searchStr2 ));
	
	char searchStr3[] = "gadde";
	printf("\n %s found in Trie ? %d \n", searchStr3, SearchInTST( &tstPtr,searchStr3 ));
	
	char searchStr4[] = "rakesh";
	printf("\n %s found in Trie ? %d \n", searchStr4, SearchInTST( &tstPtr,searchStr4 ));
	
	char searchStr5[] = "varun";
	printf("\n %s found in Trie ? %d \n", searchStr5, SearchInTST( &tstPtr,searchStr5 ));

	char searchStr6[] = "kanth";
	printf("\n %s found in Trie ? %d \n", searchStr6, SearchInTST( &tstPtr,searchStr6 ));

	char searchStr7[] = "prajju";
	printf("\n %s found in Trie ? %d \n", searchStr7, SearchInTST( &tstPtr,searchStr7 ));

	char searchStr8[] = "sandeep";
	printf("\n %s found in Trie ? %d \n", searchStr8, SearchInTST( &tstPtr,searchStr8 ));

	char searchStr9[] = "boat";
	printf("\n %s found in TST ? %d \n", searchStr9, SearchInTST( &tstPtr,searchStr9 ));

	char searchStr10[] = "bat";
	printf("\n %s found in TST ? %d \n", searchStr10, SearchInTST( &tstPtr,searchStr10 ));

	char searchStr11[] = "bats";
	printf("\n %s found in TST ? %d \n", searchStr11, SearchInTST( &tstPtr,searchStr11 ));
#endif

	PrintElements( tstPtr );	
	
	return 0;
}
