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

void SerializeBinaryTree( TreeNode *root, FILE *fp )
{
	if( !root )
	{
		fprintf( fp, "%d", -1 );
		return;
	}

	fprintf( fp, "%d", root->data );
	SerializeBinaryTree( root->left, fp );
	SerializeBinaryTree( root->right, fp );
}

void DeSerializeBinaryTree( TreeNode **root, FILE *fp )
{
	int val;
	if ( !fscanf(fp, "%d", &val) || ( -1 == val ) )
	{
		return;
	}
	
	(*root) = (TreeNode *)malloc(sizeof(TreeNode));
	(*root)->left  = NULL;
	(*root)->right = NULL;
	printf("\n Setting %d to root. \n", val);
	(*root)->data  = val;

	DeSerializeBinaryTree( &((*root)->left), fp );
	DeSerializeBinaryTree( &((*root)->right), fp );
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

	FILE *fp = fopen( "test", "w" );
	SerializeBinaryTree( root, fp );

	TreeNode *newRoot = NULL;

	fp = fopen("test", "r");
//	DeSerializeBinaryTree( &newRoot, fp );

	int val = -1;
	fscanf( fp, "%d ", &val );

	while (fscanf (fp, "%d", &val) == 1) {
        printf("%d \n", val);
    }
	
	return 0;
}
