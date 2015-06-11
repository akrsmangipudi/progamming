# include <stdio.h>

void RearrangeArray( int *arr, int count, int idx, int size )
{
	if( count == size )
	{
		return;
	}

	int valAtIdx = arr[ idx ];
	
	RearrangeArray( arr, count + 1, valAtIdx, size );

	printf("\n Inserting %d at %d position. \n", idx, arr[ valAtIdx ] );

	arr[ valAtIdx ] = idx;
}

int main()
{
	int arr[] = { 2, 0, 1, 4, 5, 3 };

	RearrangeArray( arr, 0, 0, sizeof(arr)/sizeof(arr[0]) );

	int i = 0;
	printf("\n Rearranged elements: ");
	for( i = 0; i < ( sizeof(arr)/sizeof(arr[0]) ); i++ )
	{
		printf("\t %d", arr[ i ] );
	}
	printf("\n");
}
