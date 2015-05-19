# include <stdio.h>
# include <stdlib.h>

int FindPivotElement( int arr[], int low, int high )
{
	int retVal = -1;
	while( low < high )
	{
		int mid = (low + high)/2;

		// Element next to the current element is the pivot element.
		if( ( (mid == 0) || (arr[mid] > arr[mid - 1]) ) && ( (mid == high) || (arr[mid] > arr[mid + 1] ) ) )
		{
			printf(" \n Returning %d from here. (mid-1: %d, mid+1: %d)\n", mid, arr[mid - 1], arr[mid + 1]);
			if( 0 == mid || mid == high )
			{
				retVal = -1;
			}
			else
			{
				retVal = mid + 1;
			}
			return retVal;
		}

		// Current element is the pivot element.
		if( ( ( mid == 0 ) || arr[mid] < arr[mid - 1] ) && ( ( mid == high ) || arr[mid] > arr[mid + 1] ) )
		{
			if( ( mid == 0 ) || ( mid == high ) )
				return -1;
			else
				return mid;
		}

		if( arr[mid] > arr[mid - 1] )
		{
			return FindPivotElement( arr, mid + 1, high );
		}
		else
		{
			return FindPivotElement( arr, low, mid - 1 );
		}
	}
	return retVal;
}

int main()
{
//	int arr[] = { 13, 14, 16, 19, 20, 25, 12, 8, 6, 4, 2, 1 };
	int arr[] = { 10, 100, 120, 160, 17, 15, 13, 7, 1 };

	int pivotElemPosition = FindPivotElement( arr, 0, ( sizeof(arr)/sizeof(arr[0]) - 1) );

	printf("\n %d \n", pivotElemPosition);

	return 0;
}
