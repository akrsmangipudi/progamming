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

void PrintRootToLeafPaths( TreeNode *root, int level, char* path)
{
	if( !root )
	{
		return;
	}

	path[ level++ ] = root->data + '0';
	
	if( !root->left && !root->right )
	{
		printf("\n %s \n", path);
		return;
	}

	PrintRootToLeafPaths( root->left,  level, path );
	PrintRootToLeafPaths( root->right, level, path );
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

	char RTLPath[4];
	memset( RTLPath, 0, sizeof(char) *4 );
	PrintRootToLeafPaths( root, 0, RTLPath);

	return 0;
}
