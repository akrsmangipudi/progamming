# include <stdio.h>
# include <stdlib.h>

typedef struct ListNode
{
	unsigned int data;
	unsigned int minHeapIdx;
	unsigned int maxHeapIdx;
	struct ListNode *prev;
	struct ListNode *next;
}ListNode;

typedef struct MaxHeap
{
	int size;
	int capacity;
	ListNode* *nodeArray;
}MaxHeap;

typedef struct MinHeap
{
	int size;
	int capacity;
	ListNode* *nodeArray;
}MinHeap;

typedef struct MaxMinADT
{
	ListNode *head;
	MaxHeap  *maxPtr;
	MinHeap  *minPtr;
}MaxMinADT;

// Create MaxHeap & MinHeap.

void InitializeMaxHeap(MaxHeap **maxPtr, int capacity)
{
	(*maxPtr) = (MaxHeap *)malloc(sizeof(MaxHeap));
	(*maxPtr)->size = 0;
	(*maxPtr)->capacity = capacity;
	(*maxPtr)->nodeArray = ( ListNode ** )malloc( sizeof(ListNode) * capacity );
}

void InitializeMinHeap(MinHeap **minPtr, int capacity)
{
	(*minPtr) = (MinHeap *)malloc(sizeof(MinHeap));
	(*minPtr)->size = 0;
	(*minPtr)->capacity = capacity;
	(*minPtr)->nodeArray = ( ListNode ** )malloc( sizeof(ListNode) * capacity );
}

void CreateMaxMinADT(MaxMinADT **adtPtr, int capacity)
{
	(*adtPtr) = (MaxMinADT *)malloc(sizeof(MaxMinADT));
	(*adtPtr)->head = NULL;
	InitializeMaxHeap( &(*adtPtr)->maxPtr, capacity );
	InitializeMinHeap( &(*adtPtr)->minPtr, capacity );
}

// Insertions into the DLL, MaxHeap and MinHeap.

void InsertIntoLL(ListNode **head, int data)
{
	// Inserting the first element into the LL.
	if(!(*head))
	{
		(*head) = (ListNode *)malloc(sizeof(ListNode));
		(*head)->data = data;
		(*head)->minHeapIdx = 0xff;
		(*head)->maxHeapIdx = 0xff;
		(*head)->prev = NULL;
		(*head)->next = NULL;
	}
	else
	{
		ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
		temp->data = data;
		temp->minHeapIdx = 0xff;
		temp->maxHeapIdx = 0xff;
		temp->prev = NULL;
		temp->next = (*head);
		(*head)->prev = temp;
		(*head) = temp;
	}
}

void InsertIntoMaxHeap(MaxHeap *maxPtr, ListNode *nodePtr)
{
	if( !maxPtr )
	{
		return;
	}

	if( maxPtr->size == maxPtr->capacity )
	{
		printf("\n Max Heap is full. Return. \n");
		return;
	}

	maxPtr->nodeArray[ maxPtr->size ] = nodePtr;

	int i = maxPtr->size;
	
	int val = nodePtr->data;

	while( ( i > 0 ) && ( maxPtr->nodeArray[ (i-1)/2 ]->data < val ) )
	{
		maxPtr->nodeArray[i] = maxPtr->nodeArray[ (i-1)/2 ];
		maxPtr->nodeArray[i]->maxHeapIdx = i;
		i = (i-1)/2;
	}

	static int count = 1;
	maxPtr->nodeArray[i] = nodePtr;
	maxPtr->nodeArray[i]->maxHeapIdx = i;
	maxPtr->size++;
}

void InsertIntoMinHeap(MinHeap *minPtr, ListNode *nodePtr)
{
	if( !minPtr )
	{
		return;
	}

	if( minPtr->size == minPtr->capacity )
	{
		printf("\n Min Heap is full. Return. \n");
		return;
	}

	minPtr->nodeArray[ minPtr->size ] = nodePtr;
	
	int i = minPtr->size;

	int val = nodePtr->data;

	while( ( i > 0 ) && ( minPtr->nodeArray[ (i-1)/2 ]->data > val ) )
	{
		minPtr->nodeArray[i] = minPtr->nodeArray[ (i-1)/2 ];
		minPtr->nodeArray[i]->minHeapIdx = i;
		i = (i-1)/2;
	}

	minPtr->nodeArray[i] = nodePtr;
	minPtr->nodeArray[i]->minHeapIdx = i;
	minPtr->size++;
}

