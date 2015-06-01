# include <stdio.h>
# include <stdlib.h>
# include <string.h>

const int MAX_SIZE = 10;

int frontOne = -1, rearOne = -1;
int frontTwo = -1, rearTwo = -1;
typedef struct Queue
{
	int QueueOne[MAX_SIZE];
	int QueueTwo[MAX_SIZE];
}Queue;

void initializeQueue(Queue *q, int element)
{
	q->QueueOne[++rearOne] = element;
	if(-1 == frontOne)
	{
		frontOne = 0;
	}
}

void push(Queue *q, int element, int queueIdx)
{
	if(0 == queueIdx)
	{
		if(rearOne == (MAX_SIZE - 1))
		{
			printf("\n Queue is full. Returning. \n");
			return;
		}
		q->QueueOne[++rearOne] = element;
	}
	else
	{
		if(rearTwo == (MAX_SIZE - 1))
		{
			printf("\n Queue is full. Returning. \n");
			return;
		}
		q->QueueTwo[++rearTwo] = element;
	}
}

int pop(Queue *q)
{
	int retVal = -1;
	// Queue one is empty.
	if((-1 == frontOne) && (-1 == rearOne))
	{
		while(frontTwo < rearTwo)
		{
			push(q, q->QueueTwo[frontTwo++], 0);
		}
		retVal = q->QueueTwo[frontTwo];
		if(frontTwo == rearTwo)
		{
			frontTwo = -1;
			rearTwo  = -1;
		}
	}
	else // Queue two is empty.
	{
		while(frontOne != rearOne)
		{
			push(q, q->QueueOne[frontOne++], 1);
		}
		retVal = q->QueueOne[frontOne];
		if(frontOne == rearOne)
		{
			frontOne = -1;
			rearOne  = -1;
		}
	}
	return retVal;
}

int main()
{
	Queue *q = (Queue *)malloc(sizeof(Queue));
	memset(q->QueueOne, 0, sizeof(q->QueueOne));
	memset(q->QueueTwo, 0, sizeof(q->QueueTwo));
	initializeQueue(q, 1);
	initializeQueue(q, 2);
	initializeQueue(q, 3);
	initializeQueue(q, 4);
	initializeQueue(q, 5);
	printf("\n frontOne: %d rearOne: %d frontTwo: %d rearTwo: %d \n", frontOne, rearOne, frontTwo, rearTwo);
	printf("\n Popping element: %d. \n", pop(q));
	printf("\n Popping element: %d. \n", pop(q));
	printf("\n Popping element: %d. \n", pop(q));
	printf("\n Popping element: %d. \n", pop(q));
	printf("\n Popping element: %d. \n", pop(q));
	return 0;
}
