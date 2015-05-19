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

unsigned int SearchElemIterative( TreeNode *root, unsigned int searchElem )
{
	unsigned int elemFound = 0;

	if( !root )
	{
		return elemFound;
	}

	Enqueue( root );

	while( !IsQueueEmpty() )
	{
		root = Dequeue();

		if( root->data == searchElem )
		{
			elemFound = 1;
			break;
		}

		if( root->left )
			Enqueue( root->left );

		if( root->right )
			Enqueue( root->right );
	}
	return elemFound;
}

unsigned int SearchElemRecursive( TreeNode *root, unsigned int searchElem )
{
	if( !root )
	{
		return 0;
	}

	return ( root->data == searchElem ) || SearchElemRecursive( root->left, searchElem ) || SearchElemRecursive( root->right, searchElem );
}

int main()
{
	TreeNode *root = NULL;
	InsertIntoTree( &root, 100 );
	InsertIntoTree( &root->left, 2 );
	InsertIntoTree( &root->right, 3 );
	InsertIntoTree( &root->left->left, 94 );
	InsertIntoTree( &root->left->right, 500 );
	InsertIntoTree( &root->right->left, 46 );
	InsertIntoTree( &root->right->right, 7 );

	unsigned int searchElem = 460;
	printf( "\n Elem %d found in give tree: %d \n", searchElem, SearchElemIterative( root, searchElem ) );
	printf( "\n Elem %d found in give tree: %d \n", searchElem, SearchElemRecursive( root, searchElem ) );

	return 0;
}
