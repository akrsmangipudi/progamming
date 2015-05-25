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

void PrintAncestors( TreeNode *root, char *ancestors, int level, int targetElem )
{
	if( !root )
	{
		return;
	}

	ancestors[ level++ ] = root->data + '0';

	if( targetElem == root->data )
	{
		printf("\n %s \n", ancestors );
	}

	PrintAncestors( root->left, ancestors, level, targetElem );
	PrintAncestors( root->right, ancestors, level, targetElem );

	ancestors[level] = '\0';
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

	char ancestors[4];
	memset( ancestors, 0, sizeof(char) * 4 );
	PrintAncestors( root, ancestors, 0, 70);

	return 0;
}
