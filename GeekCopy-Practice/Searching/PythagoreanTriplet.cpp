# include <stdio.h>
# include <algorithm>
# include <stdlib.h>
# include <iostream>

using namespace std;

void PrintPythagoreanTriplets( int arr[], int low, int high )
{
	int i = 0;

	sort( arr, arr + high + 1 );

	for( i = high; i >= 2; i-- )
	{
		int h = i - 1;
		int l = low;
		
		while( l < h )
		{
			if( ( arr[i] * arr[i] ) == ( arr[h] * arr[h] ) + ( arr[l] * arr[l] ) )
			{
				printf("\n Triplet: %d, %d, %d. \n", arr[l], arr[h], arr[i]);
				break;
			}

			if( ( arr[i] * arr[i] ) > ( arr[h] * arr[h] ) + ( arr[l] * arr[l] ) )
			{
				l++;
			}
			else
			{
				h--;
			}
		}
	}
}

int main()
{
	int arr[] = {3, 1, 5, 4, 4};

	PrintPythagoreanTriplets( arr, 0, ( sizeof(arr)/sizeof(arr[0]) - 1 ) );

	return 0;
}
