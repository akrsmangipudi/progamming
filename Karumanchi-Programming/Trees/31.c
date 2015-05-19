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

unsigned int sum[5];
//memset( sum, 0, sizeof(int) * 5 );

void VerticalSum( TreeNode *root, int level )
{
	if( !root )
	{
		return;
	}

	VerticalSum( root->left, level - 1 );
	VerticalSum( root->right, level + 1 );
	
	sum[ level + 2 ] = sum[ level + 2] + root->data;
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

	VerticalSum( root, 0 );

	int i = 0;
	printf("\n");
	for( i = 0; i < 5; i++ )
	{
		printf("\t %d", sum[i]);
	}
	printf("\n");

	return 0;
}
