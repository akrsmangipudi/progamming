# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void bubbleSort(int *arrToSort, int maxIdx)
{
	int outerIdx = 0, innerIdx = 0, temp = 0;

	for(outerIdx = 0; outerIdx <= maxIdx - 1; outerIdx++)
	{
		for(innerIdx = 0; innerIdx <= maxIdx - 1 - outerIdx ; innerIdx++)
		{
			if(arrToSort[innerIdx] > arrToSort[innerIdx+1])
			{
				temp = arrToSort[innerIdx];
				arrToSort[innerIdx] = arrToSort[innerIdx+1];
				arrToSort[innerIdx+1] = temp;
			}
		}
	}
}

void selectionSort(int *arrToSort, int maxIdx)
{
	int outerIdx = 0, innerIdx = 0, temp = 0;

	for(outerIdx = 0; outerIdx <= maxIdx - 1 ; outerIdx++)
	{
		for(innerIdx = outerIdx; innerIdx <= maxIdx ; innerIdx++)
		{
			if(arrToSort[outerIdx] > arrToSort[innerIdx])
			{
				temp = arrToSort[outerIdx];
				arrToSort[outerIdx] = arrToSort[innerIdx];
				arrToSort[innerIdx] = temp;
			}
		}
	}
}

void insertionSort(int *arrToSort, int maxIdx)
{
	int innerIdx = 0, outerIdx = 0, k = 0, temp = 0, shiftIdx = 0;
	for(outerIdx = 0; outerIdx <= maxIdx - 1; outerIdx++)
	{
		innerIdx = 0;
		k = outerIdx + 1;

		while((innerIdx <= k ) && (arrToSort[k] > arrToSort[innerIdx]))
			innerIdx++;

		// Element at index 'k' is where it is supposed to be. Switch to the next element.
		if(innerIdx == k)
			continue;
		// Need to do some real work here. Shifting the elements and placing the element at index 'k' where it belongs.
		// At this point, the element at index 'innderIdx' has a value more than the element at the index 'k'. Shift the elements 
		// starting from index 'innerIdx' through 'k' and place the element at index 'k' in the right position.
		else
		{
			temp = arrToSort[k];
			for(shiftIdx = k - 1; shiftIdx >= innerIdx; shiftIdx--)
			{
				arrToSort[shiftIdx + 1] = arrToSort[shiftIdx];
			}
			arrToSort[innerIdx] = temp;
		}
	}
}

int splitArr(int *arr, int lower, int upper)
{
	int p = lower + 1, q = upper, temp = 0;
	while(p <= q)
	{
		while((arr[p] < arr[lower]) && (p <= upper))
			p++;
		
		while(arr[q] > arr[lower])
			q--;

		if(q >= p)
		{
			temp = arr[q];
			arr[q] = arr[p];
			arr[p] = temp;
		}
	}

	temp = arr[q];
	arr[q] = arr[lower];
	arr[lower] = temp;
	return q;
}

void quickSort(int *arr, int lower, int upper)
{
	int i;
	if(lower < upper)
	{
		i = splitArr(arr, lower, upper);
		quickSort(arr, lower, i - 1);
		quickSort(arr, i + 1, upper);
	}
}

int main()
{
	int arrToSort[] = {25, 17, 31, 13, 2};
	int loopIdx = 0;
#if 0

// Bubble Sort Technique.
	bubbleSort(arrToSort, 4);
	printf("\n Bubble Sort:");
	for(loopIdx = 0; loopIdx < 5; loopIdx++)
	{
		printf("\t %d", arrToSort[loopIdx]);
	}
	printf("\n");

// Selection Sort Technique.
	selectionSort(arrToSort, 4);
	printf("\n Selection Sort:");
	for(loopIdx = 0; loopIdx < 5; loopIdx++)
	{
		printf("\t %d", arrToSort[loopIdx]);
	}
	printf("\n");

// Insertion Sort Technique.
	insertionSort(arrToSort, 4);
	printf("\n Insertion Sort:");
	for(loopIdx = 0; loopIdx < 5; loopIdx++)
	{
		printf("\t %d", arrToSort[loopIdx]);
	}
	printf("\n");
#endif

// Insertion Sort Technique.
	quickSort(arrToSort, 0, 4);
	printf("\n Insertion Sort:");
	for(loopIdx = 0; loopIdx < 5; loopIdx++)
	{
		printf("\t %d", arrToSort[loopIdx]);
	}
	printf("\n");
}
