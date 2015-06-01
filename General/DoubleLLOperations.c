#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *prev;
	int value;
	struct node *next;
};

void addToList(struct node **frontPtr, int value)
{
	struct node *tempPtr = *frontPtr, *createPtr = NULL;
	// Empty linked list.
	if(!(*frontPtr))
	{
		(*frontPtr) = (struct node *)malloc(sizeof(struct node));
		(*frontPtr)->prev  = NULL;
	    (*frontPtr)->value = value;
		(*frontPtr)->next  = NULL;
	}
	else
	{
		// Element is the first element in the LL.
		if(value < (*frontPtr)->value)
		{
			createPtr = (struct node *)malloc(sizeof(struct node));
			createPtr->prev   = NULL;
			createPtr->value  = value;
			createPtr->next   = (*frontPtr);
			(*frontPtr)->prev = createPtr; 
			(*frontPtr) = createPtr;
		}
		else
		{
			while((tempPtr->value < value) && (tempPtr->next != NULL) && (tempPtr->next->value < value))
				tempPtr = tempPtr->next;
			// At this point, tempPtr points to the node after which the element needs to be inserted.
			createPtr = (struct node *)malloc(sizeof(struct node));
			createPtr->value = value;
			createPtr->prev  = tempPtr;
			createPtr->next  = tempPtr->next;
			tempPtr->next    = createPtr;
			// If the inserted element is not the last element in the list.
			if(createPtr->next)
				createPtr->next->prev  = createPtr;
		}
	}
}

void reverseLL(struct node **nodePtr)
{
	// Empty list.
	if(!(*nodePtr))
		return;
	
	struct node *navPtr = *nodePtr, *tempPtr = NULL, *jumpPtr = *nodePtr;

	while(navPtr != NULL)
	{
		(*nodePtr) = navPtr;
		jumpPtr    = navPtr->next;
		tempPtr    = navPtr->prev;
		navPtr->prev = navPtr->next;
		navPtr->next = tempPtr; 
		navPtr = jumpPtr;
	}
}

void reckonRearPtr(struct node *frontPtr, struct node **rearPtr)
{
	(*rearPtr)=  NULL;
	while(frontPtr)
	{
		(*rearPtr) = frontPtr;
		frontPtr=frontPtr->next;
	}
}

void display(struct node *displayLL)
{
	while(displayLL != NULL)
	{
		printf("\t %d", displayLL->value);
		displayLL = displayLL->next;
	}
}

void displayListFromEnd(struct node *displayLL)
{
	while(displayLL != NULL)
	{
		printf("\t %d", displayLL->value);
		displayLL = displayLL->prev;
	}
}

int main()
{
	struct node *frontPtr = NULL, *rearPtr = NULL;
	addToList(&frontPtr, 41);	
	addToList(&frontPtr, 12);
	addToList(&frontPtr, 98);	
	addToList(&frontPtr, 105);	
	addToList(&frontPtr, 7);	
	addToList(&frontPtr, 19);	
	addToList(&frontPtr, 120);	
	addToList(&frontPtr, 65);
	// Inserting elements in ascending order in a double linked list.
	printf("\n Display List: ");
	display(frontPtr);
	printf("\n");
	reckonRearPtr(frontPtr, &rearPtr);
	printf("\n Display List From End: ");
	displayListFromEnd(rearPtr);
	printf("\n");
	reverseLL(&frontPtr);
	// Reversing the elements in a double linked list. 
	printf("\n Revered List: ");
	display(frontPtr);
	printf("\n");
	return 0;
}
