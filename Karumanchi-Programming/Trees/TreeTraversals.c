# include <stdio.h>
# include <stdlib.h>

# define MAX_ELEM 10

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

int top = -1;
TreeNode* Stack[ MAX_ELEM ];

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

int IsStackEmpty()
{
	return ( -1 == top ) ? 1 : 0;
}

void Push( TreeNode *node )
{
	if( ( MAX_ELEM - 1 ) == top )
	{
		printf("\n Full Stack. \n");
		return;
	}
	else
	{
		Stack[ ++top ] = node;
	}
}

TreeNode* Pop()
{
	TreeNode* retVal = NULL;
	if( IsStackEmpty() )
	{
		printf("\n Empty Stack. \n");
	}
	else
	{
		retVal = Stack[ top-- ];
	}
	return retVal;
}

void InOrderIterative( TreeNode *root )
{
	while( 1 )
	{
		while( root )
		{
			Push( root );
			root = root->left;
		}

		if( IsStackEmpty() )
		{
			break;
		}

		root = Pop();
		printf("\t %d", root->data );
		root = root->right;
	}
}

void PreOrderIterative( TreeNode *root )
{
	while( 1 )
	{
		while( root )
		{
			printf("\t %d", root->data );
			Push( root );
			root = root->left;
		}

		if( IsStackEmpty() )
		{
			break;
		}

		root = Pop();
		root = root->right;
	}
}

void PostOrderIterative( TreeNode *root )
{
	while( 1 )
	{
		while( root )
		{
			if( root-> right )
			{
				Push( root->right );
			}
			Push( root );
			root = root->left;
		}

		if( IsStackEmpty() )
		{
			break;
		}

		root = Pop();

		if( root->right && Stack[ top ] == root->right )
		{
			TreeNode *right = Pop();
			Push( root );
			root = right;
		}
		else
		{
			printf("\t %d", root->data );
			root = NULL;
		}
	}
}

void LevelOrderIterative( TreeNode *root )
{
	if( !root )
	{
		return;
	}

	Enqueue( root );

	while( !IsQueueEmpty() )
	{
		root = Dequeue();
		printf("\t %d", root->data );

		if( root->left )
			Enqueue( root->left );

		if( root->right )
			Enqueue( root->right );
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
	InsertIntoTree( &root, 1 );
	InsertIntoTree( &root->left, 2 );
	InsertIntoTree( &root->right, 3 );
	InsertIntoTree( &root->left->left, 4 );
	InsertIntoTree( &root->left->right, 5 );
	InsertIntoTree( &root->right->left, 6 );
	InsertIntoTree( &root->right->right, 7 );

	printf(" \n InOrder Iterative: ");
	InOrderIterative( root );
	printf("\n");

	printf(" \n PreOrder Iterative: ");
	PreOrderIterative( root );
	printf("\n");

	printf(" \n PostOrder Iterative: ");
	PostOrderIterative( root );
	printf("\n");

	printf("\n LevelOrder Iterative: ");
	LevelOrderIterative( root );
	printf("\n");

	printf("\n LevelOrder Recursive: ");
	LevelOrderRecursive( root );
	printf("\n");

	return 0;
}
