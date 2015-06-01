# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct Heap
{
	int *array;
	int *priority;
	int count;
	int capacity;
}Heap;

void CreateHeap(Heap **heapPtr, int capacity)
{
	(*heapPtr) = (Heap *)malloc(sizeof(Heap));
	(*heapPtr)->count    = 0;
	(*heapPtr)->capacity = capacity;
	(*heapPtr)->array    = (int *)malloc(sizeof(int) * capacity);
	memset((*heapPtr)->array, 0, sizeof(int) * capacity);
	(*heapPtr)->priority = (int *)malloc(sizeof(int) * capacity);
	memset((*heapPtr)->priority, 0, sizeof(int) * capacity);
}

void ResizeHash(Heap *heapPtr)
{
	int size = heapPtr->capacity;
	int new_size = 2 * heapPtr->capacity;
	
	int *old_array = heapPtr->array;
	int *old_priority = heapPtr->priority;
	
	heapPtr->array    = (int *)malloc( sizeof(int)* new_size );
	memset( heapPtr->array, 0, sizeof(int) * new_size );
	memcpy( heapPtr->array, old_array, sizeof(int) * heapPtr->capacity );
	
	heapPtr->priority = (int *)malloc( sizeof(int)* new_size );
	memset( heapPtr->priority, 0, sizeof(int) * new_size );
	memcpy( heapPtr->priority, old_priority, sizeof(int) * heapPtr->capacity );

	heapPtr->capacity = new_size;
	
	free(old_array);
	free(old_priority);
}

void Push(Heap *heapPtr, int value, int priority)
{

	if(heapPtr->count == heapPtr->capacity)
	{
		ResizeHash(heapPtr);
	}

	if(heapPtr->count < heapPtr->capacity)
	{
		heapPtr->priority[heapPtr->count] = priority;
		heapPtr->array[heapPtr->count++]  = value;
	}
}

void RestoreDown( int pos, Heap *heapPtr )
{
	int pri_val = heapPtr->priority[pos];
	int arr_val = heapPtr->array[pos];

	while(pos <= ( (heapPtr->count - 2)/2 + 1 ) )
	{
		int idx = 2 * pos + 1;
		
		if ( idx < ( heapPtr->count - 1 ) )
		{
			if ( heapPtr->priority[idx] < heapPtr->priority[idx + 1] )
			{
				idx = idx + 1;
			}
		}

		if ( pri_val > heapPtr->priority[idx] )
		{
			break;
		}

		heapPtr->array[ pos ]    = heapPtr->array[ idx ];
		heapPtr->priority[ pos ] = heapPtr->priority[ idx ];
		pos = idx;
	}

	heapPtr->array[pos]    = arr_val;
	heapPtr->priority[pos] = pri_val;
}

void MinHeapify(Heap *heapPtr)
{
	if(heapPtr->count > 1)
	{
		int i = 0;
		for( i = (heapPtr->count - 2)/2; i >= 0; i-- )
		{
			RestoreDown(i, heapPtr);
		}
	}
}

void Pop(Heap *heapPtr)
{
	if(heapPtr->count == 0)
	{
		printf("\n Stack is empty. Nothing to Pop. \n");
		return;
	}
	printf("\n Element %d with priority %d popped. \n", heapPtr->array[0], heapPtr->priority[0]);

	heapPtr->array[0]    = heapPtr->array[heapPtr->count - 1];
	heapPtr->priority[0] = heapPtr->priority[heapPtr->count - 1];

	heapPtr->array[ heapPtr->count - 1 ] = 0;
	heapPtr->priority[ heapPtr->count - 1 ] = 0;

	heapPtr->count = heapPtr->count - 1;

	RestoreDown(0, heapPtr);
}

void PrintHeap(Heap *heapPtr)
{
	int i = 0;
	printf("\n");
	for( i = 0; i <= heapPtr->count - 1; i++)
	{
		printf("\t %d", heapPtr->array[i]);
	}
	printf("\n");
}

int main()
{
	Heap *heapPtr = NULL;

	// Function to create a min-heap //
	CreateHeap(&heapPtr, 10);

	// Insert the 15 elements into the heap. //
	Push(heapPtr, 7, 1);
	MinHeapify(heapPtr);

	Push(heapPtr, 10, 2);
	MinHeapify(heapPtr);

	Push(heapPtr, 25, 3);
	MinHeapify(heapPtr);

	Pop(heapPtr);
	PrintHeap(heapPtr);
	
	Pop(heapPtr);
	PrintHeap(heapPtr);
	
	Pop(heapPtr);
	PrintHeap(heapPtr);
#if 0
	Push(heapPtr, 17, 4);
	MinHeapify(heapPtr);

	Push(heapPtr, 23, 5);
	MinHeapify(heapPtr);
	
	Push(heapPtr, 27, 6);
	MinHeapify(heapPtr);

	PrintHeap(heapPtr);
	
	Pop(heapPtr);
	PrintHeap(heapPtr);
	
	Pop(heapPtr);
	PrintHeap(heapPtr);

	Pop(heapPtr);
	PrintHeap(heapPtr);

	Pop(heapPtr);
	PrintHeap(heapPtr);

	Pop(heapPtr);
	PrintHeap(heapPtr);

	Pop(heapPtr);
	PrintHeap(heapPtr);

	Pop(heapPtr);
	PrintHeap(heapPtr);

	Push(heapPtr, 16, 7);
	MinHeapify(heapPtr);
	
	Push(heapPtr, 19, 8);
	MinHeapify(heapPtr);
	
	Push(heapPtr, 37, 9);
	MinHeapify(heapPtr);
	
	Push(heapPtr, 42, 10);
	MinHeapify(heapPtr);
	
	Push(heapPtr, 4, 11);
	MinHeapify(heapPtr);
	
	Push(heapPtr, 33, 12);
	MinHeapify(heapPtr);
	
	Push(heapPtr, 1, 13);
	MinHeapify(heapPtr);
	
	Push(heapPtr, 5, 14);
	MinHeapify(heapPtr);
	
	Push(heapPtr, 11, 15);
	MinHeapify(heapPtr);
	
	Pop(heapPtr);
	PrintHeap(heapPtr);

	Pop(heapPtr);
	PrintHeap(heapPtr);
	
	Pop(heapPtr);
	PrintHeap(heapPtr);
	
	Pop(heapPtr);
	PrintHeap(heapPtr);
	
	Pop(heapPtr);
	PrintHeap(heapPtr);
#endif
	
	return 0;
}
