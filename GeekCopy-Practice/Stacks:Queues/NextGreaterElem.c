# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define MAX_SIZE 10

int top = -1;
int stackArr[MAX_SIZE];

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

void nextGreaterElement(int inputList[], int n)
{
	if(-1 == top)
	{
		top = 0;
	}

	int i = 0;
	push(inputList[i]);

	for(i = 1; i < 5; i++)
	{
		int current = inputList[i];

		if(!isStackEmpty())
		{
			int element = pop();
		
			while(element < current)
			{
				printf("\n %d --> %d \n", element, current);
				if(isStackEmpty())
				{
					break;
				}
				element = pop();
			}

			if(element > current)
			{	
				push(element);
			}
		}

		push(inputList[i]);
	}

	while(!isStackEmpty())
	{
		int element = pop();
		printf("\n %d --> %d \n", element, -1);
	}
}

int main()
{
	memset(stackArr, 0, sizeof(stackArr));
	int inputList[] = {10, 4, 9, 8, 16};
	int n = (sizeof(inputList[5])/sizeof(inputList[0]));
	nextGreaterElement(inputList, n);
	return 0;
}
