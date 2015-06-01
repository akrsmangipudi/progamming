# include <stdio.h>
# include <stdlib.h>

typedef struct ListNode
{
}ListNode;

typedef struct MaxHeap
{
	int size;
	int capacity;
	ListNode* *array;
}MaxHeap;

typedef struct MinHeap
{
	int size;
	int capacity;
	ListNode* *array;
}MinHeap;

typedef struct ADT
{
	ListNode *nodePtr;
	MinHeap  *minPtr;
	MaxHeap  *maxPtr;
}ADT;

void CreateADT( ADT **adtPtr )
{
	(*adtPtr) = (ADT *)malloc(sizeof(ADT));
	(*adtPtr)->minPtr = (MinHeap *)malloc(sizeof(MinHeap));
	(*adtPtr)->maxPtr = (MinHeap *)malloc(sizeof(MinHeap));
}

int main()
{
	ADT *adtPtr = NULL;
	CreateADT(&adtPtr, 10);
	return 0;
}
