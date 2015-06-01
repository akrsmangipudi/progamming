# include <stdio.h>
# include <string.h>
# include <stdlib.h>

struct node
{
	int value;
	struct node *next;
};

#define MAX_SIZE 10

void addArrQueue(int *arrQueue, int *front, int * rear, int value)
{
	(*rear) += 1;

	// Empty Queue.
	if((*rear) == 0)
		(*front) = 0;

	if(*rear < MAX_SIZE)
	{
		arrQueue[*rear] = value;
	}
	else
	{
		(*rear)--;
		printf("\n Queue is full. \n");
	}
}

int delArrQueue(int *arrQueue, int *front, int *rear)
{
	int returnValue = -1;

	if((*front) == -1)
	{
		printf("\n Empty Queue. Nothing to delete. \n");
		return -1;
	}
	
	// Last element in the queue.
	if((*front) == (*rear))
	{
		returnValue = arrQueue[*front];
		arrQueue[*front] = 0;
		(*front) = (*rear) = -1;
		return returnValue;
	}

	return arrQueue[(*front)++];	

}

void displayArrQueue(int *arrQueue, int front, int rear)
{
	int loopIdx;
	printf("\n Queue Elements: ");
	for(loopIdx = front; loopIdx <= rear; loopIdx++)
	{
		printf("\t %d", arrQueue[loopIdx]);
	}
	printf("\n");
}

void addLLQueue(struct node **frontPtr, struct node **rearPtr, int value)
{
	struct node *temp = NULL;

	// Queue is empty.
	if(!(*rearPtr))
	{
		(*rearPtr) = (struct node *)malloc(sizeof(struct node));
		(*rearPtr)->value = value;
		(*rearPtr)->next  = NULL;
		(*frontPtr) = (*rearPtr);
	}
	else
	{
		temp = (struct node *)malloc(sizeof(struct node));
		temp->value = value;
		temp->next  = NULL;
		(*rearPtr)->next = temp;
		(*rearPtr) = temp;
	}
}

int delLLQueue(struct node **frontPtr, struct node **rearPtr)
{
	int returnVal = -1;
	struct node *temp =  NULL;

	if(!(*frontPtr))
	{
		printf("\n Queue is Empty. Nothing to delete. \n");
		return returnVal;
	}

	// Only one element in the queue.
	if((*frontPtr) == (*rearPtr))
	{
		returnVal = (*frontPtr)->value;
		temp = (*frontPtr);
		(*frontPtr) = (*rearPtr) = NULL;
		free(temp);
		return returnVal;
	}
	else
	{
		temp = (*frontPtr);
		(*frontPtr) = (*frontPtr)->next;
		temp->next = NULL;
		returnVal = temp->value;
		free(temp);
		return returnVal;
	}
}

void displayLLQueue(struct node *front, struct node *rear)
{
	if(front == NULL)
		printf("\n Empty Queue. Nothing to display. \n");

	printf("\n List Elements: ");
	while(front != NULL)
	{
		printf("\t %d", front->value);
		front = front->next;
	}
	printf("\n");
}

int main()
{
	int arrQueue[MAX_SIZE], front = -1, rear = -1, i = -1;
#if 0
	// Adding elements to an array implementation of queue.
	addArrQueue(arrQueue, &front, &rear, 23);
	addArrQueue(arrQueue, &front, &rear, 9);
	addArrQueue(arrQueue, &front, &rear, 11);
	addArrQueue(arrQueue, &front, &rear, -10);
	addArrQueue(arrQueue, &front, &rear, 25);
	addArrQueue(arrQueue, &front, &rear, 16);
	addArrQueue(arrQueue, &front, &rear, 17);
	addArrQueue(arrQueue, &front, &rear, 22);
	addArrQueue(arrQueue, &front, &rear, 19);
	addArrQueue(arrQueue, &front, &rear, 30);
	addArrQueue(arrQueue, &front, &rear, 32);

	displayArrQueue(arrQueue, front, rear);

	// Deleting elements from an array implementation of queue.
	i = delArrQueue(arrQueue, &front, &rear);
	printf("\n %d deleted from the Queue. \n", i);
	i = delArrQueue(arrQueue, &front, &rear);
	printf("\n %d deleted from the Queue. \n", i);
	i = delArrQueue(arrQueue, &front, &rear);
	printf("\n %d deleted from the Queue. \n", i);
	i = delArrQueue(arrQueue, &front, &rear);
	printf("\n %d deleted from the Queue. \n", i);
	i = delArrQueue(arrQueue, &front, &rear);
	printf("\n %d deleted from the Queue. \n", i);
	i = delArrQueue(arrQueue, &front, &rear);
	printf("\n %d deleted from the Queue. \n", i);
	i = delArrQueue(arrQueue, &front, &rear);
	printf("\n %d deleted from the Queue. \n", i);
	i = delArrQueue(arrQueue, &front, &rear);
	printf("\n %d deleted from the Queue. \n", i);
	i = delArrQueue(arrQueue, &front, &rear);
	printf("\n %d deleted from the Queue. \n", i);
	i = delArrQueue(arrQueue, &front, &rear);
	printf("\n %d deleted from the Queue. \n", i);
	
	displayArrQueue(arrQueue, front, rear);
#endif
	// Adding elements to a LL implementation of queue.
	struct node *frontPtr = NULL, *rearPtr = NULL;
	addLLQueue(&frontPtr, &rearPtr, 23);
	addLLQueue(&frontPtr, &rearPtr, 9);
	addLLQueue(&frontPtr, &rearPtr, 11);
	addLLQueue(&frontPtr, &rearPtr, -10);
	addLLQueue(&frontPtr, &rearPtr, 25);
	addLLQueue(&frontPtr, &rearPtr, 16);
	addLLQueue(&frontPtr, &rearPtr, 17);
	addLLQueue(&frontPtr, &rearPtr, 22);
	addLLQueue(&frontPtr, &rearPtr, 19);
	addLLQueue(&frontPtr, &rearPtr, 30);
	addLLQueue(&frontPtr, &rearPtr, 32);

	displayLLQueue(frontPtr, rearPtr);
	
	// Deleting elements from a LL implementation of queue.
	i = delLLQueue(&frontPtr, &rearPtr);
	printf("\n %d deleted from the Queue. \n", i);
	i = delLLQueue(&frontPtr, &rearPtr);
	printf("\n %d deleted from the Queue. \n", i);
	i = delLLQueue(&frontPtr, &rearPtr);
	printf("\n %d deleted from the Queue. \n", i);
	i = delLLQueue(&frontPtr, &rearPtr);
	printf("\n %d deleted from the Queue. \n", i);
	i = delLLQueue(&frontPtr, &rearPtr);
	printf("\n %d deleted from the Queue. \n", i);
	i = delLLQueue(&frontPtr, &rearPtr);
	printf("\n %d deleted from the Queue. \n", i);
	i = delLLQueue(&frontPtr, &rearPtr);
	printf("\n %d deleted from the Queue. \n", i);
	i = delLLQueue(&frontPtr, &rearPtr);
	printf("\n %d deleted from the Queue. \n", i);
	i = delLLQueue(&frontPtr, &rearPtr);
	printf("\n %d deleted from the Queue. \n", i);
	i = delLLQueue(&frontPtr, &rearPtr);
	printf("\n %d deleted from the Queue. \n", i);
	i = delLLQueue(&frontPtr, &rearPtr);
	printf("\n %d deleted from the Queue. \n", i);
	
	displayLLQueue(frontPtr, rearPtr);
}
