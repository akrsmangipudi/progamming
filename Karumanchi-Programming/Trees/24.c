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

void MirrorBT( TreeNode *root )
{
	if( !root )
	{
		return;
	}
	
	MirrorBT( root-> left );
	MirrorBT( root-> right );

	TreeNode *temp = root->left;
	root->left  = root->right;
	root->right = temp;
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

	MirrorBT ( root );
	
	printf("\n LevelOrder Recursive: ");
	LevelOrderRecursive( root );
	printf("\n");

	return 0;
}
