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

unsigned int FindMaxElemIterative( TreeNode *root )
{
	unsigned int maxElem = 0;
	if( !root )
	{
		return maxElem;
	}

	maxElem = root->data;
	Enqueue( root );

	while( !IsQueueEmpty() )
	{
		root = Dequeue();

		if( root->data > maxElem )
			maxElem = root->data;

		if( root->left )
			Enqueue( root->left );

		if( root->right )
			Enqueue( root->right );
	}
	return maxElem;
}

unsigned int FindMaxElemRecursive( TreeNode *root )
{
	if( !root )
	{
		return 0;
	}

	int leftMax  = FindMaxElemRecursive( root->left );
	int rightMax = FindMaxElemRecursive( root->right );

	return ( leftMax > rightMax ) ? ( ( leftMax > root->data ) ? leftMax : root->data ) : ( ( rightMax > root->data ) ? rightMax : root->data );
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

	printf("\n Max Elem in give tree: %d \n", FindMaxElemIterative( root ));;
	
	printf("\n Max Elem in give tree: %d \n", FindMaxElemRecursive( root ));;

	return 0;
}
