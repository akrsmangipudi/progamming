# include <stdio.h>
# include <stdlib.h>
# include <string.h>

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

void ReverseOrderPrintingLevelOrder( TreeNode *root )
{
	if( !root )
	{
		return;
	}

	Enqueue( root );
	Push( root );

	while( !IsQueueEmpty() )
	{
		root = Dequeue();
		
		if( root->right )
		{
			Enqueue( root->right );
			Push( root->right );
		}

		if( root->left )
		{
			Enqueue( root->left );
			Push( root->left );
		}
	}

	printf("\n Stack Elements: ");
	while( !IsStackEmpty() )
	{
		printf("\t %d", Pop()->data);
	}
	printf("\n");
}

void DeleteTree( TreeNode *root )
{
	if( ! root )
	{
		return;
	}

	DeleteTree( root->left );
	DeleteTree( root->right );

	free( root );
	return;
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

	ReverseOrderPrintingLevelOrder( root );

	DeleteTree( root );

	if( root )
	{
		printf("\n root is not NULL ! %d", root->data);
	}
	else
	{
		printf("\n root is NULL ! %d", root->data);
	}

	return 0;
}