void InsertIntoADT(MaxMinADT *adtPtr, int data)
{
	InsertIntoLL(&adtPtr->head, data);
	InsertIntoMaxHeap(adtPtr->maxPtr, adtPtr->head);
	InsertIntoMinHeap(adtPtr->minPtr, adtPtr->head);
}

int FindMax(MaxMinADT *adtPtr)
{
	if(adtPtr->maxPtr->size == 0)
	{
		printf("\n Max Heap is empty. Returing -1. \n");
		return -1;
	}
	
//	printf("\n Min Heap Idx of element 50 is : %d \n", adtPtr->minPtr->nodeArray[0]->minHeapIdx);

	return adtPtr->maxPtr->nodeArray[0]->data;
}

int FindMin(MaxMinADT *adtPtr)
{
	if(adtPtr->minPtr->size == 0)
	{
		printf("\n Min Heap is empty. Returing -1. \n");
		return -1;
	}

//	printf("\n Max Heap Idx of element 10 is : %d \n", adtPtr->minPtr->nodeArray[0]->maxHeapIdx);

	return adtPtr->minPtr->nodeArray[0]->data;
}

void MinHeapify( int pos, MinHeap *minPtr )
{
	ListNode *temp = minPtr->nodeArray[ pos ];

	int val = minPtr->nodeArray[ pos ]->data;
	
	while( pos <= ( minPtr->size - 2 )/2 )
	{
		int idx = 2 * pos + 1;
		
		if( idx < minPtr->size - 1 )
		{
			if( minPtr->nodeArray[idx]->data > minPtr->nodeArray[idx + 1]->data )
			{
				idx = idx + 1;
			}
		}

		if ( val < minPtr->nodeArray[idx]->data )
		{
			break;
		}

		minPtr->nodeArray[pos] = minPtr->nodeArray[idx];
		minPtr->nodeArray[pos]->minHeapIdx = pos;

		pos = idx;
	}

	minPtr->nodeArray[ pos ] = temp;
	minPtr->nodeArray[pos]->minHeapIdx = pos;
} 

void MaxHeapify( int pos, MaxHeap *maxPtr )
{
	ListNode *temp = maxPtr->nodeArray[ pos ];

	int val = maxPtr->nodeArray[ pos ]->data;
	
	while( pos <= ( maxPtr->size - 2 )/2 )
	{
		int idx = 2 * pos + 1;
		
		if( idx < maxPtr->size - 1 )
		{
			if( maxPtr->nodeArray[idx]->data < maxPtr->nodeArray[idx + 1]->data )
			{
				idx = idx + 1;
			}
		}

		if ( val > maxPtr->nodeArray[idx]->data )
		{
			break;
		}

		maxPtr->nodeArray[pos] = maxPtr->nodeArray[idx];
		maxPtr->nodeArray[pos]->maxHeapIdx = pos;

		pos = idx;
	}

	maxPtr->nodeArray[ pos ] = temp;
	maxPtr->nodeArray[pos]->maxHeapIdx = pos;
} 

void DeleteFromMaxHeap(MaxMinADT *adtPtr)
{
	if( 0 == adtPtr->maxPtr->size )
	{
		printf("\n Max Heap is empty. Cannot delete anything. \n");
		return;
	}

	ListNode *nodeToDel = adtPtr->maxPtr->nodeArray[0];

	adtPtr->maxPtr->nodeArray[0] = adtPtr->maxPtr->nodeArray[ adtPtr->maxPtr->size - 1 ];
	adtPtr->maxPtr->nodeArray[0]->maxHeapIdx = 0;
	adtPtr->maxPtr->size = adtPtr->maxPtr->size - 1;
	if( adtPtr->maxPtr->size > 1 )
	{
		MaxHeapify( 0, adtPtr->maxPtr );
	}

	adtPtr->minPtr->nodeArray[ nodeToDel->minHeapIdx ] = adtPtr->minPtr->nodeArray[ adtPtr->minPtr->size - 1 ];
	MinHeapify( 0, adtPtr->minPtr );
	adtPtr->minPtr->size = adtPtr->minPtr->size - 1;
	adtPtr->minPtr->nodeArray[0]->minHeapIdx = 0;
}

