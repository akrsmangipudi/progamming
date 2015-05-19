# include <stdio.h>
# include <stdlib.h>
# define MAX_ELEM 20
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

unsigned int LevelOrderIterative( TreeNode *root )
{
	unsigned int retVal = 0;

	if( !root )
	{
		return retVal;
	}

	Enqueue( root );
	Enqueue( NULL );

	while( !IsQueueEmpty() )
	{
		root = Dequeue();

		if( !root )
		{
			retVal++;
			if( !IsQueueEmpty() )
			{
				Enqueue( NULL );
				continue;
			}
			else
			{
				break;
			}
		}

		printf("\t %d", root->data );

		if( root->left )
			Enqueue( root->left );

		if( root->right )
			Enqueue( root->right );
	}
	return retVal;
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

	printf("\n Height is : %d \n", LevelOrderIterative( root ) );
	return 0;
}
