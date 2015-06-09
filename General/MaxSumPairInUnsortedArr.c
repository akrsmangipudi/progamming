# include <stdio.h>
# include <stdlib.h>

int MaxPairSum( int *arr, int numOfElem )
{
	if( numOfElem == 0 || numOfElem == 1 )
	{
		return -1;
	}

	if( numOfElem == 2 )
		return arr[ 0 ] + arr[ 1 ];

	int firstMax  = arr[ 0 ];
	int secondMax = arr[ 1 ];

	if( firstMax < secondMax )
	{
		firstMax  = firstMax ^ secondMax;
		secondMax = firstMax ^ secondMax;
		firstMax  = firstMax ^ secondMax;
	}

	int i = 0;
	for( i = 2; i < numOfElem ;i++ )
	{
		if( arr[ i ] >= firstMax )
		{
			secondMax = firstMax;

			firstMax  = arr[ i ];
		}
		else if( arr[ i ] > secondMax && arr[ i ] <= firstMax )
		{
			secondMax = arr[ i ];
		}
	}

	return firstMax + secondMax;

}

int main()
{
	int arr[] = { 112, 34, 40, 10, 6, 40, 70, 112 };

	printf("\n Max pair sum: %d \n", MaxPairSum( arr, sizeof(arr)/sizeof( arr[0]) ) );
	
	return 0;
}