int main()
{
	MaxMinADT *adtPtr = NULL;
	CreateMaxMinADT(&adtPtr, 10);
	InsertIntoADT(adtPtr, 10);
    InsertIntoADT(adtPtr, 20);
    InsertIntoADT(adtPtr, 30);
    InsertIntoADT(adtPtr, 40);
    InsertIntoADT(adtPtr, 50);

	int i = 0;
	printf("\n Max Heap : ");
	for( i = 0; i < adtPtr->maxPtr->size; i++ )
	{
		printf("\t %d", adtPtr->maxPtr->nodeArray[i]->data);
	}
	printf("\n");
	
	printf("\n Min Heap : ");
	for( i = 0; i < adtPtr->minPtr->size; i++ )
	{
		printf("\t %d", adtPtr->minPtr->nodeArray[i]->data);
	}
	printf("\n");
	
	printf("\n Max Heap : ");
	for( i = 0; i < adtPtr->maxPtr->size; i++ )
	{
		printf("\t data: %d, maxHeapIdx: %d", adtPtr->maxPtr->nodeArray[i]->data, adtPtr->maxPtr->nodeArray[i]->maxHeapIdx);
	}
	printf("\n");
	
	printf("\n Min Heap : ");
	for( i = 0; i < adtPtr->minPtr->size; i++ )
	{
		printf("\t data: %d, minHeapIdx: %d", adtPtr->minPtr->nodeArray[i]->data, adtPtr->minPtr->nodeArray[i]->minHeapIdx);
	}
	printf("\n");
	
	printf( "\n Find Max Element: %d. \n", FindMax(adtPtr) );
	printf( "\n Find Min Element: %d. \n", FindMin(adtPtr) );

	DeleteFromMaxHeap(adtPtr);

	printf("\n Max Heap : ");
	for( i = 0; i < adtPtr->maxPtr->size; i++ )
	{
		printf("\t %d, %d", adtPtr->maxPtr->nodeArray[i]->data, adtPtr->maxPtr->nodeArray[i]->maxHeapIdx);
	}
	printf("\n");
	
	printf("\n Min Heap : ");
	for( i = 0; i < adtPtr->minPtr->size; i++ )
	{
		printf("\t %d, %d", adtPtr->minPtr->nodeArray[i]->data, adtPtr->minPtr->nodeArray[i]->minHeapIdx);
	}
	printf("\n");
	
	DeleteFromMaxHeap(adtPtr);

	printf("\n Max Heap : ");
	for( i = 0; i < adtPtr->maxPtr->size; i++ )
	{
		printf("\t %d, %d", adtPtr->maxPtr->nodeArray[i]->data, adtPtr->maxPtr->nodeArray[i]->maxHeapIdx);
	}
	printf("\n");
	
	printf("\n Min Heap : ");
	for( i = 0; i < adtPtr->minPtr->size; i++ )
	{
		printf("\t %d, %d", adtPtr->minPtr->nodeArray[i]->data, adtPtr->minPtr->nodeArray[i]->minHeapIdx);
	}
	printf("\n");

	DeleteFromMaxHeap(adtPtr);

	printf("\n Max Heap : ");
	for( i = 0; i < adtPtr->maxPtr->size; i++ )
	{
		printf("\t %d, %d", adtPtr->maxPtr->nodeArray[i]->data, adtPtr->maxPtr->nodeArray[i]->maxHeapIdx);
	}
	printf("\n");
	
	printf("\n Min Heap : ");
	for( i = 0; i < adtPtr->minPtr->size; i++ )
	{
		printf("\t %d, %d", adtPtr->minPtr->nodeArray[i]->data, adtPtr->minPtr->nodeArray[i]->minHeapIdx);
	}
	printf("\n");

	DeleteFromMaxHeap(adtPtr);

	printf("\n Max Heap : ");
	for( i = 0; i < adtPtr->maxPtr->size; i++ )
	{
		printf("\t %d, %d", adtPtr->maxPtr->nodeArray[i]->data, adtPtr->maxPtr->nodeArray[i]->maxHeapIdx);
	}
	printf("\n");
	
	printf("\n Min Heap : ");
	for( i = 0; i < adtPtr->minPtr->size; i++ )
	{
		printf("\t %d, %d", adtPtr->minPtr->nodeArray[i]->data, adtPtr->minPtr->nodeArray[i]->minHeapIdx);
	}
	printf("\n");
	return 0;
}
