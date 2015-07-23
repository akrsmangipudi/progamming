# include <iostream>
# include <stdlib.h>
# include <string.h>
# include <stack>

using namespace std;

typedef struct TreeNode
{
	unsigned int value;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;

void InsertIntoTree( TreeNode **root, unsigned int value )
{
	if( !(*root ) )
	{
		(*root) = ( TreeNode* )malloc( sizeof( TreeNode ) );
		(*root)->value  = value;
		(*root)->left   = NULL;
		(*root)->right  = NULL;
	}
	else
	{
		if( (*root)->value < value )
		{
			InsertIntoTree( &(*root)->right, value );
		}
		else
		{
			InsertIntoTree( &(*root)->left, value );
		}
	}
}

void InorderIterative( TreeNode *root )
{
	if( !root )
	{
		return;
	}

	stack<TreeNode*> treeStk;

	while( 1 )
	{
		while( root )
		{
			treeStk.push( root );
			root = root->left;
		}

		if( treeStk.empty() )
		{
			break;
		}

		root = treeStk.top();
		treeStk.pop();

		cout << " " << root->value;

		root = root->right;
	}
}

void PreorderIterative( TreeNode *root )
{
	if( !root )
	{
		return;
	}

	stack<TreeNode*> treeStk;

	while( 1 )
	{
		while( root )
		{
			cout << " " << root->value;
			treeStk.push( root );
			root = root->left;
		}

		if( treeStk.empty() )
		{
			break;
		}

		root = treeStk.top();
		treeStk.pop();

		root = root->right;
	}
}

void PostorderIterative( TreeNode* root )
{
	if( !root )
	{
		return;
	}

	stack<TreeNode*> treeStk;

	while( 1 )
	{
		while(root)
		{
			if( root->right )
			{
				treeStk.push( root->right );
			}

			treeStk.push( root );

			root = root->left;			
		}

		if( treeStk.empty() )
		{
			break;
		}

		root = treeStk.top();
		treeStk.pop();

		if( !treeStk.empty() && ( root->right == treeStk.top() ) )
		{
			TreeNode* right = treeStk.top();
			treeStk.pop();

			treeStk.push( root );

			root = right;
		}
		else
		{
			cout << " " << root->value;
			root = NULL;
		}
	}
}

void SearchForElement( const unsigned int value, TreeNode* root, TreeNode** nodePtr, TreeNode** parentPtr, bool *elementFound )
{
	if( !root )
	{
		return;
	}

	if( root->value == value )
	{
		*nodePtr = root;
		*elementFound = true;
		return;
	}
	else
	{
		*parentPtr = root;
		if( root->value > value )
		{
			SearchForElement( value, root->left, nodePtr, parentPtr, elementFound );
		}
		else
		{
			SearchForElement( value, root->right, nodePtr, parentPtr, elementFound );
		}
	}
}

void DeleteNodeFromTree( TreeNode* root, unsigned int value )
{
	if( !root )
	{
		return;
	}

	bool elementFound = false;

	TreeNode* nodePtr   = NULL;
	TreeNode* parentPtr = NULL;

	SearchForElement( value, root, &nodePtr, &parentPtr, &elementFound );

	if( !elementFound )
	{
		cout << " Element we are trying to delete does not exist in the tree." << endl;
		return;
	}

	// The node that we are trying to delete has both left and right children.
	if( nodePtr->left && nodePtr->right )
	{
		parentPtr = nodePtr;
		TreeNode* successor = nodePtr->right;

		while( successor->left )
		{
			parentPtr = successor;
			successor = successor->left;
		}

		nodePtr->value = successor->value;
		nodePtr = successor;
	}

	// Next 2 conditions are for deleting a node that has at most one child.
	if( nodePtr->left && !nodePtr->right )
	{
		if( nodePtr == parentPtr->left )
		{
			parentPtr->left = nodePtr->left;
			free( nodePtr );
		}
		else
		{
			parentPtr->right = nodePtr->left;
			free( nodePtr );
		}
	}

	if( !nodePtr->left && nodePtr->right )
	{
		if( nodePtr == parentPtr->left )
		{
			parentPtr->left = nodePtr->right;
			free( nodePtr );
		}
		else
		{
			parentPtr->right = nodePtr->right;
			free( nodePtr );
		}
	}

	if( !nodePtr->left && !nodePtr->right )
	{
		if( nodePtr == parentPtr->left )
		{
			parentPtr->left = NULL;
			free( nodePtr );
		}
		else
		{
			parentPtr->right = NULL;
			free( nodePtr );
		}
	}
}

int main()
{
	TreeNode* root = NULL;

	InsertIntoTree( &root, 20 );
	InsertIntoTree( &root, 17 );
	InsertIntoTree( &root, 23 );
	InsertIntoTree( &root, 6 );
	InsertIntoTree( &root, 18 );
	InsertIntoTree( &root, 5 );
	InsertIntoTree( &root, 8 );
	InsertIntoTree( &root, 7 );
	InsertIntoTree( &root, 10 );
	InsertIntoTree( &root, 9 );
	InsertIntoTree( &root, 25 );
	InsertIntoTree( &root, 24 );
	InsertIntoTree( &root, 29 );

	cout << " Inorder Traversal : " << endl;
	InorderIterative( root );
	cout << endl;
	
#if 0
	cout << " Preorder Traversal : " << endl;
	PreorderIterative( root );
	cout << endl;
	
	cout << " Postorder Traversal : " << endl;
	PostorderIterative( root );
	cout << endl;
#endif

	DeleteNodeFromTree( root, 20 );
	
	cout << " Inorder Traversal : " << endl;
	InorderIterative( root );
	cout << endl;

	return 0;
}
