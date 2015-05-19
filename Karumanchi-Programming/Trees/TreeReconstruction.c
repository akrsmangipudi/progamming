# include <stdio.h>
# include <stdlib.h>

typedef struct TreeNode
{
	unsigned int data;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

int FindInOrderIdx( int InOrder[], int elemToFind, int start, int end )
{
	
	int i = start;
	for( ; i <= end; i++ )
	{
		if( elemToFind == InOrder[i] )
		{
			break;
		}
	}
	return i;
}

int* GetRevisedLevelOrder( int InOrder[], int LevelOrder[], int start, int end)
{
	int *returnPtr = (int *)malloc(sizeof(int) * (end - start + 1));


	unsigned int i = 0, j = 0;

	for( i = 1; i <= 6; i++ )
	{
		int retVal = FindInOrderIdx( InOrder, LevelOrder[i], start, end );
		if( retVal <= end )
		{
			returnPtr[j++] = LevelOrder[i];
		}
	}
	return returnPtr;
}

void ReconsUsingInLevel( int InOrder[], int LevelOrder[], int start, int end, TreeNode **root )
{
	if( start <= end )
	{
		(*root) = (TreeNode *)malloc(sizeof( TreeNode ));
		(*root)->data  = LevelOrder[ 0 ];
		(*root)->left  = NULL;
		(*root)->right = NULL;

		int InIdx = FindInOrderIdx( InOrder, LevelOrder[ 0 ], start, end );

		int *left  = GetRevisedLevelOrder( InOrder, LevelOrder, start, InIdx - 1); 
		int *right = GetRevisedLevelOrder( InOrder, LevelOrder, InIdx + 1, end );

		ReconsUsingInLevel( InOrder, left, start, InIdx - 1, &(*root)->left );
		ReconsUsingInLevel( InOrder, right, InIdx + 1, end,  &(*root)->right );
	}
}

void ReconsUsingInPost( int InOrder[], int PostOrder[], int start, int end, TreeNode **root )
{
	static int postIdx = 1;
	if( start <= end )
	{
		(*root) = (TreeNode *)malloc(sizeof( TreeNode ));
		(*root)->data  = PostOrder[ postIdx ];
		(*root)->left  = NULL;
		(*root)->right = NULL;

		int InIdx = FindInOrderIdx( InOrder, PostOrder[ postIdx ], start, end );
		postIdx--;

		ReconsUsingInPost( InOrder, PostOrder, InIdx+1, end  , &( (*root)->right ) );
		ReconsUsingInPost( InOrder, PostOrder, start, InIdx-1, &( (*root)->left ) );
	}
}

void ReconsUsingInPre( int InOrder[], int PreOrder[], int start, int end, TreeNode **root )
{
	static int preIdx = 0;
	if( start <= end )
	{
		(*root) = (TreeNode *)malloc(sizeof( TreeNode ));
		(*root)->data  = PreOrder[ preIdx ];
		(*root)->left  = NULL;
		(*root)->right = NULL;

		int InIdx = FindInOrderIdx( InOrder, PreOrder[ preIdx ], start, end );
		preIdx++;

		ReconsUsingInPre( InOrder, PreOrder, start, InIdx-1, &( (*root)->left ) );
		ReconsUsingInPre( InOrder, PreOrder, InIdx+1, end  , &( (*root)->right ) );
	}
}

unsigned int HeightOfTree( TreeNode *root )
{
	if( !root )
	{
		return 0;
	}

	int left  = HeightOfTree( root->left );
	int right = HeightOfTree( root->right );

	return ( left > right ) ? 1 + left : 1 + right;
}

void PrintLevel( int level, TreeNode *root )
{
	if( !root )
	{
		return;
	}

	if( 0 == level )
	{
		printf("\t %d", root->data );
		return;
	}

	PrintLevel( level - 1, root->left );
	PrintLevel( level - 1, root->right );
}

void LevelOrderRecursive( TreeNode *root )
{
	unsigned int height = HeightOfTree( root );
	unsigned int i = 0;
	for( ; i < height ; i++ )
	{
		PrintLevel( i, root );
	}
}

int main()
{
	TreeNode *InPre   = NULL;
	TreeNode *InPost  = NULL;
	TreeNode *InLevel = NULL;
//	InsertIntoTree( &root, 1 );
//	InsertIntoTree( &root->left, 2 );
//	InsertIntoTree( &root->right, 3 );
//	InsertIntoTree( &root->left->left, 4 );
//	InsertIntoTree( &root->left->right, 5 );
//	InsertIntoTree( &root->right->left, 6 );
//	InsertIntoTree( &root->right->right, 7 );

//int InOrder[]    = { 4, 2, 5, 1, 6, 3, 7 };
//int PreOrder[]   = { 1, 2, 4, 5, 3, 6, 7 };
//int PostOrder[]  = { 4, 5, 2, 6, 7, 3, 1 };
//int LevelOrder[] = { 1, 2, 3, 4, 5, 6, 7 };

	int InOrder[]    = { 1, 2};
	int PostOrder[]   = { 2, 1};

//	ReconsUsingInPre( InOrder, PreOrder, 0, sizeof(InOrder)/sizeof(InOrder[0]) - 1, &InPre );
	
//	printf("\n LevelOrder Recursive: ");
//	LevelOrderRecursive( InPre );
//	printf("\n");

	ReconsUsingInPost( InOrder, PostOrder, 0, 1, &InPost );
	
	printf("\n LevelOrder Recursive: ");
	LevelOrderRecursive( InPost );
	printf("\n");
	
#if 0	
	ReconsUsingInLevel( InOrder, LevelOrder, 0, 6, &InLevel );

	printf("\n LevelOrder Recursive: ");
	LevelOrderRecursive( InPost );
	printf("\n");
#endif
	return 0;
}
