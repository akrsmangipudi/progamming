# include <stdio.h>
# include <stdlib.h>
#define MAX_ELEM 10
typedef struct TreeNode
{
	unsigned int data;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

void InsertIntoTree( TreeNode **root, unsigned int data )
{
	(*root) = (TreeNode *)malloc(sizeof(TreeNode));
	(*root)->data  = data;
	(*root)->left  = NULL;
	(*root)->right = NULL;
}

int front = -1, rear = -1;
TreeNode* Queue[ MAX_ELEM ];

int IsQueueEmpty()
{
	return ( -1 == front ) ? 1 : 0;
}

void Enqueue( TreeNode *node )
{
	if( ( MAX_ELEM - 1 ) == rear )
	{
		printf("\n Full Queue. \n");
		return;
	}
	else
	{
		Queue[ ++rear ] = node;
		if( -1 == front )
			front = 0;
	}
}

TreeNode* Dequeue()
{
	TreeNode *retVal = NULL;
	if( IsQueueEmpty() )
	{
		printf("\n Empty Queue. \n");
	}
	else
	{
		retVal = Queue[ front++ ];
		if( front > rear )
			front = rear = -1;
	}
	return retVal;
}

void InsertIntoBTRecursive( TreeNode *root, unsigned int insertElem, int *elemInserted )
{
	if( !root )
	{
		return;
	}

	InsertIntoBTRecursive( root->left, insertElem, elemInserted );

	if( !(*elemInserted) )
	{
		root->left = (TreeNode *)malloc(sizeof( TreeNode) );
		root->left->data  = insertElem;
		root->left->left  = NULL;
		root->left->right = NULL;
		*elemInserted = 1;
	}

	return;
}

void InsertIntoBTIterative( TreeNode *root, unsigned int insertElem )
{
	if( !root )
	{
		return;
	}

	Enqueue( root );

	while( !IsQueueEmpty() )
	{
		root = Dequeue();

		if( root->left )
		{
			Enqueue( root->left );
		}
		else
		{
			TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
			temp->data  = insertElem;
			temp->left  = NULL;
			temp->right = NULL;
			root->left = temp;
			break;
		}

		if( root->right )
		{
			Enqueue( root->right );
		}
		else
		{
			TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
			temp->data  = insertElem;
			temp->left  = NULL;
			temp->right = NULL;
			root->right = temp;
			break;
		}
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
	TreeNode *root = NULL;
	InsertIntoTree( &root, 100 );
	InsertIntoTree( &root->left, 2 );
	InsertIntoTree( &root->right, 3 );
	InsertIntoTree( &root->left->left, 94 );
//	InsertIntoTree( &root->left->right, 500 );
	InsertIntoTree( &root->right->left, 46 );
	InsertIntoTree( &root->right->right, 7 );

	unsigned int insertElem = 460;

#if 0
	InsertIntoBTIterative( root, insertElem );
	
	printf("\n LevelOrder Recursive: ");
	LevelOrderRecursive( root );
	printf("\n");
#endif

	int elemInserted = 0;
	InsertIntoBTRecursive( root, insertElem, &elemInserted );
	
	printf("\n LevelOrder Recursive: ");
	LevelOrderRecursive( root );
	printf("\n");

	return 0;
}
