# include <stdio.h>
# include <stdlib.h>

typedef struct TreeNode
{
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;

int HeightOfBinaryTree(TreeNode *root)
{
	if(!root)
	{
		return 0;
	}
	else
	{
		int leftHeight  = HeightOfBinaryTree(root->left); 
		int rightHeight = HeightOfBinaryTree(root->right);
		if(leftHeight > rightHeight)
			return leftHeight + 1;
		else
			return rightHeight + 1;
	}
}

void printLevelOrder(TreeNode *root, int levelIdx)
{
	if(!root)
		return;

	if(0 == levelIdx)
	{
		printf("\t %d", root->data);
	}
	else
	{
		printLevelOrder(root->left, levelIdx - 1);
		printLevelOrder(root->right, levelIdx - 1);
	}
}

void levelOrderRecursive(TreeNode *root)
{
	if(!root)
		return;

	int heightOfTree = HeightOfBinaryTree(root);
	int levelIdx = 0;
	for(levelIdx = 0; levelIdx < heightOfTree; levelIdx++)
	{
		printLevelOrder(root, levelIdx);	
	}
}

void restoreDown(int pos, int *arr, int *num)
{
	int val = arr[pos];
	while( pos <= (*num/2 - 1) )
	{
		int idx = 2 * pos + 1;

		if( idx < (*num - 1) )
		{
			if( arr[idx] < arr[idx + 1] )
			{
				idx = idx + 1;
			}
		}
		
		if( val > arr[idx] )
		{
			break;
		}

		arr[pos] = arr[idx];

		pos = idx;
	}

	arr[pos] = val;
}

void HeapifyElements(int *arr, int *num)
{
	int i = 0;
	for( i = (*num/2 - 1); i >= 0; i--)
	{
		restoreDown(i, arr, num);
	}
}

void Replace(int *arr, int *num, int val)
{
	arr[0] = val;
	restoreDown(0, arr, num);
}

void restoreUp(int *arr, int *num)
{
	int i   = *num - 1;
	int val = arr[i];
	while( (i > 0 ) && (arr[i] > arr[(i-1)/2]) )
	{
		int temp = arr[(i-1)/2];
		arr[(i-1)/2] = arr[i];
		arr[i]   = temp;
		i = (i-1)/2;
	}
}

void Add(int *arr, int *num, int val)
{
	arr[*num] = val;
	*num = *num + 1;
	restoreUp(arr, num);
}

void CreateBSTFromMaxHeap( int *arr, TreeNode **root, int start, int end)
{
	if( start <= end )
	{
		(*root) = (TreeNode*)malloc(sizeof(TreeNode));
		(*root)->left  = NULL;
		(*root)->data  = arr[start];
		(*root)->right = NULL;
		CreateBSTFromMaxHeap(arr, &(*root)->left, 2 * start + 1, end);
		CreateBSTFromMaxHeap(arr, &(*root)->right, 2 * start + 2, end);
	}
}

void PrintElementsInHeapWithMoreValue(TreeNode *root, int thresholdValue)
{
	if( !root || root->data < thresholdValue )
	{
		return;
	}
	else
	{
		printf("\t %d", root->data );
		PrintElementsInHeapWithMoreValue( root->left, thresholdValue );
		PrintElementsInHeapWithMoreValue( root->right, thresholdValue );
	}
}

void Delete(int *arr, int *numOfElem, int *elem)
{
	*numOfElem = *numOfElem - 1;
	*elem = arr[0];
	arr[0] = arr[*numOfElem];
	restoreDown(0, arr, numOfElem);
}

void KthLargestElement(int *arr, int k, int *elem, int *numOfElem)
{
	int elemCount = k;

	while(elemCount >= 1)
	{
		Delete(arr, numOfElem, elem);
		elemCount--;	
	}
}

int main()
{
	TreeNode *root = NULL;
	int num = 15;
	int arr[20] = {7, 10, 25, 17, 23, 27, 16, 19, 37, 42, 4, 33, 1, 5, 11};
	HeapifyElements(arr, &num);

	// Print the Max-Heap //
	int i = 0;
	printf("\n");
	for( i = 0; i < num; i++ )
	{
		printf("\t %d", arr[i]);
	}
	printf("\n");

#if 0
	// Replacing root with '9' and reconstructing the heap //
	Replace(arr, *num, 9);
	printf("\n");
	for( i = 0; i < num; i++ )
	{
		printf("\t %d", arr[i]);
	}
	printf("\n");
	
	// Add an element 75 at the end //
	Add(arr, &num, 75);
	printf("\n");
	for( i = 0; i < num; i++ )
	{
		printf("\t %d", arr[i]);
	}
	printf("\n");
#endif

	// Constructing a BST based off the Max-Heap.
	CreateBSTFromMaxHeap(arr, &root, 0, num - 1);
	
	printf("\n Levelorder Recursive:");
	levelOrderRecursive(root);
	printf("\n");
	
	int value = 25;
	printf("\n Threshold: %d ::", value);
	PrintElementsInHeapWithMoreValue(root, value);
	printf("\n");

	int k = 7;
	int elem = -1;
	KthLargestElement(arr, k, &elem, &num);
	printf("\n %dth(st) largest element : %d\n", k, elem);
	
}
