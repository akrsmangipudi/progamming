# include <stdio.h>
# include <stdlib.h>

# define MAX_ELEM 20

typedef struct TreeNode
{
	unsigned int data;
	struct TreeNode *left;
	struct TreeNode *right;
	struct TreeNode *next;
} TreeNode;

void InsertIntoTree( TreeNode **root, unsigned int data )
{
	(*root) = (TreeNode *)malloc(sizeof(TreeNode));
	(*root)->data  = data;
	(*root)->left  = NULL;
	(*root)->right = NULL;
	(*root)->next  = NULL;
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

void LevelOrderIterative( TreeNode *root )
{
	if( !root )
	{
		return;
	}

	Enqueue( root );
	Enqueue( NULL );

	while( !IsQueueEmpty() )
	{
		root = Dequeue();

		if( !root )
		{
			if( !IsQueueEmpty() )
			{
				Enqueue( NULL );
				continue;
			}
			else
			{
				break;
			}
		}

		root->next = Queue[ front ];

		if( root->left )
			Enqueue( root->left );

		if( root->right )
			Enqueue( root->right );
	}

}

void RecursiveSiblings( TreeNode *root )
{
	if( !root )
	{
		return;
	}

	if( root->left )
		root->left->next = root->right;

	if( root->right )
		root->right->next = ( root->next ) ? root->next->left : NULL;

	RecursiveSiblings( root->left );
	RecursiveSiblings( root->right );
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

//	printf("\n LevelOrder: ");
//	LevelOrderIterative( root );
//	printf("\n");

	RecursiveSiblings( root );

	int i = 0;
	
	if( root->next )
	{
		printf("\n %d's next is %d. \n", root->data, root->next->data);
	}
	else
	{
		printf("\n %d's next is NULL. \n", root->data);
	}
	if( root->left->next )
	{
		printf("\n %d's next is %d. \n", root->left->data, root->left->next->data);
	}
	else
	{
		printf("\n %d's next is NULL. \n", root->left->data);
	}
	if( root->right->next )
	{
		printf("\n %d's next is %d. \n", root->right->data, root->right->next->data);
	}
	else
	{
		printf("\n %d's next is NULL. \n", root->right->data);
	}
	if( root->left->left->next )
	{
		printf("\n %d's next is %d. \n", root->left->left->data, root->left->left->next->data);
	}
	else
	{
		printf("\n %d's next is NULL. \n", root->left->left->data);
	}
	if( root->left->right->next )
	{
		printf("\n %d's next is %d. \n", root->left->right->data, root->left->right->next->data);
	}
	else
	{
		printf("\n %d's next is NULL. \n", root->left->right->data);
	}
	if( root->right->left->next )
	{
		printf("\n %d's next is %d. \n", root->right->left->data, root->right->left->next->data);
	}
	else
	{
		printf("\n %d's next is NULL. \n", root->right->left->data);
	}
	if( root->right->right->next )
	{
		printf("\n %d's next is %d. \n", root->right->right->data, root->right->right->next->data);
	}
	else
	{
		printf("\n %d's next is NULL. \n", root->right->right->data);
	}

	return 0;
}
