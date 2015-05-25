#include <stdio.h>
#include <stdlib.h>
  
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
};

struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data   = data;
  node->left   = NULL;
  node->right  = NULL;
  node->parent = NULL;
   
  return(node);
}

struct node* insert(struct node* node, int data)
{
  /* 1. If the tree is empty, return a new,
      single node */
  if (node == NULL)
    return(newNode(data));
  else
  {
    struct node *temp;  
 
    /* 2. Otherwise, recur down the tree */
    if (data <= node->data)
    {    
         temp = insert(node->left, data);
         node->left  = temp;
         temp->parent= node;
    }
    else
    {
        temp = insert(node->right, data);
        node->right = temp;
        temp->parent = node;
    }    
  
    /* return the (unchanged) node pointer */
    return node;
  }
}

struct node* inOrderSuccessor( struct  node* target )
{
	struct node* retPtr = NULL;

	if( target->right )
	{
		retPtr = target->right;
		while( retPtr->left )
			retPtr = retPtr->left;

		return retPtr;
	}

	retPtr = target->parent;

	while( retPtr && ( target == retPtr->right ) )
	{
		target = retPtr;
		retPtr = retPtr->parent;
	}

	return retPtr;
}

struct node* inOrderSuccessorII( struct node* target, struct node* root )
{
	struct node* retVal = NULL;

	if( target->right )
	{
		retVal = target->right;
		while( retVal->left )
		{
			retVal = retVal->left;
		}
		return retVal;
	}

	while( root )
	{
		if( target->data < root->data )
		{
			retVal = root;
			root   = root->left;
			continue;
		}
		else if( target->data > root->data )
		{
			root = root->right;
			continue;
		}
		break;		
	}
	return retVal;
}

int main()
{
	struct node* root = NULL, *temp, *succ, *min;
 
	root = insert(root, 20);
	root = insert(root, 8);
	root = insert(root, 22);
	root = insert(root, 4);
	root = insert(root, 12);
	root = insert(root, 10);  
	root = insert(root, 14);    
	temp = root->left->left;
 
	succ =  inOrderSuccessorII( temp, root );
	
	if(succ !=  NULL)
		printf("\n Inorder Successor of %d is %d. \n", temp->data, succ->data);    
	else
		printf("\n Inorder Successor 0f %d doesn't exit. \n", temp->data );
 
	return 0;
}
