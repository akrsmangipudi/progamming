# include <stdio.h>
# include <stdlib.h>
# include <string.h>

const unsigned int MAX_SIZE  = 10;

int top = 0;
int stackArr[MAX_SIZE];
int spans[MAX_SIZE];

int isStackEmpty()
{
	if(0 == top)
		return 1;
	else
		return 0;
}

int pop()
{
	int retVal = 0;
	if(isStackEmpty())
	{
		printf("\n Stack is empty. \n");
	}
	else
	{
		retVal = stackArr[--top];
	}
	return retVal;
}

void push(int element)
{
	if(MAX_SIZE == top)
	{
		printf("\n Stack is full. \n");
		return;
	}
	stackArr[top++] = element;
}

int findPos(int val, int inputList[])
{
	int i = 0;
	int retVal = -1;
	for(i = 0; i < 7; i++)
	{
		if(val == inputList[i])
		{
			retVal = i;
			break;
		}
	}
	printf("\n Returning %d for %d searched.", retVal, val);
	return retVal;
}

void calculateSpans(int inputList[], int n)
{
	int i = 0;
	spans[i] = 1;
	push(inputList[i]);

	for(i = 1; i < n; i++)
	{
		int t = top;
		printf("\t top = %d", t);
		while((0 != top) && (inputList[i] > stackArr[--t]))
		{
			pop();
		}

		spans[i] = (0 == top) ? (i + 1) : (i - findPos(stackArr[t], inputList));
		push(inputList[i]);
	}
}

void printSpans()
{
	int i = 0;
	printf("\n");
	for(i = 0; i < 7; i++)
	{
		printf("\t %d: %d", i, spans[i]);
	}
	printf("\n");
}

int main()
{
	memset(stackArr, 0, sizeof(stackArr));
	int inputList[] = {100, 80, 60, 70, 60, 75, 85};
	int n = (sizeof(inputList)/sizeof(inputList[0]));
	calculateSpans(inputList, n);
	printSpans();
	return 0;
}
