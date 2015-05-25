# include <stdio.h>
# include <stdbool.h>

void FindMinAndMaxInUnsortedArr( int *arr, int low, int high, int *min, int *max )
{
	int i = low;
	*min = arr[ low ];
	*max = arr[ low ];

	for( i = low; i <= high; i++ )
	{
		if( arr[i] < *min )
		{
			*min = arr[i];
		}

		if( arr[i] > *max )
		{
			*max = arr[i];
		}
	}
}

int PopulateSortIndices( int *arr, int *m_low, int *n_high, bool *sortIndicesFound )
{
	int i = 0, j = *n_high;
	int localMin = -1;
	int localMax = -1;
	
	if( i <= j )
	{
		while( ( i < ( *n_high - 1 ) ) && ( arr[ i ] <= arr[ i + 1 ] ) )
		{
			i++;
		}

		while( ( j > 0 ) && ( arr[j] >= arr[ j - 1 ] ) )
		{
			j--;
		}

		if( i <= j )
		{
			FindMinAndMaxInUnsortedArr( arr, i, j, &localMin, &localMax );
		}
		else
		{
			*sortIndicesFound = false;
			*m_low  = -1;
			*n_high = -1;
			return;
		}
	}

	printf("\n localMin: %d, localMax: %d. \n", localMin, localMax );

	i = 0, j = *n_high;
	
	// Set the low index first.
	while( ( i != *n_high ) && ( arr[i] < localMin ) )
		i++;

	*m_low = i;

	// Set the high index next.
	while( ( j != 0 ) && ( arr[j] > localMax ) )
		j--;

	*n_high = j;
	*sortIndicesFound = true;
}

int main()
{
	//int arr[] = { 1, 2, 4, 7, 10, 21, 31, 12, 6, 7, 16, 18, 19, 50 };
	int arr[] = { 1, 20, 40, 70, 100, 21, 310, 500 };
	int low  = 0;
	int high = sizeof(arr)/sizeof(arr[0]) - 1;

	int m_low = low, n_high = high;

	bool sortIndicesFound = false;
	PopulateSortIndices( arr, &m_low, &n_high, &sortIndicesFound );

	if( sortIndicesFound )
	{
		printf("\n low: %d, high: %d. \n", m_low, n_high );
	}
	else
	{
		printf("\n Array is already sorted. \n");
	}
}
