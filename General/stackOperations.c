#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	int value;
	struct node *next;
};

#define MAX_SIZE 11

void pushStackArr(int *stackArr, int *topIndex, int value)
{
	(*topIndex)++;
	if((*topIndex) < MAX_SIZE)	
	{
		stackArr[*topIndex] = value;	
	}
	else // Max size reached; cannot insert element, return !
	{
		printf("\n Cannot insert element. Max Size has been reached. \n");
		return;
	}
}

int popStackArr(int *stackArray, int *topIndex)
{
	int returnElement = -1;

	if(-1 == (*topIndex))
	{
		printf("\n Stack is empty. Nothing to Pop.");
	}
	else
	{
		returnElement = stackArray[*topIndex];
		stackArray[*topIndex] = 0;
		(*topIndex) -= 1;
	}
return returnElement;
} 

void displayArrStack(int *stackArray, int topIndex)
{
	printf("\n Remaining stack elements: ");
	while(topIndex != -1)
	{
		printf("\t %d", stackArray[topIndex]);
		topIndex--;
	}
	printf("\n");
}

void pushStackLL(struct node **headPtr, struct node **topPtr, int value)
{
	struct node *createPtr = NULL;
	// Empty Stack.
	if((*headPtr) ==  NULL)
	{
		(*headPtr) = (struct node *)malloc(sizeof(struct node));
		(*headPtr)->value = value;
		(*headPtr)->next = NULL;
		(*topPtr) = (*headPtr);
	}
	else
	{
		createPtr = (struct node *)malloc(sizeof(struct node));
		createPtr->value = value;
		createPtr->next = NULL;
		(*topPtr)->next = createPtr;
		(*topPtr) = createPtr;
	}
}

int popStackLL(struct node **headPtr, struct node **topPtr)
{
	int returnValue = -1;
	struct node *temp = (*headPtr), *swap = NULL;

	// No elements in the stack.
	if(!temp)
	{
		printf("\n Empty Stack.");
		return returnValue;
	}

	// Single element in the stack.
	if((*headPtr) == (*topPtr))
	{
		temp = (*headPtr);
		returnValue = temp->value;
		(*headPtr) = (*topPtr) = NULL;
		free(temp);
		return returnValue;
	}	

	while(temp->next != (*topPtr))
		temp = temp->next;

	swap = (*topPtr);
	(*topPtr) = temp;
	temp = swap;
	(*topPtr)->next = NULL;
	returnValue = temp->value;
	free(temp);
	return returnValue;
}

int main()
{
	int arr[MAX_SIZE], top = -1, i = 0;
	memset(arr, 0, MAX_SIZE*sizeof(int));
#if 0
	// Push operation.
	pushStackArr(arr, &top, 11);
	pushStackArr(arr, &top, 23);
	pushStackArr(arr, &top, -8);
	pushStackArr(arr, &top, 16);
	pushStackArr(arr, &top, 27);
	pushStackArr(arr, &top, 14);
	pushStackArr(arr, &top, 20);
	pushStackArr(arr, &top, 39);
	pushStackArr(arr, &top, 2);
	pushStackArr(arr, &top, 15);
	pushStackArr(arr, &top, 7);

	// Pop operation.
	i = popStackArr(arr, &top);
	printf("\n Element Popped : %d \n",i);
	i = popStackArr(arr, &top);
	printf("\n Element Popped : %d \n",i);
	i = popStackArr(arr, &top);
	printf("\n Element Popped : %d \n",i);
	i = popStackArr(arr, &top);
	printf("\n Element Popped : %d \n",i);
	i = popStackArr(arr, &top);
	printf("\n Element Popped : %d \n",i);

	// Display Stack Contents.
	displayArrStack(arr, top);
#endif 
	struct node *topNode = NULL, *headNode = NULL;

	// Push operation.
	pushStackLL(&headNode, &topNode, 11);
	pushStackLL(&headNode, &topNode, 23);
	pushStackLL(&headNode, &topNode, -8);
	pushStackLL(&headNode, &topNode, 16);
	pushStackLL(&headNode, &topNode, 27);
	pushStackLL(&headNode, &topNode, 14);
	pushStackLL(&headNode, &topNode, 20);
	pushStackLL(&headNode, &topNode, 39);
	pushStackLL(&headNode, &topNode, 2);
	pushStackLL(&headNode, &topNode, 15);
	pushStackLL(&headNode, &topNode, 7);
	
	// Pop operation.
	i = popStackLL(&headNode, &topNode);
	printf("\n Element Popped : %d \n",i);
	i = popStackLL(&headNode, &topNode);
	printf("\n Element Popped : %d \n",i);
	i = popStackLL(&headNode, &topNode);
	printf("\n Element Popped : %d \n",i);
	i = popStackLL(&headNode, &topNode);
	printf("\n Element Popped : %d \n",i);
	i = popStackLL(&headNode, &topNode);
	printf("\n Element Popped : %d \n",i);
	i = popStackLL(&headNode, &topNode);
	printf("\n Element Popped : %d \n",i);
	i = popStackLL(&headNode, &topNode);
	printf("\n Element Popped : %d \n",i);
	i = popStackLL(&headNode, &topNode);
	printf("\n Element Popped : %d \n",i);
	i = popStackLL(&headNode, &topNode);
	printf("\n Element Popped : %d \n",i);
	i = popStackLL(&headNode, &topNode);
	printf("\n Element Popped : %d \n",i);
	i = popStackLL(&headNode, &topNode);
	printf("\n Element Popped : %d \n",i);
}
