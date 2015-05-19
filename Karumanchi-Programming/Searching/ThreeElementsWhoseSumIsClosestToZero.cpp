# include <stdio.h>
# include <algorithm>
# include <stdlib.h>

using namespace std;

void PrintThreeNumbers( int arr[], int low, int high)
{
	if( (high - low) < 2)
		return;

	int l_one = low, l_two = high - 1, l_three = high;

	int minSum = arr[ l_one ] + arr[ l_two] + arr[ l_three ];

	int i = 0;
	for( i = high; i >= 2; i-- )
	{
		int l = low;
		int h = i - 1;

		while( l < h )
		{
			int currSum = arr[i] + arr[l] + arr[h];

			if( currSum == 0 )
			{
				minSum = currSum;
				l_one   = l;
				l_two   = h;
				l_three = i; 
				break;
			}

			if( abs(currSum) < abs(minSum) )
			{
				minSum  = currSum;
				l_one   = l;
				l_two   = h;
				l_three = i; 
			}

			if( currSum < 0 )
			{
				l++;
			}
			else
			{
				h--;
			}
		}
	}

	printf("\n Three elements are: %d, %d, %d. \n", arr[l_one], arr[l_two], arr[l_three]);
}

int main()
{
	int arr[] = { -90, -85, -78, -32, 16, 14, 11, 79, 87 };	
	sort( arr, arr + ( sizeof(arr)/sizeof(arr[0]) - 1 ) + 1 );
	PrintThreeNumbers( arr, 0, ( sizeof(arr)/sizeof(arr[0]) - 1 ) );

	return 0;
}
