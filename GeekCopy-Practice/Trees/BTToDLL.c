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

void ConvertBTToDLLUtil( TreeNode *root )
{
	if( !root )
	{
		return;
	}

	if( root->left )
	{
		ConvertBTToDLLUtil( root->left );

		TreeNode *temp = root->left;
		while( temp && temp->right )
		{
			temp = temp->right;
		}

		if( temp )
		{
			temp->right = root;
		}
		root->left = temp;
	}

	if( root->right )
	{
		ConvertBTToDLLUtil( root->right );

		TreeNode *temp = root->right;
		while( temp && temp->left )
		{
			temp = temp->left;
		}

		if( temp )
		{
			temp->left = root;
		}
		root->right = temp;
	}
}

void ConvertBTToDLL( TreeNode *root )
{
	if( !root )
	{
		return;
	}

	ConvertBTToDLLUtil( root );

	while( root->left )
	{
		root = root->left;
	}

	printf("\n");
	while( root )
	{
		printf("\t %d", root->data);
		root = root->right;
	}
	printf("\n");

}

TreeNode* Append( TreeNode *a, TreeNode *b )
{
	if( !a )
	{
		return b;
	}

	if( !b )
	{
		return a;
	}

	TreeNode *aLeft = a->left;
	TreeNode *bLeft = b->left;

	aLeft->right = b;
	b->left = aLeft;

	bLeft->right = a;
	a->left = bLeft;

	return a;
}

TreeNode* ConvertBTToCDLL( TreeNode *root )
{
	if( !root )
	{
		return NULL;
	}

	TreeNode *aList = ConvertBTToCDLL( root->left );
	TreeNode *bList = ConvertBTToCDLL( root->right );

	root->left = root;
	root->right = root;

	aList = Append( aList, root );
	aList = Append( aList, bList );

	return aList;
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

	//ConvertBTToDLL( root );
	
	TreeNode *one = ConvertBTToCDLL( root );
	TreeNode *two = one;
	
	printf("\n");
	while( two->right != one )
	{
		printf("\t %d", two->data);
		two = two->right;
	}

	printf("\t %d", two->data);	
	printf("\n");

	return 0;
}
