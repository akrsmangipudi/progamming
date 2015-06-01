# include <stdio.h>
# include <stdlib.h>

struct node
{
	struct node *left;
	int value;
	struct node *right;
};

// Inserting elements into a BST.
void insertIntoBST(struct node **rootPtr, int value)
{
	if(!(*rootPtr))
	{
		(*rootPtr) = (struct node *)malloc(sizeof(struct node));
		(*rootPtr)->left  = NULL;
		(*rootPtr)->value = value;
		(*rootPtr)->right = NULL;
	}
	// Search the position where the element needs to be inserted.
	else
	{
		if((*rootPtr)->value > value)
		{
			insertIntoBST(&((*rootPtr)->left), value);
		}
		else
		{
			insertIntoBST(&((*rootPtr)->right), value);
		}
	}
}

// Inorder traversal of the BST.
void inOrderTraversal(struct node *rootPtr)
{
	if(rootPtr != NULL)
	{
		inOrderTraversal(rootPtr->left);
		printf("\t %d", rootPtr->value);
		inOrderTraversal(rootPtr->right);
	}
}

// Preorder traversal of the BST.
void preOrderTraversal(struct node *rootPtr)
{
	if(rootPtr != NULL)
	{
		printf("\t %d", rootPtr->value);
		preOrderTraversal(rootPtr->left);
		preOrderTraversal(rootPtr->right);
	}
}

// Postorder traversal of the BST.
void postOrderTraversal(struct node *rootPtr)
{
	if(rootPtr != NULL)
	{
		postOrderTraversal(rootPtr->left);
		postOrderTraversal(rootPtr->right);
		printf("\t %d", rootPtr->value);
	}
}

int main()
{
	struct node *nodePtr = NULL;
	insertIntoBST(&nodePtr, 1);
	insertIntoBST(&nodePtr, 2);
	insertIntoBST(&nodePtr, 3);
	insertIntoBST(&nodePtr, 4);
	insertIntoBST(&nodePtr, 5);
	printf("\n Inorder traversal: ");
	inOrderTraversal(nodePtr);
	printf("\n");
	printf("\n Preorder traversal: ");
	preOrderTraversal(nodePtr);
	printf("\n");
	printf("\n Postorder traversal: ");
	postOrderTraversal(nodePtr);
	printf("\n");
}
