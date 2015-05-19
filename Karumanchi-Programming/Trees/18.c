# include <stdio.h>
# include <stdlib.h>

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

unsigned int Max( int a, int b, int c )
{
	return (a > b) ? ( (a > c) ? a : c ) : ( (b > c) ? b : c );
}

unsigned int LongestPathBetweenLeaves( TreeNode *root )
{
	if( !root )
	{
		return 0;
	}

	int leftDiameter  = LongestPathBetweenLeaves (root->left );
	int rightDiameter = LongestPathBetweenLeaves (root->right );

	int leftHeight  = HeightOfTree( root->left );
	int rightHeight = HeightOfTree( root->right );

	return Max( leftDiameter, rightDiameter, 1 + leftHeight + rightHeight );
}

int main()
{
	TreeNode *root = NULL;
	InsertIntoTree( &root, 1 );
	InsertIntoTree( &root->left, 2 );
	InsertIntoTree( &root->right, 3 );
	InsertIntoTree( &root->left->left, 4 );
	InsertIntoTree( &root->left->right, 5 );
//	InsertIntoTree( &root->right->left, 6 );
//	InsertIntoTree( &root->right->right, 7 );

	printf("\n Longest Path b/w two leaf nodes: %d. \n", LongestPathBetweenLeaves( root ) );

	return 0;
}
