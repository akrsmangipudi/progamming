# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define MAX_SIZE 10

int topOne = -1, topTwo = -1;
int stackOne[MAX_SIZE];
int stackTwo[MAX_SIZE];

void Enqueue_StackOne(int element)
{
	if(topOne == (MAX_SIZE - 1))
	{
		printf("\n Stack is full. Return.");
		return;
	}
	stackOne[++topOne] = element;
}

void Enqueue_StackTwo(int element)
{
	if(topTwo == (MAX_SIZE - 1))
	{
		printf("\n Stack is full. Return.");
		return;
	}
	stackTwo[++topTwo] = element;
}

int Dequeue_StackOne()
{
	int retVal = -1;
	if(-1 == topOne)
	{
		printf("\n Stack one is empty. Nothing to Dequeue.");
	}
	else
	{
		retVal = stackOne[topOne--];
	}
	return retVal;
}

int Dequeue_StackTwo()
{
	int retVal = -1;
	if(-1 == topTwo)
	{
		while(-1 != topOne)
		{
			Enqueue_StackTwo(Dequeue_StackOne());
		}
		retVal = stackTwo[topTwo--];
	}
	else
	{
		retVal = stackTwo[topTwo--];
	}
	return retVal;
}

int main()
{
	Enqueue_StackOne(1);
	Enqueue_StackOne(2);
	Enqueue_StackOne(3);
	Enqueue_StackOne(4);
	Enqueue_StackOne(5);
	Enqueue_StackOne(6);
	Enqueue_StackOne(7);
	Enqueue_StackOne(8);
	Enqueue_StackOne(9);
	Enqueue_StackOne(10);
	Enqueue_StackOne(11);
	printf("\n Removing %d from the queue.", Dequeue_StackTwo());
	printf("\n Removing %d from the queue.", Dequeue_StackTwo());
	printf("\n Removing %d from the queue.", Dequeue_StackTwo());
	printf("\n Removing %d from the queue.", Dequeue_StackTwo());
	printf("\n Removing %d from the queue.", Dequeue_StackTwo());
	printf("\n Removing %d from the queue.", Dequeue_StackTwo());
	printf("\n Removing %d from the queue.", Dequeue_StackTwo());
	printf("\n Removing %d from the queue.", Dequeue_StackTwo());
	printf("\n Removing %d from the queue.", Dequeue_StackTwo());
	printf("\n Removing %d from the queue.", Dequeue_StackTwo());
	Enqueue_StackOne(20);
	Enqueue_StackOne(21);
	Enqueue_StackOne(22);
	Enqueue_StackOne(23);
	printf("\n Removing %d from the queue.", Dequeue_StackTwo());
	printf("\n Removing %d from the queue.", Dequeue_StackTwo());
	Enqueue_StackOne(24);
	Enqueue_StackOne(25);
	printf("\n Removing %d from the queue.", Dequeue_StackTwo());
	printf("\n Removing %d from the queue.", Dequeue_StackTwo());
	printf("\n Removing %d from the queue.", Dequeue_StackTwo());
	printf("\n Removing %d from the queue.", Dequeue_StackTwo());
	return 0;
}

