# include <stdio.h>
# include <stdlib.h>

int FindFirstOccurence( int *arr, int element, int low, int high )
{
	if( low <= high )
	{
		int mid = (low + high)/2;
		if( ( (mid == 0) || (element > arr[mid - 1]) ) && (arr[mid] == element) )
		{
			return mid;
		}

		if( element > arr[mid] )
		{
			return FindFirstOccurence( arr, element, mid + 1, high );
		}
		else
		{
			return FindFirstOccurence( arr, element, low, mid - 1 );
		}
	}
	return -1;
}

int FindLastOccurence( int *arr, int element, int low, int high )
{
	if( low <= high )
	{
		int mid = (low + high)/2;
		if( ( (mid  == high) || (element < arr[mid + 1]) ) && (arr[mid] == element) )
		{
			return mid;
		}

		if( element > arr[mid] )
		{
			return FindFirstOccurence( arr, element, mid + 1, high );
		}
		else
		{
			return FindFirstOccurence( arr, element, low, mid - 1 );
		}
	}
	return -1;
}

int FindNumberOfOccurences( int arr[], int element, int low, int high )
{
	int retVal = 0;
	
	int i = FindFirstOccurence( arr, element, low, high );
	
	printf("\n i = %d", i);

	if( -1 == i )
	{
		return retVal;
	}

	printf("\n high: %d \n", high );

	int j = FindLastOccurence( arr, element, i, high );

	printf("\n j = %d", j);

	return j - i + 1;
}

int main()
{
//	int x = 2;
//	int arr[] = {1, 1, 2, 2, 2, 2, 3};

	int x = 4;
	int arr[] = {1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 4};

	printf("\n # of Occurences: %d. \n", FindNumberOfOccurences( arr, x, 0, sizeof(arr)/sizeof(arr[0]) - 1 ) ) ;

	return 0;
}
