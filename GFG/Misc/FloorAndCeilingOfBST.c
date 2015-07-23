# include <stdio.h>
# include <stdlib.h>

typedef struct node
{
    int key;
    struct node* left;
    struct node* right;
} node;

struct node* newNode(int key)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->key = key;
    node->left  = NULL;
    node->right = NULL;
    return(node);
}

int Ceil( struct node* root, int input )
{
	if( !root )
	{
		return -1;
	}

	if( root->key == input )
	{
		return root->key;
	}

	if( root->key < input )
	{
		return Ceil( root->right, input );
	}

	int ceil = Ceil( root->left, input );

	return ( ceil != -1 && ceil >= input ) ? ceil : root->key;
}

int Floor( struct node* root, int input )
{
	if( !root )
	{
		return -1;
	}

	if( root->key == input )
	{
		return root->key;
	}

	if( root->key > input )
	{
		return Floor( root->left, input );
	}

	int floor = Floor( root->right, input );

	return ( floor != -1 && floor <= input ) ? floor : root->key;
}

int main()
{
    node *root = newNode(8);
 
    root->left = newNode(4);
    root->right = newNode(12);
 
    root->left->left = newNode(2);
    root->left->right = newNode(6);
 
    root->right->left = newNode(10);
    root->right->right = newNode(14);

	printf("\n **** Ceiling **** \n"); 
	int i = 0;
    for( ; i < 16; i++)
	{
        printf("%d  %d\n", i, Ceil(root, i));
	}
 
	printf("\n **** Floor **** \n");
	i = 0;
    for( ; i < 16; i++)
	{
        printf("%d  %d\n", i, Floor(root, i));
	}
    return 0;
}
