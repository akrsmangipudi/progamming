# include <stdio.h>
# include <stdlib.h>

typedef struct ListNode
{
	unsigned int data;
	struct ListNode *left;
	struct ListNode *right;
}ListNode;

void InsertIntoDLL(ListNode **root, int data)
{
	if(!(*root))
	{
		(*root) = (ListNode *)malloc(sizeof(ListNode));
		(*root)->left  = NULL;
		(*root)->data  = data;
		(*root)->right = NULL;
	}
	else
	{
		ListNode *temp = (*root);
		
		while(temp->right)
			temp = temp->right;
	
		temp->right = (ListNode *)malloc(sizeof(ListNode));
		temp->right->left = temp;
		temp = temp->right;
		temp->data  = data;
		temp->right = NULL;
	}
}

ListNode* FindMidElem( ListNode *head )
{
	ListNode *small = head, *fast = head->right;

	while( small && fast && fast->right )
	{
		small = small->right;
		fast  = fast->right->right;
	}
	printf("\n Returning %d \n", small->data);
	return small;
}

void InOrderRecursive( ListNode *head )
{
	if( head )
	{
		InOrderRecursive( head->left );
		printf("\t %d", head->data);
		InOrderRecursive( head->right );
	}
}

ListNode* ConvertLLToBT( ListNode *root )
{
	if( !root || !root->right )
	{
		return root;
	}

	ListNode *mid  = FindMidElem( root );
	ListNode *prev = mid->left, *next = mid->right;

	if( prev )
	{
		prev->right = NULL;
	}

	if( next )
	{
		next->left = NULL;
	}

	mid->left = mid->right = NULL;

	mid->left  = ConvertLLToBT( ( mid != root ) ? root : NULL );
	mid->right = ConvertLLToBT( next );
	return mid;
}

int main()
{

	ListNode *root = NULL;
	InsertIntoDLL(&root, 1);
	InsertIntoDLL(&root, 2);
	InsertIntoDLL(&root, 3);
	InsertIntoDLL(&root, 4);
	InsertIntoDLL(&root, 5);
//	InsertIntoDLL(&root, 6);
	InsertIntoDLL(&root, 7);

#if 0
	while( head->right )
	{
	//	printf("\t %d", head->data);
		head = head->right;
	}
	printf("\n");
	while( head )
	{
		printf("\t %d", head->data);
		head = head->left;
	}
	printf("\n");
#endif


	root = ConvertLLToBT( root );
	
	printf(" \n InOrder : ");
	InOrderRecursive( root );
	printf("\n");
	
	return 0;
}
