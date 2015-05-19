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

unsigned int NumOfFullIterative( TreeNode *root )
{
	unsigned int retVal = 0;

	if( !root )
	{
		return retVal;
	}

	Enqueue( root );

	while( !IsQueueEmpty() )
	{
		root = Dequeue();

		if( root->left && root->right )
		{
			retVal++;
		}

		if( root->left )
		{
			Enqueue( root->left );
		}

		if( root->right )
		{
			Enqueue( root->right );
		}
	}
	return retVal;
}

unsigned int NumOfLeavesIterative( TreeNode *root )
{
	unsigned int retVal = 0;

	if( !root )
	{
		return retVal;
	}

	Enqueue( root );

	while( !IsQueueEmpty() )
	{
		root = Dequeue();

		if( !root->left && !root->right )
		{
			retVal++;
		}

		if( root->left )
		{
			Enqueue( root->left );
		}

		if( root->right )
		{
			Enqueue( root->right );
		}
	}
	return retVal;
}

unsigned int NumOfHalfIterative( TreeNode *root )
{
	unsigned int retVal = 0;

	if( !root )
	{
		return retVal;
	}

	Enqueue( root );

	while( !IsQueueEmpty() )
	{
		root = Dequeue();

		if( (!root->left && root->right) || (root->left && !root->right) )
		{
			retVal++;
		}

		if( root->left )
		{
			Enqueue( root->left );
		}

		if( root->right )
		{
			Enqueue( root->right );
		}
	}
	return retVal;
}

unsigned int NumberOfLeavesRecursive( TreeNode *root )
{
	if( !root )
	{
		return 0;
	}

	int leftLeaves  = NumberOfLeavesRecursive( root->left );
	int rightLeaves = NumberOfLeavesRecursive( root->right );
	
	return ( !root->left && !root->right ) ? 1 + leftLeaves + rightLeaves : leftLeaves + rightLeaves;
}

unsigned int NumberOfFullRecursive( TreeNode *root )
{
	if( !root )
	{
		return 0;
	}
	
	int leftFull  = NumberOfFullRecursive( root->left );
	int rightFull = NumberOfFullRecursive( root->right );

	return ( root->left && root->right ) ? 1 + leftFull + rightFull : leftFull + rightFull;
}

unsigned int NumberOfHalfRecursive( TreeNode *root )
{
	if( !root )
	{
		return 0;
	}
	
	int leftHalf  = NumberOfHalfRecursive( root->left );
	int rightHalf = NumberOfHalfRecursive( root->right );

	return ( (root->left && !root->right) || ( !root->left && root->right) ) ? 1 + leftHalf + rightHalf : leftHalf + rightHalf;
}

int main()
{
	TreeNode *root = NULL;
	InsertIntoTree( &root, 1 );
	InsertIntoTree( &root->left, 2 );
	InsertIntoTree( &root->right, 3 );
//	InsertIntoTree( &root->left->left, 4 );
	InsertIntoTree( &root->left->right, 5 );
	InsertIntoTree( &root->right->left, 6 );
//	InsertIntoTree( &root->right->right, 7 );

	printf(" \n Number of leaf nodes: %d. \n", NumOfLeavesIterative( root ) );
	printf(" \n Number of full nodes: %d. \n", NumOfFullIterative( root ) );
	printf(" \n Number of half nodes: %d. \n", NumOfHalfIterative( root ) );
	
	printf(" \n Number of leaf nodes: %d. \n", NumberOfLeavesRecursive( root ) );
	printf(" \n Number of full nodes: %d. \n", NumberOfFullRecursive( root ) );
	printf(" \n Number of half nodes: %d. \n", NumberOfHalfRecursive( root ) );

	return 0;
}
