# include <stdio.h>
# include <stdlib.h>
# include <string.h>

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

int HasSumPath( TreeNode *root, unsigned int sum)
{
	if( !root )
	{
		return;
	}

	unsigned int remainingSum = sum - root->data;

	if( !root->left && !root->right && ( 0 == remainingSum ) )
	{
		return 1;
	}

	return HasSumPath( root->left, remainingSum ) || HasSumPath( root->right, remainingSum );
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

	unsigned int sum = 8;
	printf("\n Sum: %d, HasSumPath: %d. \n", sum, HasSumPath( root, sum));

	return 0;
}
