# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct returnType
{
	int found;
	int position;
}returnType;

void doLinearSearch(int *inputArr, int numOfElements, int elementToSearch, returnType *returnVal)
{
	int iterateIdx = 0;
	for(iterateIdx = 0; iterateIdx < numOfElements; iterateIdx++)
	{
		if(inputArr[iterateIdx] == elementToSearch)
		{
			returnVal->found = 1;
			returnVal->position = iterateIdx;
			break;
		}
		if(inputArr[iterateIdx] > elementToSearch)
			break;
	}
return;
}

void doBinarySearch(int *inputArr, int numOfElements, int elementToSearch, returnType *binarySearchRetVal)
{
	int startIdx = 0, endIdx = numOfElements - 1, iteration = 1;
	int midIdx = (startIdx + endIdx)/2;
	
	while(startIdx <= endIdx)
	{
		if(inputArr[midIdx] == elementToSearch)
		{
			binarySearchRetVal->found = 1;
			binarySearchRetVal->position = iteration;
			break;
		}
		else if(inputArr[midIdx] > elementToSearch)
		{
			endIdx = midIdx - 1;	
		}
		else
		{
			startIdx = midIdx + 1;
		}
		iteration++;
		midIdx = (startIdx + endIdx)/2;
	}
}

int main()
{
	returnType returnVal, binarySearchRetVal;
	memset(&returnVal, 0, sizeof(returnVal));
	memset(&binarySearchRetVal, 0, sizeof(binarySearchRetVal));
	int arr[] = {1, 2, 3, 9, 11, 13, 17, 25, 57, 90};
	int elementToSearch = 57, numOfElements = 10;

// Linear Searching //

#if 0
	doLinearSearch(arr, numOfElements, elementToSearch, &returnVal);
	if(returnVal.found)
		printf("\n Linear Search: Element %d found %d position \n", elementToSearch, returnVal.position);
	else
		printf("\n Linear Search: Element %d not found. \n", elementToSearch);

	memset(&returnVal, 0, sizeof(returnVal));
	elementToSearch = 10;
	doLinearSearch(arr, numOfElements, elementToSearch, &returnVal);
	if(returnVal.found)
		printf("\n Linear Search: Element %d found %d position \n", elementToSearch, returnVal.position);
	else
		printf("\n Linear Search: Element %d not found. \n", elementToSearch);

	memset(&returnVal, 0, sizeof(returnVal));
	elementToSearch = 11;
	doLinearSearch(arr, numOfElements, elementToSearch, &returnVal);
	if(returnVal.found)
		printf("\n Linear Search: Element %d found %d position \n", elementToSearch, returnVal.position);
	else
		printf("\n Linear Search: Element %d not found. \n", elementToSearch);

	memset(&returnVal, 0, sizeof(returnVal));
	elementToSearch = 25;
	doLinearSearch(arr, numOfElements, elementToSearch, &returnVal);
	if(returnVal.found)
		printf("\n Linear Search: Element %d found %d position \n", elementToSearch, returnVal.position);
	else
		printf("\n Linear Search: Element %d not found. \n", elementToSearch);

	memset(&returnVal, 0, sizeof(returnVal));
	elementToSearch = 27;
	doLinearSearch(arr, numOfElements, elementToSearch, &returnVal);
	if(returnVal.found)
		printf("\n Linear Search: Element %d found %d position \n", elementToSearch, returnVal.position);
	else
		printf("\n Linear Search: Element %d not found. \n", elementToSearch);
#endif

// Binary Seaching //

	doBinarySearch(arr, numOfElements, elementToSearch, &binarySearchRetVal);
	if(binarySearchRetVal.found)
		printf("\n Binary Search: Element %d found %d position \n", elementToSearch, binarySearchRetVal.position);
	else
		printf("\n Binary Search: Element %d not found. \n", elementToSearch);

	memset(&binarySearchRetVal, 0, sizeof(binarySearchRetVal));
	elementToSearch = 10;
	doBinarySearch(arr, numOfElements, elementToSearch, &binarySearchRetVal);
	if(binarySearchRetVal.found)
		printf("\n Binary Search: Element %d found %d position \n", elementToSearch, binarySearchRetVal.position);
	else
		printf("\n Binary Search: Element %d not found. \n", elementToSearch);

	memset(&binarySearchRetVal, 0, sizeof(binarySearchRetVal));
	elementToSearch = 11;
	doBinarySearch(arr, numOfElements, elementToSearch, &binarySearchRetVal);
	if(binarySearchRetVal.found)
		printf("\n Binary Search: Element %d found %d position \n", elementToSearch, binarySearchRetVal.position);
	else
		printf("\n Binary Search: Element %d not found. \n", elementToSearch);

	memset(&binarySearchRetVal, 0, sizeof(binarySearchRetVal));
	elementToSearch = 25;
	doBinarySearch(arr, numOfElements, elementToSearch, &binarySearchRetVal);
	if(binarySearchRetVal.found)
		printf("\n Binary Search: Element %d found %d position \n", elementToSearch, binarySearchRetVal.position);
	else
		printf("\n Binary Search: Element %d not found. \n", elementToSearch);

	memset(&binarySearchRetVal, 0, sizeof(binarySearchRetVal));
	elementToSearch = 27;
	doBinarySearch(arr, numOfElements, elementToSearch, &binarySearchRetVal);
	if(binarySearchRetVal.found)
		printf("\n Binary Search: Element %d found %d position \n", elementToSearch, binarySearchRetVal.position);
	else
		printf("\n Binary Search: Element %d not found. \n", elementToSearch);
}	
	
	
