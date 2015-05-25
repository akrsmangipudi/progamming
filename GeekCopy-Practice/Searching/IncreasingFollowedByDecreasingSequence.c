# include <stdio.h>
# include <stdlib.h>

int FindPivotElement( int arr[], int low, int high, int maxIdx )
{
	if( low<= high )
	{
		int mid = ( low + high )/2;

//		printf("\n Mid Element : %d. (arr[mid-1]: %d, arr[mid]: %d, arr[mid+1]: %d)\n", mid, arr[mid-1], arr[mid], arr[mid+1]);
		
		if( ( (mid == 0) || ( arr[mid] > arr[mid-1] ) ) && ( (mid == maxIdx) ||  (arr[mid] > arr[mid + 1]) ) )
		{
			if( ( mid == 0 ) || ( mid == maxIdx ) )
			{
//				printf("\n Returning -1 ");
				return -1;
			}

			return mid + 1;	
		}

		if( ( mid == 0 ) || ( arr[mid] > arr[ mid - 1 ] ) )
		{
			return FindPivotElement( arr, mid + 1, high, maxIdx );
		}
		else
		{
			return FindPivotElement( arr, low, mid - 1, maxIdx );
		}
	}
	return -1;
}

int main()
{
//	int arr[] = { 13, 14, 16, 19, 20, 25, 12, 8, 6, 4, 2, 1 };
	int arr[] = { 10, 9, 8, 7, 6, 5, 4 };

	int pivotElemPosition = FindPivotElement( arr, 0, ( sizeof(arr)/sizeof(arr[0]) - 1), ( sizeof(arr)/sizeof(arr[0]) - 1) );

	printf("\n %d \n", pivotElemPosition);

	return 0;
}
