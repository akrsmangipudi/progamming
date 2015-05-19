# include <stdio.h>
# include <algorithm>
# include <stdlib.h>

using namespace std;

void PrintThreeNumbers( int arr[], int low, int high, int sum)
{
	if( (high - low) < 2)
		return;

	int i = 0;

	for( i = high; i >= 2; i-- )
	{
		int h = i - 1;
		int l = low;
		
		while( l < h )
		{
			if( sum == ( arr[i] + arr[h] + arr[l] ) )
			{
				printf("\n Triplet: %d, %d, %d. \n", arr[l], arr[h], arr[i]);
				l++;
				h--;
				continue;
			}

			if( ( arr[i] + arr[h]  + arr[l] ) < sum )
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
	int arr[] = {1, 4, 10, 5, 45, 6, 8, 9, 7};
    int sum = 22;

	sort( arr, arr + ( sizeof(arr)/sizeof(arr[0]) - 1 ) );

	PrintThreeNumbers( arr, 0, ( sizeof(arr)/sizeof(arr[0]) - 1 ), sum);

	return 0;
}
